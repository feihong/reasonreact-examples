open Prelude;

let component = RR.statelessComponent(__MODULE__);

let make = (~label, ~value, _children) => {
  ...component,
  render: _self =>
    <div
      className="ValueBox shadow-lg rounded-lg py-4 px-2 border text-center text-lg mb-4">
      <span className="text-indigo"> {(label ++ ": ")->s} </span>
      {value->Js.String.make->s}
    </div>,
};
