include Belt;

module RR = {
  include ReasonReact;
};

let noOp = _ => ();

let s = RR.string;

let makeStyle = ReactDOMRe.Style.make;

let arrayRandGet = a => a->Array.get(Random.int(a->Array.length));

let choose2 = (a1, a2, fn) => {
  switch (arrayRandGet(a1), arrayRandGet(a2)) {
  | (Some(a), Some(b)) => fn(a, b)
  | _ => ()
  };
};
