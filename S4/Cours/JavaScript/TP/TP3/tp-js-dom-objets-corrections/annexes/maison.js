var départements = [ 49, 6, 75 ];
var situations = [ 'campagne', 'ville' ];
var extensions = {
	'garage' : 0.5,
	'piscine' : 1,
}

function Localisation(dpt, sit) {
	if (départements.includes(dpt)) {
		this.département = dpt;
	}
	if (situations.includes(sit)) {
		this.situation = sit;
	}
}

/*
// Question 1
var l6c = new Localisation(6, 'campagne');
console.log(l6c.toText());
// Département : 6
// Situation : campagne

// Question 2
var lDefaut = new Localisation();
console.log(lDefaut.toText());
// Département : 49
// Situation : campagne

// Question 3
var m75vgp = new Maison(new Localisation(75, 'ville'), [ 'garage', 'piscine' ]);
console.log(m75vgp.toText());
// Département : 75
// Situation : ville
// Extensions : garage, piscine
// Surcoût : 7

// Question 4
var mDefaut = new Maison();
console.log(mDefaut.toText());
// Département : 49
// Situation : campagne
// Extensions :
// Surcoût : 0

// Questions 5 & 6
var maisons = [];
for(var d=0; d<3; ++d) {
	let dpt = départements[d];
	for(var s=0; s<2; ++s) {
		let sit = situations[s];
		for(var e=0; e<4; ++e) {
			let exts = Object.entries(extensions).map(v => v[0]).filter(function(v,k) { return ((k+1) & e) != 0; });
			let maison = new Maison(new Localisation(dpt,sit),exts);
			// console.log(maison.toText());
			maisons.push(maison);
		}
	}
}
/**/
