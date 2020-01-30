
(* fonctions à une variable *)

let calculTTC ht = ht *. 0.2;;

(* bissextile home*)

let estMinuscule car = if(car >= 'a' && car <='z')
						then true
						else false ;;

(* fonctions à deux variables*)

let moyenne r1 r2 = (r1+.r2)/.2.;;

let div num1 num2 = (num1/num2,num1 mod num2);;

(* fonctions avec déclarations locales *)

let puiss4 num =
	let carre num = num*num
	in carre (carre num) ;;

let minToMaj car = char_of_int (int_of_char (car) + ( int_of_char('A') - int_of_char('a')));;


(* fonctions récursives *)
let rec fibo num = match num with
					 0 -> 0
					|1 -> 1
					|_ -> fibo(num-1)+fibo(num-2);;

let rec sommeNCarre n = if(n=0) then 0 else
	let carre n = n*n
	in carre n + sommeNCarre(n-1);;

(* fonctions d'ordre supérieur *)
	(* sigma pour somme n carre *)
	let rec sigma fonc n x=
		if(n=0) then fonc x
		else fonc(x) + sigma fonc (n-1) (x-1);;

	let sommeNCarreSig var = sigma (fun x-> x*x) var var

	(* rond *)
	let rond f g x= g(f(x));;

(* racine carre via newton *)
let rec newton x y eps =
	if (y*.y<= x+.eps && y*.y>= x-.eps) then y
	else ((y+.x/.y)/.2.) eps;;
