#pragma once
#include <string>
#include <cstdlib>
#include <list>
#include "Element.hh"
#include "TaillePosition.hh"

/** \author BRINON Baptiste
 * Ceci n'est pas la correction du TP, mais une résolution possible de celui-ci
 */

class Carte{
	public:
		//constructeur
		Carte(Taille const & t):
			taille(t){};
		//accesseur
		/* push_back fait déjà une copie par valeur. Donc on peut placer par référencement en paramètre */
		void ajoutPersonnage(Personnage const & p){persos.push_back(p);}
		void ajoutObjet(Objet const & o){objs.push_back(o);}
		void ajoutObstacle(Obstacle const &o){obsts.push_back(o);}
		//méthodes
		void afficherPersos()const;
		bool croiseIntervale(Coordonnee const &x1, Coordonnee const &y1, Coordonnee const &x2, Coordonnee const &y2)const;

	private:
		Taille taille;
		std::list<Personnage> persos;
		std::list<Obstacle> obsts;
		std::list<ObjetRamassable> objs;
}
