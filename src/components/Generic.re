/* open Prelude;

   type item('a) = {
     label: string,
     value: 'a,
   };

   /* let item1 = {label: "a", value: 1}; */

   type state('a) = {current: option(item('a))};

   type action =
     | ChangeCurrent(string);

   let component = RR.reducerComponent(__MODULE__);

   let make = (~initValue: option('a)=?, ~items: array(item('a)), _children) => {
     ...component,
     initialState: () => {
       current:
         initValue->Option.mapWithDefault(None, initValue =>
           items->Js.Array.find(item => item.value == initValue, _)
         ),
     },

     reducer: (action, state) =>
       switch (action) {
       | ChangeCurrent(label) =>
         let item = items->Js.Array.find(item => item.label == label, _);
         RR.Update({current: item});
       },

     render: ({state, send}) =>
       <select
         value={state.current->Option.mapWithDefault("", item => item.label)}
         onChange={evt => {
           let label = evt->ReactEvent.Form.target##value;
           send @@ ChangeCurrent(label);
         }}>
         {items
          ->Array.map(item => <option value={item.label}> item.label->s </option>)
          ->RR.array}
       </select>,
   }; */
