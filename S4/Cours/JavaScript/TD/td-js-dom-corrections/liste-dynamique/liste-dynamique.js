function ajouter() {
	var item = prompt("Entrer un élément à ajouter à la liste",
			"Elément par défaut");
	if (item != "" && item != null) {
		var div = window.document.getElementById("ici");
		if (div.hasChildNodes() == false) {
			var ul = window.document.createElement("ul");
			ul.setAttribute("id", "liste");
			div.appendChild(ul);
		} else
			var ul = window.document.getElementById("liste");
		var li = window.document.createElement("li");
		li.innerHTML = item;
		ul.appendChild(li);
	}
}
function supprimer() {
	var div = window.document.getElementById("ici");
	var ul = window.document.getElementById("liste");
	if (div.hasChildNodes())
		div.removeChild(ul);
}
