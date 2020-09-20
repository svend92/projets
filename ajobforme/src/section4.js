import React from "react";
import "./assets/vendor/bootstrap/css/bootstrap.min.css";
import "./assets/css/style.css";
import './App.css';
import { Icon, InlineIcon } from '@iconify/react';
import linkedinFilled from '@iconify/icons-ant-design/linkedin-filled';
import bxEnvelope from '@iconify/icons-bx/bx-envelope';


function Section4(props){
    return (
        <section id="sec4">
<div class="container">

  <div class="section-title">
    <h2>{props.curstate.cont1}</h2>
  </div>

  <div class="container">
  <a href="https://www.linkedin.com/in/svend-emil-therkildsen-07564324/" target="_blank"><Icon icon={linkedinFilled} width="5em" height="5em" /></a>
  <a href="mailto: stherkil@student.42.fr" target="_blank"><Icon icon={bxEnvelope} width="5em" height="5em" /></a>
  
</div>

</div>

</section>
);
}

export default Section4;