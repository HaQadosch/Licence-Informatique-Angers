// Test.java
package test;
import util.*;
import program.*;

public class Test {

	public static void main(String[] args) {

		Annuaire annuaire = new Annuaire();


		int rep =0;
		while(rep!=-1){
			System.out.println("1 ===>  Ajouter un nouveau client");
			System.out.println("2 ===>  Afficher la taille de l'annuaire");
			System.out.println("3 ===>  Afficher l'annuaire complet");
			System.out.println("4 ===>  Rechercher un client par son identifiant");
			System.out.println("5 ===>  Supprimer un client par son identifiant");
			System.out.println("6 ===>  Crediter le solde d'un client");
			System.out.println("7 ===>  Afficher le total des soldes des clients de l'annuaire");
			System.out.println("-1 ===>  Quitter");

			rep = Saisie.lireEntier("Votre choix ?");

			if(rep == 1){

				Client c= new Client(Saisie.lireString("entrez un nom de client"));
				annuaire.ajoutClient(c);

			} else if (rep ==2){

				System.out.println("il y a actuellement"+annuaire.taille()+"clients dans l'annuaire");

			} else if (rep ==3){

				annuaire.afficheClients();

			} else if (rep ==4){

				int numSaisi=Saisie.lireEntier(" entrez un numero client:");
				System.out.println("le client correspondant est"); annuaire.afficheClient(numSaisi);

			} else if (rep ==5){

				int numSaisi=Saisie.lireEntier(" entrez un numero client à supprimer:");
				System.out.println("le client correspondant est"); annuaire.supprimeClient(numSaisi);


			} else if (rep ==6){

				int numSaisi=Saisie.lireEntier(" entrez un numero client à créditer:");
				double creditSaisi=Saisie.lireEntier(" entrez le montant à créditer:");
				annuaire.ajoutSolde(numSaisi,creditSaisi);

			} else if (rep ==7){

				System.out.println("il y a au total"+ annuaire.sommeTotale() +" de crédits dans l'annuaire");

			}
		}
	}
}
