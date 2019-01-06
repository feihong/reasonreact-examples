open Prelude;

let component = RR.statelessComponent(__MODULE__);

let make = _children => {
  ...component,
  render: _self =>
    <div className="Scratch">
      <h1 className="mb-4"> "Scratch"->s </h1>
      <h2 className="mb-4"> "ValueBox"->s </h2>
      <ValueBox label="int" value=677 />
      <ValueBox label="float" value=123.567 />
      <ValueBox label="array" value=[|1, 2, 3|] />
      <ValueBox label="list" value=[1, 2, 3] />
      <ValueBox label="object" value={"apple": 1, "banana": 2} />
    </div>,
};
