(* graphe de l'énoncé qui sera utilisé pour l'exemple *)
let graphe1 = [(1,[6;7;8]) ; (2,[1;4]) ; (3, [2]) ; (4, [3;5]) ; (5, [1])
; (6, [5;7]) ; (7, []) ; (8, [6;7])];;

(*retourne la liste des sommets*)
let rec liste_sommets graphe = match graphe with
	((num,_)::suite) -> num::(liste_sommets suite)
	(*cas du dernier sommet*)
	|([]) -> [];;

(* retourne le premier sommet du graphe*)
let rec racine graphe = match graphe with
	((num,succs)::_) -> (num,succs)
	|[]->failwith "graphe vide";;

(* retourne le numero du sommet *)
let numSommet sommet = match sommet with
	(num,succs)->num;;

(*retourne la liste des successeurs du sommet dans le graphe ) VER 1
let rec liste_succ sommet ((num,succs)::suite) =
	if (sommet=0) then failwith "sommet invalide" else
	if (sommet=1) (* cas ou l'on est sur le bon sommet*)
		then succs
	else  if(((num,succs)::suite)=[]) (*cas ou le sommet saisi n'est pas dans le graphe*)
		then failwith "sommet non présent dans le graphe"
	else liste_succ (sommet-1) suite;; (*cas ou l'on cherche le sommet *) *)



(*retourne la liste des successeurs de sommet dans graphe*)
let rec successeurs graphe sommet = match graphe with
	((x, s)::r) -> if x = sommet then s else (successeurs r sommet)
	| [] -> failwith "Ce sommet n'appartient pas au graphe";;
(*successeurs graphe1 3;;*)


(*indique si num est dans la liste ou non
est utilisé dans le parcours pour savoir si un sommet n'a pas encore été visité)
let estDans num liste = match liste with
	(x::r)-> if(x=num) then true else nEstPasDans num r
	|([]) -> false;;
(*********** estDans = List.mem ???? **************) *)

(*retire les elements de l2 à l1*)
let rec retirer l1 l2 = match l1 with
	(x::r) -> if List.mem x l2 	then retirer r l2
									else x :: retirer r l2
	| [] -> [];;

(*retourne une liste des elements de liste1 qui ne sont pas dans liste 2)
let rec neSontPasDans liste1 liste2 *)

(* parcours en profondeur *)
let parcours_profondeur graphe =
	(* parcours des successeurs *)
	(* s'il n'y a plus de successeurs à traiter
	ajout de l'element à la liste des sommets visités  *)
	let rec parcours_interne sommet dejaVisite pasEncoreVisite=
		if (pasEncoreVisite=[]) then dejaVisite (* cas où l'on a fini de parcourir le graphe*)
 		else
		match sommet with
			(num,succs) ->
				if(List.mem num pasEncoreVisite) (* si le sommet n'est pas encore visité*)
				(* 3 - alors on ajoute ses successeurs qui ne sont pas dans " déjà visité " dans " pas encore visité "*)
				(* 3bis - on retire le sommet actuel de ceux pasEncoreVisités*)
				(* 2 - on ajoute le sommet actuel dans la liste de ceux déjà visités*)
				(* 1 - on visite le prochain element de pas encore visité *)
				then (*num::*)parcours_interne List.hd(retirer (succs@pasEncoreVisite dejaVisite)) (dejaVisite::num) (retirer (succs@pasEncoreVisite) (dejaVisite::num))
			|_ -> failwith "sommet invalide"


	in parcours_interne (racine graphe) [] [numSommet (racine graphe)];;
