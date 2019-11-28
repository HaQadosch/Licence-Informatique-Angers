class Mere{ // pas abstraite car fct2 n'est pas virtuelle pure
	public:
		void rire(){std::cout<<"haha"<<std::endl;}
		Mere(int value1,int value2):
			var1(value1),var2(value2){}

		// liaison statique
		int fct1()const{return 2;}
		int lavar()const{return fct1()+var1;}

		 // liaison dynamique
		virtual int fct2() const; // cependant, on lui passe un code dans le .CC donc ce n'est pas une virtuelle pure
		int lavar()const{return fct2()+var1;}
		//cependant, l'appel à des fonctions dynamiques est plus lent. A utiliser que quand nécessaire

		// virtual int virtuellePure() const =0;
		// uniquement déclarée, pas définie, donc virtuelle pure

	private:
		int var1;
		int var2;

};

//la classe Fille dispose des attributs et méthodes de la classe Mere
class Fille:public Mere{
	public:
		//réutilisation des méthode mères
		void rire(){// redéfinission de la méthode déclarée dans la classe Mere
			Mere::rire();
			std::cout<<"ha"<<std::endl;
		}
		//surtout dans le constructeur
		Fille(int value1,int value2, int value3):
			Mere(value1,value2),var3(value3){}

		// attention, le destructeur des classes mères est tjr appelé aprés destruction de la classe Fille

		/* ici, la fonction lavar est héritée. hors, elle contient fct1 de Mere et non de Fille, même appelée depuis Fille
		Donc ici, fct1 ne sers à rien */
		int fct1()const{return 4;} // liaison statique
		int fct2()const override{return 4;} // une virtual se fait forcément override
		// Il faut donc utiliser virtual pour la redéfinir (fct2())

	private:
		int var3;
}
