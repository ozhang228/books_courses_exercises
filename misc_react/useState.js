/*
const [state, setState] = useState(initalValue);

Each react component is just a function. So how can it have state? Closures
*/

const React = (() => {
  let _states = [];
  let idx = 0;

  const useState = (initalValue) => {
    const _idx = idx
    const curr = _states[_idx] || initalValue;
    const setState = (newState) => {
      _states[_idx] = newState
    }
    idx += 1;
    return [curr, setState]
  }


  const render = (Component) => {
    idx = 0;
    const app = Component();
    app.render();
    return app;
  }
  return { render, useState }
})()


const Component = () => {
  const [count, setCount] = React.useState(0)
  const [text, setText] = React.useState("World")

  return {
    render: () => console.log(count, text),
    click: () => setCount(count + 1),
    type: (word) => setText(word)
  }
}

const app1 = React.render(Component);
app1.click();
app1.type("Hello React");

const app2 = React.render(Component);
app2.click();

const app3 = React.render(Component);



