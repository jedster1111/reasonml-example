type todo = {
  id: string,
  text: string,
  isDone: bool,
};

let component = ReasonReact.statelessComponent("Todo");

let make = (~todo, ~removeTodo, ~closeTodo, ~openTodo, _children) => {
  ...component,

  render: _self =>
    <li>
      {ReasonReact.string(todo.text ++ " " ++ (todo.isDone ? "Done" : ""))}
      <div>
        <button
          onClick={
            _event => todo.isDone ? openTodo(todo.id) : closeTodo(todo.id)
          }>
          {ReasonReact.string(todo.isDone ? "Re-open" : "Done")}
        </button>
        <button onClick={_event => removeTodo(todo.id)}>
          {ReasonReact.string("Remove")}
        </button>
      </div>
    </li>,
};