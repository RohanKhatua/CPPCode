CREATE TABLE Bill (
    bill_no CHAR(10) primary key,
    bill_amt NUMBER(6) not null,
    day NUMBER(2) not null,
    month NUMBER(2) not null,
    year NUMBER(4) not null,
    constraint chkyear check(year in (2022, 2023))
);

INSERT INTO
    Bill
VALUES
    ('L/5098/22', 6850, 09, 02, 2023);

INSERT INTO
    Bill
VALUES
    ('L/14', 4484, 01, 04, 2023);

INSERT INTO
    Bill
VALUES
    ('L/20', 13250, 03, 04, 2023);

INSERT INTO
    Bill
VALUES
    ('L/390', 3953, 21, 04, 2023);

INSERT INTO
    Bill
VALUES
    ('L/812', 2553, 12, 05, 2023);

CREATE
OR REPLACE FUNCTION DOC_COUNT(col VARCHAR) RETURN number IS total number(2) := 0;

BEGIN
SELECT
    count(*) INTO total
FROM
    col;

RETURN total;

END;

/ DECLARE c number(2);

var char(5) := 'Bill';

BEGIN c := DOC_COUNT(var);

dbms_output.put_line('Total no. of Bills is ' || c);

END;