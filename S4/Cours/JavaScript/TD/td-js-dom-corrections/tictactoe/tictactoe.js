var coups = 0;
var termine = false;
var motifs = [ "X", "O" ];
var values = [ -1, 1 ];
var aqui = 0;

var tab = [ 0, 0, 0, 0, 0, 0, 0, 0, 0 ];
function $(id) {
	return window.document.getElementById(id);
}
function clic(pos) {
	if (!termine) {
		if ($(pos).innerHTML == "") {
			aqui += 1;
			coups += 1;
			$(pos).innerHTML = motifs[aqui % 2];
			motif = "O";
			tab[index(pos)] = values[aqui % 2];
			if (gagne(values[aqui % 2])) {
				$("msg_joueur").innerHTML = "Le joueur " + motifs[aqui % 2]
						+ " a gagné !";
				termine = true;
			} else if (coups == 9) {
				$("msg_joueur").innerHTML = "Partie nulle !";
				termine = true;
			} else
				$("msg_joueur").innerHTML = "C'est le tour du joueur "
						+ motifs[(aqui + 1) % 2];// + tab.toString();
		}
	}
}
function index(pos) {
	var i = parseInt(pos.substring(1, 2));
	var j = parseInt(pos.substring(2, 3));
	console.log(j);
	return 3 * i + j;
}
function gagne(joueur) {
	if (ligne(joueur) || colonne(joueur) || diagonale(joueur))
		return true;
	else
		return false;
}
function ligne(joueur) {
	for (i = 0; i < 3; ++i)
		if (tab[3 * i] + tab[3 * i + 1] + tab[3 * i + 2] == 3 * joueur)
			return true;
	return false;
}
function colonne(joueur) {
	for (i = 0; i < 3; ++i)
		if (tab[i] + tab[i + 3] + tab[i + 6] == 3 * joueur)
			return true;
	return false;
}
function diagonale(joueur) {
	if (tab[0] + tab[4] + tab[8] == 3 * joueur)
		return true;
	if (tab[2] + tab[4] + tab[6] == 3 * joueur)
		return true;
	return false;
}