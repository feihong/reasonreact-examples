let title = "Emoji Generator";

let imgStyle = {
  let w = "48px";
  RR.makeStyle(~height=w, ~width=w, ());
};

module Example = {
  [@react.component]
  let make = () => {
    let (emojis, setEmojis) = RR.useStateValue([||]);

    <div>
      <div className="text-xs mb-4"> "(Images from Twemoji)"->RR.s </div>
      <div className="mb-4">
        <Button
          onClick={_ =>
            setEmojis @@ Js.Array2.append(emojis, Emojilib.getRandom())
          }>
          "Add"->RR.s
        </Button>
        <Button onClick={_ => setEmojis @@ [||]}> "Clear"->RR.s </Button>
      </div>
      <div>
        {emojis
         ->Array.mapWithIndex((index, emoji) =>
             <div
               key={index->string_of_int}
               className="inline flex flex-col border items-center">
               <span className="mb-1">
                 emoji.name->RR.s
                 " => "->RR.s
                 emoji.category->RR.s
                 {emoji.fitzpatrick_scale
                    ? " (fitzpatrick scale)"->RR.s : RR.null}
               </span>
               <div className="flex content-center">
                 <span className="text-5xl mr-4"> emoji.char->RR.s </span>
                 <img style=imgStyle src={Twemoji.emojiUrl(emoji.char)} />
               </div>
             </div>
           )
         ->RR.array}
      </div>
    </div>;
  };
};

let render = () => <Example />;
