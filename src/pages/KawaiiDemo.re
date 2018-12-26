open Prelude;
open Kawaii;

type component = [
  | `Backpack
  | `Browser
  | `CreditCard
  | `Ghost
  | `IceCream
  | `Mug
  | `Planet
  | `SpeechBubble
];

module ComponentSelect = {
  include Select.Make({
    type t = component;
  });

  let compItems =
    [|
      ("backpack", `Backpack),
      ("browser", `Browser),
      ("credit card", `CreditCard),
      ("ghost", `Ghost),
      ("ice cream", `IceCream),
      ("mug", `Mug),
      ("planet", `Planet),
      ("speech bubble", `SpeechBubble),
    |]
    ->Array.map(pair => {label: pair->fst, value: pair->snd});

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
  component,
  mood: Kawaii.mood,
};

type action =
  | ChangeComponent(component)
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
      {switch (state.component) {
       | `Backpack => <Backpack mood={state.mood} />
       | `Browser => <Browser mood={state.mood} />
       | `CreditCard => <CreditCard mood={state.mood} />
       | `Ghost => <Ghost mood={state.mood} />
       | `IceCream => <IceCream mood={state.mood} />
       | `Mug => <Mug mood={state.mood} />
       | `Planet => <Planet mood={state.mood} />
       | `SpeechBubble => <SpeechBubble mood={state.mood} />
       }}
    </div>,
};
