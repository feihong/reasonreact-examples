// Generated by BUCKLESCRIPT, PLEASE EDIT WITH CARE

import * as Curry from "bs-platform/lib/es6/curry.js";
import * as React from "react";
import * as Prelude$ReasonreactExamples from "../Prelude.bs.js";

var component = Curry._1(Prelude$ReasonreactExamples.RR.statelessComponent, "ValueBox-ReasonreactExamples");

function make(label, value, _children) {
  return {
          debugName: component.debugName,
          reactClassInternal: component.reactClassInternal,
          handedOffState: component.handedOffState,
          willReceiveProps: component.willReceiveProps,
          didMount: component.didMount,
          didUpdate: component.didUpdate,
          willUnmount: component.willUnmount,
          willUpdate: component.willUpdate,
          shouldUpdate: component.shouldUpdate,
          render: (function (_self) {
              return React.createElement("div", {
                          className: "ValueBox shadow-lg rounded-lg py-4 px-2 border text-center text-lg mb-4"
                        }, React.createElement("span", {
                              className: "text-indigo"
                            }, Prelude$ReasonreactExamples.s(label + ": ")), Prelude$ReasonreactExamples.s(String(value)));
            }),
          initialState: component.initialState,
          retainedProps: component.retainedProps,
          reducer: component.reducer,
          jsElementWrapped: component.jsElementWrapped
        };
}

export {
  component ,
  make ,
  
}
/* component Not a pure module */
