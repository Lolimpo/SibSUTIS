<html> <head>
<title> Листинг 14-1. Применение функции ereg() 
</title> </head> <body>
<?php
$url = "http://www.ngs.ru";
// Разделить $url на три компонента: 
// "http://www", "ngs" и "ru"
$www_url = ereg("^(http://www)\.([[:alnum:]]+)\.([[:alnum:]]+)", 
     $url, $regs);
if ($www_url) { // Если переменная $www_url содержит URL
foreach ($regs as $val) {print "<p>$val";} 
}
?>
</body> </html>
