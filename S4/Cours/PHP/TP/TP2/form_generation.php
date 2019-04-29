<!DOCTYPE html>
<head>
  <meta charset="UTF-8"/>
  <tilte> TP onsenbalecdutitre<br /></title>
</head>
<body>
<?php
  include("form_generation.inc.php");
  $formulaire=form("{$_SERVER['PHP_SELF']}","post","complétez le formulaire");
  $formulaire.=text("votre nom","texte");
  $formulaire.=text("votre prenom","texte");
  $formulaire.=radio("Paris","ville","test");
  $formulaire.=radio("Lyon","ville","test");
  $formulaire.=submit("envoyer","supprimer");
  $formulaire.=finform();
  echo $formulaire;
?>
</body>
