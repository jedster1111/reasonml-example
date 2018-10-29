open Todo;

let component = ReasonReact.statelessComponent("TodoList");

let make =
    (
      ~todos,
      ~addTodo,
      ~handleInputChange,
      ~inputValue,
      ~removePoll,
      _children,
    ) => {
  ...component,

  render: _self =>
    <div>
      {ReasonReact.string("Hello")}
      <ul>
        {
          ReasonReact.array(
            Array.map(todo => <Todo todo key={todo.id} removePoll />, todos),
          )
        }
      </ul>
      <form onSubmit=addTodo>
        <input value=inputValue onChange=handleInputChange />
        <button> {ReasonReact.string("Add")} </button>
      </form>
    </div>,
};