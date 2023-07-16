CREATE TABLE EMPLOYEES (
    employee_id NUMBER PRIMARY KEY,
    employee_name VARCHAR2(100),
    department_id NUMBER,
    salary NUMBER
);

INSERT INTO EMPLOYEES VALUES(1, 'Rohan', 10, 2000);

INSERT INTO EMPLOYEES VALUES (2, 'Alan', 10, 1000);

INSERT INTO EMPLOYEES VALUES (3, 'David', 20, 5000);

INSERT INTO EMPLOYEES VALUES (4, 'Rahul', 30, 3000);

DECLARE 
-- Locally declared variables 
v_id NUMBER; 
v_name VARCHAR2(100); 
d_id NUMBER; 
v_salary NUMBER; 
BEGIN 
-- Read a record from the table into local variables 
SELECT employee_id, employee_name, department_id, salary INTO v_id, v_name, d_id, v_salary FROM employees WHERE employee_id = 1; 
-- Replace with the desired employee ID -- Display the values using locally declared variables 
DBMS_OUTPUT.PUT_LINE('Employee ID: ' || v_id); 
DBMS_OUTPUT.PUT_LINE('Employee Name: ' || v_name); 
DBMS_OUTPUT.PUT_LINE('Department ID: ' || d_id); 
DBMS_OUTPUT.PUT_LINE('Employee Salary: ' || v_salary); 
END; 
/