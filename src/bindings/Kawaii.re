open Prelude;

[@bs.module "react-kawaii"] external backpack: RR.reactClass = "Backpack";

[@bs.deriving jsConverter]
type mood = [
  | `sad
  | `shocked
  | `happy
  | `blissful
  | `lovestruck
  | `excited
  | `ko
];

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
    ~props=jsProps(~mood=?mood->Option.map(moodToJs), ~size?, ~color?, ()),
    children,
  );
