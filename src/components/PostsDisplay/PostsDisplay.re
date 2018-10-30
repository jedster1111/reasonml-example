type post = {
  userId: int,
  id: int,
  title: string,
  body: string,
};

type actions =
  | LoadPosts
  | PostsLoaded(list(post))
  | LoadPostsFailed;

type state =
  | LoadingPosts
  | WaitingForUser(list(post))
  | Error;

let decodePostJson = json =>
  Json.Decode.{
    userId: json |> field("userId", int),
    id: json |> field("id", int),
    title: json |> field("title", string),
    body: json |> field("body", string),
  };

let decodePostsJson = Json.Decode.list(decodePostJson);

let loadPostsSideEffects = self =>
  ReasonReact.(
    Js.Promise.(
      Fetch.fetch("https://jsonplaceholder.typicode.com/posts")
      |> then_(Fetch.Response.json)
      |> then_(json => decodePostsJson(json) |> resolve)
      |> then_(data => PostsLoaded(data) |> self.send |> resolve)
      |> catch(_error => self.send(LoadPostsFailed) |> resolve)
      |> ignore
    )
  );

let reducer = (action, _state) =>
  ReasonReact.(
    switch (action) {
    | LoadPosts => UpdateWithSideEffects(LoadingPosts, loadPostsSideEffects)
    | PostsLoaded(data) => Update(WaitingForUser(data))
    | LoadPostsFailed => Update(Error)
    }
  );

let renderParagraph = text => <p> {ReasonReact.string(text)} </p>;

let renderLoading = () => renderParagraph("Loading...");

let renderError = () => renderParagraph("There was an error!");

let renderPost = post =>
  <li key={string_of_int(post.id)}>
    {renderParagraph("userId: " ++ string_of_int(post.userId))}
    {renderParagraph("id: " ++ string_of_int(post.id))}
    {renderParagraph("Title: " ++ post.title)}
    {renderParagraph("Body: " ++ post.body)}
  </li>;

let renderPosts = posts =>
  <div className="posts-display">
    <ul>
      {
        List.map(post => renderPost(post), posts)
        |> Array.of_list
        |> ReasonReact.array
      }
    </ul>
  </div>;

let render = self =>
  ReasonReact.(
    <div className="posts-display">
      <p>
        {string("An example of side effects. Fetching posts from ")}
        <a href="https://jsonplaceholder.typicode.com" target="_blank">
          {string("JSON Placeholder")}
        </a>
      </p>
      <button onClick={_event => self.send(LoadPosts)}>
        {string("Reload")}
      </button>
      {
        switch (self.state) {
        | LoadingPosts => renderLoading()
        | WaitingForUser(posts) => renderPosts(posts)
        | Error => renderError()
        }
      }
    </div>
  );

let component = ReasonReact.reducerComponent("PostsDisplay");

let make = _children => {
  ...component,
  reducer,
  render,
  initialState: () => LoadingPosts,
  didMount: self => self.send(LoadPosts),
};