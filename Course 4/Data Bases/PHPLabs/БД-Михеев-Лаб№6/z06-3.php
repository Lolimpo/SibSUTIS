<html> 
<head>
    <title>z06-3</title>
 </head> 
<body> 
<?php
	function Ru($color) {
	    print '<font color="'.$color.'">Здравствуйте!</font>';
	}

	function En($color) {
	    print '<font color="'.$color.'">Hello!</font>';
	}

	function Fr($color) {
	    print '<font color="'.$color.'">Bonjour!</font>';
	}

	function De($color) {
	    print '<font color="'.$color.'">Guten Tag!</font>';
	}

	$lang = $_GET['lang'];
	$color = $_GET['color'];
	$lang($color);
?>
</body> 
</html>
