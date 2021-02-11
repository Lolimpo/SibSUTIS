<?php
    print "<table border='1' cellpadding='0'>";

    for($i = 1; $i <= 30; $i++)
    {
        print "<tr>";
        for($j = 1; $j <= 30; $j++)
        {
            $num = $i * $j;
            if($num % 7 == 0)
                $color = "white";
            elseif ($num % 7 == 1) 
                $color = "aqua";
            elseif ($num % 7 == 2) 
                $color = "blue";
            elseif ($num % 7 == 3) 
                $color = "yellow";
            elseif ($num % 7 == 4) 
                $color = "purple";
            elseif ($num % 7 == 5) 
                $color = "red";
            else 
                $color = "lime";
            print "<td width='14', height='15' bgcolor=$color>";
            print "<font size='1'>&nbsp;</font>";
            print "</td>";
        }
        print "</tr>";
    }
    print "</table>";
?>