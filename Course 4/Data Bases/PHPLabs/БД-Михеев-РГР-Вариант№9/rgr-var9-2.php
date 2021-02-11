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
                print '<form action="rgr-var9-2.php" method="post">';
                print '<label for="task_entry">Вывести список ОС, кроме: </label>';
                print '<select name="task_entry[]">';
                print '<option value="first">первого</option>';
                print '<option value="last">последнего</option>';
                print '</select>';
                print ' по алфавиту типа.<br>';
                print '<button type="submit">Вывести</button>';
                print '</form>';
        }
        elseif(!empty($_POST['task_entry']))
        {
            $sql_query_1 = "SELECT ostype FROM T2;";
            $result = mysqli_fetch_all(mysqli_query($link, $sql_query_1));
            $res = array();
            foreach($result as $row)
                $res[] = $row[0];
            if($_POST['task_entry'][0] == "first")
            {
                sort($res);
                $sql_query_2 = "SELECT osname FROM T2 WHERE ostype!='".$res[0]."';";
                $result = mysqli_query($link, $sql_query_2);
                if($result)
                    while($row = mysqli_fetch_assoc($result)) 
                    {
                        foreach($row as $value) 
                            print $value."<br>";
                    }
                else
                    print "Ошибка: ".mysqli_error($link);
            }
            elseif($_POST['task_entry'][0] == "last")
            {
                rsort($res);
                $sql_query_2 = "SELECT osname FROM T2 WHERE ostype!='".$res[0]."';";
                $result = mysqli_query($link, $sql_query_2);
                if($result)
                    while($row = mysqli_fetch_assoc($result)) 
                    {
                        foreach($row as $value) 
                            print $value."<br>";
                    }
                else
                    print "Ошибка: ".mysqli_error($link);
            }
            else
                print "Непредвиденная ошибка, как вы это сделали?";
        }
        else
            print "Непредвиденная ошибка, как вы это сделали?";

        mysqli_close($link);
    ?>
</body>
</html>