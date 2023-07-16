CREATE TABLE EMPLOYEES (
    employee_id NUMBER,
    employee_name VARCHAR2(100),
    department_id NUMBER,
    salary NUMBER
);

DECLARE v_employee_id NUMBER := 5;

v_employee_name VARCHAR2(100) := 'Rohan';

v_department_id NUMBER := 10;

v_salary NUMBER := 4000;

BEGIN
INSERT INTO
    EMPLOYEES
VALUES
    (
        v_employee_id,
        v_employee_name,
        v_department_id,
        v_salary
    );

COMMIT;

-- Commit the transaction 
DBMS_OUTPUT.PUT_LINE('Record inserted successfully.');

EXCEPTION
WHEN OTHERS THEN DBMS_OUTPUT.PUT_LINE('Error occurred: ' || SQLERRM);

END;

