type operateur_bin = Mult | Add;;
type operateur_un = Moins;;
type arbre = Const of int
			| Var of string
			| Noeud1 of (operateur_un * arbre)
			| Noeud2 of (operateur_bin * arbre * arbre);;

(* définition du cas test de l'énoncé*)
let test=
Noeud2(
	Add,
	Noeud2(
		Mult,
		Var "x",
		Const 3
	),
	Var "y"
);;

(*début des questions*)
let rec chaine_de_arbre e = match e with
	Const(i)->string_of_int i
	|Var(str)->str
	|Noeud1(op,exp)-> "(-"^ chaine_de_arbre exp^")"
	|Noeud2(op,exp1,exp2)->( match op with
		Mult-> "("^ chaine_de_arbre exp1 ^"*"^ chaine_de_arbre exp2^")"
		|Add -> "("^ chaine_de_arbre exp1 ^"+"^ chaine_de_arbre exp2^")"
		);;

let rec close e li = match e with
	Var(x)-> List.mem x li
	|Noeud1(op,exp)-> close exp li
	|Noeud2(op,exp1,exp2)-> close exp1 li && close exp2 li
	|_-> true;;

let rec trouver nomVar li= 

let rec eval e L = if close e li then
	match e,L with
		(Const(i),_)->i
		((Var(x)),(nom,val)-> (*utiliser une autre fonction*)
	else failwith " des variables n'ont pas de valeurs attribuées"
