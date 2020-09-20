import React from "react";
import "./assets/vendor/bootstrap/css/bootstrap.min.css";
import "./assets/css/style.css";
import './App.css';
import { Icon, InlineIcon } from '@iconify/react';
import filePdfFilled from '@iconify/icons-ant-design/file-pdf-filled';
import CV from './Svend-CV-sep20.pdf';
import githubFilled from '@iconify/icons-ant-design/github-filled';

function Section3(props){
    return (
        <section id="sec3">
<div class="container">

  <div class="section-title">
    <h2>{props.curstate.cvtitle}</h2>
  </div>
  <a href={CV} target="_blank"><Icon icon={filePdfFilled} width="5em" height="5em" /></a>

  <a href="https://github.com/svend92/projets" target="_blank"><Icon icon={githubFilled} width="5em" height="5em" /></a>


</div>

</section>
);
}

export default Section3;