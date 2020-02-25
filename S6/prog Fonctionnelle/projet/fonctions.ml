(* graphe de l'énoncé qui sera utilisé pour l'exemple *)
let graphe1 = [
	(1, [6;7;8]); 
	(2, [1;4]);
	(3, [2]);
	(4, [3;5]);
	(5, [1]);
	(6, [5;7]);
	(7, []);
	(8, [6;7])
];;

(*retourne la liste des sommets*)
let rec liste_sommets graphe = 
	match graphe with
	| ((num,_)::suite) -> num::(liste_sommets suite)
	| ([])             -> []
;;
	(*cas du dernier sommet*)

(* retourne le premier sommet du graphe*)
let rec racine graphe =
	match graphe with
	| ((num,succs)::_) -> (num,succs)
	| []               -> failwith "graphe vide"
;;

(* retourne le numero du sommet *)
let numSommet sommet = 
	match sommet with
	| (num,succs) -> num
;;

(*retourne la liste des successeurs de sommet dans graphe*)
let rec successeurs graphe sommet = 
	match graphe with
	| ((x, s)::r) -> if x = sommet then s else (successeurs r sommet)
	| []          -> failwith "Ce sommet n'appartient pas au graphe"
;;
(*successeurs graphe1 3;;*)


(*retire les elements de l2 à l1*)
let rec retirer l1 l2 =
	match l1 with
	| (x::r) -> if List.mem x l2 	
								then retirer r l2
								else x::retirer r l2
	| []     -> []
;;


(* parcours en profondeur *)
let parcours_profondeur graphe =
	let rec parcours_interne sommet dejaVisite pasEncoreVisite =
		if (pasEncoreVisite=[])
			then (*[]*)dejaVisite (* cas où l'on a fini de parcourir le graphe*)
			else	match sommet with
			| (num,succs) -> if(List.mem num pasEncoreVisite) (* si le sommet n'est pas encore visité*)
													then (*num::*)parcours_interne
																(List.hd(retirer (succs@pasEncoreVisite) dejaVisite),successeurs graphe (List.hd(retirer (succs@pasEncoreVisite) dejaVisite))) (*on visite le prochain element de pas encore visité *)
																(dejaVisite::num) (*on ajoute le sommet actuel dans la liste de ceux déjà visités*)
																(retirer (succs@pasEncoreVisite) (dejaVisite::num))	(* alors on ajoute ses successeurs qui ne sont pas dans " déjà visité " dans " pas encore visité "*)
																(*on retire le sommet actuel de ceux pasEncoreVisités*)
			|_ -> failwith "sommet invalide"
	in parcours_interne (racine graphe) [] [numSommet (racine graphe)]
;;
