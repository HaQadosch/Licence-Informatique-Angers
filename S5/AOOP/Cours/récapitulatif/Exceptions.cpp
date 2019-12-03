try{ // bloc de gestion d'exceptions
	throw var ; //levée d'exception
}
catch (typeExcept except1){
	std::cout << "erreur détéctée"<<std::endl;
}
// attention aux exceptions dans un constructeur : problèmes si l'objet est à moitié construit

//il faut écrire les blocs catch de la plus spécifique à la plus générique, car le 1er bloc correspondant est celui appliqué

catch(...){
	//cas d'erreur pour tous ceux n'ayant pas encore été traités. Le + générique de tous les catch
}

//si une classe ne léve pas d'exception, on utilisera le mot-clef noexcept

/* on peut utiliser les classes d'exception de la bibliothèque standard*/
#include <stdexcept>
std::exception -> const char * what()const noexcept; // appelée quand une exception sort du main. fonction à redéfinir
std::bad_alloc //levée lors d’une erreur rencontrée par new .
std::bad_cast //levée lors d’un dynamic_cast impossible versune référence d’une sous-classe.
std::out_of_range// levée lors d’un appel incorrect à std::vector::at , etc.
std::logic_error;
std::invalid_argument;
