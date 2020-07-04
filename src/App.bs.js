// Generated by BUCKLESCRIPT, PLEASE EDIT WITH CARE

import * as Curry from "bs-platform/lib/es6/curry.js";
import * as React from "react";
import * as Belt_List from "bs-platform/lib/es6/belt_List.js";
import * as RR$ReasonreactExamples from "./RR.bs.js";
import * as HelloWorld$ReasonreactExamples from "./examples/HelloWorld.bs.js";

function App$Title(Props) {
  var children = Props.children;
  return React.createElement("h1", {
              className: "text-4xl"
            }, children);
}

var Title = {
  make: App$Title
};

function render(param) {
  return RR$ReasonreactExamples.s("Use the navigation menu to select an example");
}

var Home = {
  title: "Home",
  render: render
};

var examples_1 = {
  hd: {
    title: HelloWorld$ReasonreactExamples.title,
    render: HelloWorld$ReasonreactExamples.render
  },
  tl: /* [] */0
};

var examples = {
  hd: Home,
  tl: examples_1
};

function App(Props) {
  var match = RR$ReasonreactExamples.useStateValue(Home);
  var setExample = match[1];
  var example = match[0];
  return React.createElement("div", {
              className: "h-screen flex flex-row"
            }, React.createElement("div", {
                  className: "bg-blue-600 text-white py-4 px-6 mr-8"
                }, React.createElement("div", {
                      className: "text-lg underline mb-4"
                    }, RR$ReasonreactExamples.s("Navigation")), RR$ReasonreactExamples.list(Belt_List.mapWithIndex(examples, (function (i, example) {
                            return React.createElement("div", {
                                        key: String(i),
                                        className: "cursor-pointer",
                                        onClick: (function (param) {
                                            return Curry._1(setExample, example);
                                          })
                                      }, RR$ReasonreactExamples.s(example.title));
                          })))), React.createElement("div", {
                  className: "mt-4 grid gap-4",
                  style: {
                    gridTemplateRows: "auto 1fr"
                  }
                }, React.createElement(App$Title, {
                      children: RR$ReasonreactExamples.s(example.title)
                    }), Curry._1(example.render, undefined)));
}

var make = App;

export {
  Title ,
  Home ,
  examples ,
  make ,
  
}
/* react Not a pure module */
