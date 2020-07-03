// This component can render an arbitrary number of children, and those children
// do not need to have key props.
open Prelude;

let component = RR.statelessComponent(__MODULE__);

let make = children => {
  ...component,

  render: _self =>
    <div className="border p-4 mb-4">
      <div className="text-xs text-grey mb-1"> "Header of container"->s </div>
      <div> ...children </div>
      <div className="text-xs text-grey mt-1"> "Footer of container"->s </div>
    </div>,
};
