[%bs.raw {|require('./Index.pcss')|}];

Random.self_init();

ReactDOMRe.renderToElementWithId(<App />, "index");

/* Sets up hot module replacement using Parcel */
[%bs.raw {|(module.hot) ? module.hot.accept() : null|}];
