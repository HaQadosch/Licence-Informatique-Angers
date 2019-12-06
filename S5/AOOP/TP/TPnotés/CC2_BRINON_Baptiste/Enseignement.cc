#include "Enseignement.hh"
#include <iostream>

bool Formation::operator==(Formation const & f) const{
	if(f.getNom()==nom && f.getNiv()==niv) return true;
	return false;
}
/*
bool Formation::operator!=(Formation const & f) const{
	return (!(this==(f)));
}
*/
std::string Formation::tostring()const{
	std::string result;
	switch(niv){
		case(Niveau::L1):result="L1";break;
		case(Niveau::L2):result="L2";break;
		case(Niveau::L3):result="L3";break;
		case(Niveau::M1):result="M1";break;
		case(Niveau::M2):result="M2";break;
		default: result="erreur";break;
	}
	result=result+" "+nom;
	return result;
}

std::string Enseignement::tostring()const{
	std::string result;
	result=form.tostring()+" : ";
	switch(type){
		case(TypeEns::Cours):result+="Cours ";break;
		case(TypeEns::TD):result+="TD ";break;
		case(TypeEns::TP):result+="TP ";break;
		default: result="erreur";break;
	}
	result+=nom;
	return result;
}
