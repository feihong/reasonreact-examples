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

  didMount: ({send}) => send @@ AddEmoji,

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
      <h1 className=""> "Emoji Generator"->s </h1>
      <div className="text-xs mb-4"> "(Images from Twemoji)"->s </div>
      <div className="mb-4">
        <Button className="mr-4" text="Add" onClick={_ => send @@ AddEmoji} />
        <Button className="mr-4" text="Clear" onClick={_ => send @@ Clear} />
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
                 {emoji.fitzpatrick_scale ? " (fitzpatrick scale)"->s : RR.null}
               </span>
               <div className="flex content-center">
                 <span className="text-5xl mr-4"> emoji.char->s </span>
                 <img style=imgStyle src={Twemoji.emojiUrl(emoji.char)} />
               </div>
             </div>
           )
         ->RR.array}
      </div>
    </div>,
};
