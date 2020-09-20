import React from "react";
import "./assets/vendor/bootstrap/css/bootstrap.min.css";
import "./assets/css/style.css";
import './App.css';

function Section1(props){
    return (
        <section id="sec1">
<div class="container">

  <div class="section-title">
    <h2>{props.curstate.videotxt}</h2>
    <div class="embed-responsive embed-responsive-21by9">
        <iframe class="embed-responsive-item" src={props.curstate.video}></iframe>
        </div>
  </div>

  <div class="container">

  
</div>

        </div>

</section>
);
}

export default Section1;