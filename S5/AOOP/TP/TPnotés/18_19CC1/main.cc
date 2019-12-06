#include "NumEpisode.hh"
#include "Visionnage.hh"
#include <iostream>
#include <string>
#include <sstream>

int main(){
	NumEpisode e1(1,1);
	std::cout<<e1.tostring()<<std::endl;
	NumEpisode e2(1,2);
	NumEpisode e3(2,1);
	std::cout<<"1. 1->"<<e2.estAvant(e3)<<std::endl;
	Film ten("tenten",10,"richard");
	std::cout<<ten.getNom()<<"est un "<<ten.typeVisionnage()<<std::endl;
	return 0;
}
