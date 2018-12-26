include Belt;

let noOp = _ => ();

module RR = {
  include ReasonReact;
};

let s = RR.string;

let makeStyle = ReactDOMRe.Style.make;
