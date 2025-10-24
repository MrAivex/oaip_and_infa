#!/bin/bash

ps

echo "Количество запущенных процессов: "

count=$( ps | wc -l )

(( count -= 3 ))

echo "$count"
