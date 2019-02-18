/**
* la classe Quartier correspond aux quartiers,
* elle contient une liste de batiments
* Cependant, pour le moment, cette classe ne dispose pas de constructeur
* @author Brinon Baptiste
*/
public class Quartier {
	/**
	* tab est un tableau de batiments
	* @see Batiment
	*/
	private Batiment[] tab=new Batiment[10];

	/**
	* ajoute une batiment a la premiere case libre du tableau
	* @param ajout ajout correspond au batiment à ajouter au tableau
	*/
	public void ajoutBatiment(Batiment ajout){
		int i=0;
		while(tab[i]!=null){
			i++;
		}
		tab[i]=ajout;
	}

	/**
	* affiche les batiments du Quartier
	*/
	public void afficherBatiments(){
		for(int i=0;i<tab.length;i++)
			System.out.println("ligne ["+i+"] "+tab[i]);
	}

	/**
	* affiche les batiments du quartiers ayant une categorie superieure à celle choisie
	* @param cat cat est la categorie minimale dont on veut afficher les batiment
	*/
	public void afficherBatiments(int cat){
		for(int i=0;i<tab.length;i++){
			if(tab[i]!=null){
				if(tab[i].categorie()<cat) System.out.println("ligne ["+i+"] la catégorie est trop petite");
				else System.out.println("ligne ["+i+"] "+tab[i]);
			}
			else System.out.println("ligne ["+i+"] "+tab[i]);
		}
	}

	/**
	* determine le plus grand batiment du quartier
	* @return retourne le batiment ayant la plus grande surfaceHabitable
	*/
	public Batiment plusGrandBatiments(){
		Batiment result=tab[0];
		for(int i=1;i<tab.length;i++){
			if(tab[i]!=null){
					result=tab[i].comparer(result);
			}
		}
		return(result);
	}

}
