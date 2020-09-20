import React from "react";
import ReactDOM from "react-dom";
import './App.css';
import contentData from './contentData.js';
import Menu from './menu.js';
import Section1 from './section1.js';
import Section2 from './section2.js';
import Section3 from './section3.js';
import Section4 from './section4.js';

class App extends React.Component {
  state = contentData;
  curstate = this.state.fr;

  langSwitch = () => {
    this.curstate = this.curstate.id ? this.state.fr : this.state.en;
    this.setState(this.curstate);
  };

  render()
  {
    return (
      <>
      <Menu curstate={this.curstate} langSwitch={this.langSwitch} profilepic/>
      <main id="main">
     <Section1 curstate={this.curstate}/>
     <Section2 curstate={this.curstate} profilepic/>
     <Section3 curstate={this.curstate}/>
     <Section4 curstate={this.curstate}/>
     </main>
  </>
    )
  }
}

const rootElement = document.getElementById("root");
ReactDOM.render(<App />, rootElement);

export default App; 