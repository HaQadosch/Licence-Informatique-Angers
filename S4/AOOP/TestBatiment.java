
public class TestBatiment {
	
	
	
	public static void main(String[] args){
		
		//creation et affichage des différents batiments
		Maison maiTes=new Maison("rue du jardin",40,5,40000);
		Batiment batTes=new Batiment("rue de l'aquaponey",28);
		Immeuble immTes=new Immeuble("rue de zero",70,8);
		
		System.out.println(" affichage de l'exercice 6 \n");
		System.out.println(maiTes);
		System.out.println(batTes);
		System.out.println(immTes);
		
		//creation et remplissage d'un tableau de batiment
		Batiment[] test= new Batiment[3];
		test[0]=maiTes;
		test[1]=batTes;
		test[2]=immTes;
		
		//affichage
		System.out.println("\n affichage de l'exercice 7 \n");
		for(int i=0;i<test.length;i++)
			System.out.println("ligne ["+i+"] "+test[i]);
		
		//creation et affichage d'un quartier
		Quartier quaTes=new Quartier();
		quaTes.ajoutBatiment(batTes);
	
		System.out.println("\n affichage de l'exercice 10 \n");
		System.out.println("avec un seul élément \n");
		quaTes.afficherBatiments();
		
		System.out.println("\navec deux élément \n");
		quaTes.ajoutBatiment(immTes);
		quaTes.afficherBatiments(2);
		
		//test de la méthode categorie
		System.out.println("\n affichage de l'exercice 11 \n");
		System.out.println("catégorie de immTes: "+immTes.categorie());
		
		
	}
	 	
}
