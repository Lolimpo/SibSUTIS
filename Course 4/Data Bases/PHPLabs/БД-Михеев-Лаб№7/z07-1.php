<?php
    for ($n = 1; $n <= 10; $n++) {
        $treug[] = $n * ($n + 1) / 2;
    }
    print "treug: ";
    foreach ($treug as $t) {
        print "$t&nbsp;&nbsp;";
    }
    print "<br>";

    for($n = 1; $n <= 10; $n++)
    {
        $kvd[] = $n * $n;
    }
    print "kvd: ";
    foreach ($kvd as $k) {
        print "$k ";
    }
    print "<br>";

    print "rez: ";
    $rez = array_merge($treug, $kvd);
    foreach ($rez as $r) {
        print "$r ";
    }
    print "<br>";

    print "rez_sort: ";
    sort($rez);
    foreach ($rez as $r) {
        print "$r ";
    }
    print "<br>";

    print "rez_shift: ";
    array_shift($rez);
    foreach ($rez as $r) {
        print "$r ";
    }
    print "<br>";

    print "res_unique: ";
    $rez1 = array_unique($rez);
    foreach ($rez1 as $r1) {
        print "$r1 ";
    }
?>