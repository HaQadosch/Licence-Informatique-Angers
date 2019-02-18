
public class TestBatiment {



	public static void main(String[] args){

		//creation et affichage des différents batiments
		Maison maiTes=new Maison("rue du jardin",65,7,4000);
		Batiment batTes=new Batiment("rue de l'aquaponey",28);
		Immeuble immTes=new Immeuble("rue de zero",70,8);

		System.out.println(" ///////////////affichage de l'exercice 6/////////////// \n");
		System.out.println(maiTes);
		System.out.println(batTes);
		System.out.println(immTes);

		//creation et remplissage d'un tableau de batiment
		Batiment[] test= new Batiment[3];
		test[0]=maiTes;
		test[1]=batTes;
		test[2]=immTes;

		//affichage
		System.out.println("\n ///////////////affichage de l'exercice 7/////////////// \n");
		for(int i=0;i<test.length;i++)
			System.out.println("ligne ["+i+"] "+test[i]);

		//creation et affichage d'un quartier
		Quartier quaTes=new Quartier();
		quaTes.ajoutBatiment(batTes);

		System.out.println("\n ///////////////affichage de l'exercice 10/////////////// \n");
		System.out.println("avec un seul élément \n");
		quaTes.afficherBatiments();

		System.out.println("\navec plusieurs élément \n");
		//creation de batiments à ajouter, puis ajout
		Immeuble immTes2=new Immeuble("rue de zero",46,3);
		Maison maiTes2=new Maison("rue du jardin",28,3,300);
		Maison maiTes3=new Maison("rue du jardin",20,3,40000);
		Maison maiTes4=new Maison("rue du jardin",36,4,40000);
		Batiment tresGrand=new Batiment("rue de l'aquaponey",130);
		quaTes.ajoutBatiment(immTes);
		quaTes.ajoutBatiment(maiTes);
		quaTes.ajoutBatiment(immTes2);
		quaTes.ajoutBatiment(maiTes2);
		quaTes.ajoutBatiment(maiTes3);
		quaTes.ajoutBatiment(maiTes4);
		quaTes.ajoutBatiment(tresGrand);
		quaTes.afficherBatiments(2);

		//test de la méthode categorie
		System.out.println("\n ///////////////affichage de l'exercice 11/////////////// \n");
		System.out.println("catégorie de immTes: "+immTes.categorie());

		//test de la méthode comparer
		System.out.println("\n ///////////////affichage de l'exercice 13/////////////// \n");
		System.out.println(immTes.comparer(batTes) + " est le plus grand batiment entre \n" + immTes + "\n et \n" + batTes );

		//test de la méthode plusGrandBatiments
		System.out.println("\n ///////////////affichage de l'exercice 14/////////////// \n");
		System.out.println("le plus grand batiment du quartier est " + quaTes.plusGrandBatiments());
	}

}
