open Todo;

let component = ReasonReact.statelessComponent("TodoList");

let make =
    (
      ~todos,
      ~addTodo,
      ~handleInputChange,
      ~inputValue,
      ~removeTodo,
      ~openTodo,
      ~closeTodo,
      _children,
    ) => {
  ...component,

  render: _self =>
    <div>
      {ReasonReact.string("Todos")}
      <ul>
        {
          todos
          ->Belt.List.map(todo =>
              <Todo todo key={todo.id} removeTodo openTodo closeTodo />
            )
          ->Array.of_list
          ->ReasonReact.array
        }
      </ul>
      <form onSubmit=addTodo>
        <input value=inputValue onChange=handleInputChange />
        <button> {ReasonReact.string("Add")} </button>
      </form>
    </div>,
};