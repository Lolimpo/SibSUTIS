<html> <head>
<title> Листинг 10-3. HTML-форма с выбором из списка 
</title> </head> <body>
<!--
Здесь в скрипт ls10-4.php передаются: 
1) переменная $user 
2) массив hobby[] со значениями, которые были выбраны 
   в форме
-->
<form action="ls10-7.php" method="POST">
<p>Введите ваше имя
<p><input type="text" name="user">
<p>Что вы любите делать в свободное время <br>
   (можно выбрать несколько вариантов)
<select name= "hobby[]" multiple> <option value="лежать на диване">лежать на диване 
    <option value="читать книгу">читать книгу 
    <option value="смотреть телевизор">смотреть телевизор 
    <option value="гулять на улице">гулять на улице 
</select>
<p><input type="submit" value="Выбор сделан">
</form>
</body> </html>
