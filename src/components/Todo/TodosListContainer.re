open Todo;

type actions =
  | Add(string)
  | Close(string)
  | ReOpen(string)
  | Remove(string)
  | HandleInputChange(string);

type state = {
  todos: array(todo),
  todoInput: string,
};

let component = ReasonReact.reducerComponent("TodoContainer");

let make = _children => {
  ...component,

  initialState: () => {todos: [||], todoInput: ""},

  reducer: (action, state) =>
    switch (action) {
    | Add(text) =>
      ReasonReact.Update({
        todos:
          Array.append(
            [|{id: Uuid.v4(), text, isDone: false}|],
            state.todos,
          ),
        todoInput: "",
      })

    | Close(id) =>
      let todoToUpdateIndex =
        Js.Array.findIndex(todo => todo.id === id, state.todos);
      let todoToUpdate = state.todos[todoToUpdateIndex];

      let closedTodo = {...todoToUpdate, isDone: true};
      let newTodos = Array.copy(state.todos);
      newTodos[todoToUpdateIndex] = closedTodo;
      ReasonReact.Update({...state, todos: newTodos});

    | ReOpen(id) =>
      let todoToUpdateIndex =
        Js.Array.findIndex(todo => todo.id === id, state.todos);
      let todoToUpdate = state.todos[todoToUpdateIndex];

      let openedTodo = {...todoToUpdate, isDone: false};
      let newTodos = Array.copy(state.todos);
      newTodos[todoToUpdateIndex] = openedTodo;
      ReasonReact.Update({...state, todos: newTodos});

    | Remove(id) =>
      let copyOfTodos = Array.copy(state.todos);
      let newTodos = Js.Array.filter(todo => todo.id !== id, copyOfTodos);
      ReasonReact.Update({...state, todos: newTodos});

    | HandleInputChange(value) =>
      ReasonReact.Update({...state, todoInput: value})
    },

  render: self =>
    <TodosList
      todos={self.state.todos}
      addTodo={
        event => {
          ReactEventRe.Synthetic.preventDefault(event);
          self.send(Add(self.state.todoInput));
        }
      }
      inputValue={self.state.todoInput}
      handleInputChange={
        event =>
          self.send(
            HandleInputChange(
              ReactDOMRe.domElementToObj(ReactEventRe.Form.target(event))##value,
            ),
          )
      }
      removePoll={id => self.send(Remove(id))}
    />,
};