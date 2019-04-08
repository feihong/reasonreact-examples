// Generated by BUCKLESCRIPT VERSION 4.0.18, PLEASE EDIT WITH CARE

import * as Cn from "re-classnames/src/Cn.bs.js";
import * as Block from "bs-platform/lib/es6/block.js";
import * as Curry from "bs-platform/lib/es6/curry.js";
import * as React from "react";
import * as $$String from "bs-platform/lib/es6/string.js";
import * as Belt_Array from "bs-platform/lib/es6/belt_Array.js";
import * as ReasonReact from "reason-react/src/ReasonReact.js";
import * as Hello$ReasonreactExamples from "./pages/Hello.bs.js";
import * as Emojis$ReasonreactExamples from "./pages/Emojis.bs.js";
import * as Prelude$ReasonreactExamples from "./Prelude.bs.js";
import * as Scratch$ReasonreactExamples from "./pages/Scratch.bs.js";
import * as KawaiiDemo$ReasonreactExamples from "./pages/KawaiiDemo.bs.js";
import * as ContainerDemo$ReasonreactExamples from "./pages/ContainerDemo.bs.js";

var sidebarLinks = /* array */[
  /* tuple */[
    "Hello",
    /* Hello */1
  ],
  /* tuple */[
    "Emojis",
    /* Emojis */2
  ],
  /* tuple */[
    "Kawaii",
    /* KawaiiDemo */3
  ],
  /* tuple */[
    "Container",
    /* Container */4
  ],
  /* tuple */[
    "Scratch",
    /* Scratch */5
  ]
];

function getPageFromUrl(url) {
  var match = url[/* path */0];
  if (match) {
    switch (match[0]) {
      case "container" : 
          if (match[1]) {
            return /* NotFound */0;
          } else {
            return /* Container */4;
          }
      case "emojis" : 
          if (match[1]) {
            return /* NotFound */0;
          } else {
            return /* Emojis */2;
          }
      case "hello" : 
          if (match[1]) {
            return /* NotFound */0;
          } else {
            return /* Hello */1;
          }
      case "kawaii" : 
          if (match[1]) {
            return /* NotFound */0;
          } else {
            return /* KawaiiDemo */3;
          }
      case "scratch" : 
          if (match[1]) {
            return /* NotFound */0;
          } else {
            return /* Scratch */5;
          }
      default:
        return /* NotFound */0;
    }
  } else {
    return /* Hello */1;
  }
}

var component = Curry._1(Prelude$ReasonreactExamples.RR[/* reducerComponent */2], "App-ReasonreactExamples");

function make(_children) {
  return /* record */[
          /* debugName */component[/* debugName */0],
          /* reactClassInternal */component[/* reactClassInternal */1],
          /* handedOffState */component[/* handedOffState */2],
          /* willReceiveProps */component[/* willReceiveProps */3],
          /* didMount */(function (self) {
              var send = self[/* send */3];
              var changePage = function (url) {
                return Curry._1(send, /* ChangePage */[getPageFromUrl(url)]);
              };
              var url = ReasonReact.Router[/* dangerouslyGetInitialUrl */3](/* () */0);
              Curry._1(send, /* ChangePage */[getPageFromUrl(url)]);
              var watcherID = ReasonReact.Router[/* watchUrl */1](changePage);
              return Curry._1(self[/* onUnmount */4], (function (param) {
                            return ReasonReact.Router[/* unwatchUrl */2](watcherID);
                          }));
            }),
          /* didUpdate */component[/* didUpdate */5],
          /* willUnmount */component[/* willUnmount */6],
          /* willUpdate */component[/* willUpdate */7],
          /* shouldUpdate */component[/* shouldUpdate */8],
          /* render */(function (param) {
              var currentPage = param[/* state */1][/* currentPage */0];
              var tmp;
              switch (currentPage) {
                case 0 : 
                    tmp = React.createElement("div", {
                          className: "NotFound"
                        }, Prelude$ReasonreactExamples.s("The content you seek was not found"));
                    break;
                case 1 : 
                    tmp = ReasonReact.element(undefined, undefined, Hello$ReasonreactExamples.make(/* array */[]));
                    break;
                case 2 : 
                    tmp = ReasonReact.element(undefined, undefined, Emojis$ReasonreactExamples.make(/* array */[]));
                    break;
                case 3 : 
                    tmp = ReasonReact.element(undefined, undefined, KawaiiDemo$ReasonreactExamples.make(/* array */[]));
                    break;
                case 4 : 
                    tmp = ReasonReact.element(undefined, undefined, ContainerDemo$ReasonreactExamples.make(/* array */[]));
                    break;
                case 5 : 
                    tmp = ReasonReact.element(undefined, undefined, Scratch$ReasonreactExamples.make(/* array */[]));
                    break;
                
              }
              return React.createElement("div", {
                          className: "App h-screen flex flex-row"
                        }, React.createElement("div", {
                              className: "SideBar bg-blue text-white flex flex-col"
                            }, React.createElement("div", {
                                  className: "pt-4 px-4 pb-4 border-b font-bold text-lg"
                                }, Prelude$ReasonreactExamples.s("RR Examples")), Belt_Array.map(sidebarLinks, (function (param) {
                                    var page = param[1];
                                    var name = param[0];
                                    var match = currentPage === page;
                                    var className = Cn.make(/* :: */[
                                          "px-4 py-3",
                                          /* :: */[
                                            match ? "cursor-default bg-blue-darker" : "cursor-pointer hover:bg-blue-dark",
                                            /* [] */0
                                          ]
                                        ]);
                                    return React.createElement("div", {
                                                key: name,
                                                className: className,
                                                onClick: (function (param) {
                                                    var match = currentPage !== page;
                                                    if (match) {
                                                      return ReasonReact.Router[/* push */0]($$String.lowercase(name));
                                                    } else {
                                                      return /* () */0;
                                                    }
                                                  })
                                              }, Prelude$ReasonreactExamples.s(name));
                                  }))), React.createElement("div", {
                              className: "Content pt-6 pl-6"
                            }, tmp));
            }),
          /* initialState */(function (param) {
              return /* record */[/* currentPage : Hello */1];
            }),
          /* retainedProps */component[/* retainedProps */11],
          /* reducer */(function (action, _state) {
              return /* Update */Block.__(0, [/* record */[/* currentPage */action[0]]]);
            }),
          /* jsElementWrapped */component[/* jsElementWrapped */13]
        ];
}

export {
  sidebarLinks ,
  getPageFromUrl ,
  component ,
  make ,
  
}
/* component Not a pure module */
