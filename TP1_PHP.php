/////////// EXO 1 ///////////
<?php
echo "rapport d’erreurs préconfiguré : ".error_reporting()."<br/>";
//error_reporting(~E_WARNING);
$a = 2 / 0;
echo "division par 0<br/>";
//error_reporting(~E_NOTICE);
echo $b;
echo "variable indéfinie<br/>";
//error_reporting(~E_ALL);
require "nowhere.file";
echo "ne s’affichera pas<br/>";
?>

/////////// EXO 2 ///////////
//head.php
<?php
	echo "<h1>EN-TETE</h1>";
	echo "<h2> Fichier ".__FILE__."</h2>";
	echo "TP ".$tp." - Exercice ".$exo;
?>

//body.php
<?php
	echo "<h1>CORPS</h1>";
	echo "<h2> Fichier ".__FILE__."</h2>";
	echo "Methode HTTP utilisée :".$_SERVER["REQUEST_METHOD"]."</br></br>";
	echo "Chemin du fichier en cours d'execution ".$_SERVER["PHP_SELF"]."</br></br>";
	echo "Répertoire du fichier courant ".getcwd()."</br>";
?>

//foot.php
<?php
	echo "<h1>PIED</h1>";
	echo "<h2> Fichier ".__FILE__."</h2>";
	echo "<a href=\"http://www.php.net\">Le site officiel de PHP</a></br>";
?>

//main.php
<?php
	$tp=1;
	$exo=2;
	echo "<!DOCTYPE html>";
	echo "<head><br/><title> exercice $exo du TP $tp </title>";
	echo "<body>";
	include("head.php");
	echo "<hr>";
	include("body.php");
	echo "<hr>";
	include("foot.php");
	echo "</body>";
?>
