DECLARE v_department_id NUMBER := 10; 
-- Replace with the desired department ID 
v_count NUMBER; 
v_result VARCHAR2(10); 
BEGIN 
-- Find the total number of employees in the department with salary > 10000 
SELECT COUNT(*) INTO v_count FROM employees WHERE department_id = v_department_id AND salary > 10000;
-- Check if the count is odd or even 
IF MOD(v_count, 2) = 0 THEN v_result := 'EVEN'; 
ELSE v_result := 'ODD'; 
END IF; 
-- Display the count and the result (odd or even) 
DBMS_OUTPUT.PUT_LINE('Total Employees in Department ' || v_department_id || ' with Salary > 10000: ' || v_count); 
DBMS_OUTPUT.PUT_LINE('Count is ' || v_result); 
END; 
/