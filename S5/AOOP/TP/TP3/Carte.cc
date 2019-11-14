#include "Carte.hh"
/** \author BRINON Baptiste
 * Ceci n'est pas la correction du TP, mais une résolution possible de celui-ci
 */


void Carte::afficherPersos()const{
	std::cout<<" la carte est de taille "<<taille.toString()<<std::endl;
	if(!persos.empty()){
		for (auto const & i : per){
			std::cout <<i.accesPosition().toString()<<i.accesTaille().toString()<<std::endl;
		}
	}
}

//test effectué avec des intervalles de type inclus-exclus ( [x,y[)
bool Carte::croiseIntervale(Coordonnee const &debx1, Coordonnee const &finx1, Coordonnee const &debx2, Coordonnee const &finx2)const{
	//ils se croisent s'ils ne se croisent pas pas.
	/*if(debx1<debx2&&finx1>debx2) return true;
	if(debx1>=debx2&&debx1<finx2) return true;
	return false; ->code long */
	/*meilleur :*/
	if(finx1<=debx2 || finx2<=debx1) return false;
	return true;
}
