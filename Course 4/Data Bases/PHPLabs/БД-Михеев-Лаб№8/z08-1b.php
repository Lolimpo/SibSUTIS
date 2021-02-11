<!DOCTYPE HTML>
<html>
	<body>
		<table border="1" align="center">
			<tr>
			<?php
				if (empty($_GET['align']) || empty($_GET['valign']))
    				print '<td width="100" height="100" align="center" valign="middle">Text</td>';
    			else
					print '<td width="100" height="100" align="'.$_GET['align'].' "valign="'.$_GET['valign'].'">Text</td>';
			?>
			</tr>
		</table>
		<a style="text-align:center;display:block;" href = "z08-1a.html">Back</a> 
	</body>
</html>