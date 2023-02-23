CREATE TABLE Participants
(
    PID INT NOT NULL PRIMARY KEY,
    P_name VARCHAR(20),
    B_date DATE,
    Gender VARCHAR(10),
    OID INT FOREIGN KEY (OID) REFERENCES Organizations ON DELETE SET NULL ON UPDATE CASCADE
);

SELECT *
FROM Participants;

--Insert
INSERT INTO Participants
VALUES(
        1, 'Moeez Ali', '1996/05/27', 'MALE', 5
);
INSERT INTO Participants
VALUES(
        2, 'Ayesha Saikhani', '2005/07/05', 'FEMALE', 5
);
INSERT INTO Participants
VALUES(
        3, 'Cato', '2000/11/29', 'MALE', 1
);
INSERT INTO Participants
VALUES(
        4, 'Saad Simp', '2000/01/20', 'MALE', NULL
);
INSERT INTO Participants
VALUES(
        5, 'Noor', '1998/12/22', 'Trans', NULL
);
