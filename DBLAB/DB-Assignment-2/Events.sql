
CREATE TABLE Events
(
    EID INT NOT NULL,
    Ename VARCHAR(20) NOT NULL,
    Location VARCHAR(20),
    Type VARCHAR(20),
    Start_Date DATE,
    Start_Time TIME,
    End_Date DATE,
    End_Time TIME,
    PRIMARY KEY (EID)
);

SELECT *
FROM Events;

--Insert

INSERT INTO Events
VALUES(
        1, 'AI', 'FAST-NUCES', 'Seminar', '2023/02/14', '13:00', '2023/02/14', '16:00'
);

INSERT INTO Events
VALUES(
        2, 'Block Chain', 'FAST-NUCES', 'Seminar', '2023/02/15', '11:00', '2023/02/15', '13:00'
);

INSERT INTO Events
VALUES(
        3, 'Women Rights', 'FAST-NUCES', 'Conference', '2023/02/15', '14:00', '2023/02/15', '17:00'
);

INSERT INTO Events
VALUES(
        4, 'Photoshop', 'FAST-NUCES', 'Workshop', '2023/02/16', '11:00', '2023/02/16', '17:00'
);

INSERT INTO Events
VALUES(
        5, 'Video Editing', 'FAST-NUCES', 'Workshop', '2023/02/17', '10:00', '2023/02/17', '13:00'
);
