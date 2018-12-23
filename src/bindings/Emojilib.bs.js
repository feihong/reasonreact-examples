// Generated by BUCKLESCRIPT VERSION 4.0.14, PLEASE EDIT WITH CARE

import * as Random from "bs-platform/lib/es6/random.js";
import * as Js_dict from "bs-platform/lib/es6/js_dict.js";
import * as Emojilib from "emojilib";
import * as Belt_Array from "bs-platform/lib/es6/belt_Array.js";
import * as Belt_Option from "bs-platform/lib/es6/belt_Option.js";

var emojiCount = Emojilib.ordered.length;

var defaultEmojiObj = {
  char: "fun",
  fitzpatrick_scale: false,
  category: "people"
};

function getRandom(param) {
  var index = Random.$$int(emojiCount);
  var name = Belt_Option.getWithDefault(Belt_Array.get(Emojilib.ordered, index), "smile");
  var obj = Belt_Option.getWithDefault(Js_dict.get(Emojilib.lib, name), defaultEmojiObj);
  return /* record */[
          /* name */name.replace((/_/g), " "),
          /* char */obj.char,
          /* fitzpatrick_scale */obj.fitzpatrick_scale,
          /* category */obj.category
        ];
}

export {
  emojiCount ,
  defaultEmojiObj ,
  getRandom ,
  
}
/* emojiCount Not a pure module */
