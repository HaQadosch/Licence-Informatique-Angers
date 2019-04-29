<?php
$nb=57;
$compteur=0;
$x=rand(0,1000);
//Boucle while
while($x%$nb!=0)
{
    $x=rand(0,1000);
    $compteur++;
}
echo "$x est multiple de $nb: Résultat obtenu en $compteur coups";
?>