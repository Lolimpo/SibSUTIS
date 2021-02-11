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
                print '<form action="rgr-var9-3.php" method="post">';
                print '<label for="task_entry">Выберите фирму-производителя: </label>';
                print '<select name="task_entry[]">';
                print '<option value="Microsoft">Microsoft</option>';
                print '<option value="UnixF">UnixF</option>';
                print '<option value="Jobbs">Jobbs</option>';
                print '<option value="Apple">Apple</option>';
                print '</select>';
                print '<button type="submit">Вывести</button>';
                print '</form>';
        }
        elseif(!empty($_POST['task_entry']))
        {
            $sql_query = "SELECT DISTINCT(b.osname) 
                FROM `t2` AS a, `t2` AS b 
                WHERE a.oscreator = '".$_POST['task_entry'][0]."' 
                AND a.ostype = b.ostype";
            $result = mysqli_query($link, $sql_query);
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

        mysqli_close($link);
    ?>
</body>
</html>