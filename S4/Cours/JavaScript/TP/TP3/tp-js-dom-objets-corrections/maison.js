var départements = [ 49, 6, 75 ];
var situations = [ 'campagne', 'ville' ];
var extensions = {
	'garage' : 0.5,
	'piscine' : 1,
};

function Localisation(dpt, sit) {
	if (départements.includes(dpt)) {
		this.département = dpt;
	}
	if (situations.includes(sit)) {
		this.situation = sit;
	}
	// Q1
	// 0.5 pt
	this.toText = function() {
		return "Département : " + this.département + "\n" + "Situation : "
				+ this.situation;
	}
}

// Q1 - résultat
var l6c = new Localisation(6, 'campagne');
console.log(l6c.toText());
// Département : 6
// Situation : campagne

// Q2
Localisation.prototype.département = 49;
Localisation.prototype.situation = 'campagne';
// Q2 - résultat
var lDefaut = new Localisation();
console.log(lDefaut.toText());
// Département : 49
// Situation : campagne

function conformes(exts) {
	return exts.every(function(o) {
		return o in extensions;
	})
}

function Maison(loc, exts) {
	// Q3-1
	if (loc instanceof Localisation) {
		this.localisation = loc;
	}
	// Q3-2
	if ((exts instanceof Array) && conformes(exts)) {
		this.extensions = exts;
	}
	// Q3-3
	this.surcout = function() {
		var surcoutDepartement = départements
				.indexOf(this.localisation.département) * 2;
		var surcoutSituation = situations.indexOf(this.localisation.situation) * 1.5;
		var surcoutExtensions = this.extensions.reduce(function(a, v) {
			return a + extensions[v];
		}, 0);
		return (surcoutDepartement + surcoutSituation + surcoutExtensions);
	}
	// Q3-4
	this.toText = function() {
		return this.localisation.toText() + "\nExtensions : "
				+ this.extensions.join(", ") + '\nSurcoût : ' + this.surcout();
	}
}

// Q3 - résultat
var m75vgp = new Maison(new Localisation(75, 'ville'), [ 'garage', 'piscine' ]);
console.log(m75vgp.toText());
// Département : 75
// Situation : ville
// Extensions : garage, piscine
// Surcoût : 7

// Q4
Maison.prototype.localisation = new Localisation();
Maison.prototype.extensions = [];
// Q4 - résultat
var mDefaut = new Maison();
console.log(mDefaut.toText());
// Département : 49
// Situation : campagne
// Extensions :
//Surcoût : 0

// Pour Q5
var maisons = [];
for(var d=0; d<3; ++d) {
	let dpt = départements[d];
	for(var s=0; s<2; ++s) {
		let sit = situations[s];
		for(var e=0; e<4; ++e) {
			let exts = Object.entries(extensions).map(v => v[0]).filter(function(v,k) { return ((k+1) & e) != 0; });
			let maison = new Maison(new Localisation(dpt,sit),exts);
			console.log(maison.toText());
			maisons.push(maison);
		}
	}
}

// Q5
var table =	document.querySelector('#myTab > table');
for (var r = 0; r < 24; r++) {
	let row = table.rows[r+1];
	row.lastChild.textContent = maisons[r].surcout();
}

// Q6a
function colorerTableau(min,max) {
	var table =	document.querySelector('#myTab > table');
	for (var r = 0; r < 24; r++) {
		let row = table.rows[r+1];
		if(maisons[r].surcout()>=min && maisons[r].surcout()<=max) {
			row.style.backgroundColor = 'green';
		} else {
			row.style.backgroundColor = 'white';						
		}
	}
}

// Q6b
(function() {
	var minMax = document.querySelectorAll('.minMax');
	for(var input of minMax) {
		input.addEventListener('change', function(e) {
			var min = parseFloat(document.querySelector('#min').value);
			var max = parseFloat(document.querySelector('#max').value);
			if (!isNaN(min) && min >= 0 && min <= 7 && !isNaN(max) && max >= 0 && max <= 7) {
				// Q7
				// 1.5 pt
				while(min>max) {
						var x = parseFloat(prompt("Le surcoût minimum excède le surcoût maximum\nModifiez la valeur " + e.target.id + "."));
						if(e.target.id=="min") {
							document.querySelector('#min').value = min = x;
						} else {
							document.querySelector('#max').value = max = x;							
						}
				} // fin Q7
				colorerTableau(min,max);
			}
		},false);
	}
})();
