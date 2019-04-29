<?php
$tab[0][]="Azerky";
$tab[0][]="Sophia";
$tab[1][]="Bazertudoh";
$tab[1][]="Jean-Michel";
for($i=0;$i<count($tab);$i++)
{
    echo vsprintf ("<tt>%'_-20s %'_-20s </tt><br />",$tab[$i]);
}
?>