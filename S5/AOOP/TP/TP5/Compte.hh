#pragma once
#include "proprietaire.hh"

class Compte{
	public:
			Compte(std::shared_ptr<proprietaire> prop, float montant);
			void verser (float m);
			void retirer(float m);
			void virerVers(Compte & c,float f);
	private:
			unsigned int numero;
			std::shared_ptr<proprietaire> prop;
			float montant;
			static unsigned int compteur;
};
