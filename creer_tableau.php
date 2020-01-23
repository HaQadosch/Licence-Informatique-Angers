<?php 
$articles=range("A","K");
$TVA=[0.05,010,0.20];
$taux_TVA=array_fill_keys($articles,0);

function initialize(){
	global $TVA;
	return ["prix"=>rand(0,100),"taux"=> $TVA[rand(0,2)]];
}

$prix_taux=array_map("initialize",$taux_TVA);

echo '<pre>'; print_r($prix_taux); echo '</pre>';
?>
