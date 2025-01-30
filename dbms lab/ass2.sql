create database assign2;
use assign2;

-- Question 1
CREATE TABLE Hotel (
    HotelNo INT PRIMARY KEY,
    Name VARCHAR(100) NOT NULL,
    City VARCHAR(100) NOT NULL
);

CREATE TABLE Room (
    RoomNo INT PRIMARY KEY,
    HotelNo INT NOT NULL,
    Type VARCHAR(50) CHECK (Type IN ('Single', 'Double', 'Suite')) NOT NULL,
    Price DECIMAL(10, 2) CHECK (Price > 0),
    FOREIGN KEY (HotelNo) REFERENCES Hotel(HotelNo)
);

CREATE TABLE Guest (
    GuestNo INT PRIMARY KEY,
    GuestName VARCHAR(100) NOT NULL,
    GuestAddress VARCHAR(200) NOT NULL
);

CREATE TABLE Booking (
    BookingID INT PRIMARY KEY,
    HotelNo INT NOT NULL,
    GuestNo INT NOT NULL,
    DateFrom DATE NOT NULL,
    DateTo DATE NOT NULL,
    RoomNo INT NOT NULL,
    FOREIGN KEY (HotelNo) REFERENCES Hotel(HotelNo),
    FOREIGN KEY (GuestNo) REFERENCES Guest(GuestNo),
    FOREIGN KEY (RoomNo) REFERENCES Room(RoomNo),
    CHECK (DateTo > DateFrom)
);


-- Question 2
CREATE TABLE emp (
    eno INT PRIMARY KEY,
    ename VARCHAR(100) NOT NULL,
    Zip INT NOT NULL,
    hdate DATE NOT NULL
);

CREATE TABLE parts (
    pno INT PRIMARY KEY,
    pname VARCHAR(100) NOT NULL,
    qty_on_hand INT CHECK (qty_on_hand >= 0) NOT NULL,
    price DECIMAL(10, 2) CHECK (price > 0) NOT NULL
);

CREATE TABLE customer (
    cno INT PRIMARY KEY,
    cname VARCHAR(100) NOT NULL,
    street VARCHAR(200) NOT NULL,
    Zip INT NOT NULL,
    phone VARCHAR(15) NOT NULL
);

CREATE TABLE "order" (
    ono INT PRIMARY KEY,
    cno INT NOT NULL,
    receivedate DATE NOT NULL,
    shippeddate DATE,
    FOREIGN KEY (cno) REFERENCES customer(cno)
);

CREATE TABLE odetails (
    odetail_id INT PRIMARY KEY,
    ono INT NOT NULL,
    pno INT NOT NULL,
    qty INT CHECK (qty > 0) NOT NULL,
    FOREIGN KEY (ono) REFERENCES "order"(ono),
    FOREIGN KEY (pno) REFERENCES parts(pno)
);

CREATE TABLE zipcode (
    Zip INT PRIMARY KEY,
    city VARCHAR(100) NOT NULL
);
