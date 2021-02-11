<html> <head>
<title> Листинг 14-4. Идентификация браузера 
</title> </head> <body>
<?php
function browser_info ($agent) {
// Назначение: возвращает тип и версию браузера
	global $type_vers;
// Определить тип браузера
// Искать строку MSIE (Internet Explorer)
	if (ereg('MSIE ([0-9].[0-9]{1,2})', 
        $agent, $version)) {
		$browse_type = "IE";
		$browse_version = $version[1];}

// Искать строку Opera
	elseif (ereg('Opera ([0-9].[0-9]{1,2})', 
                 $agent, $version)) {
		$browse_type = "Opera";
		$browse_version = $version[1];}
// Искать строку Mozilla (Netscape). 
// Проверка браузера Netscape должна выполняться 
// после проверки Internet Explorer и Opera,
// поскольку все эти браузеры любят сообщать 
// имя Mozilla вместе с настоящим именем.
	elseif (ereg('Mozilla/([0-9].[0-9]{1,2})', 
            $agent, $version)) {
		$browse_type = "Netscape";
		$browse_version = $version[1];}
// Если это не Internet Explorer, Opera или Netscape - 
// значит, мы обнаружили неизвестный браузер.
	else {
		$browse_type = "Неизвестно";
		$browse_version = "Неизвестно";
	      }
$type_vers = array($browse_type, $browse_version);
return $type_vers;
} # Конец функции browser_info
function opsys_info($agent) {
// Назначение: возвращает информацию об операционной 
// системе пользователя
// Идентифицировать операционную систему
// Искать строку Windows
	if ( strstr ($agent, 'Win') ) {
		$opsys = "Windows";}
// Искать строку Linux
	elseif ( strstr($agent, 'Linux') ) {
		$opsys = "Linux";}
// Неизвестная платформа
	else {
		$opsys = "Неизвестно";
	     }
// Вернуть информацию об операционной системе
     return $opsys;
} # Конец функции opsys_info
browser_info($HTTP_USER_AGENT);
$browse_type = $type_vers[0];
$browse_version = $type_vers[1];
$operating_sys = opsys_info($HTTP_USER_AGENT);
print "Тип браузера: $browse_type <br>";
print "Версия браузера: $browse_version <br>";
print "Операционная система: $operating_sys";
?>
</body> </html>
