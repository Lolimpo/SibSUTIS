<?php
    $filename = "notebook_br09.txt";
    if(file_exists($filename))
        print 'File '.$filename.' exists on a server<br>';
    else
    {
        print 'No such file. Creating...<br>';
        touch($filename);
    }

    $link = mysqli_connect("localhost", "root", "", "sample");
    if (mysqli_connect_errno())
    {
        printf("Не удалось подключиться: %s\n", mysqli_connect_error());
        exit();
    }

    $result = mysqli_query($link, "SELECT * FROM notebook_br09");

    $file_handler = fopen($filename, "w");
    if (mysqli_num_rows($result) > 0)
    {
        while ($row = mysqli_fetch_assoc($result)) {
	    	foreach($row as $key => $value) {
	    		if ($key == 'birthday') {
	    			fwrite($file_handler, preg_replace('/(\d{4})-(\d{2})-(\d{2})/', '${3}-${2}-${1}', $value).' | ');
	    			continue;
	    		}

				fwrite($file_handler, $value . ' | ');
	    	}
			fwrite($file_handler, "\r\n");
		}
    }
    fclose($file_handler);
    mysqli_close($link);
    
    $file_handler = fopen($filename, "r")
        or die("Нельзя открыть $filename");
    while (! feof($file_handler))
    {
        $line = fgets($file_handler, 1024);
        print "$line<br>";
    }
    fclose($file_handler);
?>