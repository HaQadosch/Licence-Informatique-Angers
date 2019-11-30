class Generale{
	public:
		Generale(int var1,char var2);
		virtual Generale* clone() const=0; /* contructeur virtuel
		permet l'ajout (et la recopie) de Classe1 et Classe 2 dans le vecteur sans y ajouter de Generale tout court*/

		virtual ~Generale() =default; /* définition d'un destructeur virtuel
		Si on le mets pas virtual, c'est lui qui est appellé lors de la destruction des pointeurs du vecteur, et non ceux de Classe1 et Classe2
		Pour éviter ça, on le défini Virtual. Et donc ceux appellés seront ceux de Classe1 et Classe2
		*/

		//definition d'une methode virtuelle à utiliser dans l'affichage
		virtual void sortie(std::ostream & os) const;

		virtual str::string quiSuisJe() const=0;

	private:
		int var1;
		char var2;
};

class Classe1:public Generale{
	public:
		//redefinition du constructeur virtuel
		Generale* clone() const override{
			return new Classe1(*this);
		}
		//redefinition de l'affichage
		void sortie(std::ostream & os) const override;

		//methodes spécifiques à la sous-classe
		bool JeSuisTop(int truc)const;
		std::string quiSuisJe() const override;
	private:
		std::string nom;
};

class Classe2:public Generale{
	public:
		//redefinition du constructeur virtuel
		Generale* clone() const override{
			return new Classe2(*this);
		}
		//redefinition de l'affichage
		void sortie(std::ostream & os) const override;

		std::string quiSuisJe() const override;
	private:
		std::string prenom;
};

class Polym{
	public:
		Polym(Polym const & c);
		//attention, utilisations de pointeurs donc redéfinition destructeur
		~Polym();
		void afficheSiTop(int truc)const;
		void ajouterClasse(Generale const & c);
	private:
		std::vector<Generale *> done; // vecteur pouvant contenir des Classe1 et Classe 2. Necessite d'utiliser des pointeurs de Generale
};

std::ostream & operator <<(std::ostream & os, Generale const & c);
