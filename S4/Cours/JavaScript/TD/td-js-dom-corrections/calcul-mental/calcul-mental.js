var on = true;
function $(id) {
	return window.document.getElementById(id);
}

function flip() {
	if (on == true) {
		$("42").style.visibility = "hidden";
		/*
		 * style.display="none" similar but element looses original position
		 * document.getElementById("42").style.display="none";
		 */
		$("bt").setAttribute("value", "Cliquer pour afficher la réponse");
		$("bt").setAttribute("style", "background-color:green;");
		on = false;
	} else {
		$("42").style.visibility = "visible";
		/*
		 * style.display="initial" similar but element looses original position
		 * document.getElementById("42").style.display="initial";
		 */
		$("bt").setAttribute("value", "Cliquer pour cacher la réponse");
		$("bt").setAttribute("style", "background-color:salmon;");
		on = true;
	}
	return;
}
