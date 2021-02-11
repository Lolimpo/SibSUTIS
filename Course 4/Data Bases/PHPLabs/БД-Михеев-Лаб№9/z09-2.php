<?php
	$record = $_POST['record'];
	
	if ($record['name'] == "" || $record['email'] == "") 
	{
		print "<html><body><p>Поля, помеченные[*], являются обязательными для заполнения!</p></body></html>";
		exit();
	} 

	$link = mysqli_connect("localhost", "root", "", "sample");
	if (mysqli_connect_errno()) 
	{
		printf("Не удалось подключиться: %s\n", mysqli_connect_error());
		exit();
	}
	$sql = "INSERT INTO notebook_br09 (name, city, address, birthday, mail) 
	VALUES ('{$record['name']}', 
			'{$record['city']}', 
			'{$record['address']}', 
			'{$record['dob']}', 
			'{$record['email']}'
			)";
		
	if (mysqli_query($link, $sql)) 
	{
	  	print "Запись добавлена успешно.";
	} 
	else 
	{
	  	print "Неудалось добавить запись в таблицу.";
	}	
	mysqli_close($link);
?>