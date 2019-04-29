<!DOCTYPE html >
<html>
<head>
<meta charset="UTF-8" />
<title>Liste des inscrits</title>
<style type="text/css">
table, th, td {
	border-collapse: collapse;
	border-style: solid;
	border-width: 1px;
	text-align: left;
}

td {
	width: 100px;
}
</style>
</head>
<body>
<?php
require ("connexpdo.inc.php");
require ("afficher-tableau.php");
$idcom = connexpdo("l2_tp_personne");
// removing field 'pwd2'
$fields = array_filter($_POST['person'], function ($v, $k) {
    return $k != 'pwd2' && ! empty($v);
}, ARRAY_FILTER_USE_BOTH);
// adding/setting column value for checkbox 'news'
$fields['news'] = array_key_exists('news', $fields) ? 1 : 0;
$href = "formulaire.html";

if (count($fields) == 8) {
    // setting column value (type enumeration) for input field 'gender'
    $fields['gender'] = ($fields['gender'] === 'H') ? 'Homme' : 'Femme';
    // setting column value (type enumeration) for select field 'country'
    switch ($fields['country']) {
        case 'en':
            $fields['country'] = 'ANGLETERRE';
            break;
        case 'fr':
            $fields['country'] = 'FRANCE';
            break;
        case 'us':
            $fields['country'] = 'ETATS-UNIS';
            break;
        default:
            $fields['country'] = '';
            break;
    }
    // setting column value (type int) for input field 'age'
    $fields['age'] = (int) $fields['age'];
    
    try {
        $columns = [
            'GENRE',
            'NOM',
            'PRENOM',
            'AGE',
            'LOGIN',
            'MOTDEPASSE',
            'PAYS',
            'NEWSLETTER'
        ];
        $columnsQ = implode(',', $columns);
        $markers = implode(',', array_map(function ($v) {
            return ':' . $v;
        }, array_keys($fields)));
        $query = "INSERT INTO Personne (" . $columnsQ . ") VALUES ($markers)";
        $sth = $idcom->prepare($query);
        if (! $sth->execute($fields)) {
            alert("Erreur : \"$idcom->errorCode()\"");
        } else {
            $sth1 = $idcom->query("SELECT " . $columnsQ . " FROM Personne");
            $records = $sth1->fetchAll(PDO::FETCH_ASSOC);
            affiche_tableau($records);
            echo "<h3><a href='{$href}'>Retour au formulaire</a></h3>";
        }
    } catch (PDOException $e) {
        displayException($e);
        exit();
    }
} else {
    echo "<h3><a href='{$href}'>Formulaire à compléter!</a></h3>";
}
$idcom = null;
?>
</body>
</html>
