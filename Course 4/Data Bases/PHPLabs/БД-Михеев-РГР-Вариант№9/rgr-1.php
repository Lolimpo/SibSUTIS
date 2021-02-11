<?php
    $link = mysqli_connect("localhost", "root", "", "rgr");
    if (mysqli_connect_errno()) 
    {
		printf("Не удалось подключиться: %s\n", mysqli_connect_error());
    	exit();
    }

    mysqli_query($link, "DROP TABLE IF EXISTS `T2`");

    $sql_query_create = "CREATE TABLE IF NOT EXISTS `T2`
        (
            `num` INT NOT NULL AUTO_INCREMENT PRIMARY KEY UNIQUE, 
            `osname` VARCHAR(10) NOT NULL, 
            `ostype` VARCHAR(6) NOT NULL, 
            `oscreator` VARCHAR(20) NOT NULL
        )";
    if(mysqli_query($link, $sql_query_create)) 
    {
        print "Таблица успешно создана.<br>";
    } 
    else 
    {
        print "Ошибка: ".mysqli_error($link);
        exit();
    }

    $sql_query_insert = "INSERT INTO `T2_2` VALUES 
        ('1', 'Win95', 'Win', 'Microsoft'),
        ('2', 'Win98', 'Win', 'Microsoft'),
        ('3', 'WinNT', 'Win', 'UnixF'),
        ('4', 'WinXP', 'Win', 'Apple'),
        ('5', 'Unix', 'Unix', 'UnixF'),
        ('6', 'FreeBSD', 'Unix', 'Jobbs'),
        ('7', 'Linux', 'Unix', 'UnixF'),
        ('8', 'MacOS1', 'Mac', 'Apple'),
        ('9', 'MacOS2', 'Mac', 'Apple'),
        ('10', 'MacOS3', 'Mac', 'Jobbs');
    ";
    if(mysqli_query($link, $sql_query_insert)) 
    {
        print "Таблица успешно заполнена.<br>";
    } 
    else 
    {
        print "Ошибка: ".mysqli_error($link);
        exit();
    }

    mysqli_close($link);
?>