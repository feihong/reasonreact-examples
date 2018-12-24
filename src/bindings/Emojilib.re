open Prelude;

[@bs.module "emojilib"] external ordered: array(string) = "";
[@bs.module "emojilib"]
external fitzpatrick_scale_modifiers: array(string) = "";

type emojiObj = {
  .
  "char": string,
  "fitzpatrick_scale": bool,
  "category": string,
};

type emoji = {
  name: string,
  char: string,
  fitzpatrick_scale: bool,
  category: string,
};

[@bs.module "emojilib"] external lib: Js.Dict.t(emojiObj) = "";

let emojiCount = ordered->Array.length;

let defaultEmojiObj: emojiObj = {
  "char": "smile",
  "fitzpatrick_scale": false,
  "category": "people",
};

let humanize = s => s->Js.String.replace([%bs.raw {|/_/g|}], " ", _);

let randomFitzpatrickScale = () => {
  let index = Random.int(Array.length(fitzpatrick_scale_modifiers));
  fitzpatrick_scale_modifiers
  ->Array.get(index)
  ->Option.getWithDefault({js|🏻|js});
};

let getRandom = () => {
  let index = Random.int(emojiCount);
  let name = ordered->Array.get(index)->Option.getWithDefault("smile");
  let obj = lib->Js.Dict.get(name)->Option.getWithDefault(defaultEmojiObj);
  {
    name: name->humanize,
    char: obj##char,
    fitzpatrick_scale: obj##fitzpatrick_scale,
    category: obj##category->humanize,
  };
};
