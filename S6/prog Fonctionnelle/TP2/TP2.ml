(* fonctions sur les listes *)

let longueur list=
	let rec long taille list= match list with
		(x::r) -> long (taille+1) r
		|_ -> taille
	in long 0 list;;

let concat l1 l2= l1@l2;;

let nieme (*voir TD *)

(* fonctions intermediaires *)

let rec npremiers n list =match list with
	[]->failwith "liste vide"
	|(x::r) -> if(n=1) then x
				else if(n=0) then failwith "aucun chiffre à retourner"
				else x@npremiers (n-1) r;;

npremiers 3 [2;4;5];;

let met_a_plat list = match list with
	(l::r) ->
