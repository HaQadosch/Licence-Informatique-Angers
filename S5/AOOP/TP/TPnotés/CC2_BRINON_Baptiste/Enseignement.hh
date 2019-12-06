#pragma once
#include<string>

enum class Niveau{
	L1,
	L2,
	L3,
	M1,
	M2
};
enum class TypeEns{Cours, TD, TP};

class Formation {
	public:
		Formation(Niveau const & level, std::string const & name):
			niv(level),nom(name){}
		//getters & setters
		std::string getNom() const{return nom;}
		Niveau getNiv() const{return niv;}

		bool operator==(Formation const & f) const;
		//bool operator!=(Formation const & f) const;
		std::string tostring()const;
	private:
		Niveau niv;
		std::string nom;
};

class Enseignement{
	public:
		Enseignement(Formation const & f, TypeEns const & t, std::string const & n):
			form(f),type(t),nom(n){}

		//getters & setters
		Formation getForm()const{return form;}
		TypeEns getType()const{return type;}
		std::string getNom()const{return nom;}

		//méthodes
		std::string tostring()const;
	private:
		Formation form;
		TypeEns type;
		std::string nom;
};
