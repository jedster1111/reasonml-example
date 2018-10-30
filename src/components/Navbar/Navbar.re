let component = ReasonReact.statelessComponent("Navbar");

let make = (~navHome, ~navTodos, ~navPosts, _children) => {
  ...component,

  render: _self =>
    ReasonReact.(
      <nav>
        <ol>
          <li> <button onClick=navHome> {string("Home")} </button> </li>
          <li> <button onClick=navTodos> {string("Todos")} </button> </li>
          <li> <button onClick=navPosts> {string("Posts")} </button> </li>
        </ol>
      </nav>
    ),
};