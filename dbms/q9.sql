CREATE TABLE student(
    ID NUMBER PRIMARY KEY,
    MARK1 NUMBER,
    MARK2 NUMBER,
    MARK3 NUMBER,
    PERCENTAGE NUMBER
);

CREATE
OR REPLACE TRIGGER PERCENT BEFORE
INSERT
    ON student FOR EACH ROW BEGIN :NEW.PERCENTAGE := (:NEW.MARK1 + :NEW.MARK2 + :NEW.MARK3) / 3;

END;

/
INSERT INTO
    STUDENT(ID, MARK1, MARK2, MARK3)
VALUES
(1, 30, 45, 90);

SELECT
    *
FROM
    student;