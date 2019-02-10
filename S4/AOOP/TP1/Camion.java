
public class Camion extends Vehicule {

	private double volumeStockage;
	
	public Camion(String nModele, int nAnneeAchat, double nPrixAchat, String nImmat, char nPermis,double nVolumeStockage) {
		super(nModele, nAnneeAchat, nPrixAchat, nImmat, nPermis);
		this.volumeStockage=nVolumeStockage;
	}

	public boolean peutTransporterVolume(double volumeTest){
		return (volumeStockage>volumeTest);
	}

	public void afficherCamion(){
		super.afficherVehicule();
		System.out.println("Je dispose en plus d'un volume de stockage de "+this.volumeStockage+"kg");
	}
	
}
