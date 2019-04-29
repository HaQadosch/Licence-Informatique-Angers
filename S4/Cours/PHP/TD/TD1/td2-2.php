<?php
$x="PostgreSQL";
$y="MySQL";
$z=&$x;
$x="PHP 5";
$y=&$x;
echo '$x vaut ',$x,"<br/>";
echo '$y vaut ',$y,"<br/>";
echo '$z vaut ',$z,"<br/>";
?>