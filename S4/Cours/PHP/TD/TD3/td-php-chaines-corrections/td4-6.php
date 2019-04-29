<?php
$ch="Zut je me suis trompé";
$modele="/zut/i";
if(preg_match($modele,$ch)) echo "Un Mot censuré";
else echo $ch
?>