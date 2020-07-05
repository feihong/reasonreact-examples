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

module Backpack = {
  [@bs.module "react-kawaii"] [@react.component]
  external internal:
    (~size: int=?, ~color: string=?, ~mood: string=?) => React.element =
    "Backpack";

  let make = internal;
  let makeProps = (~size=?, ~color=?, ~mood=?) =>
    internalProps(
      ~size?,
      ~color?,
      ~mood=?{
        mood->Option.map(moodToJs);
      },
    );
};
