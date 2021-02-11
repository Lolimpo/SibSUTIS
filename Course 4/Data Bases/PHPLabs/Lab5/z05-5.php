<?php
	$lang = $_GET['lang'];

	print 'Language: ';
	if ($lang == "ru")
		print 'Russian';
	elseif ($lang == "en")
        print 'English';
	elseif ($lang == "fr")
        print 'France';
	elseif ($lang == "de")
        print 'Deutsch';
	else
        print 'Unknown language.';
?>