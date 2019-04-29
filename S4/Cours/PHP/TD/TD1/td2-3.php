<?php
$x="PostgreSQL";
$y="MySQL";
$z=&$x;
$x="PHP 5";
$y=&$x;
echo $GLOBALS['x'], "<br />";
echo $GLOBALS['y'], "<br />";
echo $GLOBALS['z'], "<br />";

$GLOBALS['x'] = 48;
echo $x, "<br />";

?>