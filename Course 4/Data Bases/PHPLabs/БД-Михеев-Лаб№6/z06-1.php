<html> 
    <head>
        <title>z06-1</title>
    </head> 
    <body> 
	<?php
	$i = 0;
	$color = 'silver';

	print '<table cellpadding=5, border = "1">';
	while($i < 10) 
	{
		$j = 0;
		echo '<tr>';
		while($j < 10) 
		{
			if($i == $j)
				print '<td align="center" bgcolor = "'.$color.'">'.($i + 1) * ($j + 1).'</td>';
			else
				print '<td align="center">'.($i + 1) * ($j + 1).'</td>';
			$j++;
		}
		$i++;
		print '</tr>';
	}
	print '</table>';
	?>
    </body> 
</html>
