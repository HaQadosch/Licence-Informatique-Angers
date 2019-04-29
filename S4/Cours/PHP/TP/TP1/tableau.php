<!DOCTYPE html>
<html lang="fr">
<head>
  <meta charset="UTF-8"/>
  <title>TP PHP 1 - Exercice 3</title>
  <style type="text/css">
  th { background-color:cyan;}
  </style>
</head>

<?php
//declaration des variables et tableaux
$taille=12;
$affiche=["==","TRUE","FALSE","1","0","-1","\"1\"","\"0\"","\"-1\"","NULL","[]","\"\""];
$ensemble=['==',TRUE,FALSE,1,0,-1,"1","0","-1",NULL,[],""];
$tableau=$ensemble;
//remplissage du tableau en placant chaque ligne l'une aprés l'autre
for ($i=1;$i<$taille;$i++) {
  $ligne[0]=$ensemble[$i];
  for ($j=1;$j<$taille;$j++) {
    $ligne[$j]=($ensemble[$i]==$ensemble[$j]);
  }
  $tableau[$i]=$ligne;
}

//affichage du tableau
echo "<table border=\"2\" style=\"text-align:left;border-collapse: collapse;\">";
//affichage de la premiere ligne
for ($i=0;$i<$taille;$i++) {
  echo "<th>".$affiche[$i]."</th>";
}
//affichage du corps
for ($i=1;$i<$taille;$i++) {
  echo "</tr>";
  for ($j=0;$j<$taille;$j++) {
    if($j==0) echo "<th>".$affiche[$i]."</th>";
    else if($tableau[$i][$j]==1) echo "<td>TRUE</td>";
    else echo"<td></td>";
  }
}
echo "</table>";
?>
