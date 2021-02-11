<html> <head>
<title> Листинг 14-3. Применение функции preg_match() 
</title> 
</head> 
<body>
 
<?php
if (preg_match ("/\bweb\b/i", "World Wide Web")) 
     {print "<p>Строка найдена.";} 
else {print "<p>Строка не найдена.";}
if (preg_match ("/\bweb\b/i", "PHP is the website 
                 scripting language.")) 
     {print "<p>Строка найдена.";} 
else {print "<p>Строка не найдена.";}
?> </body> </html>
