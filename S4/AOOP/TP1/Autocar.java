
public class Autocar extends Camion {
	
	private int nbPassager;
	
	public Autocar(String nModele, int nAnneeAchat, double nPrixAchat, String nImmat, char nPermis, double nVolumeStockage, int nNbPassager) {
		super(nModele, nAnneeAchat, nPrixAchat, nImmat, nPermis, nVolumeStockage);
		this.nbPassager=nNbPassager;
	}

	public boolean peutTransporterPassager(int nbNouvPassager, double volumepPassager){
		return((nbNouvPassager<nbPassager) && (this.peutTransporterVolume(nbNouvPassager*volumepPassager)));
	}

	public void afficherAutocar(){
		super.afficherCamion();
		System.out.println("Je peux transporter "+this.nbPassager+" personnes");
	}
}
