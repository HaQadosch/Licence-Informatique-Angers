<?php

     ## lecture de villes.txt et comptages du mot Angers

     $fn = "villes.txt" ;
     if (!file_exists($fn)) {
       echo  "\nLe fichier $fn n'existe pas. Stop.\n" ;
       exit(-1) ;
     } ; # fin si

     # lecture et remplacement des caractères spéciaux par espace
     # au passage, on convertit en minuscule

     $contenu = "" ;
     $fh      = fopen($fn,"r") ;
     $symb    = array(",",".","'","\n") ;
     while ($lig = fgets($fh,4096)) {
       $contenu .= "   ".str_replace($symb,"  ",strtolower($lig))."   " ;
     } ; # fin tant que
     fclose($fh) ;

     # recherche des occurrences d'Angers

     $nbAngers   = 0 ;
     $lngContenu = strlen($contenu) ;
     $idc        = 0 ;
     while ($idc<=$lngContenu) {
       $jdc = strpos($contenu," angers ",$idc) ;
       if ($jdc>0) {
         $nbAngers++ ;
         $idc = $jdc + 6 ;  # car angers a 6 lettres
       } else {
         $idc++ ;
       } ; # fin si
     } ; # fin tant que
     echo " Angers est vu $nbAngers fois dans le fichier $fn.\n" ;
?>

SOLUCE 2 

<?php

     ## lecture de villes.txt et comptages du mot Angers

     $fn = "villes.txt" ;

     if (!file_exists($fn)) {
       echo  "\nLe fichier $fn n'existe pas. Stop.\n" ;
       exit(-1) ;
     } ; # fin si

     $contenu  = file_get_contents($fn) ;
     $symb     = array(",",".","'","\n") ;
     $contenu  = " ".str_replace($symb," ",$contenu)." " ;
     $nbAngers = preg_match_all("/ angers /i",$contenu,$vu) ;

     echo " Angers est vu $nbAngers fois dans le fichier $fn.\n" ;

?>

SOLUCE 3 utilise des fonctions

<?php

 function angers($x="") {
   return( strtolower($x)=="angers" ) ;
 } ; # fin fonction angers

 ## lecture de villes.txt et comptages du mot Angers

 $fn = "villes.txt" ;

 if (!file_exists($fn)) {
   echo  "\nLe fichier $fn n'existe pas. Stop.\n" ;
   exit(-1) ;
 } ; # fin si

 $contenu  = file_get_contents($fn) ;
 $symb     = array(",",".","'","\n") ;
 $contenu  = " ".str_replace($symb," ",$contenu)." " ;
 $mots     = preg_split("/\s+/",$contenu) ;
 $tangers  = array_filter($mots,"angers") ;
 $nbAngers = count($tangers) ;

 echo " Angers est vu $nbAngers fois dans le fichier $fn.\n" ;

?>
