create database assgn8;
use assgn8;

CREATE TABLE BOOK (
    Isbn VARCHAR(20) PRIMARY KEY,
    Title VARCHAR(255),
    SoldCopies INT DEFAULT 0
);

CREATE TABLE AUTHOR (
    Name VARCHAR(255) PRIMARY KEY,
    SoldCopies INT DEFAULT 0
);

CREATE TABLE WRITING (
    Isbn VARCHAR(20),
    Name VARCHAR(255),
    PRIMARY KEY (Isbn, Name),
    FOREIGN KEY (Isbn) REFERENCES BOOK(Isbn) ON DELETE CASCADE,
    FOREIGN KEY (Name) REFERENCES AUTHOR(Name) ON DELETE CASCADE
);

CREATE OR REPLACE TRIGGER update_author_soldcopies  
AFTER UPDATE OF SoldCopies ON BOOK  
FOR EACH ROW  
BEGIN  
    UPDATE AUTHOR  
    SET SoldCopies = (  
        SELECT COALESCE(SUM(B.SoldCopies), 0)  
        FROM BOOK B  
        JOIN WRITING W ON B.Isbn = W.Isbn  
        WHERE W.Name = AUTHOR.Name  
    )  
    WHERE Name IN (SELECT Name FROM WRITING WHERE Isbn = :OLD.Isbn);  
END;  
/

CREATE OR REPLACE TRIGGER insert_writing_update_author  
AFTER INSERT ON WRITING  
FOR EACH ROW  
BEGIN  
    UPDATE AUTHOR  
    SET SoldCopies = (  
        SELECT COALESCE(SUM(B.SoldCopies), 0)  
        FROM BOOK B  
        JOIN WRITING W ON B.Isbn = W.Isbn  
        WHERE W.Name = AUTHOR.Name  
    )  
    WHERE Name = :NEW.Name;  
END;  
/
