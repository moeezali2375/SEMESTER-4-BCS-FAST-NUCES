
CREATE TABLE Attended
(
    PID INT NOT NULL REFERENCES Participants ON DELETE CASCADE ON UPDATE CASCADE,
    EID INT NOT NULL REFERENCES Events ON DELETE CASCADE ON UPDATE CASCADE,
    PRIMARY KEY(PID,EID)
);

SELECT *
FROM Attended;

--Insert
INSERT INTO 
Attended
VALUES(
        1, 4
);
INSERT INTO 
Attended
VALUES(
        1, 5
);
INSERT INTO 
Attended
VALUES(
        1, 1
);
INSERT INTO 
Attended
VALUES(
        2, 3
);
INSERT INTO 
Attended
VALUES(
        2, 2
);


