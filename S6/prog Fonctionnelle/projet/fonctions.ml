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

(*retourne la liste des successeurs du sommet dans le graphe *)
let rec liste_succ sommet ((num,succs)::suite) =
	if (sommet=0) then failwith "sommet invalide" else
	if (sommet=1) (* cas ou l'on est sur le bon sommet*)
		then succs
	else  if(((num,succs)::suite)=[]) (*cas ou le sommet saisi n'est pas dans le graphe*)
		then failwith "sommet non présent dans le graphe"
	else liste_succ (sommet-1) suite;; (*cas ou l'on cherche le sommet *)

(*indique si num est dans la liste ou non
est utilisé dans le parcours pour savoir si un sommet n'a pas encore été visité*)
let estDans num liste = match liste with
	(x::r)-> if(x=num) then true else nEstPasDans num r
	|([]) -> false;;
(*********** estDans = List.mem ???? **************)

(*retourne une liste des elements de liste1 qui ne sont pas dans liste 2*)
let rec neSontPasDans liste1 liste2

(* parcours en profondeur *)
let parcours_profondeur graphe =
	(* parcours des successeurs *)
	(* s'il n'y a plus de successeurs à traiter
	ajout de l'element à la liste des sommets visités  *)
	let rec parcours_interne sommet dejaVisite pasEncoreVisite=
		if (pasEncoreVisite=[]) then [] (* cas ou l'on a fini de parcourir le graphe*)
 		else
		match sommet with
			(num,succs) ->
				if(List.mem num pasEncoreVisite) (* si le sommet n'est pas encore visité*)
				(*alors on ajoute ses successeurs qui ne sont pas dans " deja visite " dans " pas encore visité "*)
				(*on ajoute le sommet actuel dans la liste de ceux déjà visités*)
				(*on visite le prochain element de pas encore visité *)
				then num::parcours_interne ? ? (pasEncoreVisite::(neSontPasDans succs dejaVisite))



	in parcours_interne (racine graphe) [] [1];;

(* *)
