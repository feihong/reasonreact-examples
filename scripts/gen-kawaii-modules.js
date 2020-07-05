const names = `
Backpack
Browser
Cat
Chocolate
CreditCard
File
Ghost
IceCream
Mug
Planet
SpeechBubble
`
  .trim()
  .split("\n")
  .map(
    (name) =>
      `module ${name} = {
  [@bs.module "react-kawaii"] [@react.component]
  external internal:
    (~size: int=?, ~color: string=?, ~mood: string=?) => React.element =
    "${name}";

  let make = internal;
  let makeProps = (~mood=?) =>
    internalProps(
      ~mood=?{
        mood->Option.map(moodToJs);
      },
    );
  };`
  );

console.log(names.join("\n\n"));
