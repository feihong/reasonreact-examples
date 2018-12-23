open Prelude;

let chars: array(string) = [%bs.raw {|[..."你好世界！"]|}];

let colors = [|
  "blue",
  "red",
  "green",
  "purple",
  /* "yellow", */
  "orange",
  "indigo",
|];

let randomStyle = () => {
  let size = Random.int(4) + 1;
  makeStyle(~fontSize=size->string_of_int ++ "rem", ());
};

let randomClassName = () => {
  let index = Random.int(Array.length(colors));
  let color = colors->Array.get(index)->Option.getWithDefault("black");
  "text-" ++ color;
};

let component = RR.statelessComponent(__MODULE__);

let make = _children => {
  ...component,

  render: _self =>
    <div className="Hello">
      {chars
       ->Array.map(ch =>
           <span className={randomClassName()} style={randomStyle()} key=ch>
             ch->s
           </span>
         )
       ->RR.array}
    </div>,
};
