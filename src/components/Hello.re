open Prelude;

let component = RR.statelessComponent(__MODULE__);

let make = _children => {
  ...component,

  render: _self => <div className="Hello"> {js|你好世界！|js}->s </div>,
};
