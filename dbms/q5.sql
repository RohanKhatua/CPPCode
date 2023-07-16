CREATE TABLE customer (
    customer_id INT,
    name VARCHAR2(100),
    gender VARCHAR2(10),
    balance NUMBER
);

-- Insert sample data into the first table 
INSERT INTO
    customer
VALUES
    (1, 'David', 'Male', 1000);

INSERT INTO
    customer
VALUES
    (2, 'Rohan', 'Male', 2000);

INSERT INTO
    customer
VALUES
    (3, 'Rahul', 'Male', 3000);

INSERT INTO
    customer
VALUES
    (4, 'Maria', 'Female', 4000);

INSERT INTO
    customer
VALUES
    (5, 'Michelle', 'Female', 5000);

-- Create the second table 
CREATE TABLE updated_customer (
    customer_id INT,
    name VARCHAR2(100),
    gender VARCHAR2(10),
    balance NUMBER
);

-- PL/SQL program to read data from the first table and update records in the second table 
DECLARE v_customer_id customer.customer_id % TYPE;

v_name customer.name % TYPE;

v_gender customer.gender % TYPE;

v_balance customer.balance % TYPE;

BEGIN -- Fetch customer records from the first table 
FOR customer_rec IN (
    SELECT
        *
    FROM
        customer
) LOOP v_customer_id := customer_rec.customer_id;

v_name := customer_rec.name;

v_gender := customer_rec.gender;

v_balance := customer_rec.balance;

-- Check if the customer is female 
IF v_gender = 'Female' THEN -- Update the balance with 5% addition 
v_balance := v_balance + (v_balance * 0.05);

END IF;

-- Insert the updated record into the second table 
INSERT INTO
    updated_customer
VALUES
    (v_customer_id, v_name, v_gender, v_balance);

END LOOP;

-- Display the updated records from the second table 
FOR updated_rec IN (
    SELECT
        *
    FROM
        updated_customer
) LOOP DBMS_OUTPUT.PUT_LINE(
    'Customer ID: ' || updated_rec.customer_id || ', Name: ' || updated_rec.name || ', Gender: ' || updated_rec.gender || ', Balance: ' || updated_rec.balance
);

END LOOP;

END;

/