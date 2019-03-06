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

	public boolean contient(Client c){
		for(int i=0;i<listeClients.size();i++){
			if(c==listeClients.get(i)) return true;
		}
		return false;
	}

}
