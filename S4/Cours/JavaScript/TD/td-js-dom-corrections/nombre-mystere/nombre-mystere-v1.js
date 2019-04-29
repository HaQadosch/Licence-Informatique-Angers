var nb_mystere = 1 + Math.floor(Math.random() * 30);

function test_nb_mystere() {
	var nb = document.getElementById('proposition').value;
	nb = parseInt(nb);
	if (nb < nb_mystere)
		alert("C'est plus");
	else if (nb > nb_mystere)
		alert("C'est moins");
	else
		alert("Bravo!");
}
