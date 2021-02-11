<?php

    $cust = array(
        'cnum' => 2001,
        'cname' => "Hoffman",
        'city' => "London",
        'snum' => 1001,
        'rating' => 100
    );
    
    print "1:<br>";
    foreach ($cust as $key => $val)
    {
        print "$key: $val<br>";
    }  

    print "<br>2:<br>";
    asort($cust);
    foreach ($cust as $key => $val)
    {
        print "$key: $val<br>";
    } 

    print "<br>3:<br>";
    ksort($cust);
    foreach ($cust as $key => $val)
    {
        print "$key: $val<br>";
    } 

    print "<br>4:<br>";
    sort($cust);
    foreach ($cust as $key => $val)
    {
        print "$key: $val<br>";
    } 
?>