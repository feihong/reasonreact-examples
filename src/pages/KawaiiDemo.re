open Prelude;
open Kawaii;

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

module ComponentSelect = {
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

type state = {
  component: compChoice,
  mood: Kawaii.mood,
};

type action =
  | ChangeComponent(compChoice)
  | ChangeMood(Kawaii.mood);

let component = RR.reducerComponent(__MODULE__);

let make = _children => {
  ...component,

  initialState: () => {component: `Ghost, mood: `happy},

  reducer: (action, state) =>
    switch (action) {
    | ChangeComponent(component) => RR.Update({...state, component})
    | ChangeMood(mood) => RR.Update({...state, mood})
    },

  render: ({state, send}) =>
    <div className="KawaiiDemo">
      <h1 className="mb-4"> "React-Kawaii Demo"->s </h1>
      <div className="mb-4">
        <span className="mr-1"> "Mood:"->s </span>
        <ComponentSelect
          className="mr-4"
          initValue=`Ghost
          onChange={v => send @@ ChangeComponent(v)}
        />
        <span className="mr-1"> "Mood:"->s </span>
        <MoodSelect initValue=`happy onChange={v => send @@ ChangeMood(v)} />
      </div>
      <SpeechBubble mood={state.mood} />
    </div>,
};
