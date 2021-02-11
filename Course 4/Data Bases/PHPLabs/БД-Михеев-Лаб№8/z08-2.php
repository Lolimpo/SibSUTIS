<!DOCTYPE HTML>
<html>
	<body>
		<table border="1" align="center">
			<tr>
			<?php
				if (empty($_GET['align']) || empty($_GET['valign']))
    				print '<td width="100" height="100" align="left" valign="top">Text</td>';
    			else
					print '<td width="100" height="100" align="'.$_GET['align'].' "valign="'.$_GET['valign'].'">Text</td>';
			?>
			</tr>
		</table>
		<br>
		<form action = "z08-2.php" method = "GET" style="width: 250px; margin: auto;">
			<b>Choose horizontal alignment:</b>
			<p><input type = "radio" name = "align" value = "left">Left<br>
			<p><input type = "radio" name = "align" value = "center">Middle<br>
			<p><input type = "radio" name = "align" value = "right">Right<br>
			<br><b>Choose vertical alignment:</b>
			<p><input type = "checkbox" name = "valign" value = "top">Top<br>
			<p><input type = "checkbox" name = "valign" value = "middle">Middle<br>
			<p><input type = "checkbox" name = "valign" value = "bottom">Bottom<br>
			<p><input type = "submit" value = "Send"><br>
		</form>
	</body>
</html>