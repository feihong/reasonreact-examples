open Prelude;

let component = RR.statelessComponent(__MODULE__);

let make = (~className="", ~text, ~onClick, _children) => {
  let className =
    Cn.make(["text-grey-darker bg-grey-light px-2 py-1 rounded", className]);
  {
    ...component,
    render: _self => <button className onClick> text->s </button>,
  };
};
