open Prelude;
open Kawaii;

let component = RR.statelessComponent(__MODULE__);

let make = _children => {
  ...component,

  render: _self =>
    <div className="KawaiiDemo">
      <h1 className="mb-4"> "React-Kawaii Demo"->s </h1>
      <SpeechBubble mood=`shocked />
    </div>,
};
