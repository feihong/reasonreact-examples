open Prelude;

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

module type JsComponent = {let reactClass: RR.reactClass;};

module MakeComponent = (JC: JsComponent) => {
  let make = (~mood=?, ~size=?, ~color=?, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=JC.reactClass,
      ~props=jsProps(~mood=?mood->Option.map(moodToJs), ~size?, ~color?, ()),
      children,
    );
};

module Backpack =
  MakeComponent({
    [@bs.module "react-kawaii"]
    external reactClass: RR.reactClass = "Backpack";
  });

module Browser =
  MakeComponent({
    [@bs.module "react-kawaii"] external reactClass: RR.reactClass = "Browser";
  });

module CreditCard =
  MakeComponent({
    [@bs.module "react-kawaii"]
    external reactClass: RR.reactClass = "CreditCard";
  });

module Ghost =
  MakeComponent({
    [@bs.module "react-kawaii"] external reactClass: RR.reactClass = "Ghost";
  });

module IceCream =
  MakeComponent({
    [@bs.module "react-kawaii"]
    external reactClass: RR.reactClass = "IceCream";
  });

module Mug =
  MakeComponent({
    [@bs.module "react-kawaii"] external reactClass: RR.reactClass = "Mug";
  });

module Planet =
  MakeComponent({
    [@bs.module "react-kawaii"] external reactClass: RR.reactClass = "Planet";
  });

module SpeechBubble =
  MakeComponent({
    [@bs.module "react-kawaii"]
    external reactClass: RR.reactClass = "SpeechBubble";
  });
