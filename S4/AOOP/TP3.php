// client.java

public class Client {
	private int numeroClient;
	String nom;
	private double solde;
	private static int cptClient=0;
	/*
	 * constructeur
	 */
	public Client(String nom) {
		this.nom = nom;
		this.solde = 0;
		cptClient++;
		numeroClient=cptClient;
	}

	// getters et setters
	
	public int getNumeroClient() {
		return numeroClient;
	}

	public void setNumeroClient(int numeroClient) {
		this.numeroClient = numeroClient;
	}

	public double getSolde() {
		return solde;
	}

	public void setSolde(double solde) {
		this.solde = solde;
	}

	public static int getCptClient() {
		return cptClient;
	}

	public static void setCptClient(int cptClient) {
		Client.cptClient = cptClient;
	}

	
	/*
	 * redefinition de to_string
	 */
	public String toString() {
		return "Client [numeroClient=" + numeroClient + ", nom=" + nom
				+ ", solde=" + solde + "]";
	}
	
}

// annuaire.java
import java.util.ArrayList;


public class Annuaire {
	
	private ArrayList<Client> listeClients = new ArrayList<Client>();
	
	//affiche le client associé au numero entré précedamment
	public void afficheClient(int numClient){ 
		
		for(int i=0;i<listeClients.size();i++){
			if(listeClients.get(i).getNumeroClient()==numClient) System.out.println(listeClients.get(i));
		}
	}
	
	public void afficheClients(){ 
		
		for(int i=0;i<listeClients.size();i++){
			System.out.println(listeClients.get(i));
		}
	}
	
	public void supprimeClient(int numClient){
		for(int i=0;i<listeClients.size();i++){
			if(listeClients.get(i).getNumeroClient()==numClient) listeClients.remove(i);
		}
	}
	
	public void ajoutSolde(int numClient, double ajout){
		
		for(int i=0;i<listeClients.size();i++){
			if(listeClients.get(i).getNumeroClient()==numClient) listeClients.get(i).setSolde(listeClients.get(i).getSolde()+ajout);
		}
		
	}
	public int taille(){
		return(listeClients.size());
	}
	
	public double sommeTotale(){
		double max=0;
		for(int i=0;i<listeClients.size();i++,max=max+listeClients.get(i).getSolde()) {/*mdr*/} 
		return max;
	}
	
	public void ajoutClient(Client c){
		this.listeClients.add(c);
	}
	
}

// saisie.java
import java.io.*;

public class Saisie {

	public static String lireChaine(String message){
		String ligne = null;

		try{
			InputStreamReader isr = new InputStreamReader(System.in);
			BufferedReader br = new BufferedReader(isr);
			System.out.print(message);
			ligne = br.readLine();
		}
		catch (IOException e){
			System.err.println(e.getMessage());
		}
		return ligne;
	}

	public static int lireEntier(String message){
		return Integer.parseInt(lireChaine(message));
	}

	public static double lireReel(String message){
		return Double.parseDouble(lireChaine(message));
	}

	public static String lireString(String message){
		return lireChaine(message);
	}
}
// Test.java


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
