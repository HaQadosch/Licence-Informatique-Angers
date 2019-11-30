// Differents types
	signed;unsigned;
	char; short int; int; long int; long long int; float; double; long double;
	wchar_t(unicode); bool;
	int8_t;int16_t;uint16_t;...(int à taille fixée. details sur http://en.cppreference.com/w/cpp/types/integer)

	il existe aussi des types spéciaux :
		std::size_t; ...
		auto; //inférence de type: type détérminé à l'initialisation
		// /!\ auto t{1,2,3}; ne créée pas un tableau mais un std::initializer_list;

//on peut aussi créer un type
	typedef unsigned int Dio; // renommage. Fonctionne aussi avec using
	using Jojo=unsigned int
	enum nomTypeEnum{ // type pouvant prendre plusieurs valeurs
		val1,
		val2,
		val3
	};
	enum class enumType{ // enum sans la background des int
		val4,
		val5
	};
	struct nomStruct{ // structure contenant des vals
		Dio val;
		std::string autreVal;
		Jojo uneAutreVal;
	};
//cast & conversion de type
	float res=((float)a/b); // cast générique
	float res=(static_cast<float>(a)/b); // cast good sur expression
	char * c('12');
	int * i(reinterpret_cast<int *>(c)); // cast sur pointeurs



//initialisations
	short int type1; type1=10; // declaration PUIS initialisation
	short int type2(20); // declaration et Initialisation en même temps
	short int type3=30; // declaration et Initialisation V2

	void f(int a, int b=type1){} /* ici, b à une valeur pas défaut.
	Cependant, cela ne fonctionne qu'avec les derniers arguments ( donc pas a sans b) */
	f(1,1);
	f(1); // a=1,b=type1;

//utilisation des types struct & enum
	nomStruct structure;
	structure.val=10;
	structure.autreVal="exemple";
	structure.uneAutreVal=10;

	nomTypeEnum enumeration(val2);
	enumeration++;
	bool isCorrect=(enumeration==val3);

// operations sur chaines
	std::string s("ceci est un exemple");
	std::string s2(" et on en a la suite ici");
	int taille=s.length(); //retourne la taille
	std::string sTot=s+s2; // concaténation via +

//operations sur tableau, fournies par std::array
	std::array<char,taille> sBis {"c","e","c","i"," ","e","s","t"," ","u","n"," ","e","x","e","m","p","l","e"};
	std::size_t indice(1);
	char e=sBis[indice]; //aucune verification
	char e=sBis.at(indice); // at lève une exception
	bool correct=sBis.max_element()==taille;

// operations sur vecteur



//constance
	const int i(4); // équivalent à
	int const i(4);

	char * c;
	char * const c1; //pointeur constant sur des caractères variables
	c1=c;/*INTERDIT*/ *c1='a'; c[1]='b'; /* OK */
	char const * c2 ; // pointeur variable sur caractères constants
	*c2='a'; c2[1]='b'; /*INTERDITS */ c2=c; /* OK */
	char const * const c3; // pointeur constant sur caractères constants
	*c3='a'; c3[1]='b';c3=c; /*INTERDITS */

	int maximum(std::array<int, 1000> const & t); // variable par reference mais ne sera pas modifiée à l'origine ( seulement dans la fonction ) car const

// boucles for
	for(int i=0;i<taille;i++); // i=0->taille
	for(int i=0;i<taille;++i); // i=1->taille
	for(auto i : sBis); // parcours de n'importe quelle classe disposant de begin&end

//flux entrées-sorties
	std::cin >> entreeClassique;
	std::cout << sortieClassique;
	//iostream peut-être modifié et transféré

	//redefinition des operateurs >> et <<
	std::ostream & operator <<(std::ostream & os, Classe const & c);
	std::istream & operator >>(std::istream & os, Classe & c);
