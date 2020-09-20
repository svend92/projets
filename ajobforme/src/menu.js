import React from 'react';
import './App.css';
import "./assets/vendor/bootstrap/css/bootstrap.min.css";
import "./assets/css/style.css";
import { Icon, InlineIcon } from '@iconify/react';
import bxHomeAlt from '@iconify/icons-bx/bx-home-alt';
import bxEnvelope from '@iconify/icons-bx/bx-envelope';
import bxFileBlank from '@iconify/icons-bx/bx-file-blank';
import bxUser from '@iconify/icons-bx/bx-user';
import profilepic from "./assets/img/profile-img.jpg";


function Menu(props) {
	return (
		<>
		<button type="button" class="mobile-nav-toggle d-xl-none"><i class="icofont-navigation-menu"></i></button>
		<header id="header">
		  <div class="d-flex flex-column">
	  
			<div class="profile">
			  <img src={profilepic} alt="" class="img-fluid rounded-circle" />
			  <h1 class="text-light"><a href="#">Svend Emil Therkildsen</a></h1>
			  <div class="social-links mt-3 text-center">
                <div onClick={props.langSwitch}> <a class="google-plus"><Icon width="1em" height="1em" icon={props.curstate.flag} /> </a></div>
			  </div>
			</div>
	  
			<nav class="nav-menu">
			  <ul>
                <li><a href="#sec1"><Icon icon={bxHomeAlt} width="1.5em" height="1.5em" /> <span>{props.curstate.menu1}</span></a></li>
				<li><a href="#sec2"><Icon icon={bxUser} width="1.5em" height="1.5em"/> <span>{props.curstate.menu2}</span></a></li>
				<li><a href="#sec3"><Icon icon={bxFileBlank} width="1.5em" height="1.5em"/> <span>{props.curstate.menu3}</span></a></li>
                <li><a href="#sec4"><Icon icon={bxEnvelope} width="1.5em" height="1.5em"/> <span>{props.curstate.menu4}</span></a></li>
	  
			  </ul>
			</nav>
			<button type="button" class="mobile-nav-toggle d-xl-none"><i class="icofont-navigation-menu"></i></button>
	  
		  </div>
		</header>
		</>
		);
}

export default Menu;