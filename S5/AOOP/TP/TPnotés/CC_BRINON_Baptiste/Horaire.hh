#pragma once
#include <cstdlib>
#include <string>

class Horaire{
	public:
		//constructeur
		Horaire(int m,int j,int h):
			mois(m),jour(j),heure(h){}
		//accesseur
		int getMois(){return mois;}
		int getJour(){return jour;}
		int getHeure(){return heure;}
		//méthodes
		std::string toString();

	private:
		unsigned int mois,jour,heure;
};
