create database evaluation;

--1
SELECT EID, Ename
FROM Events;

--2
SELECT EID, Ename, start_time
FROM Events
WHERE Start_Date='2023-02-14';

--3
SELECT P_name
FROM Participants
WHERE Gender='Female' AND B_date>'1998-01-01';

--4
SELECT O_name,organizations.OID ,Count(O_name) AS 'Total Events'
FROM (Organizations JOIN Sponsors on Organizations.OID=Sponsors.OID)
GROUP BY O_name,Organizations.OID
HAVING COUNT(O_name)>0;

--5
SELECT Participants.PID, Participants.P_name
FROM (Attended JOIN Events ON Attended.EID=Events.EID)JOIN Participants ON Participants.PID=Attended.PID JOIN Sponsors ON Events.EID=Sponsors.EID JOIN Organizations ON Organizations.OID=Sponsors.OID
WHERE O_name='CCS' AND Start_Date='2023-02-14';

--6
SELECT Distinct Organizations.O_name
FROM Organizations JOIN Sponsors ON Organizations.OID=Sponsors.OID JOIN Events ON Sponsors.EID=Events.EID
WHERE Events.Type!='Seminar';

--7
SELECT Participants.PID, COUNT(Participants.PID) AS Attended_Events
FROM Participants JOIN Attended ON Participants.PID=Attended.PID
GROUP BY Participants.PID
HAVING COUNT(Participants.PID)=5;

--8
SELECT Participants.PID, COUNT(Participants.PID) AS Attended_Events
FROM Participants JOIN Attended ON Participants.PID=Attended.PID
GROUP BY Participants.PID
;


--9
Select min(amount) as min_amount, max(amount) as max_amount, avg(amount) as avg_amount
from Sponsors
--10
SELECT O_name
FROM Organizations INNER JOIN Sponsors ON Organizations.OID=Sponsors.OID INNER JOIN Events ON Sponsors.EID=Events.EID
WHERE (type='seminar' ) AND (MONTH(start_date)=12) AND (YEAR(start_date)=2022)
INTERSECT
SELECT O_name
FROM Organizations INNER JOIN Sponsors ON Organizations.OID=Sponsors.OID INNER JOIN Events ON Sponsors.EID=Events.EID
WHERE ( type='workshop') AND (MONTH(start_date)=12) AND (YEAR(start_date)=2022);
--11
SELECT P_name
FROM Participants
WHERE PID IN (SELECT PID
    FROM Attended JOIN Events ON Attended.EID=Events.EID
    WHERE type='seminar') AND PID NOT IN (SELECT PID
    FROM Attended INNER JOIN Events ON Attended.EID=Events.EID
    WHERE type='conference');

--12
SELECT PID
FROM Participants
WHERE PID NOT IN (SELECT PID
    FROM Attended) OR PID IN (SELECT PID
    FROM Attended
    WHERE EID IN (SELECT EID
    FROM Events
    WHERE start_date='2023-01-05'));




