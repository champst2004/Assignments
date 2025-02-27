CREATE DATABASE assign5;
USE assign5;

CREATE TABLE emp (
    eno INT PRIMARY KEY,
    ename VARCHAR(50),
    Zip INT,
    hdate DATE
);

CREATE TABLE parts (
    pno INT PRIMARY KEY,
    pname VARCHAR(50),
    qty_on_hand INT,
    price DECIMAL(10,2)
);

CREATE TABLE customer (
    cno INT PRIMARY KEY,
    cname VARCHAR(50),
    street VARCHAR(100),
    Zip INT,
    phone VARCHAR(15)
);

CREATE TABLE orders (
    ono INT PRIMARY KEY,
    cno INT,
    receivedate DATE,
    shippeddate DATE,
    FOREIGN KEY (cno) REFERENCES customer(cno)
);

CREATE TABLE odetails (
    ono INT,
    pno INT,
    qty INT,
    PRIMARY KEY (ono, pno),
    FOREIGN KEY (ono) REFERENCES orders(ono),
    FOREIGN KEY (pno) REFERENCES parts(pno)
);

CREATE TABLE zipcode (
    Zip INT PRIMARY KEY,
    city VARCHAR(50)
);

-- Queries

SELECT pno, pname FROM parts WHERE price < 20.00;

SELECT o.ono, c.cname FROM orders o 
JOIN customer c ON o.cno = c.cno
WHERE o.shippeddate IS NULL;

SELECT DISTINCT c.cname FROM customer c
JOIN orders o ON c.cno = o.cno
JOIN emp e ON c.Zip = e.Zip
JOIN zipcode z ON e.Zip = z.Zip
WHERE z.city IN ('Pune', 'Mumbai');

SELECT SUM(qty) AS total_quantity FROM odetails WHERE pno = 1060;

SELECT COUNT(*) AS total_customers FROM customer;

UPDATE emp SET ename = 'huehuehue' WHERE eno = 101;

DELETE FROM emp WHERE Zip IN (SELECT Zip FROM zipcode WHERE city = 'Pune');

ALTER TABLE emp ADD COLUMN salary DECIMAL(10,2);

ALTER TABLE emp DROP COLUMN hdate;

CREATE VIEW customer_orders AS
SELECT c.cname, o.ono, o.receivedate, o.shippeddate 
FROM customer c
JOIN orders o ON c.cno = o.cno;
