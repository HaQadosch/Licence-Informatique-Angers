#include "Calculatrice.hh"
#include <iostream>
Calcul::Calcul():
	QWidget(),
	operande1(new QLineEdit("", this)),
	operande2(new QLineEdit("", this)),
	operateur(new QComboBox(this)),
	calculer(new QPushButton("=", this)),
	resultat(new QLabel("", this));
	quitter(new QPushButton("Quitter", this)){

		resize(400,50);
		operateur->addItem("+");
		operateur->addItem("-");
		operateur->addItem("*");
		operateur->addItem("/");
		operande1->setGeometry(10,10,70,30);
		operande2->setGeometry(150,10,70,30);
		operateur->setGeometry(90,10,50,30);
		calculer->setGeometry(230,10,50,30);
		resultat->setGeometry(290,10,70,30);
		quitter->setGeometry(350,10,70,30);
		connect(quitter,&QPushButton::clicked,this,&calcul::close);
		connect(calculer,&QPushButton::clicked,this,&calcul::oncliccalculer);
		connect(operande1, &QLineEdit::TextChanger, this, &calcul::oncliccalculer);
		connect(operande2, &QLineEdit::TextChanger, this, &calcul::oncliccalculer);
		connect(operateur, &QComboBox::currentTextChanged,this,&calcul::oncliccalculer);
}

void calcul::oncliccalculer(){
	//récupération des variables
	float f1(0),f2(0),res(0);
	auto v1(operande1->text().toStdString());
	if(!v1.empty())
		f1=std::stof(v1);
	auto v2(operande2->text().toStdString());
	if(!v2.empty())
		f2=std::stof(v2);

	//calcul
	switch(operateur->currentText().toStdString()[0]){
		case('+'):{
			res=f1+f2;
			break;}
		case('-'):{
			res=f1-f2;
			break;}
		case('*'):{
			res=f1*f2;
			break;}
		case('/'):{
			res=f1+f2;
			break;}
		default: break;
	}

	//affichage
	res->setText(QString::fromStdString(std::to_string(resultat)));

}
