<?php
	if (empty($_GET))
		exit();

	$answers = array(
		'prado_1' => "6", 
		'reichstag_2' => "9",
		'scala_3' => "4", 
		'bronze_horseman_4' => "1",
		'wall_of_tears_5' => "3",
		'tretyakov_gallery_6' => "2",
		'triumphal_arch_7' => "5",
		'statue_of_liberty_8' => "8",
		'tower_9' => "7"
	);

	$user_score = 0;
	foreach($_GET as $key => $value)
        if($value == $answers[$key])
        {
            $user_score++;
        }
			

	print '<div>User, ' . $_GET['name'] . ', you ';
	switch($user_score) {
        case 2: 
            print 'know geography very bad.';
			break;
        case 3: 
            print 'know geography bad.';
			break;
        case 4: 
            print 'know geography not good.';
			break;	
        case 5: 
            print 'know geography satisfactorily.';
			break;
        case 6: 
            print 'know geography well.';
			break;
        case 7: 
            print 'know geography very well.';
			break;
        case 8: 
            print 'know geography excellent.';
			break;
        case 9: 
            print 'know geography great.';
			break;
        default: 
            print 'don\'t know geography at all.';
			break;
	}
	print ' Your result: ' . $user_score . ' out of ' . count($answers) . ' questions.';
	print '<br><a href = "z08-3a.html">Назад</a>';
?>