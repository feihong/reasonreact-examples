// Generated by BUCKLESCRIPT, PLEASE EDIT WITH CARE

import * as Random from "bs-platform/lib/es6/random.js";
import * as Js_dict from "bs-platform/lib/es6/js_dict.js";
import * as Emojilib from "emojilib";
import * as Belt_Array from "bs-platform/lib/es6/belt_Array.js";
import * as Belt_Option from "bs-platform/lib/es6/belt_Option.js";

var emojiCount = Emojilib.ordered.length;

var defaultEmojiObj = {
  char: "smile",
  fitzpatrick_scale: false,
  category: "people"
};

function humanize(s) {
  return s.replace(/_/g, " ");
}

function randomFitzpatrickScale(param) {
  var index = Random.$$int(Emojilib.fitzpatrick_scale_modifiers.length);
  return Belt_Option.getWithDefault(Belt_Array.get(Emojilib.fitzpatrick_scale_modifiers, index), "🏻");
}

function getRandom(param) {
  var index = Random.$$int(emojiCount);
  var name = Belt_Option.getWithDefault(Belt_Array.get(Emojilib.ordered, index), "smile");
  var obj = Belt_Option.getWithDefault(Js_dict.get(Emojilib.lib, name), defaultEmojiObj);
  return {
          name: humanize(name),
          char: obj.char,
          fitzpatrick_scale: obj.fitzpatrick_scale,
          category: humanize(obj.category)
        };
}

export {
  emojiCount ,
  defaultEmojiObj ,
  humanize ,
  randomFitzpatrickScale ,
  getRandom ,
  
}
/* emojiCount Not a pure module */
