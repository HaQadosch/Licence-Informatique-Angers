// Création du tableau
function generateTable(cols, rows, bgColor, txtAlg) {
	// Q4
	var table = document.createElement('table');
	var numbers = new Array(rows * cols);
	numbers.fill(0);
	numbers = numbers.map(function(v) {
		return Math.round(100 * Math.random());
	});
	numbers.sort(function(a, b) {
		return a - b;
	});
	console.log(numbers);
	// Q5
	for (var r = 0; r < rows; r++) {
		var row = table.insertRow();
		for (var c = 0; c < cols; c++) {
			var cell = row.insertCell();
			cell.textContent = numbers[r * cols + c];
		}
	}
	table.style.backgroundColor = bgColor;
	table.style.textAlign = txtAlg;
	var myTab = document.querySelector('#myTab');
	myTab.innerHTML = "";
	myTab.appendChild(table);
	return table;
}

// Création de la liste
function generateList(table) {
	// Q6
	var olist = document.createElement('ul');
	var rows = table.querySelectorAll("tr");
	for (var r = 0; r < rows.length; r++) {
		var item = document.createElement('li');
		item.textContent = (Array.from(rows[r].querySelectorAll("td"))).reduce(
				function(acc, v) {
					return acc + parseInt(v.textContent);
				}, 0);
		olist.appendChild(item);
	}
	var myDiv = document.querySelector("#myList");
	myDiv.innerHTML = "";
	myDiv.appendChild(olist);
}

(function() { 
	var myGenTab = document.querySelector('#generateTable');
	myGenTab.addEventListener('click', function(e) {
		// Q1
		var cols = parseInt(document.querySelector('#cols').value);
		var rows = parseInt(document.querySelector('#rows').value);
		if (isNaN(cols) || cols < 1 || cols > 5) {
			alert("Entrez un nombre de colonnes entre 1 et 5");
		} else if (isNaN(rows) || rows < 1 || rows > 5) {
			alert("Entrez un nombre de lignes entre 1 et 5");
		} else {
			// Q2
			var bgColors = Array.from(document
					.getElementsByName('tab[bgColor]'));
			var bgColor = ((bgColors.filter(function f(b) {
				return b.checked ? true : false;
			}))[0]).value;
			// Q3
			var txtAlgs = document.querySelector('#txtAlg');
			var txtAlg = txtAlgs.options[txtAlgs.selectedIndex].value;
			// cf fonctions
			var table = generateTable(cols, rows, bgColor, txtAlg);
			generateList(table);
		}
	}, false);

	// Q7
	var myReset = document.querySelector('input[type="reset"]');
	myReset.addEventListener('click', function(e) {
		var myTab = document.querySelector('#myTab');
		myTab.innerHTML = "";
		var myList = document.querySelector("#myList");
		myList.innerHTML = "";
		e.preventDefault();
	});
})();
/**/