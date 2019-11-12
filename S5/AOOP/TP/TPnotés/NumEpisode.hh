#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>

class NumEpisode{

	public:
	//constructeur
		NumEpisode(unsigned int sais,unsigned int epis):
			numSaison(sais),numEpi(epis){};

	//accesseur
	unsigned int getSaison(){return numSaison;}
	unsigned int getEpisode(){return numEpi;}

	//méthodes
	std::string tostring();
	bool estAvant(NumEpisode epi);

	private:
		unsigned int numSaison,numEpi;
};
