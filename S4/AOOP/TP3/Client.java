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

	boolean Equals(Object c){
		return(c.nom==this.nom);
	}

}
