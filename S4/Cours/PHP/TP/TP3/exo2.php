<!DOCTYPE html>
<html lang="fr">
<head>
  <meta charset="UTF-8"/>
  <title>TP PHP 3 - Exercice 2</title>
  <style type="text/css">
  body { background-color:yellow;}
  </style>
</head>

<body>
<?php
//inclusion des fonctions pour formulaire
include("../fonctions_formulaire.php");
//generation du formulaire
$formulaire=form("{$_SERVER['PHP_SELF']}","post","inscrivez-vous ou affichez la liste étudiants");
$formulaire.="<table><tbody><tr><td>";
$formulaire.=text("Nom","nom");
$formulaire.="</td></tr><tr><td>";
$formulaire.=text("Prenom","prenom");
$formulaire.="</td></tr><tr><td>";
$formulaire.=debut_select("groupe","groupe");
$formulaire.=option_select("I1");
$formulaire.=option_select("I2");
$formulaire.=option_select("I3");
$formulaire.=default_option_select("I4");
$formulaire.=option_select("I5");
$formulaire.=option_select("I6");
$formulaire.=fin_select();
$formulaire.="</td></tr><tr><td>";
$formulaire.=submit("envoi","inscrire");
$formulaire.=submit("envoi","lister");
$formulaire.="</td></tr></tbody></table>";
$formulaire.=finform();
echo $formulaire;

//traitement
if(isset($_POST["envoi"])){
// recuperation du fichier et affichage
  if($_POST["envoi"]=="lister"){
    $fic=fopen("etudiants.csv","a+");
    //debut du tableau
    echo "<table border=\"2\"> \n";
    //affichage premiere ligne
    echo "<th>ID</th><th>NOM</th><th>PRENOM</th><th>GROUPE</th> \n";
    for($id=0;$ligne=fgetcsv($fic,200,";");$id++){
      if($id>0){
        echo "<tr> \n <td>".$id."</td>";
        $nom=$ligne[0];
        $prenom=$ligne[1];
        $groupe=$ligne[2];
        $email = str_replace(" ","-",strtolower($ligne[1])).".".str_replace(" ","-",strtolower($ligne[0]))."@univ-angers.fr";
        echo "<td><a href=\"mailto:$email\"> $nom </td><td>$prenom</td><td>$groupe</td> \n";
        echo "</tr>";
      }
    }
    echo "</table>";
    fclose($fic);
  }
  // recuperation du fichier et ajout
  else if($_POST["envoi"]=="inscrire" && isset($_POST["nom"]) && isset($_POST["prenom"])){
    $fic=fopen("etudiants.csv","a");
    $nom=trim($_POST["nom"]);
    $prenom=trim($_POST["prenom"]);
    $groupe=$_POST["groupe"];
    $ajout="\n".$nom.";".$prenom.";".$groupe;
    flock($fic,2);
    fwrite($fic,$ajout);
    flock($fic,3);
    fclose($fic);
    echo "<h3>",ucwords(strtolower($prenom))," ", ucwords(strtolower($nom))," : vous êtes inscrits dans le groupe ".$groupe."</h3>";

  } else {
    echo " veuillez compléter tous les champs ";
  }
}

 ?>
</body>
