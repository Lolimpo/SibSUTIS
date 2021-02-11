<?php
	$link = mysqli_connect("localhost", "root", "", "sample");
	if (mysqli_connect_errno()) 
	{
		printf("Не удалось подключиться: %s\n", mysqli_connect_error());
    	exit();
	}

	mysqli_query($link, "DROP TABLE IF EXISTS notebook_br09");
	$sql = "CREATE TABLE notebook_br09 (
		id int not null auto_increment primary key, 
		name varchar(50), 
		city varchar(50), 
		address varchar(50), 
		birthday DATE, 
		mail VARCHAR(20))";

	if (mysqli_query($link, $sql)) 
	{
	  print "Таблица успешно создана";
	} 
	else 
	{
	  print "Нельзя создать таблицу notebook_br09";
	}

	mysqli_close($link);
?>