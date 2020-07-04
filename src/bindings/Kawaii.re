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
  external make:
    (~size: int=?, ~mood: string=?, ~color: string=?) => React.element =
    "Backpack";
};
