<?php
$compteur=0;
do
{
    $x=rand(0,1000);
    $y=rand(0,1000);
    $z=rand(0,1000);
    $compteur++;
    echo $x, "," , $y, "," , $z,"<br />";
}
while($x%2==1 OR $y%2==0 OR $z%2==0);
echo "Résultat obtenu en $compteur coups.";
?>