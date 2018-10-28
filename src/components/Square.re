type state = {hasBeenHovered: bool};

type action =
  | Hover
  | Unhover;

let component = ReasonReact.reducerComponent("Square");

let make = (~handleClick, _children) => {
  ...component,

  initialState: () => {hasBeenHovered: false},

  reducer: (action, _state) =>
    switch (action) {
    | Hover => ReasonReact.Update({hasBeenHovered: true})
    | Unhover => ReasonReact.Update({hasBeenHovered: false})
    },

  render: self =>
    <button
      onClick=handleClick
      onMouseEnter={_event => self.send(Hover)}
      onMouseLeave={_event => self.send(Unhover)}>
      {
        self.state.hasBeenHovered ?
          ReasonReact.string("Hovered!") : ReasonReact.string("Not Hovered")
      }
    </button>,
};