let base = "https://twemoji.maxcdn.com/2/";

[@bs.module "./twemoji-mini"] external grabTheRightIcon: string => string = "";

let emojiUrl = echar => base ++ "svg/" ++ grabTheRightIcon(echar) ++ ".svg";
