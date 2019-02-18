
public class Quartier {
	
	private Batiment[] tab=new Batiment[10];

	public void ajoutBatiment(Batiment ajout){
		int i=0;
		while(tab[i]!=null){
			i++;
		}
		tab[i]=ajout;
	}
	
	public void afficherBatiments(){
		for(int i=0;i<tab.length;i++)
			System.out.println("ligne ["+i+"] "+tab[i]);
	}
	
	public void afficherBatiments(int cat){
		for(int i=0;i<tab.length;i++){
			if(tab[i]!=null){
				if(tab[i].categorie()<cat) System.out.println("ligne ["+i+"] la catégorie est trop petite");
				else System.out.println("ligne ["+i+"] "+tab[i]);
			}
			else System.out.println("ligne ["+i+"] "+tab[i]);
		}
	}
	
}
