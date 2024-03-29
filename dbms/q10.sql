CREATE TABLE DEPT(
    DEPTID VARCHAR(5) PRIMARY KEY,
    DEPTNAME VARCHAR(20)
);

CREATE TABLE STUD(
    SID NUMBER PRIMARY KEY,
    SNAME VARCHAR(20),
    DEPTID VARCHAR(5),
    FOREIGN KEY(DEPTID) REFERENCES DEPT(DEPTID)
);

INSERT INTO
    DEPT
VALUES
('1', 'Computer Science');

INSERT INTO
    DEPT
VALUES
('2', 'Biotechnology');

INSERT INTO
    STUD
VALUES
(1, 'Rohan', '1');

INSERT INTO
    STUD
VALUES
(2, 'Rahul', '2');

SELECT
    *
FROM
    DEPT;

SELECT
    *
FROM
    STUD;

CREATE
OR REPLACE TRIGGER DEL_PARENT
AFTER
    DELETE ON STUD FOR EACH ROW BEGIN
DELETE FROM
    DEPT
WHERE
    DEPTID = :OLD.DEPTID;

END;

/
DELETE FROM
    STUD
WHERE
    SID = 1;

SELECT
    *
FROM
    DEPT;

SELECT
    *
FROM
    STUD;