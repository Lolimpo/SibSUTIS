<?php
    const NUM_E = 2.71828;
    print "Number e equals " . NUM_E . '<br/>';

    $num_e1 = NUM_E;
    print gettype($num_e1) . ' ' . $num_e1 . '<br/>';
    
    settype($num_e1, string);
    print gettype($num_e1) . ' ' . $num_e1 . '<br/>';

    settype($num_e1, integer);
    print gettype($num_e1) . ' ' . $num_e1 . '<br/>';

    settype($num_e1, bool);
    print gettype($num_e1) . ' ' . $num_e1 . '<br/>';
?>