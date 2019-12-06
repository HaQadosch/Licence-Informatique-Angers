#include "NumEpisode.hh"

std::string NumEpisode::tostring(){
	return "S"+std::to_string(numSaison)+"E"+std::to_string(numEpi);
}

bool NumEpisode::estAvant(NumEpisode epi){
	if(numSaison<epi.getSaison()) return true;
	if (numEpi<epi.getEpisode()) return true;
	return false;
}
