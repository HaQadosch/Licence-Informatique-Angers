//reference = variable synonyme
	int i;
	int & j(i); // j et i auront tjr la même valeur:
	i=5; // j=5 aussi
	j=3; //i=3 aussi

	int maximum(std::array<int, 1000> t); // créer une copie de t qui est modifiée
	int maximum(std::array<int, 1000> & t); /* modifier directement le referecement, évite de faire une copie de 1000 int
	cependant, le paramètre sera modifié. Si on veut éviter celà, on ajoute un const	*/
	int maximum(std::array<int, 1000> const & t);

//allocation & destruction simple new->delete
	int * i=new int;delete i;
	int * i=new int(valInitiale);delete i;
	int * t=new int[taille];delete []i;

// accés aux variables
	(*ptr).val;
	ptr->val; // sont identiques

// On évite d'utiliser les pointeurs, car ils sont la cause de fuites mémoires et autres. à Utiliser en cas de nécéssité uniquement
// ne pas oublier durant leur emploi qu'on pointeur peut être nullptr
// la bonne pratique (RAII) consiste à créer l'objet pointé dans le constructeur, et le détruire dans le destructeur.

/* 2 types de pointeurs intelligents: */
#include <memory>
std::unique_ptr<type> unom; /* pointeur unique. Il est le seul à pouvoir pointer sur l'objet qu'il pointe
 	il ne peut pas être copié
	il libére automatiquement l'objet cible quand détruit
	conversion en booléen true s'il pointe sur un objet, en false sinon. */
auto entier=std::make_unique<int>(40); // construction de l'objet propriété, évite un cast
vector.push_back(std::move(entier)); // change l'objet propriété
reset; //libère l'objet propriété
/!\ il faut interdire le construction par copie dans ce cas là ( avec =delete )

std::shared_ptr<type> snom; /* pointeur partagé.
	il peut être copié
	il libére automatiquement l'objet ciblé quand le dernier pointeur est détruit
	il peut être vide , et nullptr peut être utilisé dans le constructeur */
std::make_shared<type>(val) ; // evite le cast
std::shared_ptr<>::use_count(); // permet d’accéder au compteur de références.

// en bref : unique_ptr>shared_ptr>ptr
