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
