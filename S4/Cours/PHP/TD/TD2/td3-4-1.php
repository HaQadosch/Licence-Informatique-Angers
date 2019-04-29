<?php
$initx=80;//lettre P
$inity=72;//lettre H
$initz=80;//lettre P
//Boucles imbriquées
for($x=$initx;$x<=90;$x++)
{
    for($y=$inity;$y<=90;$y++)
    {
        for($z=$initz;$z<=90;$z++)
        {
            for($num=100;$num<120;$num++)
            {
                echo "Numéro : $num ",chr($x),chr($y),chr($z)," 75<br />";
            }
            $initz=65;//on repart à la lettre A pour le troisième caractère
        }
        $inity=65;//on repart à la lettre A pour le deuxième caractère
    }
}
?>