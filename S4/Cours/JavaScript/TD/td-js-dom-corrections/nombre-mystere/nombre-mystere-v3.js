var nb_mystere = 1 + Math.floor(Math.random() * 30);

function test_nb_mystere() {
	var nb = document.getElementById('proposition').value;
	nb = parseInt(nb);

	if (isNaN(nb))
		alert("Veuillez saisir un nombre");
	else if ((nb < 1) || (nb > 30))
		alert("Veuillez saisir un nombre entre 1 et 30");
	else {
		if (nb < nb_mystere)
			var node = window.document.createTextNode("C'est plus");
		else if (nb > nb_mystere)
			var node = window.document.createTextNode("C'est moins");
		else if (nb == nb_mystere)
			var node = window.document.createTextNode("Bravo!");

		var p = window.document.createElement("p");
		p.appendChild(node);
		window.document.getElementById('resultat').appendChild(p);
	}
}