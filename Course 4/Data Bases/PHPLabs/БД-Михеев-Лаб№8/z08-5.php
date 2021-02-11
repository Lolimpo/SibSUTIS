<?php
	if(!empty($_POST['site']))
		header("Location: $_POST[site]");

	$list_sites = array(
		'www.yandex.ru' => "https://www.yandex.ru", 
		'www.google.ru' => "https://www.google.ru", 
		'www.rambler.ru' => "https://www.rambler.ru",
		'www.yahoo.com' => "https://www.yahoo.com/",
		'www.altavista.com' => "https://www.altavista.com/"
	);
?>

<!DOCTYPE HTML>
<html>
	<body>
		<form action = "index.php" method = "POST">
			<select name="site">
				<option value="">Поисковые системы:</option>
				<?php 
					foreach($list_sites as $name => $site)
				 		echo '<option value='.$site.'>'.$name.'</option>';
				?>
			</select>
            <input type = "submit" value = "Перейти">
		</form>
	</body>
</html>