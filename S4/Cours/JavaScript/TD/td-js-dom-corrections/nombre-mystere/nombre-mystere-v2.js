var nb_mystere = 1 + Math.floor(Math.random() * 30);

function test_nb_mystere() {
	var nb = document.getElementById('proposition').value;
	nb = parseInt(nb);
	var p = window.document.createElement("p");
	if (nb < nb_mystere)
		var node = window.document.createTextNode("C'est plus");
	else if (nb > nb_mystere)
		var node = window.document.createTextNode("C'est moins");
	else
		var node = window.document.createTextNode("Bravo!");

	p.appendChild(node);
	window.document.getElementById('resultat').appendChild(p);
}
