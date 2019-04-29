function sumMatrix(matrix) {
	var result = "", i, ii, c, cc;

	for (i = 0, c = matrix.length; i < c; i++) {

		for (ii = 0, cc = matrix[i].length; ii < cc; ii++) {
			result += matrix[i][ii] + " ";
		}

		if (matrix[i + 1]) { // S'il y a encore un sous-tableau à parcourir,
								// on ajoute un retour à la ligne
			result += "\n";
		}
	}
	return result;
}

var matrix = [ [ 1, 2, 3 ], [ 4, 5, 6 ], [ 7, 8, 9 ] ];
alert(sumMatrix(matrix));
