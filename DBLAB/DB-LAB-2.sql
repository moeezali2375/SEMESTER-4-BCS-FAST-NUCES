CREATE DATABASE organisation;

CREATE TABLE student
(
    roll_number CHAR (7) NOT NULL,
    student_name VARCHAR (20),
    gender char (1),
    phone varchar (13)
);
SELECT *
FROM student;

INSERT INTO student
VALUES('L164123', 'Ali Ahmad', 'M', '0333-3333333');
INSERT INTO student
VALUES('L164124', 'Rafia Ahmad', 'F', '0333-3456789');
INSERT INTO student
VALUES('L164125', 'Basit Junaid', 'M', '0345-3243567');

INSERT INTO student
VALUES('L162334', 'Fozan Shahid', 'M', 3.2 );

ALTER TABLE student ADD PRIMARY KEY (roll_number);

ALTER TABLE student DROP COLUMN phone;

ALTER TABLE student ADD warning_count int;
ALTER TABLE student ADD CHECK (gender='M' OR gender='F');

DELETE FROM student WHERE roll_number='l162334';

DELETE FROM student WHERE roll_number='L164124';
DELETE FROM student WHERE roll_number='L164123';

CREATE TABLE attendance
(
    roll_number CHAR(7) NOT NULL,
    day_id DATE,
    present CHAR (1),
    class_venue INT
);
-- DROP TABLE attendance;
SELECT *
FROM attendance;

INSERT INTO attendance
VALUES('L164123', '2016-02-22', 'P', 2);
INSERT INTO attendance
VALUES('L164124', '2016-02-23', 'A', 1);
INSERT INTO attendance
VALUES('L164125', '2016-03-04', 'P', 2);

ALTER TABLE attendance ADD PRIMARY KEY (roll_number);
ALTER TABLE attendance ADD FOREIGN KEY (class_venue) REFERENCES class_venue ON DELETE SET NULL ON UPDATE CASCADE;
ALTER TABLE attendance ADD FOREIGN KEY (roll_number) REFERENCES student ON DELETE CASCADE ON UPDATE CASCADE;
ALTER TABLE attendance ADD CHECK (present='A' OR present='P');


CREATE TABLE class_venue
(
    id INT NOT NULL,
    building VARCHAR (20),
    room_num INT,
    teacher VARCHAR (20),
);
SELECT *
FROM class_venue;

INSERT INTO class_venue
VALUES
    (1, 'CS', 2, 'Sarim Baig');

INSERT INTO class_venue
VALUES
    (2, 'Civil', 7, 'Bismillah Jan');

-- INSERT INTO class_venue
-- VALUES
--     (3, 'CS', 5, 'Ali');

ALTER TABLE class_venue ADD PRIMARY KEY (id);
ALTER TABLE class_venue ADD FOREIGN KEY (teacher) REFERENCES teachers ON DELETE SET NULL ON UPDATE CASCADE;

CREATE TABLE teachers
(
    teacher_name VARCHAR (20) NOT NULL,
    designation VARCHAR (20),
    department VARCHAR (20),
);
SELECT *
FROM teachers;

INSERT INTO teachers
VALUES
    ('Sarim Baig', 'Assisstant Prof.', 'Computer Science');
INSERT INTO teachers
VALUES
    ('Bismillah Jan', 'Lecturer', 'Civil Eng.');
INSERT INTO teachers
VALUES
    ('Kashif Zafar', 'Professor', 'Civil Eng.');

ALTER TABLE teachers ADD PRIMARY KEY (teacher_name);

ALTER TABLE teachers ADD UNIQUE(teacher_name);
-- ALTER TABLE teachers ADD FOREIGN KEY (teacher_name);
UPDATE teachers SET teacher_name='Dr. Kashif Zafar' WHERE teacher_name='Kashif Zafar';
