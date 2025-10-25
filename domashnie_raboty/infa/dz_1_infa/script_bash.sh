#!/bin/bash

[ $# -ne 2 ] && echo "Использование: $0 <файл> <строка>" && exit 1

file="$1"
text="$2"

[ ! -f "$file" ] && touch "$file" # 1

echo "$text" >> "$file" # 2

echo "Содержимое файла:" # 3
cat "$file"

nc -l -p 12345 >> "$file" 2>/dev/null & # 4
echo "Netcat запущен (PID: $!)"