#include <fstream>

using Sommet=unsigned int;

class Graphe{
	public:
		ajoutSommet(Sommet s);
		Sauvegarder()
		Charger()
	private:
		std::vector<std::vector<Sommet>> matAdjac;
}

class GrapheOriente:public Graphe{
	public:
		ajoutArc(Sommet s1, Sommet s2, int val);
}

class GrapheNonOriente:public Graphe{
	public:
		ajoutArete(Sommet s1,Sommet s2,int val);

}
