<html> 
<head>
    <title>z06-4</title>
 </head> 
<body> 
<?php
	$size = 7;
	function WeekDay($day, $color) 
	{
		global $size;
		print "<font color='$color', size='$size'>$day</br>";
		$size--;
	}

	WeekDay("Понедельник", "black");
	WeekDay("Вторник", "gray");
	WeekDay("Среда", "dark-blue");
	WeekDay("Четверг", "blue");
	WeekDay("Пятница", "orange");
	WeekDay("Суббота", "pink");
	WeekDay("Воскресенье", "red");
?>
</body> 
</html>
