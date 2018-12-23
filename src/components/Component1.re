open Prelude;

let component = RR.statelessComponent(__MODULE__);

let make = _children => {
  ...component,

  render: _self =>
    <div className="text-4xl text-green italic"> "Component 1"->s </div>,
};
