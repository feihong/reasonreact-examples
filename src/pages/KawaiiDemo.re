open Prelude;
open Kawaii;

module ComponentSelect = {
  [@bs.deriving jsConverter]
  type compChoice = [
    | `Backpack
    | `CreditCart
    | `Ghost
    | `IceCream
    | `Mug
    | `Planet
    | `SpeechBubble
  ];
  include Select.Make({
    type t = compChoice;
  });

  let compItems =
    [|
      `Backpack,
      `CreditCart,
      `Ghost,
      `IceCream,
      `Mug,
      `Planet,
      `SpeechBubble,
    |]
    ->Array.map(comp => {label: comp->compChoiceToJs, value: comp});

  let make = make(~items=compItems);
};

module MoodSelect = {
  include Select.Make({
    type t = Kawaii.mood;
  });

  let moodItems =
    [|`sad, `shocked, `happy, `blissful, `lovestruck, `excited, `ko|]
    ->Array.map(mood => {label: mood->Kawaii.moodToJs, value: mood});

  let make = make(~items=moodItems);
};

let component = RR.statelessComponent(__MODULE__);

let make = _children => {
  ...component,

  render: _self =>
    <div className="KawaiiDemo">
      <h1 className="mb-4"> "React-Kawaii Demo"->s </h1>
      <div className="mb-4">
        <span className="mr-1"> "Mood:"->s </span>
        <ComponentSelect className="mr-4" initValue=`Ghost />
        <span className="mr-1"> "Mood:"->s </span>
        <MoodSelect initValue=`happy />
      </div>
      <SpeechBubble mood=`shocked />
    </div>,
};
