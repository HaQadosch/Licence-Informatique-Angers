#pragma once
#include <cstdlib>
#include <string>
#include <cstdio>
#include <iostream>

enum jourdelasemaine{
	lundi,
	mardi,
	mercredi,
	jeudi,
	vendredi,
	samedi,
	dimanche
};

bool estAvant(jourdelasemaine const & j1, jourdelasemaine const & j2);
std::string tostring(jourdelasemaine const & j);

class Horaire{
	public:
		Horaire(unsigned int const & h,unsigned int const & m);
		//getters & setters
		unsigned int getH(){return h;}
		unsigned int getM(){return m;}
		//methodes
		std::string tostring();		
	private:
		unsigned int h;
		unsigned int m;
};
