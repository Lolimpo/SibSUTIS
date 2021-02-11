<?php
	if(!empty($_GET['structure'])) 
    {
		foreach($_GET['structure'] as $table_name) 
        {
			vid_structure($table_name);
		}
	}

	if(!empty($_GET['content'])) 
    {
		foreach($_GET['content'] as $table_name) 
        {
			vid_content($table_name);
		}
	}

	if(empty($_GET['structure']) && empty($_GET['content']))
		print '<p>Составлен пустой запрос.</p>';

    function vid_structure($table_name) {
    	global $link;

        $sql_query = 'SELECT * FROM `'.$table_name.'`';
        $result = mysqli_query($link, $sql_query);
		if(!$result)
			die('Could not show records from table `'.$table_name.'`: '.mysqli_error());

        print "<b>$table_name</b><br>";

        $fields = mysqli_fetch_fields($result);
        foreach($fields as $field)
        {
            print "<i>";
            print $field->type;
            print "</i> <i>";
            print $field->length;
            print "</i> <b>";
            print $field->name;
            print "</b> <i>";
            print $field->flags;
            print "</i><br>";
        }
        print "<br>";
    }

	function vid_content($table_name) 
    {
		global $link;

		print '<table cellpadding="5" border = "1" ><caption><h4>Содержимое таблицы "'.$table_name.'"</h4></caption>';

		$sql_query = 'SHOW COLUMNS FROM `'.$table_name.'`';
		$result = mysqli_query($link, $sql_query);
		if(!$result)
			die('Could not show columns from table `'.$table_name.'`: '.mysqli_error());

		print '<tr>';
		if (mysqli_num_rows($result) > 0)
			while ($row = mysqli_fetch_assoc($result))
				print '<th>'.$row['Field'].'</th>';
		print '</tr>';

		$sql_query = 'SELECT * FROM `'.$table_name.'`';
		$result = mysqli_query($link, $sql_query);
		if(!$result)
			die('Could not show records from table `'.$table_name.'`: '.mysqli_error());

		if (mysqli_num_rows($result) > 0)
		    while ($row = mysqli_fetch_assoc($result)) 
            {
				print '<tr>';
		       	foreach($row as $value)
					print '<td>'.$value.'</td>';
		       	print '</tr>';
		    }
	}
    print "</table><a href=z10-1.htm>Возврат к выбору таблицы</a>";
?>