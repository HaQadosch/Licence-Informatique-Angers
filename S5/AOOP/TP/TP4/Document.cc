#include "Document.hh"

std::ostream & operator<<(std::ostream & os, Document const & d){
	d.sortieFlox(os);
	return os;
}

void Document::sortieFlux(std::ostream & os) const{
	os << typeDoc() <<" ";
	os << titre <<" "<< auteur;
	os <<(empruntable() ? "Empruntable" : "NonEmpruntable");
	os << "Coût: "<< prix();
}

void Video::sortieFlux(std::ostream & os) const{
	Document::sortieFlux(os);
	swotch(type){
		case typeVideo::DVD: os<<"DVD"; break;
		case typeVideo::BR: os<<"BR"; break;
		case typeVideo::BR3D: os<<"BR3D"; break;
	}
}

void DocEcrit::sortieFlux(std::ostream & os) const{
	os << " " << pages <<"p.";
}

void Periodique::sortieFlux(std::ostream & os) const{
	DocEcrit::sortieFlux(os);
	os<<" num."<<numero;
}
bool Video::empruntable() const{
	return true;
}
bool Periodique::empruntable()const{
	return true;
}

bool Livre::empruntable() const{
	return empruntable;
}

float Video::prix()const{
	return 70;
}

float DocEcrit::prix()const{
	return 0.5*pages;
}

Document * Video::clone() const override{
	return new Video(*this);
}

Document * Livre::clone() const override{
	return new Livre(*this)
}

Document * Periodique::clone()const override{
	return new Periodique(*this);
}
