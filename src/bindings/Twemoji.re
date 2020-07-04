let base = "https://twemoji.maxcdn.com/2";

[@bs.module "./twemoji-mini"]
external grabTheRightIcon: string => string = "grabTheRightIcon";

let emojiUrl = echar =>
  Printf.sprintf("%s/svg/%s.svg", base, grabTheRightIcon(echar));
