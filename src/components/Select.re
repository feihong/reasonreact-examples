open Prelude;

module Make = (C: {type t;}) => {
  type item = {
    label: string,
    value: C.t,
  };

  let component = RR.statelessComponent(__MODULE__);

  let make =
      (~value, ~items: array(item), ~className="", ~onChange=noOp, _children) => {
    ...component,

    render: _self =>
      <select
        className={Cn.make(["border", className])}
        value={
          items
          ->Js.Array.find(item => item.value == value, _)
          ->Option.mapWithDefault("", item => item.label)
        }
        onChange={evt => {
          let label = evt->ReactEvent.Form.target##value;
          items
          ->Js.Array.find(item => item.label == label, _)
          ->Option.map(item => onChange(item.value))
          ->ignore;
        }}>
        {items
         ->Array.map(item =>
             <option key={item.label} value={item.label}>
               item.label->s
             </option>
           )
         ->RR.array}
      </select>,
  };
};
