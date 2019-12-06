#include "Calendrier.hh"
#include <sstream>
std::string tostring(jourdelasemaine const & j){
	switch(j){
		case(0):return "lundi";break;
		case(1):return "mardi";break;
		case(2):return "mercredi";break;
		case(3):return "jeudi";break;
		case(4):return "vendredi";break;
		case(5):return "samedi";break;
		case(6):return "dimanche";break;
		default:return "erreur";break;
	}
}

bool estAvant(jourdelasemaine const & j1, jourdelasemaine const & j2){
	return j1<j2;
}

Horaire::Horaire(unsigned int const & hr,unsigned int const & min){
	if(hr<24 && min<60){
		h=hr;
		m=min;
	}
}
std::string Horaire::tostring(){
	std::stringstream minute;
	std::stringstream heure;
	minute<<m;
	heure<<h;
	return(heure.str()+":"+minute.str());
}
