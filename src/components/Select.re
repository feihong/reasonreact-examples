open Prelude;

module Make = (C: {type t;}) => {
  type item = {
    label: string,
    value: C.t,
  };
  type state = {current: option(item)};

  type action =
    | ChangeCurrent(string);

  let component = RR.reducerComponent(__MODULE__);

  let make =
      (
        ~initValue=?,
        ~items: array(item),
        ~className="",
        ~onChange=noOp,
        _children,
      ) => {
    ...component,
    initialState: () => {
      current:
        initValue->Option.mapWithDefault(None, initValue =>
          items->Js.Array.find(item => item.value == initValue, _)
        ),
    },
    reducer: (action, _state) =>
      switch (action) {
      | ChangeCurrent(label) =>
        let item = items->Js.Array.find(item => item.label == label, _);
        RR.UpdateWithSideEffects(
          {current: item},
          _ => item->Option.map(item => onChange(item.value))->ignore,
        );
      },
    render: ({state, send}) =>
      <select
        className={Cn.make(["border", className])}
        value={state.current->Option.mapWithDefault("", item => item.label)}
        onChange={evt => {
          let label = evt->ReactEvent.Form.target##value;
          send @@ ChangeCurrent(label);
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
