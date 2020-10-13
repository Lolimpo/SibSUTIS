#!/bin/bash
echo -n "Дата: " & date
echo -n "Имя учетной записи: " & whoami
echo -n "Доменное имя пк: " & hostname
echo "Процессор:"
echo -ne "\tИмя Модели- " & lscpu | grep "Имя модели" | cut -c49-57
echo -ne "\tАрхитектура- " & lscpu | grep "Архитектура" | cut -c33-60
echo -ne "\tТактовая частота - " & lscpu | grep "Имя модели:" | awk '{print $8}'
echo -ne "\tКоличество ядер - " & lscpu | grep -m 1 "CPU(s):" | awk '{print $2}'
echo -ne "\tКоличество потоков на одно ядро - " & lscpu | grep "Потоков на" | awk '{print $4}'
echo "Оперативная память:"
echo -ne "\tВсего - " & cat /proc/meminfo | grep "MemTotal" | awk '{print $2 $3}'
echo -ne "\tДоступно - " & cat /proc/meminfo | grep "MemFree" | awk '{print $2 $3}'
echo "Жесткий диск:"
echo -ne "\tВсего - " & df -h | grep "/dev/sda1" | awk '{print $2}'
echo -ne "\tДоступно - " & df -h | grep "/dev/sda1" | awk '{print $3}'
echo -ne "\tСмонтировано в корневую дерикторию / - " & df | grep -w " /" | awk '{print $1}'
echo -ne "\tSWAP всего - " & cat /proc/meminfo | grep "SwapTotal" | awk '{print $2/(1024) "MB"}'
echo -ne "\tSWAP свободно - " & cat /proc/meminfo | grep "SwapFree" | awk '{print $2/(1024) "MB"}'
echo "Сетевые интерфейсы:"
echo -ne "\tКоличество интерфейсов - " & find /sys/class/net -maxdepth 1 -type d | wc -l
echo -ne "No\tName\tIP\t\tMask\t\t\tSpeed\n"
echo -ne "1\t" & ifconfig | awk 'NR == 1{printf substr($1, 1, length($1)-1) "\t"}'
ifconfig | awk 'NR == 2{printf $6 "\t"}'
ifconfig | grep "ether" | awk '{printf $2 "\t"}'
cat /sys/class/net/enp0s3/speed
