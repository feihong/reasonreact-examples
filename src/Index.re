[%bs.raw {|require('./Index.pcss')|}];

ReactDOMRe.renderToElementWithId(<App />, "index");

/* Sets up hot module replacement using Parcel */
module Parcel = {
  type t;
  type hot;

  [@bs.val] external parcelModule: t = "module";
  [@bs.get] external hot: t => Js.nullable(hot) = "";
  [@bs.send] external accept: hot => unit = "";

  switch (parcelModule->hot->Js.Nullable.toOption) {
  | Some(h) => h->accept
  | _ => Js.log("We are not hot")
  };
};
