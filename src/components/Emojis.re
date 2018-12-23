open Prelude;

type state = {emojis: array(Emojilib.emoji)};

type action =
  | AddEmoji
  | Clear;

let component = RR.reducerComponent(__MODULE__);

let make = _children => {
  ...component,

  initialState: () => {emojis: [||]},

  reducer: (action, state) =>
    switch (action) {
    | AddEmoji =>
      RR.Update({
        emojis: Js.Array.concat(state.emojis, [|Emojilib.getRandom()|]),
      })
    | Clear => RR.Update({emojis: [||]})
    },

  render: ({state, send}) =>
    <div className="Emojis">
      <div className="mb-4">
        <button className="border px-2 py-1" onClick={_ => send @@ AddEmoji}>
          "Add"->s
        </button>
        <button className="border px-2 py-1" onClick={_ => send @@ Clear}>
          "Clear"->s
        </button>
      </div>
      <div>
        {state.emojis
         ->Array.map(emoji =>
             <div
               key={emoji.name}
               className="inline flex flex-col border items-center">
               <span className="mb-1">
                 emoji.name->s
                 ", "->s
                 emoji.category->s
               </span>
               <span className="text-5xl"> emoji.char->s </span>
             </div>
           )
         ->RR.array}
      </div>
    </div>,
};
