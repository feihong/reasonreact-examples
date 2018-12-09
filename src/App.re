[%bs.raw {|require('./App.pcss')|}];

open Prelude;

let component = RR.statelessComponent("App");

let make = _children => {
  ...component,

  render: _self => <div className="App"> {js|你好世界！|js}->s </div>,
};
