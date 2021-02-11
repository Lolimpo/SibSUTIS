<?php
    $record = $_POST['record'];
    if(count($record) == 0)
    {
        print "Ни один столбец не был запрошен. <br><a href='rgr-2.php'>Назад</a>";
        exit();
    }

    $link = mysqli_connect("localhost", "root", "", "rgr");
    if (mysqli_connect_errno()) 
    {
		printf("Не удалось подключиться: %s\n", mysqli_connect_error());
    	exit();
    }

    $sql_request_handler = "SELECT ";
    foreach($record as $col)
    {
        $sql_request_handler .= $col.", ";
    }

    $sql_request_handler = substr($sql_request_handler, 0, -2)." FROM T2;";
    $result = mysqli_query($link, $sql_request_handler);
    if($result) 
    {
        print "<table border='2'><tr>";
        foreach($record as $col_name)
            print "<td>".$col_name."</td>";
        print "</tr>";
        while($row = mysqli_fetch_assoc($result)) 
        {
            print "<tr>";
            foreach($row as $value) 
                print "<td>".$value."</td>";
            print "</tr>";
        }
        print "</table>";
        print "<br><a href='rgr-2.php'>Назад</a>";
    } 
    else 
        print "Ошибка: ".mysqli_error($link);

    mysqli_close($link);
?>