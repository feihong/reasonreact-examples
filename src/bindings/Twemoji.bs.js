// Generated by BUCKLESCRIPT VERSION 4.0.18, PLEASE EDIT WITH CARE

import * as TwemojiMini from "./twemoji-mini";

var base = "https://twemoji.maxcdn.com/2/";

function emojiUrl(echar) {
  return base + ("svg/" + (TwemojiMini.grabTheRightIcon(echar) + ".svg"));
}

export {
  base ,
  emojiUrl ,
  
}
/* ./twemoji-mini Not a pure module */
