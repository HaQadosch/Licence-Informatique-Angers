(* graphe de l'énoncé qui sera utilisé pour l'exemple *)
let graphe1 = [(1,[6;7;8]) ; (2,[1;4]) ; (3, [2]) ; (4, [3;5]) ; (5, [1])
; (6, [5;7]) ; (7, []) ; (8, [6;7])];;

(*retourne la liste des sommets*)
let rec liste_sommets graphe = match graphe with
	((num,_)::suite) -> num::(liste_sommets suite)
	(*cas du dernier sommet*)
	|([]) -> []

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
let nEstPasDans num liste = List.map(fun (x::r) -> x<>num) liste;;

(* parcours en profondeur *)
let parcours_profondeur graphe =
	(* parcours des successeurs *)
	(* s'il n'y a plus de successeurs à traiter
	ajout de l'element à la liste des sommets visités  *)
	let rec parcours_interne g dejaVisite=
 		match g with
			((num,succs)::suite) -> if(nEstPasDans num dejaVisite) then

	in parcours_interne graphe []

(* *)
