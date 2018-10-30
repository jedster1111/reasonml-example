open Todo;

type actions =
  | Add(string)
  | Close(string)
  | Open(string)
  | Remove(string)
  | HandleInputChange(string);

type state = {
  todos: list(todo),
  todoInput: string,
};

let reducer = (action, state) =>
  switch (action) {
  | Add(text) =>
    switch (text) {
    | "" => ReasonReact.NoUpdate
    | _ =>
      ReasonReact.Update({
        todos: [{id: Uuid.v4(), text, isDone: false}, ...state.todos],
        todoInput: "",
      })
    }

  | Close(id) =>
    let todo = state.todos->Belt.List.getBy(todo => todo.id == id);
    switch (todo) {
    | None => ReasonReact.NoUpdate
    | Some(todo) =>
      let newTodo = {...todo, isDone: true};
      let newTodos =
        state.todos
        ->Belt.List.map(todo =>
            switch (todo) {
            | _ when todo.id == id => newTodo
            | _ => todo
            }
          );
      ReasonReact.Update({...state, todos: newTodos});
    };

  | Open(id) =>
    let todo = state.todos->Belt.List.getBy(todo => todo.id == id);
    switch (todo) {
    | None => ReasonReact.NoUpdate
    | Some(todo) =>
      let newTodo = {...todo, isDone: false};
      let newTodos =
        state.todos
        ->Belt.List.map(todo =>
            switch (todo) {
            | _ when todo.id == id => newTodo
            | _ => todo
            }
          );
      ReasonReact.Update({...state, todos: newTodos});
    };

  | Remove(id) =>
    let newTodos = state.todos->Belt.List.keep(todo => todo.id != id);
    ReasonReact.Update({...state, todos: newTodos});

  | HandleInputChange(value) =>
    ReasonReact.Update({...state, todoInput: value})
  };

let component = ReasonReact.reducerComponent("TodoContainer");

let make = _children => {
  ...component,

  initialState: () => {todos: [], todoInput: ""},

  reducer,

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
          ReactEventRe.Form.target(event)->ReactDOMRe.domElementToObj##value
          ->HandleInputChange
          ->(self.send)
      }
      removeTodo={id => self.send(Remove(id))}
      openTodo={id => self.send(Open(id))}
      closeTodo={id => self.send(Close(id))}
    />,
};