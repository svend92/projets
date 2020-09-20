import React from "react";
import './App.css';
import "./assets/vendor/bootstrap/css/bootstrap.min.css";
import "./assets/css/style.css";
import profilepic from "./assets/img/profile-img.jpg";

function transpose(a) {
  return Object.keys(a[0]).map(function(c) {
      return a.map(function(r) { return r[c]; });
  });
}

function Section2(props){
  const boxlist =  transpose([props.curstate.boxlist1, props.curstate.boxlist2]);
  const boxlist2 =  transpose([props.curstate.boxlist3, props.curstate.boxlist4]);

  const listItem1 = boxlist.map((boxlist) =>
  <li><i class="icofont-rounded-right"></i> <strong>{boxlist[0]}</strong> {boxlist[1]}</li>
);
  const listItem2 = boxlist2.map((boxlist2) =>
  <li><i class="icofont-rounded-right"></i> <strong>{boxlist2[0]}</strong> {boxlist2[1]}</li>
);
    return (
      <>
<section id="sec2">

      <div class="container">

        <div class="section-title">
          <h2>{props.curstate.profiletitle}</h2>
    <p>{props.curstate.profileintro}</p>
        </div>

        <div class="row">
          <div class="col-lg-4" data-aos="fade-right">
            <img src={profilepic} class="img-fluid" alt="" />
          </div>
          <div class="col-lg-8 pt-4 pt-lg-0 content" data-aos="fade-left">
            <h3>{props.curstate.boxtitle}</h3>
            <p class="font-italic">
              {props.curstate.boxtxt}
            </p>
            <div class="row">
              <div class="col-lg-6">
                <ul> {listItem1} </ul>
              </div>
              <div class="col-lg-6">
              <ul> {listItem2} </ul>
              </div>
            </div>
          </div>
        </div>

      </div>
   </section>
   </>
       );
    }

    export default Section2;