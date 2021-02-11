<html> 
    <head>
        <title> Листинг 3-1. Проверка и изменение типа переменной </title> 
    </head> 
    <body> 
        <?php
        $var = 3.14;
        print gettype($var);    // double 
        print " - $var<br>";    // 3.14 
        settype($var, "string"); 
        print gettype($var);    // string 
        print " - $var<br>";    // 3.14 
        settype($var, "integer"); 
        print gettype($var);    // integer 
        print " - $var<br>";    // 3 
        settype($var, "double"); 
        print gettype($var);   // double
        print " - $var<br>";   // 3
        settype($var, "boolean");
        print gettype($var);   // boolean
        print " - $var<br>";   // 1
        ?>
    </body> 
</html>
