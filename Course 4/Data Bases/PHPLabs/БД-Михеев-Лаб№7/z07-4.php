<?php

    $colors = array("white","aqua","blue","yellow","purple","red","lime");
    for($k = 4; $k <= 7; $k++)
    {
        print "k = $k";
        print "<table border='1' cellpadding='0'>";
        for($i = 1; $i <= 30; $i++)
        {
            print "<tr>";
            for($j = 1; $j <= 30; $j++)
            {
                $num = $i * $j;
                $color = $colors[($num % $k)];
                print "<td width='14', height='15' bgcolor=$color>";
                print "<font size='1'>&nbsp;</font>";
                print "</td>";
            }
            print "</tr>";
        }
        print "</table>";
    }
    
?>