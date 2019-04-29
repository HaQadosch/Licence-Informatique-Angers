<?php
$nb=57;
$compteur=0;
do
{
    $x=rand(0,1000);
    $compteur++;
}
while($x%$nb!=0);
echo "$x est multiple de $nb: Résultat obtenu en $compteur coups";
?>