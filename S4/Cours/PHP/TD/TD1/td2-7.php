<?php
echo "TRUE s'affiche par ",TRUE,"<br />";
echo "FALSE s'affiche par ",FALSE,"<br />";
echo "==============<br/>";
function bool($val)
{
    if($val) echo "TRUE <br />";
    else echo "FALSE <br />";
}
//********************
$a="0";
echo "\$a vaut : ",bool($a);
$b="TRUE";
echo "\$b vaut : ",bool($b);
$c=FALSE;
echo "\$c vaut : ",bool($c);
$d=($a OR $b);
echo "\$d vaut : ",bool($d);
$e=($a AND $c);
echo "\$e vaut : ",bool($e);
$f=($a XOR $b);
echo "\$f vaut : ",bool($f);
?>