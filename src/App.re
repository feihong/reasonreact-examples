let getSlug = title =>
  title->JsString.toLowerCase->JsString.replace([%raw {|/_/g|}], "-");

module type Example = {
  let title: string;
  let render: unit => React.element;
};

type example = {
  title: string,
  slug: string,
  render: unit => React.element,
};

let home = {
  title: "Home",
  slug: "home",
  render: () => "Use the navigation menu to select an example"->RR.s,
};

let examples: list(example) = {
  let modules: list(module Example) = [(module HelloWorld)];
  let examplesFromModules =
    modules->List.map(example => {
      let (module Ex) = example;
      {title: Ex.title, slug: getSlug(Ex.title), render: Ex.render};
    });
  [home, ...examplesFromModules];
};

[@react.component]
let make = () => {
  // let url = ReasonReactRouter.useUrl();

  let (example, setExample) = RR.useStateValue(home);

  <div className="h-screen flex flex-row">
    <div className="bg-blue-600 text-white py-4 px-6 mr-8">
      <div className="text-lg underline mb-4"> "Navigation"->RR.s </div>
      {examples
       ->List.mapWithIndex((i, example) =>
           <div
             key={i->string_of_int}
             className="cursor-pointer"
             onClick={_ => setExample(example)}>
             example.title->RR.s
           </div>
         )
       ->RR.list}
    </div>
    <div
      className="mt-4 grid gap-4"
      style={ReactDOMRe.Style.make(~gridTemplateRows="auto 1fr", ())}>
      <Title> example.title->RR.s </Title>
      {example.render()}
    </div>
  </div>;
};
