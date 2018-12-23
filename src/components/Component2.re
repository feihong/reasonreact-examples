open Prelude;

let component = RR.statelessComponent(__MODULE__);

let make = _children => {
  ...component,

  render: _self =>
    <div className="text-orange text-5xl underline capitalize">
      "Component 2"->s
    </div>,
};
