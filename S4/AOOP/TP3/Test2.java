public class Test2 {

	public static void main(String[] args) {

		Annuaire annuaire = new Annuaire();

		//ajout des clients
		Client c1= new Client("testmemenom");
		annuaire.ajoutClient(c1);

		Client c2= new Client("testmemenom");

		System.out.println("Verifions si deux clients différents avec le même nom sont différenciés: \n"
		 + annuaire.contient(c2) + "\n");


	 }
}
