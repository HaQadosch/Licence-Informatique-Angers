type 'a abr = Feuille of ('a)| Noeud of ('a abr * 'a abr) | Noeud2 of ('a abr);;

let abr2= Noeud(Noeud(Feuille(1),Feuille(4)),Noeud(Feuille(2),Noeud2(Feuille(3))));;
let abrsup= Noeud(Noeud(Feuille(1),Feuille(4)),Noeud(Feuille(2),Feuille(3)));;

let rec nb_noeuds abr = match abr with
	Feuille(_)-> 0
	|Noeud(abrG,abrD)-> 1+nb_noeuds abrG + nb_noeuds abrD
	|Noeud2(abr)->1+nb_noeuds abr;;

let rec nb_feuilles abr = match abr with
	Feuille(_)-> 1
	|Noeud(abrG,abrD)-> nb_feuilles abrG + nb_feuilles abrD
	|Noeud2(abr)-> nb_feuilles abr;;

let rec profondeur abr = match abr with
	Feuille(_)-> 0
	|Noeud(abrG,abrD)-> if profondeur abrG> profondeur abrD then 1+ profondeur abrG else 1+profondeur abrD
	|Noeud2(abr)-> 1+ profondeur abr;;

let rec memeForme abr1 abr2= match abr1,abr2 with
 	(Feuille(_),Feuille(_))->true
	|(Noeud(abrGG,abrGD),Noeud(abrDG,abrDD))-> (memeForme abrGG abrDG && memeForme abrGD abrDD)
	|(Noeud2(abrG),Noeud2(abrD))-> memeForme abrG abrD
	|(_) -> false;;

let rec liste_feuilles abr = match abr with
	Feuille(x)-> [x]
	|Noeud(abrG,abrD)-> liste_feuilles abrG@liste_feuilles abrD
	|Noeud2(abr)-> liste_feuilles abr;;

let rec map_arbre abr f = match abr with
	Feuille(x)-> Feuille(f x)
	|Noeud(abrG,abrD)-> Noeud(map_arbre abrG f , map_arbre abrD f)
	|Noeud2(abr)-> Noeud2(map_arbre abr f);;

map_arbre abr2 (fun x->x+1);;
