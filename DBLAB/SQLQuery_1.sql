create table dummy5(
    course_code VARCHAR(10),
    course_name VARCHAR (10)
);

INSERT INTO dummy5 VALUES ('CS1-0202', 'hehe');
DELETE FROM dummy5 where course_code='CS1-0202';
ALTER TABLE dummy4 ADD PRIMARY KEY (course_code);
ALTER TABLE dummy5 ADD CHECK (course_code NOT NULL);
INSERT INTO courses VALUES ('CS1000','DataBases');
select *FROM dummy5;