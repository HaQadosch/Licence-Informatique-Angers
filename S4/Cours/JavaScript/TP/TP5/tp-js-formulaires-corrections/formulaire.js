///////// UTILITAIRES ///////////////////////////////////////////////////////////////////
// Masque les "tooltips"
function deactivateTooltips() {
	var tooltips = document.querySelectorAll('span.tooltip');
	for (var tooltip of tooltips) {
		tooltip.style.display = 'none';
	}
}

// Renvoie le "tooltip" associé à l'élément elt (ie. l'élément qui suit elt dans sa fratrie) 
// Renvoie false si le "tooltip" n'existe pas
function getTooltip(elt) {
	var tooltip = elt.nextElementSibling; // Element else null
	if (tooltip && tooltip.classList.contains('tooltip')) {
		return tooltip;
	} else {
		return false;
	}
}

// Fonction booléenne de validation et affichage :
// Si la condition "cond" est vraie : classe "correct" l'élément "elt", masque le "tooltip", et renvoie vrai
// Sinon : classe "incorrect" l'élément "elt", affiche le "tooltip", et renvoie faux
function validate(cond,elt,tooltip) {
	if (cond) {
		elt.className = 'correct';
		tooltip.style.display = 'none';
		return true;
	} else {
		elt.className = 'incorrect';
		tooltip.style.display = 'inline-block';
		return false;
	}
}

///////// ECOUTEURS ///////////////////////////////////////////////////////////////////
// Fonctions booléennes de vérification des champs du formulaire : 1 fonction par champ.
// Chaque fonction est une méthode de l'objet "check" et dénommée selon son champ, 
// e.g. check.gender est la fonction de vérification pour le champ de nom "gender"
var check = {};

check['gender'] = function() {
	var gender = document.querySelectorAll('input[name="person\[gender\]"]');
	return validate((gender[0].checked || gender[1].checked), gender[1], getTooltip(gender[1]));
};

check['lastName'] = function() {
	var field = document.querySelector('input[id="lastName"]');
	return validate((field.value.length >= 2), field, getTooltip(field));
};

check['firstName'] = function() {
	var field = document.querySelector('input[id="firstName"]');
	return validate((field.value.length >= 2), field, getTooltip(field));
};

check['age'] = function() {
	var field = document.querySelector('input[id="age"]');
	var ageValue = parseInt(field.value);
	return validate((!isNaN(ageValue) && ageValue >= 5 && ageValue <= 140), field, getTooltip(field));
};

check['login'] = function() {
	var field = document.querySelector('input[id="login"]');
	return validate((field.value.length >= 4), field, getTooltip(field));
};

check['pwd1'] = function() {
	var field = document.querySelector('input[id="pwd1"]');
	return validate((field.value.length >= 6), field, getTooltip(field));
};

check['pwd2'] = function() {
	var field = document.querySelector('input[id="pwd2"]');
	var pwd1 = document.querySelector('input[id="pwd1"]');
	return validate((pwd1.value == field.value && field.value != ''), field, getTooltip(field));
};

check['country'] = function() {
	var field = document.querySelector('select[id="country"]');
	return validate((field.options[field.selectedIndex].value != 'none'), field, getTooltip(field));
};

///////// GESTIONNAIRES D'EVENEMENT///////////////////////////////////////////////////////////////
(function() { // IIFE pour éviter les variables globales.
	var myForm = document.querySelector('#myForm');
	var texts = document.querySelectorAll('input[type="text"], input[type="password"]');
	var radios = document.querySelectorAll('input[type="radio"]');
	var textradios = document.querySelectorAll('input[type="text"], input[type="password"], input[type="radio"]');
	var select = document.querySelector('select');

	for (var text of texts) {
		text.addEventListener('keyup', function(e) {check[e.target.id]();}, false);
	}

	for (var radio of radios) {
		radio.addEventListener('click', function(e) {check['gender']();}, false);
	}

	select.addEventListener('mouseup', function(e) {console.log(e);check['country']();}, false);

	myForm.addEventListener('submit', function(e) {
		var result = true;
		for (var i in check) {
			result = check[i]() && result;
		}

		if (result) {
			alert('Le formulaire est bien rempli.');
		} else {
			e.preventDefault();
		}
	}, false);

	myForm.addEventListener('reset', function() {
		for (var textradio of textradios) {
			textradio.className = '';
		}

		deactivateTooltips();
	}, false);
})();

///////// DESACTIVATION PAR DEFAUT ///////////////////////////////////////////////////////////////
deactivateTooltips();
