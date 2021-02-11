<html>
<head>
    <title>РГР-Михеев-Вар.9</title>
</head>
<body>
    <h4><font style="bold">Выберите столбец для отображения</font></h4>
    <form action="rgr-3.php" method="post">
        <input type="checkbox" checked name="record[]" value="num"/>Номер<br>
        <input type="checkbox" name="record[]" value="osname"/>Название ОС<br>
        <input type="checkbox" name="record[]" value="ostype"/>Тип ОС<br>
        <input type="checkbox" name="record[]" value="oscreator"/>Создатель ОС<br>
        <button type="submit">Вывести</button>
    </form>
</body>
</html>