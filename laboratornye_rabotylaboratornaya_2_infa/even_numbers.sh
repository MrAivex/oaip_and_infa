#!/bin/bash


echo "Просто выводим числа: "

for i in {1..20}; do
echo -n "$i "
done

echo "" #Переход на новую строку

for i in {1..20}; do
if (( $i % 2 == 0 ))
then
echo -n "$i "
fi
done

echo "" #Переход на новую строку

