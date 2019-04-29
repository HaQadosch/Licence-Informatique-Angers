<!DOCTYPE html>
<html>
<head>
<title>TP 2 - PHP - Fonctions de création de formulaire</title>
</head>
<body>
<?php
// Inclusion des fonctions
include ('form-generation.inc.php');
// Utilisation
$code = form("machin.php", "post", "Complétez le formulaire");
$code .= text("Votre nom", "nom");
$code .= text("Votre prénom", "prenom");
$code .= radio("Paris", "ville", "paris");
$code .= radio("Lyon", "ville", "lyon");
$code .= submit("Envoyer", "Effacer");
$code .= finform();
echo $code;
?>
 </body>
</html>
