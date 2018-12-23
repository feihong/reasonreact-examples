open Prelude;

[@bs.module "emojilib"] external ordered: array(string) = "";

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
  "char": "fun",
  "fitzpatrick_scale": false,
  "category": "people",
};

let getRandom = () => {
  let index = Random.int(emojiCount);
  let name = ordered->Array.get(index)->Option.getWithDefault("smile");
  let obj = lib->Js.Dict.get(name)->Option.getWithDefault(defaultEmojiObj);
  {
    name: name->Js.String.replace("_", " ", _),
    char: obj##char,
    fitzpatrick_scale: obj##fitzpatrick_scale,
    category: obj##category,
  };
};
