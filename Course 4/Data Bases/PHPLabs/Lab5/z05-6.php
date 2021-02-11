<?php
    $lang = $_GET['lang'];

    print 'Language: ';
	switch($lang) {
		case 'ru':
			print 'Russian';
			break;
		case 'en':
			print 'English';
			break;
		case 'fr':
			print 'France';
			break;
		case 'de':
			print 'Deutsch';
			break;
		default:
            print 'Unknown language.';
			break;
	}
?>