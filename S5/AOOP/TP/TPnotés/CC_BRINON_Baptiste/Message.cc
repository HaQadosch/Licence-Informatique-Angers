#include "Message.hh"

unsigned int Message::compteur(0);

Message::Message(std::string expe):
	expediteur(expe),id(++compteur){}


/*
bool Proposition::reunionDate(unsigned int jour,unsigned int mois)const override{
	for (auto h:horaires){
		if(horaires[i].getJour()==jour && horaires[i].getMois()==mois) return true;
	}
	return false;
}
*/
