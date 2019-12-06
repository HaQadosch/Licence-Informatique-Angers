#include "Calendrier.hh"

int main(){
	jourdelasemaine j1(lundi);
	jourdelasemaine j2(dimanche);
	std::cout<<tostring(j1)<<"est-il avant"<<tostring(j2)<<"? \n la réponse est "<<estAvant(j1,j2)<<std::endl;
	Horaire h(10,11);
	std::cout<<h.tostring()<<std::endl;
	return 0;
}
