CREATE
OR REPLACE FUNCTION factorial(n NUMBER) RETURN NUMBER IS BEGIN IF n = 0 then RETURN 1;

ELSE RETURN n * factorial(n -1);

END IF;

END;

DECLARE input_number NUMBER := 7;

result NUMBER;

BEGIN result := factorial(input_number);

DBMS_OUTPUT.PUT_LINE(
    'The factorial of ' || input_number || ' is ' || result
);

END;

/