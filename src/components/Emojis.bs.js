// Generated by BUCKLESCRIPT VERSION 4.0.14, PLEASE EDIT WITH CARE

import * as Block from "bs-platform/lib/es6/block.js";
import * as Curry from "bs-platform/lib/es6/curry.js";
import * as React from "react";
import * as Belt_Array from "bs-platform/lib/es6/belt_Array.js";
import * as Prelude$ReasonreactExamples from "../Prelude.bs.js";
import * as Emojilib$ReasonreactExamples from "../bindings/Emojilib.bs.js";

var component = Curry._1(Prelude$ReasonreactExamples.RR[/* reducerComponent */2], "Emojis-ReasonreactExamples");

function make(_children) {
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
              return React.createElement("div", {
                          className: "Emojis"
                        }, React.createElement("div", {
                              className: "mb-4"
                            }, React.createElement("button", {
                                  className: "border px-2 py-1",
                                  onClick: (function (param) {
                                      return Curry._1(send, /* AddEmoji */0);
                                    })
                                }, Prelude$ReasonreactExamples.s("Add")), React.createElement("button", {
                                  className: "border px-2 py-1",
                                  onClick: (function (param) {
                                      return Curry._1(send, /* Clear */1);
                                    })
                                }, Prelude$ReasonreactExamples.s("Clear"))), React.createElement("div", undefined, Belt_Array.map(param[/* state */1][/* emojis */0], (function (emoji) {
                                    return React.createElement("div", {
                                                key: emoji[/* name */0],
                                                className: "inline flex flex-col border items-center"
                                              }, React.createElement("span", {
                                                    className: "mb-1"
                                                  }, Prelude$ReasonreactExamples.s(emoji[/* name */0]), Prelude$ReasonreactExamples.s(", "), Prelude$ReasonreactExamples.s(emoji[/* category */3])), React.createElement("span", {
                                                    className: "text-5xl"
                                                  }, Prelude$ReasonreactExamples.s(emoji[/* char */1])));
                                  }))));
            }),
          /* initialState */(function (param) {
              return /* record */[/* emojis : array */[]];
            }),
          /* retainedProps */component[/* retainedProps */11],
          /* reducer */(function (action, state) {
              if (action) {
                return /* Update */Block.__(0, [/* record */[/* emojis : array */[]]]);
              } else {
                return /* Update */Block.__(0, [/* record */[/* emojis *//* array */[Emojilib$ReasonreactExamples.getRandom(/* () */0)].concat(state[/* emojis */0])]]);
              }
            }),
          /* jsElementWrapped */component[/* jsElementWrapped */13]
        ];
}

export {
  component ,
  make ,
  
}
/* component Not a pure module */