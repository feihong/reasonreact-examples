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

/* https://discuss.ocaml.org/t/more-natural-preferred-way-to-shuffle-an-array/217/2 */
let knuthShuffle = a => {
  let n = a->Array.length;
  let a = a->Array.copy;
  for (i in n - 1 downto 1) {
    let k = Random.int(i + 1);
    let x = a->Array.getExn(k);
    a->Array.setExn(k, a->Array.getExn(i));
    a->Array.setExn(i, x);
  };
  a;
};

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

  render: _self => {
    let colors = knuthShuffle(colors);
    <div className="Hello">
      {Array.zip(chars, colors)
       ->Array.map(((ch, color)) =>
           <span key=ch className={"text-" ++ color} style={randomStyle()}>
             ch->s
           </span>
         )
       ->RR.array}
    </div>;
  },
};
