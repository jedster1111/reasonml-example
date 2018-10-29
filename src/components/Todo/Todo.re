type todo = {
  id: string,
  text: string,
  isDone: bool,
};

let component = ReasonReact.statelessComponent("Todo");

let make = (~todo, ~removePoll, _children) => {
  ...component,

  render: _self =>
    <li>
      {ReasonReact.string(todo.text)}
      <button onClick={_event => removePoll(todo.id)}>
        {ReasonReact.string("Remove")}
      </button>
    </li>,
};