let title = "Hello World";

let colors = [|
  "blue",
  "red",
  "green",
  "purple",
  "yellow",
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

module RandomHanzi = {
  [@bs.val] external fromCodePoint: int => string = "String.fromCodePoint";

  let randomInt = (min, max) => Random.int(max - min + 1) + min;

  let getCharFromRange = (min, max) => randomInt(min, max)->fromCodePoint;

  let getRandomHanzi = n =>
    Array.makeBy(n, _ => getCharFromRange(0x4e00, 0x9fff));

  let randomStyle = () => {
    let size = Random.int(4) + 1;
    ReactDOMRe.Style.make(~fontSize=size->string_of_int ++ "rem", ());
  };

  [@react.component]
  let make = () => {
    let (chars, setChars) = RR.useStateValue(getRandomHanzi(5));

    let colors = knuthShuffle(colors);
    <div>
      <Button onClick={_ => setChars(getRandomHanzi(5))}>
        "Refresh"->RR.s
      </Button>
      <div>
        {Array.zip(chars, colors)
         ->Array.map(((ch, color)) =>
             <span
               key=ch
               className={"text-" ++ color ++ "-500"}
               style={randomStyle()}>
               ch->RR.s
             </span>
           )
         ->RR.array}
      </div>
    </div>;
  };
};

let render = () => <div> {js|你好世界！|js}->RR.s <RandomHanzi /> </div>;
