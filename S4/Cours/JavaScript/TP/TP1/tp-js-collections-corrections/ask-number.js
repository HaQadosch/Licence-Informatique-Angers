function askNumber() {
	var string, number;

	while (true) {
		string = prompt('Entrez un nombre entier positif');
		number = parseInt(string);

		if (!isNaN(number)) { // C'est bien un nombre
			return number;
		}
	}
}
console.log(askNumber());