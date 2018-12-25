open Prelude;

let component = RR.statelessComponent(__MODULE__);

let make = _children => {
  ...component,

  render: _self =>
    <div className="KawaiiDemo">
      <h1> "React-Kawaii Demo"->s </h1>
      <Kawaii mood=`happy />
    </div>,
};
