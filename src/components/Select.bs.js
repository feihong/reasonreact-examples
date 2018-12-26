// Generated by BUCKLESCRIPT VERSION 4.0.14, PLEASE EDIT WITH CARE

import * as Cn from "re-classnames/src/Cn.bs.js";
import * as Block from "bs-platform/lib/es6/block.js";
import * as Curry from "bs-platform/lib/es6/curry.js";
import * as React from "react";
import * as Caml_obj from "bs-platform/lib/es6/caml_obj.js";
import * as Belt_Array from "bs-platform/lib/es6/belt_Array.js";
import * as Belt_Option from "bs-platform/lib/es6/belt_Option.js";
import * as Caml_option from "bs-platform/lib/es6/caml_option.js";
import * as Prelude$ReasonreactExamples from "../Prelude.bs.js";

function Make(C) {
  var component = Curry._1(Prelude$ReasonreactExamples.RR[/* reducerComponent */2], "Select-ReasonreactExamples");
  var make = function (initValue, items, $staropt$star, $staropt$star$1, _children) {
    var className = $staropt$star !== undefined ? $staropt$star : "";
    var onChange = $staropt$star$1 !== undefined ? $staropt$star$1 : Prelude$ReasonreactExamples.noOp;
    return /* record */[
            /* debugName */component[/* debugName */0],
            /* reactClassInternal */component[/* reactClassInternal */1],
            /* handedOffState */component[/* handedOffState */2],
            /* willReceiveProps */component[/* willReceiveProps */3],
            /* didMount */component[/* didMount */4],
            /* didUpdate */component[/* didUpdate */5],
            /* willUnmount */component[/* willUnmount */6],
            /* willUpdate */component[/* willUpdate */7],
            /* shouldUpdate */component[/* shouldUpdate */8],
            /* render */(function (param) {
                var send = param[/* send */3];
                return React.createElement("select", {
                            className: Cn.make(/* :: */[
                                  "border",
                                  /* :: */[
                                    className,
                                    /* [] */0
                                  ]
                                ]),
                            value: Belt_Option.mapWithDefault(param[/* state */1][/* current */0], "", (function (item) {
                                    return item[/* label */0];
                                  })),
                            onChange: (function (evt) {
                                var label = evt.target.value;
                                return Curry._1(send, /* ChangeCurrent */[label]);
                              })
                          }, Belt_Array.map(items, (function (item) {
                                  return React.createElement("option", {
                                              key: item[/* label */0],
                                              value: item[/* label */0]
                                            }, Prelude$ReasonreactExamples.s(item[/* label */0]));
                                })));
              }),
            /* initialState */(function (param) {
                return /* record */[/* current */Belt_Option.mapWithDefault(initValue, undefined, (function (initValue) {
                                return Caml_option.undefined_to_opt(items.find((function (item) {
                                                  return Caml_obj.caml_equal(item[/* value */1], initValue);
                                                })));
                              }))];
              }),
            /* retainedProps */component[/* retainedProps */11],
            /* reducer */(function (action, _state) {
                var label = action[0];
                var item = items.find((function (item) {
                        return item[/* label */0] === label;
                      }));
                var item$1 = item === undefined ? undefined : Caml_option.some(item);
                return /* UpdateWithSideEffects */Block.__(2, [
                          /* record */[/* current */item$1],
                          (function (param) {
                              Belt_Option.map(item$1, (function (item) {
                                      return Curry._1(onChange, item[/* value */1]);
                                    }));
                              return /* () */0;
                            })
                        ]);
              }),
            /* jsElementWrapped */component[/* jsElementWrapped */13]
          ];
  };
  return /* module */[
          /* component */component,
          /* make */make
        ];
}

export {
  Make ,
  
}
/* react Not a pure module */
