<?php
    for ($n = 0; $n <= 30; $n++) 
    {
        $treug[] = $n * ($n + 1) / 2;
        $kvd[] = $n * $n;
    }

    print "<table border = '1'>\n";

    for($i = 1; $i <= 30; $i++)
    {
        print "<tr>";
        for($j = 1; $j <= 30; $j++) 
        {
            $sum = $i * $j;
            if(array_search($sum, $treug) && array_search($sum, $kvd)) 
                $color = "red";
            elseif(array_search($sum, $treug)) 
                $color = "green";
            elseif(array_search($sum, $kvd)) 
                $color = "blue";
            else
                $color = "white";
            print "<td bgcolor=$color>";
            print "<font size='1'>$sum</font>";
            print "</td>";
        }
        print "</tr>";
    }
    print "</table>";

    foreach ($treug as $t) {
        print "$t  ";
    }
?>