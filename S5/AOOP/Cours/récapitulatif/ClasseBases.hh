//declaration dans le
class Classe{
  public:

    /*méthodes*/
	int stable(int truc)const; /* la méthode étant constante, elle est particuliere:
		- elle ne peut pas modifier les attributs de la classe.
		- elle ne peut pas appeler une méthode qui n'est pas constante
		- peut être appelée sur un objet constant ( contrairement à une méthode non-const)
	on doit déclarer une méthode const si elle ne modifie pas l'objet
	*/

	static bool comparaison(Classe const & c1, Classe const & c2)const; /* méthode de classe et non d'instance
	elle ne peut pas être appellée sur this, ni directement
	elle peut cependant modifier les variables de classe directement.
	*/

    /*constructeurs*/
    void Classe() =default; // constructeur à vide, un peu inutile. constructeur par défaut
	void Classe (type const & var){this.var=var; ptr=nullptr;} // constructeur basique: declare PUIS initialise
	void Classe (type const & var):
		var(var),ptr(nullptr),sharedVar++{} // constructeur par liste d'initialisation. Initialisation à la construction
	void Classe(Class const & c ) =default; //constructeur par recopie par défaut
	void Classe (Classe const & c); //constructeur par recopie
	void Classe (Classe const & c):
		var(c.var); // constructeur par recopie en liste d'initialisation
	void Classe(Classe const & c) =delete; // rends le constructeur par copie par défaut inutilisable. Utile quand on veut interdire cette fonction

	/*destructeur*/
	~Classe() =default; // si utilisation d'un constructeur par recopie par défaut
	~Classe(){delete ptr}; // détruit de base le contenu, mais pas les pointeurs pointant dessus
	// il faut donc le faire manuellement

    /*setters & getters*/
    type getVar() const {return Var;}
    void setVar(type var){this.var=var};

	/*operateurs*/
	//redefinition via le mot operator suivi de l'operateur ( ==,=,>,>>,<<,<,+...)
	// /!\ operateurs << et >> sont spéciaux, et sont signés hors de la classe
	//à l'appel, l'operateur de l'objet gauche est appelé, et prends l'objet droit en paramètre(v1=v2 -> v1.=(v2))
	Classe & operator=(Classe const & c);


  private:
    /*variables*/
	static type sharedVar; // attribut de de classe, partagé entre tous les membres de la classe
    type var; // attribut d'instance ( nouvelle valeur à chaque création)
	typePtr * ptr;
};

//redefinition des operateurs >> et <<
std::ostream & operator <<(std::ostream & os, Classe const & c);
std::istream & operator >>(std::istream & os, Classe & c);
