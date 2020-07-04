module type Example = {
  let title: string;
  let make: Js.t({.}) => React.element;
  let makeProps: (~key: string=?, unit) => Js.t({.});
};

let exampleModules: list(module Example) = [
  (module HelloWorld),
  (module Emojis),
];

module Page = {
  type t = {
    title: string,
    slug: string,
    render: unit => React.element,
  };

  let home = {
    title: "Home",
    slug: "",
    render: () => "Use the navigation menu to select an example"->RR.s,
  };

  let notFound = {
    title: "Not found",
    slug: "not-found",
    render: () => "That example was not found"->RR.s,
  };

  let getSlug = title =>
    title->JsString.toLowerCase->JsString.replaceByRe([%re "/ /g"], "-");

  let pages = {
    let pages =
      exampleModules->List.map(example => {
        let (module Ex) = example;
        {title: Ex.title, slug: getSlug(Ex.title), render: () => <Ex />};
      });
    [home, ...pages];
  };

  let fromPath = path => {
    let slug = path->List.head->Option.getWithDefault("");
    pages
    ->List.getBy(page => page.slug == slug)
    ->Option.getWithDefault(notFound);
  };
};

[@react.component]
let make = () => {
  let url = ReasonReactRouter.useUrl();

  let page = Page.fromPath(url.path);

  <div className="h-screen flex flex-row">
    <div className="bg-blue-600 text-white py-4 px-6 mr-8">
      <div className="text-lg underline mb-4"> "Navigation"->RR.s </div>
      {Page.pages
       ->List.mapWithIndex((i, page) =>
           <div
             key={i->string_of_int}
             className="cursor-pointer"
             onClick={_ => ReasonReactRouter.push("/" ++ page.slug)}>
             page.title->RR.s
           </div>
         )
       ->RR.list}
    </div>
    <div
      className="mt-4 grid gap-4"
      style={ReactDOMRe.Style.make(~gridTemplateRows="auto 1fr", ())}>
      <Title> page.title->RR.s </Title>
      {page.render()}
    </div>
  </div>;
};
