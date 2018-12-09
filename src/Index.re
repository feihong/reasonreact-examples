open Prelude;

module App = {
  let component = RR.statelessComponent("App");

  let make = _children => {
    ...component,

    render: _self => <div> {js|你好世界！|js}->s </div>,
  };
};

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
