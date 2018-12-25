open Prelude;

type page =
  | NotFound
  | Hello
  | Emojis
  | Component2;

let sidebarLinks = [|"Hello", "Emojis", "Component2"|];

type state = {currentPage: page};

type actions =
  | ChangePage(page);

let getPageFromUrl = url =>
  switch (url.RR.Router.path) {
  | []
  | ["hello"] => Hello
  | ["emojis"] => Emojis
  | ["component2"] => Component2
  | _ => NotFound
  };

let component = RR.reducerComponent(__MODULE__);

let make = _children => {
  ...component,
  initialState: () => {currentPage: Hello},
  didMount: ({send} as self) => {
    let changePage = url => send @@ ChangePage(url->getPageFromUrl);

    changePage(RR.Router.dangerouslyGetInitialUrl());
    let watcherID = RR.Router.watchUrl(changePage);
    self.onUnmount(() => RR.Router.unwatchUrl(watcherID));
  },
  reducer: (action, _state) =>
    switch (action) {
    | ChangePage(currentPage) => RR.Update({currentPage: currentPage})
    },
  render: ({state}) =>
    <div className="App h-screen flex flex-row">
      <div className="SideBar bg-blue text-white flex flex-col">
        <div className="pt-4 px-4 pb-4 border-b font-bold text-lg">
          "RR Examples"->s
        </div>
        {sidebarLinks
         ->Array.map(name => {
             let className =
               Cn.make(["cursor-pointer px-4 py-3 hover:bg-blue-dark"]);
             <div
               className
               key=name
               onClick={_ => RR.Router.push(name->String.lowercase)}>
               name->s
             </div>;
           })
         ->RR.array}
      </div>
      <div className="Content pt-6 pl-6">
        {switch (state.currentPage) {
         | NotFound =>
           <div className="NotFound">
             "The content you seek was not found"->s
           </div>
         | Hello => <Hello />
         | Emojis => <Emojis />
         | Component2 => <Component2 />
         }}
      </div>
    </div>,
};
