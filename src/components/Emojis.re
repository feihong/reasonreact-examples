open Prelude;

type state = {emojis: array(Emojilib.emoji)};

let imgStyle = {
  let w = "48px";
  makeStyle(~height=w, ~width=w, ());
};

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
        <button
          className="border px-2 py-1 rounded mr-4"
          onClick={_ => send @@ AddEmoji}>
          "Add"->s
        </button>
        <button
          className="border px-2 py-1 rounded" onClick={_ => send @@ Clear}>
          "Clear"->s
        </button>
      </div>
      <div>
        {state.emojis
         ->Array.mapWithIndex((index, emoji) =>
             <div
               key={index->string_of_int}
               className="inline flex flex-col border items-center">
               <span className="mb-1">
                 emoji.name->s
                 " => "->s
                 emoji.category->s
               </span>
               <div className="flex content-center">
                 <span className="text-5xl mr-2"> emoji.char->s </span>
                 <img style=imgStyle src={Twemoji.emojiUrl(emoji.char)} />
               </div>
             </div>
           )
         ->RR.array}
      </div>
    </div>,
};
