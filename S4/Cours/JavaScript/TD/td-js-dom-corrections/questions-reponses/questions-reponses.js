function $(id) {
	return window.document.getElementById(id);
}

var on = true;
var x, y;

function flip() {
	if (on == true) {
		$("bt").setAttribute("value", "Montrer la réponse");
		$("bt").setAttribute("style", "background-color:green;");
		x = Math.floor(Math.random() * 11);
		y = Math.floor(Math.random() * 11);
		$("reponse").innerHTML = "";
		$("question").innerHTML = "Combien font " + x + " fois " + y + " ? ";
		on = false;
	} else {
		$("bt").setAttribute("value", "Créer une question");
		$("bt").setAttribute("style", "background-color:salmon;");
		$("reponse").innerHTML = x * y;
		on = true;
	}
	return;
}