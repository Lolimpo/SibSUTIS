<?php
    $filename = "notebook_br09.txt";
    if(file_exists($filename))
        print 'File '.$filename.' exists on a server<br>';
    else
    {
        print 'No such file. Creating...<br>';
        touch($filename);
    }

    $file_array = file($filename)
		or die('Could not read from file "'.$filename);
?>

<!DOCTYPE HTML>
<html>
<body>
    <?php
        print '<b>Моя записная книжка</b>';
		print '<table cellpadding="10" border = "1">';
        foreach($file_array as $line) 
        {
			$line = rtrim($line, " | \r\n");
			$line = preg_replace("/(\S+@\S+)/", '<a href="mailto:${1}">${1}</a>', $line);
			$line = str_replace(' | ', '</td><td align="center">', $line);
			print '<tr><td align="center">' . $line . '</td></tr>';
		}
		print '</table>';
		print '<br>Дата последней записи: '.date('D d M Y h:i:s', fileatime($filename));
	?>
</body>
</html>