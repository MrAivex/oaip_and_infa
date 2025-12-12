--1. СОЗДАНИЕ ТАБЛИЦ
CREATE TABLE students (
    student_id SERIAL PRIMARY KEY,
    full_name VARCHAR(100) NOT NULL,
    group_number VARCHAR(10) NOT NULL
);

CREATE TABLE subjects (
    subject_id SERIAL PRIMARY KEY,
    subject_name VARCHAR(100) NOT NULL
);

CREATE TABLE grades (
    grade_id SERIAL PRIMARY KEY,
    student_id INT REFERENCES students(student_id),
    subject_id INT REFERENCES subjects(subject_id),
    grade INT CHECK (grade >= 2 AND grade <= 5),
    created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP
);

CREATE TABLE attendance (
    attendance_id SERIAL PRIMARY KEY,
    student_id INT REFERENCES students(student_id),
    date_attended DATE NOT NULL,
    status VARCHAR(20) CHECK (status IN ('присутствовал', 'отсутствовал', 'опоздал')),
    CONSTRAINT unique_student_date UNIQUE (student_id, date_attended)
);

CREATE TABLE notes (
    note_id SERIAL PRIMARY KEY,
    student_id INT REFERENCES students(student_id),
    note_text TEXT,
    created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP
);

-- 2. НАПОЛНЕНИЕ ДАННЫХ
-- Добавляем 6 студентов одной группы
INSERT INTO students (full_name, group_number) VALUES
('Иванов Иван Иванович', 'ГР-101'),
('Петров Петр Петрович', 'ГР-101'),
('Сидорова Анна Сергеевна', 'ГР-101'),
('Козлов Дмитрий Владимирович', 'ГР-101'),
('Смирнова Екатерина Андреевна', 'ГР-101'),
('Васильев Алексей Николаевич', 'ГР-101');

-- Добавляем 3 предмета
INSERT INTO subjects (subject_name) VALUES
('Математический анализ'),
('Аналитическая геометрия'),
('Информатика');

-- Добавляем оценки для всех студентов по каждому предмету
INSERT INTO grades (student_id, subject_id, grade)
SELECT s.student_id, sub.subject_id, 
       CASE 
           WHEN s.student_id % 6 = 0 THEN 5
           WHEN s.student_id % 6 = 1 THEN 4
           WHEN s.student_id % 6 = 2 THEN 3
           WHEN s.student_id % 6 = 3 THEN 4
           WHEN s.student_id % 6 = 4 THEN 5
           ELSE 4
       END
FROM students s
CROSS JOIN subjects sub
ORDER BY s.student_id, sub.subject_id;

-- Добавляем записи посещаемости для всех студентов на два дня
INSERT INTO attendance (student_id, date_attended, status)
SELECT student_id, '2024-01-15', 
       CASE WHEN student_id % 4 = 0 THEN 'присутствовал' 
            WHEN student_id % 4 = 1 THEN 'опоздал' 
            ELSE 'присутствовал' 
       END
FROM students;

INSERT INTO attendance (student_id, date_attended, status)
SELECT student_id, '2024-01-16', 
       CASE WHEN student_id % 5 = 0 THEN 'отсутствовал' 
            ELSE 'присутствовал' 
       END
FROM students;

-- Добавляем заметки по каждому студенту
INSERT INTO notes (student_id, note_text) VALUES
(1, 'Любит информатику, активно участвует на занятиях'),
(2, 'Нужна помощь по информатике, требуется дополнительное занятие'),
(3, 'Редко посещает занятия по информатике, но успевает по другим предметам'),
(4, 'Отличник по всем предметам, особенно силен в математическом анализе'),
(5, 'Хорошо работает в команде на лабораторных по информатике'),
(6, 'Прогресс по информатике заметен, стал лучше разбираться в программировании');

-- 3. СОЗДАНИЕ ИНДЕКСОВ
-- Индекс для быстрого поиска одногруппников
CREATE INDEX idx_students_group ON students(group_number);

-- Индекс для ускорения агрегированных запросов по оценкам
CREATE INDEX idx_grades_student ON grades(student_id);
CREATE INDEX idx_grades_subject ON grades(subject_id);

-- GIN индекс для полнотекстового поиска по заметкам
-- Сначала добавим поле для поиска (tsvector)
ALTER TABLE notes ADD COLUMN note_tsvector TSVECTOR;
UPDATE notes SET note_tsvector = to_tsvector('russian', note_text);
CREATE INDEX idx_notes_search ON notes USING GIN(note_tsvector);

-- 4. ПРЕДСТАВЛЕНИЯ
CREATE VIEW student_avg_grades AS
SELECT 
    s.student_id,
    s.full_name,
    s.group_number,
    ROUND(AVG(g.grade)::numeric, 2) as average_grade,
    COUNT(g.grade_id) as total_grades
FROM students s
LEFT JOIN grades g ON s.student_id = g.student_id
GROUP BY s.student_id, s.full_name, s.group_number;

-- 5. ТРАНЗАКЦИЯ (добавление нового студента с оценками)
BEGIN;

INSERT INTO students (full_name, group_number) 
VALUES ('Новиков Сергей Викторович', 'ГР-101')
RETURNING student_id;

-- Получаем ID нового студента
WITH new_student AS (
    SELECT student_id 
    FROM students 
    WHERE full_name = 'Новиков Сергей Викторович'
)
INSERT INTO grades (student_id, subject_id, grade)
SELECT 
    (SELECT student_id FROM new_student),
    subject_id,
    4 -- начальная оценка
FROM subjects;

-- Добавляем начальную посещаемость
WITH new_student AS (
    SELECT student_id 
    FROM students 
    WHERE full_name = 'Новиков Сергей Викторович'
)
INSERT INTO attendance (student_id, date_attended, status)
SELECT 
    (SELECT student_id FROM new_student),
    date_attended,
    'присутствовал'
FROM (VALUES 
    ('2024-01-15'),
    ('2024-01-16')
) AS dates(date_attended);

-- Добавляем заметку
WITH new_student AS (
    SELECT student_id 
    FROM students 
    WHERE full_name = 'Новиков Сергей Викторович'
)
INSERT INTO notes (student_id, note_text)
SELECT 
    (SELECT student_id FROM new_student),
    'Новый студент, адаптируется к группе';

COMMIT;

-- 6. SQL-ЗАПРОСЫ

-- 1) Найти 5 одногруппников студента (2 до и 3 после него по списку student_id)
WITH target_student AS (
    SELECT student_id, group_number 
    FROM students 
    WHERE full_name = 'Иванов Иван Иванович'
),
group_mates AS (
    SELECT 
        s.student_id,
        s.full_name,
        ROW_NUMBER() OVER (ORDER BY s.student_id) as rn
    FROM students s
    WHERE s.group_number = (SELECT group_number FROM target_student)
),
target_rn AS (
    SELECT rn 
    FROM group_mates 
    WHERE student_id = (SELECT student_id FROM target_student)
)
SELECT 
    student_id,
    full_name
FROM group_mates
WHERE rn BETWEEN (SELECT rn FROM target_rn) - 2 
              AND (SELECT rn FROM target_rn) + 3
  AND student_id != (SELECT student_id FROM target_student)
ORDER BY student_id
LIMIT 5;

-- 2) Посмотреть средний балл конкретного студента через представление
SELECT * 
FROM student_avg_grades 
WHERE full_name = 'Иванов Иван Иванович';

-- 3) Агрегировать средний балл по предмету «Информатика»
SELECT 
    s.subject_name,
    ROUND(AVG(g.grade)::numeric, 2) as average_grade,
    COUNT(g.grade_id) as total_grades
FROM grades g
JOIN subjects s ON g.subject_id = s.subject_id
WHERE s.subject_name = 'Информатика'
GROUP BY s.subject_name;

-- 4) Полнотекстовый поиск по заметкам, содержащим слово «Информатика»
SELECT 
    n.note_id,
    s.full_name,
    n.note_text,
    ts_headline('russian', n.note_text, plainto_tsquery('russian', 'Информатика')) as highlighted_text
FROM notes n
JOIN students s ON n.student_id = s.student_id
WHERE n.note_tsvector @@ plainto_tsquery('russian', 'Информатика')
ORDER BY n.created_at DESC;

-- 5) Обновить посещаемость студента на конкретную дату через транзакцию
BEGIN;

-- Сначала проверяем существование записи
INSERT INTO attendance (student_id, date_attended, status)
SELECT 
    s.student_id,
    '2024-01-17',
    'опоздал'
FROM students s
WHERE s.full_name = 'Иванов Иван Иванович'
ON CONFLICT (student_id, date_attended) 
DO UPDATE SET 
    status = EXCLUDED.status,
    attendance_id = attendance.attendance_id
RETURNING *;

COMMIT;

-- ДОПОЛНИТЕЛЬНЫЕ ЗАПРОСЫ ДЛЯ ПРОВЕРКИ

-- Просмотр всех студентов с их средними баллами
SELECT * FROM student_avg_grades ORDER BY average_grade DESC;

-- Просмотр посещаемости конкретного студента
SELECT 
    s.full_name,
    a.date_attended,
    a.status
FROM attendance a
JOIN students s ON a.student_id = s.student_id
WHERE s.full_name = 'Иванов Иван Иванович'
ORDER BY a.date_attended;

-- Статистика посещаемости по группе
SELECT 
    status,
    COUNT(*) as count
FROM attendance a
JOIN students s ON a.student_id = s.student_id
WHERE s.group_number = 'ГР-101'
GROUP BY status;