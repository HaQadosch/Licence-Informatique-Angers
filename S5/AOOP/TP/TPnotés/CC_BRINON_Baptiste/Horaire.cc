#include "Horaire.hh"


std::string Horaire::toString(){
	return std::to_string(jour)+"/"+std::to_string(mois)+"-"+std::to_string(heure)+"h";
}
