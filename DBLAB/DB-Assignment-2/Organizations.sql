CREATE TABLE Organizations
(
    OID INT NOT NULL PRIMARY KEY,
    O_name VARCHAR(20),
    Address VARCHAR (50)
);

SELECT *
FROM Organizations;

--Insert
INSERT INTO Organizations
VALUES
    (
        1, 'NMG', 'FAST-NUCES,Lahore'
);
INSERT INTO Organizations
VALUES
    (
        2, 'CCS', 'FAST-NUCES,Lahore'
);
INSERT INTO Organizations
VALUES
    (
        3, 'GDSC', 'FAST-NUCES,Lahore'
);
INSERT INTO Organizations
VALUES
    (
        4, 'SOFTEC', 'FAST-NUCES,Lahore'
);
INSERT INTO Organizations
VALUES
    (
        5, 'RUNG', 'FAST-NUCES,Lahore'
);


