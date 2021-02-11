<html> 
<head>
<title> Листинг 10-4. Обработка данных формы 
		из листинга 10-3 
</title> 
</head> 
<body> 
	<?php  
		print "<p>$user, оказывается, вы предпочитаете";
		print "<ul>\n";
		
		foreach ($HTTP_POST_VARS as $key=>$value)
			print "$key = $value<br>\n";
   
		print "</ul>\n";
	?>
</body> 
</html> 
