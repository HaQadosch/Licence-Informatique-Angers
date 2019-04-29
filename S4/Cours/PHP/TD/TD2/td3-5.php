<?php
//Nombre à trouver
$nb=789;
//boucle de tirage
for($coup=1;$x!=$nb;$coup++)
{
    $x=rand(0,1000);
    //echo $x,"<br />";//pour afficher tous les tirages
}
echo "$nb trouvé en $coup coups ";
?>
