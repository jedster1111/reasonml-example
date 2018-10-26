type square = {
  id: string,
  text: string,
};

type actions =
  | Add(square)
  | Remove(string);

type state = {items: list(square)};

let component = ReasonReact.reducerComponent("SquareList");

let make = _children => {
  ...component,

  initialState: () => {items: []},

  reducer: (action, state) =>
    switch (action) {
    | Add(item) => ReasonReact.Update({items: [item, ...state.items]})
    | Remove(id) =>
      ReasonReact.Update({
        items: List.filter(square => square.id !== id, state.items),
      })
    },

  render: self =>
    <div>
      {ReasonReact.string("Hello can you see this? Again? Test")}
      <div className="item-list">
        {
          ReasonReact.array(
            Array.mapi(
              (index, _square) => <Square key={string_of_int(index)} />,
              Array.of_list(self.state.items),
            ),
          )
        }
      </div>
      <div className="buttons-container">
        <button
          onClick={_event => self.send(Add({id: "test", text: "Hello"}))}>
          {ReasonReact.string("Add")}
        </button>
      </div>
    </div>,
};