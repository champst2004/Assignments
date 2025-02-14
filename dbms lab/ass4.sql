-- Question 1

CREATE DATABASE assign4a;
USE assign4a;

CREATE TABLE Hotel (
    HotelNo INT PRIMARY KEY,
    Name VARCHAR(100) NOT NULL,
    City VARCHAR(50) NOT NULL
);

CREATE TABLE Room (
    RoomNo INT,
    HotelNo INT,
    Type VARCHAR(50) CHECK (Type IN ('Single', 'Double', 'Suite', 'Deluxe')),
    Price DECIMAL(10,2) CHECK (Price > 0),
    PRIMARY KEY (RoomNo, HotelNo),
    FOREIGN KEY (HotelNo) REFERENCES Hotel(HotelNo) ON DELETE CASCADE
);

CREATE TABLE Guest (
    GuestNo INT PRIMARY KEY,
    GuestName VARCHAR(100) NOT NULL,
    GuestAddress VARCHAR(255) NOT NULL
);

CREATE TABLE Booking (
    HotelNo INT,
    GuestNo INT,
    RoomNo INT,
    DateFrom DATE NOT NULL,
    DateTo DATE NOT NULL,
    PRIMARY KEY (HotelNo, GuestNo, RoomNo, DateFrom),
    FOREIGN KEY (HotelNo) REFERENCES Hotel(HotelNo) ON DELETE CASCADE,
    FOREIGN KEY (GuestNo) REFERENCES Guest(GuestNo) ON DELETE CASCADE,
    FOREIGN KEY (RoomNo, HotelNo) REFERENCES Room(RoomNo, HotelNo) ON DELETE CASCADE,
    CHECK (DateFrom < DateTo)
);

SELECT COUNT(*) AS TotalHotels FROM Hotel;

SELECT R.Price, R.Type 
FROM Room R
JOIN Hotel H ON R.HotelNo = H.HotelNo
WHERE H.Name = 'Grosvenor Hotel';

SELECT H.HotelNo, H.Name, COUNT(R.RoomNo) AS TotalRooms 
FROM Hotel H
LEFT JOIN Room R ON H.HotelNo = R.HotelNo
GROUP BY H.HotelNo, H.Name;

UPDATE Room
SET Price = Price * 1.05;

SELECT * FROM Hotel WHERE City = 'London';

SELECT AVG(Price) AS AverageRoomPrice FROM Room;

SELECT G.GuestNo, G.GuestName, G.GuestAddress
FROM Guest G
JOIN Booking B ON G.GuestNo = B.GuestNo
JOIN Hotel H ON B.HotelNo = H.HotelNo
WHERE H.Name = 'Grosvenor Hotel'
AND CURDATE() BETWEEN B.DateFrom AND B.DateTo;

SELECT H.HotelNo, H.Name, COUNT(R.RoomNo) AS TotalRooms 
FROM Hotel H
LEFT JOIN Room R ON H.HotelNo = R.HotelNo
WHERE H.City = 'London'
GROUP BY H.HotelNo, H.Name;

CREATE VIEW BookingDetails AS
SELECT B.HotelNo, H.Name AS HotelName, G.GuestNo, G.GuestName, B.RoomNo, B.DateFrom, B.DateTo
FROM Booking B
JOIN Hotel H ON B.HotelNo = H.HotelNo
JOIN Guest G ON B.GuestNo = G.GuestNo;
SELECT * FROM BookingDetails WHERE HotelName = 'Grosvenor Hotel';

-- Question 2

create database assign4b;
use assign4b;

CREATE TABLE emp (
    eno INT PRIMARY KEY,
    ename VARCHAR(100) NOT NULL,
    Zip VARCHAR(10) NOT NULL,
    hdate DATE NOT NULL,
    FOREIGN KEY (Zip) REFERENCES zipcode(Zip) ON DELETE CASCADE
);

CREATE TABLE parts (
    pno INT PRIMARY KEY,
    pname VARCHAR(100) NOT NULL,
    qty_on_hand INT CHECK (qty_on_hand >= 0),
    price DECIMAL(10,2) CHECK (price > 0)
);

CREATE TABLE customer (
    cno INT PRIMARY KEY,
    cname VARCHAR(100) NOT NULL,
    street VARCHAR(255) NOT NULL,
    Zip VARCHAR(10) NOT NULL,
    phone VARCHAR(15) NOT NULL,
    FOREIGN KEY (Zip) REFERENCES zipcode(Zip) ON DELETE CASCADE
);

CREATE TABLE orders (
    ono INT PRIMARY KEY,
    cno INT NOT NULL,
    receivedate DATE NOT NULL,
    shippeddate DATE,
    FOREIGN KEY (cno) REFERENCES customer(cno) ON DELETE CASCADE,
    CHECK (shippeddate IS NULL OR receivedate <= shippeddate)
);

CREATE TABLE odetails (
    ono INT,
    pno INT,
    qty INT CHECK (qty > 0),
    PRIMARY KEY (ono, pno),
    FOREIGN KEY (ono) REFERENCES orders(ono) ON DELETE CASCADE,
    FOREIGN KEY (pno) REFERENCES parts(pno) ON DELETE CASCADE
);

CREATE TABLE zipcode (
    Zip VARCHAR(10) PRIMARY KEY,
    city VARCHAR(100) NOT NULL
);

SELECT pno, pname 
FROM parts 
WHERE price < 20.00;

SELECT o.ono, c.cname 
FROM orders o
JOIN customer c ON o.cno = c.cno
WHERE o.shippeddate IS NULL;

SELECT DISTINCT c.cname
FROM customer c
JOIN orders o ON c.cno = o.cno
JOIN emp e ON c.Zip = e.Zip
JOIN zipcode z ON e.Zip = z.Zip
WHERE z.city IN ('Pune', 'Mumbai');

SELECT DISTINCT z.city
FROM zipcode z
JOIN customer c ON z.Zip = c.Zip
UNION
SELECT DISTINCT z.city
FROM zipcode z
JOIN emp e ON z.Zip = e.Zip;

SELECT SUM(qty) AS TotalQuantityOrdered
FROM odetails
WHERE pno = 1060;

SELECT COUNT(*) AS TotalCustomers FROM customer;

CREATE VIEW OrderDetailsView AS
SELECT o.ono, c.cname, p.pname, od.qty, o.receivedate, o.shippeddate
FROM orders o
JOIN customer c ON o.cno = c.cno
JOIN odetails od ON o.ono = od.ono
JOIN parts p ON od.pno = p.pno;
SELECT * FROM OrderDetailsView;