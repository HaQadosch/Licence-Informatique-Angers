#include "ArrayInt.hh"

ArrayInt::ArrayInt(indice iMin, indice iMax):
	contenu(iMax-iMin+1,0), iMin(iMin),iMax(iMax){}

char const * ExceptionArrayInt::what() const noexcept{
	return message.c_str();
}

void ArrayInt::set(indice i,int v){
	if((i>= iMin) && (i<= iMax))
		contenu[i-iMin]=v;
	else
		throw ExceptionArrayInt("indice invalide dans set",i);
}

int ArrayInt::set::at(indice i) const{
	if((i>= iMin) && (i<= iMax))
		return contenu[i-iMin];
	else
		throw ExceptionArrayInt("indice invalide dans at",i);
}

int ArrayInt::operator[](incide i) const{
	return at(i);
}
bool ArrayInt::operator==(ArrayInt cont & a) const{
	return (contenu==a.contenu) && (iMin==a.iMin);
}

std::ostream & operator==(,std::ostream & os,ArrayInt const & a){
	
}
