function calcul_carre() {
	var tab = [ 0 ];
	var str = "";
	for (i = 1; i < 11; i++) {
		tab[i] = i * i + tab[i - 1];
		str += "<p>" + i + "<sup>2</sup> = " + tab[i] + "</p>";
	}
	document.write(str);
	document.close(); // otherwise browser keeps "loading" document
}
