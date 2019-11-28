#include <QtWidgets>

class Calcul::public QWidget{
	Q_OBJECT
	public:
		Calcul();
	public slots:
	void oncliccalculer();
	private:
		QLineEdit * operande1, * operande2;
		QComboBox * operateur;
		QLabel * resultat;
		QPushButton *calculer, *quitter

};
