type todo = {
  id: string,
  text: string,
  isDone: bool,
};

let component = ReasonReact.statelessComponent("Todo");

let make = (~todo, _children) => {
  ...component,

  render: _self => <li> {ReasonReact.string(todo.text)} </li>,
};