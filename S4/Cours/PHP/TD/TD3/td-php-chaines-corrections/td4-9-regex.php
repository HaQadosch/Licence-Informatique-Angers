<?php
$ch="PHP  \n est meilleur \n que ASP \n et JSP \n réunis";
$modele="/\n/";
$nouveau="/<br />/";
echo preg_replace("/\n/","<br />",$ch);
?>