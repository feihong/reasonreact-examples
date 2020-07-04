[@react.component]
let make = (~onClick, ~children) =>
  <button
    onClick
    className="bg-blue-500 hover:bg-blue-700 text-white font-bold py-2 px-4 rounded">
    children
  </button>;
