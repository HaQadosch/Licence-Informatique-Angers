function $(id) {
	return window.document.getElementById(id);
}
var Semaine = [ 'Dimanche', 'Lundi', 'Mardi', 'Mercredi', 'Jeudi', 'Vendredi',
		'Samedi' ];
function displayDate() {
	date = new Date();
	$("postit").innerHTML = Semaine[date.getDay()] + "<br/>" + date.getHours()
			+ ":" + date.getMinutes() + ":" + date.getSeconds();
	var t = setTimeout(displayDate, 500); // 500 milliseconds
	return;
}

