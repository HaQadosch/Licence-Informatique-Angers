#include<Proprietaire.hh>

std::string Societe::nom() const {
	return nom;
}
std::string PersoPhysique::nom() const {
	return nom;
}
std::string Couple::nom() const {
	return p1->nom()+" "+p2->nom();
}


type Societe::typeProg() const {
	return type::societe;
}
type Couple::typeProg() const {
	return type::Couple;
}
type PersPhysique::typeProg() const {
	return type::PersPhysique;
}


std::string const & Couple::adresse() const{
	return p1->adresse();
}

std::string const & Societe::adresse() const{
	return adresse();
}

std::string const & PersPhysique::adresse() const{
	return adresse();
}

std::string Proprietaire::etiquetteExpedition() const{
	return nom()+" "+adresse();
}

std::ostream & operator<<(std::ostream &os, Proprietaire const &p){
	p.sortieFlux(os);
	return os;
}

virtual void Proprietaire::sortieFlux(std::ostream & os) const{
	os<<nom()<<std::endl;
	os<<adresse()<<std::endl;
}
virtual void Couple::sortieFlux(std::ostream & os) const{
	os<< "Couple";
	Proprietaire::sortieFlux(os);
}
virtual void Societe::sortieFlux(std::ostream & os) const{
	os<< "Societe";
	Proprietaire::sortieFlux(os);
	os<<"Proprietaire :";
	os<<(*proprio)<<std::endl;
}
virtual void PersPhysique::sortieFlux(std::ostream & os) const{
	os<< "Personne";
	Proprietaire::sortieFlux(os);
	os<<naissance<<std::endl;
}
