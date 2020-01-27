<?php 
include "creer_tableau.php";
$nbCol=5;
$affiche=["Article","Prix","Taux T.V.A.","Coût H.T.","Coût T.T.C."];

function afficheLigne(){
}


//affichage du tableau
echo "<table border=\"2\" style=\"text-align:left;border-collapse: collapse;\">";
//affichage de la premiere ligne
for ($i=0;$i<$nbCol;$i++) {
  echo "<th>".$affiche[$i]."</th>";
}
//affichage du corps
for ($i=1;$i<$taille;$i++) {
  echo "</tr>";
  for ($j=1;$j<$nbCol;$j++) {
    if($j==0) echo "<th>".$articles[$i]."</th>";
    //else if($tableau[$i][$j]==1) echo "<td>TRUE</td>";
    else echo"<td></td>";
  }
}
echo "</table>";
?>
