module type Example = {
  let title: string;

  let render: unit => React.element;
};

module Title = {
  [@react.component]
  let make = (~children) => <h1 className="text-4xl"> children </h1>;
};

module Home = {
  let title = "Home";

  let render = () => "Use the navigation menu to select an example"->RR.s;
};

let examples: list(module Example) = [(module Home), (module HelloWorld)];

[@react.component]
let make = () => {
  let (example, setExample) =
    RR.useStateValue((module Home): (module Example));
  let (module Ex) = example;

  <div className="h-screen flex flex-row">
    <div className="bg-blue-600 text-white py-4 px-6 mr-8">
      <div className="text-lg underline mb-4"> "Navigation"->RR.s </div>
      {examples
       ->List.mapWithIndex((i, example) =>
           <div
             key={i->string_of_int}
             className="cursor-pointer"
             onClick={_ => setExample(example)}>
             {let (module Ex) = example;
              Ex.title->RR.s}
           </div>
         )
       ->RR.list}
    </div>
    <div
      className="mt-4 grid gap-4"
      style={ReactDOMRe.Style.make(~gridTemplateRows="auto 1fr", ())}>
      <Title> Ex.title->RR.s </Title>
      {Ex.render()}
    </div>
  </div>;
};
