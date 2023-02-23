--Create database
CREATE database Event;

--Events
CREATE TABLE Events
(
    EID INT,
    Ename VARCHAR(20),
    Location VARCHAR(20),
    Type VARCHAR(20),
    Start_Date DATE,
    Start_Time TIME,
    End_Date DATE,
    End_Time TIME,
);
