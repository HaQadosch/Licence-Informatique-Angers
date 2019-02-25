/////////////// connexion.php //////////
<?php 



function connectTo($string){
$sgbd="mysql";
$host="localhost";
$user="root";
$pass="YR8488";
	$pdo=new PDO("$sgbd:host=$host;dbname=$string;charset=utf8",$user,$pass);
	return $pdo;
}

?>

///////////////////test.php/////////

<?php	 

   include("connexion.php");
   $objdb = connectTo("Sportifs");
   $requete = "SELECT * FROM personne";
   $result = $objdb->query($requete);
    var_dump($result);

?>
