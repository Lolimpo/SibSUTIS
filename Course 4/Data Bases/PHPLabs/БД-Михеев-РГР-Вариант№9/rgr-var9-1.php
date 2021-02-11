<?php
    $link = mysqli_connect("localhost", "root", "", "rgr");
    if (mysqli_connect_errno()) 
    {
		printf("Не удалось подключиться: %s\n", mysqli_connect_error());
    	exit();
    }
?>

<html>
<head>
    <title>РГР-Михеев-Вар.9</title>
</head>
<body>
    <?php
        if(empty($_POST['task_entry']))
        {
                print '<form action="rgr-var9-1.php" method="post">';
                print '<label for="task_entry">Выберите тип ОС: </label>';
                print '<select name="task_entry[]">';
                print '<option value="Win">Win</option>';
                print '<option value="Unix">Unix</option>';
                print '<option value="Mac">Mac</option>';
                print '</select>';
                print '<button type="submit">Вывести</button>';
                print '</form>';
        }
        elseif(!empty($_POST['task_entry']))
        {
            $sql_query = "SELECT * FROM T2_2 WHERE ostype='".$_POST['task_entry'][0]."';";
            $result = mysqli_fetch_all(mysqli_query($link, $sql_query));
            if($result) 
                print "Число строк содержащих данные об ОС типа ".$_POST['task_entry'][0].": ".count($result);
            else 
                print "Ошибка: ".mysqli_error($link);
        }
        else
            print "Непредвиденная ошибка, как вы это сделали?";
        mysqli_close($link);
    ?>
</body>
</html>