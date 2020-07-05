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

// The code below was generated using scripts/gen-kawaii-modules.js

module Backpack = {
  [@bs.module "react-kawaii"] [@react.component]
  external internal:
    (~size: int=?, ~color: string=?, ~mood: string=?) => React.element =
    "Backpack";

  let make = internal;
  let makeProps = (~mood=?) =>
    internalProps(
      ~mood=?{
        mood->Option.map(moodToJs);
      },
    );
};

module Browser = {
  [@bs.module "react-kawaii"] [@react.component]
  external internal:
    (~size: int=?, ~color: string=?, ~mood: string=?) => React.element =
    "Browser";

  let make = internal;
  let makeProps = (~mood=?) =>
    internalProps(
      ~mood=?{
        mood->Option.map(moodToJs);
      },
    );
};

module Cat = {
  [@bs.module "react-kawaii"] [@react.component]
  external internal:
    (~size: int=?, ~color: string=?, ~mood: string=?) => React.element =
    "Cat";

  let make = internal;
  let makeProps = (~mood=?) =>
    internalProps(
      ~mood=?{
        mood->Option.map(moodToJs);
      },
    );
};

module Chocolate = {
  [@bs.module "react-kawaii"] [@react.component]
  external internal:
    (~size: int=?, ~color: string=?, ~mood: string=?) => React.element =
    "Chocolate";

  let make = internal;
  let makeProps = (~mood=?) =>
    internalProps(
      ~mood=?{
        mood->Option.map(moodToJs);
      },
    );
};

module CreditCard = {
  [@bs.module "react-kawaii"] [@react.component]
  external internal:
    (~size: int=?, ~color: string=?, ~mood: string=?) => React.element =
    "CreditCard";

  let make = internal;
  let makeProps = (~mood=?) =>
    internalProps(
      ~mood=?{
        mood->Option.map(moodToJs);
      },
    );
};

module File = {
  [@bs.module "react-kawaii"] [@react.component]
  external internal:
    (~size: int=?, ~color: string=?, ~mood: string=?) => React.element =
    "File";

  let make = internal;
  let makeProps = (~mood=?) =>
    internalProps(
      ~mood=?{
        mood->Option.map(moodToJs);
      },
    );
};

module Ghost = {
  [@bs.module "react-kawaii"] [@react.component]
  external internal:
    (~size: int=?, ~color: string=?, ~mood: string=?) => React.element =
    "Ghost";

  let make = internal;
  let makeProps = (~mood=?) =>
    internalProps(
      ~mood=?{
        mood->Option.map(moodToJs);
      },
    );
};

module IceCream = {
  [@bs.module "react-kawaii"] [@react.component]
  external internal:
    (~size: int=?, ~color: string=?, ~mood: string=?) => React.element =
    "IceCream";

  let make = internal;
  let makeProps = (~mood=?) =>
    internalProps(
      ~mood=?{
        mood->Option.map(moodToJs);
      },
    );
};

module Mug = {
  [@bs.module "react-kawaii"] [@react.component]
  external internal:
    (~size: int=?, ~color: string=?, ~mood: string=?) => React.element =
    "Mug";

  let make = internal;
  let makeProps = (~mood=?) =>
    internalProps(
      ~mood=?{
        mood->Option.map(moodToJs);
      },
    );
};

module Planet = {
  [@bs.module "react-kawaii"] [@react.component]
  external internal:
    (~size: int=?, ~color: string=?, ~mood: string=?) => React.element =
    "Planet";

  let make = internal;
  let makeProps = (~mood=?) =>
    internalProps(
      ~mood=?{
        mood->Option.map(moodToJs);
      },
    );
};

module SpeechBubble = {
  [@bs.module "react-kawaii"] [@react.component]
  external internal:
    (~size: int=?, ~color: string=?, ~mood: string=?) => React.element =
    "SpeechBubble";

  let make = internal;
  let makeProps = (~mood=?) =>
    internalProps(
      ~mood=?{
        mood->Option.map(moodToJs);
      },
    );
};
