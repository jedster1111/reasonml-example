type state = {isClicked: bool};

type action =
  | Click;

let component = ReasonReact.reducerComponent("Square");

let make = _children => {
  ...component,

  initialState: () => {isClicked: false},

  reducer: (action, state) =>
    switch (action) {
    | Click => ReasonReact.Update({isClicked: !state.isClicked})
    },

  render: self =>
    <button onClick={_event => self.send(Click)}>
      {
        self.state.isClicked ?
          ReasonReact.string("You clicked on me!, click again?") :
          ReasonReact.string("Click me?")
      }
    </button>,
};