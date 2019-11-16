#pragma once
#include <string>
#include <vector>
#include "Horaire.hh"
class Message{
	public:
		//constructeur
		Message(std::string expe);
		//accesseur
		int getId() const {return id;}
		std::string getExpediteur() const{return expediteur;}
		std::string getDestinataire(int num){return destinataires[num];}
		//méthodes
		void ajoutDestinataire(std::string dest){destinataires.push_back(dest);}
		//virtual bool reunionDate(unsigned int jour,unsigned int mois)const{return false;} //vaux TRUE que dans les proposition & réponses
		//mise en commentaire car rends le test du main obsolète. On ne devrait pas l'instancier
	private:
		std::string expediteur;
		std::vector<std::string> destinataires;
		unsigned int id;
		static unsigned int compteur;
};
/*
class Proposition:public Message{
	public:
		//constructeur
		//Proposition(std::string expe);
		//accesseur
		void ajoutHoraire(Horaire h){horaires.push_back(h);}
		int getId();
		std::string getExpediteur();
		std::string getDestinataire(int num);
		//méthodes
		void ajoutDestinataire(std::string dest){destinataires.push_back(dest);}
		bool reunionDate(unsigned int jour,unsigned int mois) const override;

	private:
		std::vector<Horaire> horaires;
		std::string expediteur;
		std::vector<std::string> destinataires;
		unsigned int id;
		static unsigned int compteur;
};

*/

/*
class Reponse:public Message{
	public:
		//constructeur
		Reponse(std::string expe)=default;
		//accesseur
		void ajoutHoraire(Horaire h){horaires.push_back(h);}
		int getId();
		std::string getExpediteur();
		std::string getDestinataire(int num);
		//méthodes
		void ajoutDestinataire(std::string dest){destinataires.push_back(dest);}
		bool reunionDate(unsigned int jour,unsigned int mois) const override {return(horaire.jour==jour && horaire.mois==mois)};

	private:
		Horaire horaire;
		.std::string expediteur;
		std::vector<std::string> destinataires;
		unsigned int id;
		static unsigned int compteur;
};
*/
