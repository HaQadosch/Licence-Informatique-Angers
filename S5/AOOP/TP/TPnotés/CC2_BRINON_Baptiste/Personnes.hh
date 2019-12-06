#pragma once
#include<string>
#include<vector>
#include "Enseignement.hh"

enum class Grade{ MCF, Professeur};

class Personne{
	public:
		Personne(std::string const & n):
			nom(n){}
		//getters & setters
		std::string getNom()const{return nom;}
	private:
		std::string nom;
};

class Etudiant:public Personne{
	public:
		Etudiant(std::string const & n,Formation const & f);
		//getters & setters
		unsigned int getId()const{return id;}
		Formation getForm()const{return form;}
	private:
		Formation form;
		static unsigned int id;
};

class Enseignant:public Personne{
	public:
		Enseignant(std::string const & n,Grade const & g):
			Personne(n),gr(g){}
		//getters & setters
		Grade getGrade()const{return gr;}
		void ajoutEnseignement(Enseignement e);
		Enseignement getEnseignement(unsigned int i){return enseigne[i];}
	private:
		Grade gr;
		std::vector<Enseignement> enseigne;
};

class Personnel:public Personne{
	public:
		Personnel(std::string const & n):
			Personne(n){}
		void ajoutFormation(Formation f);
	private:
		std::vector<Formation> listeForm;
};
