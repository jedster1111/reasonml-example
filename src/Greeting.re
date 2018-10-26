let component = ReasonReact.statelessComponent("Greeting");

let make = (~name, _children) => {
  ...component,
  render: _self =>
    <button>
      {ReasonReact.string("Hello, how are you doing " ++ name ++ "!")}
    </button>,
};