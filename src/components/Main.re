type page =
  | Todo
  | Posts
  | Home
  | NotFound;

type state = {route: page};

type action =
  | UpdatePage(page);

let component = ReasonReact.reducerComponent("Main");

let make = _children => {
  ...component,

  initialState: () => {
    let url = ReasonReact.Router.dangerouslyGetInitialUrl();
    let page =
      switch (url.path) {
      | ["todo"] => Todo
      | ["posts"] => Posts
      | [] => Home
      | _ => NotFound
      };
    {route: page};
  },

  reducer: (action, state) =>
    switch (action) {
    | UpdatePage(route) =>
      ReasonReact.UpdateWithSideEffects(
        {route: route},
        (
          _self => {
            if (route != state.route)
              {
                ReasonReact.Router.push(switch(route){
                  | Todo => "/todo"
                  | Posts => "/posts"
                  | Home => "/"
                  | NotFound => "/404"
                })
              };
            }
        ),
      )
    },

  didMount: self => {
    let watcherId =
      ReasonReact.Router.watchUrl(url =>
        switch (url.path) {
        | ["todo"] => self.send(UpdatePage(Todo))
        | ["posts"] => self.send(UpdatePage(Posts))
        | [] => self.send(UpdatePage(Home))
        | _ => self.send(UpdatePage(NotFound))
        }
      );
    self.onUnmount(() => ReasonReact.Router.unwatchUrl(watcherId));
  },

  render: self =>
    ReasonReact.(
      <div className="main">
        <Navbar
          navHome={_event => self.send(UpdatePage(Home))}
          navTodos={_event => self.send(UpdatePage(Todo))}
          navPosts={_event => self.send(UpdatePage(Posts))}
        />
        {
          switch (self.state.route) {
          | Todo => <TodosListContainer />
          | Posts => <PostsDisplay />
          | Home => <p> {string("Welcome to Reason")} </p>
          | NotFound => <p> {string("Whoops, 404 not found!")} </p>
          }
        }
      </div>
    ),
};