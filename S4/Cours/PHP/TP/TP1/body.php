<?php
	echo "<h1>CORPS</h1>";
	echo "<h2> Fichier ".__FILE__."</h2>";
	echo "Methode HTTP utilisée :".$_SERVER["REQUEST_METHOD"]."</br></br>";
	echo "Chemin du fichier en cours d'execution ".$_SERVER["PHP_SELF"]."</br></br>";
	echo "Répertoire du fichier courant ".getcwd()."</br>";
?>