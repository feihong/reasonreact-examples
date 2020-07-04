// Generated by BUCKLESCRIPT, PLEASE EDIT WITH CARE

import * as Curry from "bs-platform/lib/es6/curry.js";
import * as React from "react";
import * as Belt_List from "bs-platform/lib/es6/belt_List.js";
import * as Belt_Option from "bs-platform/lib/es6/belt_Option.js";
import * as ReasonReactRouter from "reason-react/src/ReasonReactRouter.bs.js";
import * as RR$ReasonreactExamples from "./RR.bs.js";
import * as Title$ReasonreactExamples from "./widgets/Title.bs.js";
import * as Emojis$ReasonreactExamples from "./examples/Emojis.bs.js";
import * as HelloWorld$ReasonreactExamples from "./examples/HelloWorld.bs.js";

function getSlug(title) {
  return title.toLowerCase().replace(/ /g, "-");
}

function home_render(param) {
  return RR$ReasonreactExamples.s("Use the navigation menu to select an example");
}

var home = {
  title: "Home",
  slug: "",
  render: home_render
};

function notFound_render(param) {
  return RR$ReasonreactExamples.s("That example was not found");
}

var notFound = {
  title: "Not found",
  slug: "not-found",
  render: notFound_render
};

var modules_0 = {
  title: HelloWorld$ReasonreactExamples.title,
  render: HelloWorld$ReasonreactExamples.render
};

var modules_1 = {
  hd: {
    title: Emojis$ReasonreactExamples.title,
    render: Emojis$ReasonreactExamples.render
  },
  tl: /* [] */0
};

var modules = {
  hd: modules_0,
  tl: modules_1
};

var examplesFromModules = Belt_List.map(modules, (function (example) {
        return {
                title: example.title,
                slug: getSlug(example.title),
                render: example.render
              };
      }));

var examples = {
  hd: home,
  tl: examplesFromModules
};

function getExampleFromPath(path) {
  var slug = Belt_Option.getWithDefault(Belt_List.head(path), "");
  return Belt_Option.getWithDefault(Belt_List.getBy(examples, (function (ex) {
                    return ex.slug === slug;
                  })), notFound);
}

function App(Props) {
  var url = ReasonReactRouter.useUrl(undefined, undefined);
  var example = getExampleFromPath(url.path);
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
                                            return ReasonReactRouter.push("/" + example.slug);
                                          })
                                      }, RR$ReasonreactExamples.s(example.title));
                          })))), React.createElement("div", {
                  className: "mt-4 grid gap-4",
                  style: {
                    gridTemplateRows: "auto 1fr"
                  }
                }, React.createElement(Title$ReasonreactExamples.make, {
                      children: RR$ReasonreactExamples.s(example.title)
                    }), Curry._1(example.render, undefined)));
}

var make = App;

export {
  getSlug ,
  home ,
  notFound ,
  examples ,
  getExampleFromPath ,
  make ,
  
}
/* examplesFromModules Not a pure module */
