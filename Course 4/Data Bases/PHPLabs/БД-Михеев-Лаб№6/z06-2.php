<html> 
<head>
    <title>z06-2</title>
 </head> 
<body> 
<?php
	$color = 'blue';
	print '<table cellpadding=5, border=1>';
	for($i = 0; $i < 10; $i++) {	
		print '<td align="center">';
		if($i == 0)
			print '<font color = "red"> + ';
		else
			print '<font color = "'.$color.'">'.($i + 1);
		print '</td>';
	}

	for($i = 1; $i < 10; $i++){
		print '<tr>';
		for($j = 0; $j < 10; $j++) {
			print '<td align="center">';
			if($j == 0)
				print '<font color = "'.$color.'">'.($i + ($j+1)).'</font>';
			else
				print (($i+1) + ($j+1));
			print '</td>';
		}

		print '</tr>';
	}
	print '</table>';
?>
</body> 
</html>
