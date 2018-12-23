open Prelude;

/* type state = {emojis: array(string)}; */

let component = RR.statelessComponent(__MODULE__);

let make = _children => {
  ...component,

  render: _self => {
    let emoji = Emojilib.getRandom();
    <div className="flex flex-col border items-center">
      <span> emoji.name->s </span>
      <span className="text-5xl"> emoji.char->s </span>
    </div>;
  },
};
