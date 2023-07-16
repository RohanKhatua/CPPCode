DECLARE num1 NUMBER := 10;
num2 NUMBER := 20;
choice NUMBER := 3;
result NUMBER;
BEGIN -- Perform the selected operation 
CASE
    choice
    WHEN 1 THEN result := num1 + num2;
DBMS_OUTPUT.PUT_LINE('Result: ' || result);
WHEN 2 THEN result := num1 - num2;
DBMS_OUTPUT.PUT_LINE('Result: ' || result);
WHEN 3 THEN result := num1 * num2;
DBMS_OUTPUT.PUT_LINE('Result: ' || result);
WHEN 4 THEN IF num2 <> 0 THEN result := num1 / num2;
DBMS_OUTPUT.PUT_LINE('Result: ' || result);
ELSE DBMS_OUTPUT.PUT_LINE('Error: Division by zero');
END IF;
ELSE DBMS_OUTPUT.PUT_LINE('Invalid choice');
END CASE;
END;
/