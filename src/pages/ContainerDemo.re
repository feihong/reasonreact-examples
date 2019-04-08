open Prelude;

let component = RR.statelessComponent(__MODULE__);

let make = _children => {
  ...component,

  render: _self =>
    <div>
      <h1> "Container"->s </h1>
      <CoolContainer> "This is a container"->s </CoolContainer>
      <CoolContainer>
        <p> "This container has more content"->s </p>
        <p> {js|这个容器的内容更丰富一些|js}->s </p>
      </CoolContainer>
    </div>,
};
