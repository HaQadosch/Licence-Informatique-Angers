#include "Pieces.hh"
#include <algorithm>
#include <sstream>

std::ostream & operator<<(std::ostream & os, Position const & p) {
	os << "("<<p.getX()<<"."<<p.getY()<<")";
	return os;
}

/////////////////////////////////////////////////////////////////////////////
char Pion::symbole() const{
	return 'P';
}
char Dame::symbole() const{
	return 'D';
}
char Roi::symbole() const{
	return 'R';
}
char Cavalier::symbole() const{
	return 'C';
}
int Pion::valeur() const{
	return 1;
}
int Cavalier::valeur() const{
	return 3;
}
int Dame::valeur() const{
	return 9;
}
int Roi::valeur() const{
	return 20;
}

std::vector<Position> Pion::deplacementsPossibles() const{
	std::vector<Position> res;
	auto p(getPos());
	p.setY(p.getY()+((getCoul()==Couleurs::noir)? 1: -1));
	//avant d'ajouter la position, on verifie que la piece n'est pas hors de l'echiquier
	if(p.estValide())
		res.push_back(p);
	return res;
}

std::vector<Position> Cavalier::deplacementsPossibles() const{
	std::vector<Position> res;
	Position posActuelle(getPos());
	//déplacement du cavalier en "2cases puis 1"
	for (coord a : {-2,2})
		for (coord b : {-1, 1}){
			//premier cas 2-1
			Position p(posActuelle.getX()+a,posActuelle.getY()+b);
			if(p.estValide()) res.push_back(p);	//avant d'ajouter la position, on verifie que la piece n'est pas hors de l'echiquier
			//deuxieme cas 2-1
			Position p(posActuelle.getX()+b,posActuelle.getY()+a);
			if(p.estValide()) res.push_back(p);	//avant d'ajouter la position, on verifie que la piece n'est pas hors de l'echiquier
		}

	return res;
}

std::vector<Position> Dame::deplacementsPossibles() const{
	std::vector<Position> res;
	return res;
}

std::vector<Position> Roi::deplacementsPossibles() const{
	std::vector<Position> res;
	Position posActuelle(getPost());
	for(coord x=-1; x<=1;++x)
		for(coord y=-1; y<=1; ++y){
			if(x!=0 || y!=0) // si la piece n'est pas immobile
				Position p(posActuelle.getX()+x,posActuelle.getY()+y);
				//avant d'ajouter la position, on verifie que la piece n'est pas hors de l'echiquier
				if(p.estValide())
					res.push_back(p);
		}
	return res;
}

std::string Piece::toString() const {
	/* return symbole()+((coul==couleur::noir)? "N" : "B")+Position.getX()+Position.getY();
		problème car "N" et "B" sont des chaines de c aractères litterales. pas std::string mais char*.
		Comme symbole() est un char, le + entre symbole et couleur effectue une addition et non une concaténation.
		on ajoute donc un string vide au début pour la conversion en string & donc effectuer des concaténations
	*/

	return std::string()+symbole()+((coul==Couleur::noir)? "N" : "B")+std::to_string(pos.getX())+std::to_string(pos.getY());

	//autre méthode :
	std::ostringstream os;
	os << symbole();
	if(coul==Couleur::noir)
		os<<"N";
	else
		os<<"B";
	os<<std::to_string(pos.getX())<<std::to_string(pos.getY());
	return os.str();
}


bool Piece::accepterPosition(Position const &p)const{
	auto dp=deplacementsPossibles();
	return (std::find(dp.begin(),dp.end(), p)!= dp.end());

}
/*
bool Piece::deplacer(){

}
*/
