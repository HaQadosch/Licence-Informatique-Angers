<?php

//Définition de la fonction form
function form($action,$methode,$legend)
{
    $code ="<form action=\"$action\" method=\"$methode\" >\n";
    $code.="<fieldset><legend>$legend</legend>\n";
    return $code;
}

//Définition de la fonction text
function text($libtexte,$nomtexte)
{
    $code="<label><b> $libtexte </b></label> <input type=\"text\" name=\"$nomtexte\" /><br />\n";
    return $code;
}

//Définition de la fonction number
function number($libtexte,$nomnumber,$step,$size,$def)
{
    $code="<label><b> $libtexte </b></label> <input type=\"number\" step=\"$step\" name=\"$nomnumber\" size=\"$size\" value=\"$def\" />\n";
    return $code;
}

//Définition de la fonction radio
function radio($libradio,$nomradio,$valradio)
{
    $code="<label><b> $libradio </b></label><input type=\"radio\" name=\"$nomradio\" value=\"$valradio\" /><br />\n";
    return $code;
}

//definition de la fonction mail
function form_mail($libmail,$nommail){
    $code="<label><b> $libmail </b></label> <input type=\"mail\" name=\"$nommail\" /><br />\n";
    return $code;
}

//definition de la fonction tel
function tel($libtel,$nomtel){
    $code="<label><b> $libtel </b></label> <input type=\"tel\" name=\"$nomtel\" /><br />\n";
    return $code;
}

//definition de la fonction password
function passsword($libpswd,$nompswd){
    $code="<label><b> $libpswd </b></label> <input type=\"password\" name=\"$nompswd\" /><br />\n";
    return $code;
}
//definition de la fonction date
function form_date($libdate,$nomdate){
    $code="<label><b> $libdate </b></label> <input type=\"date\" name=\"$nomdate\" /><br />\n";
    return $code;
}

//definition de la fonction checkbox
function checkbox($libcheck,$nomcheck){
    $code="<label><b> $libcheck </b></label> <input type=\"checkbox\" name=\"$nomcheck\" /><br />\n";
    return $code;
}

//definition de la fonction form_file
function form_file($libfile,$nomfile,$typefile="",$multipleFile=""){
    $code="<label><b> $libfile </b></label> <input type=\"file\" name=\"$nomfile\" ";
    if($typefile!=""){
      $code.="accept=\"$typefile\" ";
    }
    if($multipleFile!=""){
      $code.="multiple";
    }
    $code.="/><br />\n";
    return $code;
}

//definition de la fonction debut_select
function debut_select($libselect,$nomselect,$sizeselect=""){
    $code="<label><b> $libselect </b></label> <select name=\"$nomselect\" ";
    if($sizeselect!=""){
      $code.=" size=\"$sizeselect\" ";
    }
    $code.= "><br />\n";
    return $code;
}

//definition de la fonction option
function option_select($optnom){
  $code="<option> $optnom \n";
  return $code;
}

//definition de la fonction default_option
function default_option_select($optnom){
  $code="<option selected> $optnom \n";
  return $code;
}

//definition de la fonction fin_select
function fin_select(){
    $code="</select>\n";
    return $code;
}

//Définition de la fonction submit
function submit($nomsubmit,$value,$libsubmit="")
{
    $code="<input type=\"submit\" name=\"$nomsubmit\" value=\"$value\" />&nbsp;&nbsp;&nbsp;\n";
    if($libsubmit!="")
        $code ="<label><b> $libsubmit </b></label> ".$code;
    return $code;
}

//Définition de la fonction reset
function breset($libreset)
{
    $code.="<input type=\"reset\" value=\"$libreset\" /><br />\n";
    return $code;
}

//Définition de la fonction finform
function finform()
{
    $code="</fieldset></form>\n";
    return $code;
}
?>
