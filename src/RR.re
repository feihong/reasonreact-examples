include React;

let s = string;

let list = lst => lst->List.toArray->array;

let useStateValue = initial => {
  React.useReducer((_ignored, newState) => newState, initial);
};

let makeStyle = ReactDOMRe.Style.make;
