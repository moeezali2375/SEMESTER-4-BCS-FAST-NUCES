--EVENT
CREATE TABLE Event
(
    eid INT NOT NULL,
    e_name VARCHAR(20) NOT NULL,
    location VARCHAR(20),
    type VARCHAR(20),
    startdate DATE,
    startime TIME,
    enddate DATE,
    endtime TIME,
    PRIMARY KEY (eid)
);

SELECT *
FROM Event;

--Insert

INSERT INTO Event
VALUES
    (1, 'ABC', 'lahore', 'Seminar', '2022/02/22', '2:00', '2022/02/22', '6:00')
;

INSERT INTO Event
VALUES
    (2, 'DEF', 'lahore', 'Seminar', '2022/1/25', '2:00', '2022/1/25', '6:00')
;

INSERT INTO Event
VALUES
    (3, 'GHI', 'lahore', 'Seminar', '2022/12/22', '2:00', '2022/12/22', '6:00')
;
INSERT INTO Event
VALUES
    (4, 'JKL', 'lahore', 'Conference', '2022/2/22', '2:00', '2022/2/22', '6:00');

INSERT INTO Event
VALUES
    (5, 'MNO', 'lahore', 'Workshop', '2022/12/22', '2:00', '2022/12/22', '6:00');
;
--ORGANIsATION
CREATE TABLE Organisation
(
    oid INT NOT NULL PRIMARY KEY,
    oname VARCHAR(20),
    address VARCHAR (50)
);

SELECT *
FROM Organisation;

--Insert
INSERT INTO Organisation
VALUES
    (1, 'SOFTEC', 'FAST,lahore')
;
INSERT INTO Organisation
VALUES
    (2, 'FAST', 'Faisal Town,lahore')
;
INSERT INTO Organisation
VALUES
    (3, 'Techlogix', 'FAST,lahore')
;
INSERT INTO Organisation
VALUES
    (4, 'DEF', 'FAST,lahore')
;

INSERT INTO Organisation
VALUES
    (5, 'XYZ', 'FAST,lahore')
;
--PARTICIPANTS
CREATE TABLE Participant
(
    pid INT NOT NULL PRIMARY KEY,
    pname VARCHAR(20),
    bdate DATE,
    gender VARCHAR(10),
    oid INT FOREIGN KEY (oid) REFERENCES Organisation ON DELETE SET NULL ON UPDATE CASCADE
);

SELECT *
FROM Participant;

--Insert
INSERT INTO Participant
VALUES
    (1, 'Hashim', '2002/8/10', 'Male', 1)
;
INSERT INTO Participant
VALUES
    (2, 'Hugo', '2002/8/10', 'Male', 1);

INSERT INTO Participant
VALUES
    (3, 'Ali', '2002/8/10', 'Male', 1);

INSERT INTO Participant
VALUES
    (4, 'Asad', '2002/8/10', 'Male', 1)
;

INSERT INTO Participant
VALUES
    (5, 'Sania', '2002/8/10', 'Female', NULL)
;
INSERT INTO Participant
VALUES
    (6, 'Hania', '2002/8/10', 'Female', NULL);

--SPOSNOSRS
CREATE TABLE Sponsor
(
    eid INT NOT NULL REFERENCES event ON DELETE NO ACTION ON UPDATE CASCADE,
    oid INT NOT NULL REFERENCES event ON DELETE NO ACTION ,
    amount INT,
    PRIMARY KEY (eid, oid)
);

SELECT *
FROM Sponsor;

--Insert
INSERT INTO Sponsor
VALUES
    (1, 1, 5000)
;
INSERT INTO Sponsor
VALUES
    (2, 1, 1000)
;
INSERT INTO Sponsor
VALUES
    (3, 3, 3000)
;
INSERT INTO Sponsor
VALUES
    (4, 5, 4000)
;
INSERT INTO Sponsor
VALUES
    (5, 3, 7000)
;
INSERT INTO Sponsor
VALUES
    (2, 3, 9000)
;

--ATTENDED
CREATE TABLE Attend
(
    pid INT NOT NULL REFERENCES Participant ON DELETE CASCADE ON UPDATE CASCADE,
    eid INT NOT NULL REFERENCES Event ON DELETE CASCADE ON UPDATE CASCADE,
    PRIMARY KEY(pid,eid)
);

SELECT *
FROM Attend;

--Insert
INSERT INTO 
Attend
VALUES(
        1, 1
);
INSERT INTO 
Attend
VALUES(
        1, 4
);
INSERT INTO 
Attend
VALUES(
        1, 2
);
INSERT INTO 
Attend
VALUES(
        1, 3
);
INSERT INTO 
Attend
VALUES(
        1, 5
);

INSERT INTO 
Attend
VALUES(
        3, 4
);

INSERT INTO 
Attend
VALUES(
        4, 1
);
INSERT INTO 
Attend
VALUES(
        5, 1
);

create database evaluation;

--1
SELECT eid, e_name
FROM event;

--2
SELECT eid, e_name, startime
FROM event
WHERE startdate='2023-01-03';

--3
SELECT pname
FROM Participant
WHERE Gender!='Female' AND bdate>'1998-01-01';

--4
SELECT oname, Count(oname) AS 'Total event'
FROM (Organisation JOIN Sponsor on Organisation.OID=Sponsor.OID)
GROUP BY oname
HAVING COUNT(oname)>0;

--5
SELECT Participant.PID, Participant.pname
FROM (Attend JOIN event ON Attend.eid=event.eid)JOIN Participant ON Participant.PID=Attend.PID JOIN Sponsor ON event.eid=Sponsor.eid JOIN Organisation ON Organisation.OID=Sponsor.OID
WHERE oname='Techlogix' AND startdate='2003-01-25';

--6
SELECT distinct Organisation.oname
FROM Organisation JOIN Sponsor ON Organisation.OID=Sponsor.OID JOIN event ON Sponsor.eid=event.eid
WHERE event.Type!='Seminar';

--7
SELECT Participant.PID, COUNT(Participant.PID) AS Attended_Events
FROM Participant JOIN Attend ON Participant.PID=Attend.PID
GROUP BY Participant.PID
HAVING COUNT(Participant.PID)=5;

--8
SELECT Participant.PID, COUNT(Participant.PID) AS Attended_Events
FROM Participant JOIN Attend ON Participant.PID=Attend.PID
GROUP BY Participant.PID
;


--9
Select min(amount) as min_amount, max(amount) as max_amount, avg(amount) as avg_amount
from Sponsor
--10
    SELECT oname
    FROM Organisation INNER JOIN Sponsor ON Organisation.OID=Sponsor.OID INNER JOIN event ON Sponsor.eid=event.eid
    WHERE (type='seminar') AND (MONTH(startdate)=12) AND (YEAR(startdate)=2022)
INTERSECT
    SELECT oname
    FROM Organisation INNER JOIN Sponsor ON Organisation.OID=Sponsor.OID INNER JOIN event ON Sponsor.eid=event.eid
    WHERE ( type='workshop') AND (MONTH(startdate)=12) AND (YEAR(startdate)=2022);
--11
SELECT pname
FROM Participant
WHERE PID IN (SELECT PID
    FROM Attend JOIN event ON Attend.eid=event.eid
    WHERE type='seminar') AND PID NOT IN (SELECT PID
    FROM Attend INNER JOIN event ON Attend.eid=event.eid
    WHERE type='conference');

--12
SELECT PID
FROM Participant
WHERE PID NOT IN (SELECT PID
    FROM Attend) OR PID IN (SELECT PID
    FROM Attend
    WHERE eid IN (SELECT eid
    FROM event
    WHERE startdate='2023-01-05'));




