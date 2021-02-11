<?php
	$link = mysqli_connect("localhost", "root", "", "sample");
	if (mysqli_connect_errno()) 
	{
		printf("Не удалось подключиться: %s\n", mysqli_connect_error());
		exit();
	}

	if (isset($_POST['id']) && isset($_POST['field_name'])) 
	{
		$upd_query = "UPDATE notebook_br09 SET {$_POST['field_name']} = '{$_POST['field_value']}' WHERE id = {$_POST['id']}";
		mysqli_query($link, $upd_query);
		$query = "SELECT * FROM notebook_br09";
		$result = mysqli_query($link, $query);
		if (mysqli_num_rows($result) > 0) 
		{
			print "<html>
			   		<body>
			   			<form action='' method=post>
			   			<table border=1>
			   				<tr>
			   					<td><b>id</b></td>
			   					<td><b>name</b></td>
			   					<td><b>city</b></td>
			   					<td><b>address</b></td>
			   					<td><b>birthday</b></td>
			   					<td><b>mail</b></td>
			   					<td><b>исправить</b></td>
			   				</tr>";
			while ($row = mysqli_fetch_assoc($result)) 
			{
				print "<tr><td>".$row['id'].
					"</td><td>".$row['name'].
					"</td><td>".$row['city'].
					"</td><td>".$row['address'].
					"</td><td>".$row['birthday'].
					"</td><td>".$row['mail'].
					"</td><td><input type=radio name=id id=radioChangeButton value=".$row['id'].">
					<label for=radioChangeButton></label>";
			}
			print "</td></tr></table><br><button type=submit>Отправить</button></form></body></html>";
		} 
		else 
		{
			print "0 results";
		}
	} 
	elseif(isset($_POST['id']))
	{
		$query = "SELECT * FROM notebook_br09 WHERE id = " .$_POST['id']; 
		$result = mysqli_query($link, $query);
		if (mysqli_num_rows($result) > 0) {
			print "<form action='' method=post><p><select size=1 name=field_name>";
			$row = mysqli_fetch_assoc($result);
			$id = $row['id'];
			print "<option value=name>".$row['name']."</option>
					<option value=city>".$row['city']."</option>
					<option value=address>".$row['address']."</option>
					<option value=birthday>".$row['birthday']."</option>
					<option value=mail>".$row['mail']."</option>
				</select>  введите новое значение: <input type=text name=field_value></p><p><button type=submit>Заменить</button></p><input type=hidden name=id value=$id></form>";
		}
	} 
	else 
	{
		$query = "SELECT * FROM notebook_br09";
		$result = mysqli_query($link, $query);
		if (mysqli_num_rows($result) > 0) 
		{
			print "<html>
			   		<body>
			   			<form action='' method=post>
			   			<table border=1>
			   				<tr>
			   					<td><b>id</b></td>
			   					<td><b>name</b></td>
			   					<td><b>city</b></td>
			   					<td><b>address</b></td>
			   					<td><b>birthday</b></td>
			   					<td><b>mail</b></td>
			   					<td><b>исправить</b></td>
			   				</tr>";
			while ($row = mysqli_fetch_assoc($result)) 
			{
				print "<tr><td>".$row['id'].
					"</td><td>".$row['name'].
					"</td><td>".$row['city'].
					"</td><td>".$row['address'].
					"</td><td>".$row['birthday'].
					"</td><td>".$row['mail'].
					"</td><td><input type=radio name=id id=radioChangeButton value=".$row['id'].">
					<label for=radioChangeButton></label>";
			}
			print "</td></tr></table><br><button type=submit>Отправить</button></form></body></html>";
		} 
		else 
		{
			print "0 results";
		}
	}
	
	mysqli_close($link);
?>