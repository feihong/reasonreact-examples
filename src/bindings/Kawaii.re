open Prelude;

[@bs.module "react-kawaii"] external backpack: RR.reactClass = "Backpack";

[@bs.deriving abstract]
type jsProps = {
  [@bs.optional]
  mood: string,
  [@bs.optional]
  size: int,
  [@bs.optional]
  color: string,
};

let make = (~mood=?, ~size=?, ~color=?, children) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=backpack,
    ~props=jsProps(~mood?, ~size?, ~color?, ()),
    children,
  );
