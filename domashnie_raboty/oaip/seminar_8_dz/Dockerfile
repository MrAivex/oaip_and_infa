# Установка python
FROM python:3.10

# Назначение рабочей директории
WORKDIR /src/app/

# Копирование файлов в рабочую директорию
COPY . /src/app/

# Установка зависимостей из файла requirements.txt
RUN pip install -r requirements.txt

# Запуск
CMD ["python", "main.py"]