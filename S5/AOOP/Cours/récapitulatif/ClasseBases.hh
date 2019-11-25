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

    /*constructeurs*/
    void Classe() =default; // constructeur à vide, un peu inutile. constructeur par défaut
	void Classe (type const & var){this.var=var; ptr=nullptr;} // constructeur basique: declare PUIS initialise
	void Classe (type const & var):
		var(var),ptr(nullptr){} // constructeur par liste d'initialisation. Initialisation à la construction
	void Classe(Class const & c ) =default; //constructeur par recopie par défaut
	void Classe (Classe const & c); //constructeur par recopie
	void Classe (Classe const & c):
		var(c.var); // constructeur par recopie en liste d'initialisation

	/*destructeur*/
	~Classe() =default; // si utilisation d'un constructeur par recopie par défaut
	~Classe(){delete ptr}; // détruit de base le contenu, mais pas les pointeurs pointant dessus
	// il faut donc le faire manuellement

    /*setters & getters*/
    type getVar() const {return Var;}
    void setVar(type var){this.var=var};

  private:
    /*variables*/
    type var;
	typePtr * ptr;
}
