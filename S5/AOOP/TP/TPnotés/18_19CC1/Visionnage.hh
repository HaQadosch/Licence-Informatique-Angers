#pragma once
#include <string>
#include <cstdlib>
#include "NumEpisode.hh"

class Visionnage{
	public:
		//constructeur
		Visionnage()=default;
		//accesseur
		std::string getNom(){return nom;}
		unsigned int getDate(){return date;}
		//méthodes
		virtual std::string typeVisionnage() const =0;

	private:
		unsigned int date;
		std::string nom;
};

class Film:public Visionnage{
	public:
		//constructeur
		Film(std::string name,unsigned int when,std::string who):
			date(when),nom(name),realis(who){};
		//accesseur
		std::string getNom(){return Visionnage::getNom();}
		unsigned int getDate(){return Visionnage::getDate();}
		std::string getRealis(){return realis;}
		//méthodes
		std::string typeVisionnage() const override {return "Film";}

	private:
		unsigned int date;
		std::string nom,realis;

};
class Serie:public Visionnage{
	public:
		//constructeur
		Serie(std::string name,unsigned int when,NumEpisode epis):
			date(when),nom(name),numEpisode(epis){};
		//accesseur
		std::string getNom(){return Visionnage::getNom();}
		unsigned int getDate(){return Visionnage::getDate();}
		std::string getNumEpisode(){return numEpisode.tostring();}
		//méthodes
		std::string typeVisionnage() const override {return "Serie";}

	private:
		unsigned int date;
		std::string nom;
		NumEpisode numEpisode;

};

/*
class Saga:public Film{
	public:
		//constructeur
		Saga(std::string name,unsigned int when,std::string who):
			date(when),nom(name),realis(who){};
		//accesseur
		std::string getNom(){return Visionnage::getNom();}
		unsigned int getDate(){return Visionnage::getDate();}
		std::string getRealis(){return realis;}
		//méthodes
		std::string typeVisionnage() const override {return "Film";}

	private:
		unsigned int date;
		std::string nom,realis;

};
*/
