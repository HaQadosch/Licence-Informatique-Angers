//EXO1
<?php
	$fic=fopen("./logs.txt","a+");
	if(!$fic) die("unable to create file");
	$date=date("d/M H:m:s",time());
	fwrite($fic,$date."\n");
	fclose($fic);
?>
//EXO2
