create databse assgn9;
use assgn9;

CREATE TABLE EMPLOYEE (
    ENo NUMBER PRIMARY KEY,
    FName VARCHAR2(100),
    Age NUMBER,
    Grade VARCHAR2(50),
    Salary NUMBER
);

INSERT INTO EMPLOYEE VALUES (101, 'John', 35, 'Asst. Prof', 50000);
INSERT INTO EMPLOYEE VALUES (102, 'Alice', 40, 'Associate Prof', 70000);
INSERT INTO EMPLOYEE VALUES (103, 'Bob', 45, 'Professor', 90000);

DECLARE  
    -- Define a cursor to fetch employee records
    CURSOR Emp_Cursor IS  
    SELECT ENo, Grade, Salary FROM EMPLOYEE;  

    -- Variables to hold data from cursor  
    v_ENo EMPLOYEE.ENo%TYPE;  
    v_Grade EMPLOYEE.Grade%TYPE;  
    v_Salary EMPLOYEE.Salary%TYPE;  
    v_Increment NUMBER;  

BEGIN   
    OPEN Emp_Cursor;  
    LOOP  
        FETCH Emp_Cursor INTO v_ENo, v_Grade, v_Salary;  
        EXIT WHEN Emp_Cursor%NOTFOUND;  

        IF v_Grade = 'Asst. Prof' THEN  
            v_Increment := 10000;  
        ELSIF v_Grade = 'Associate Prof' THEN  
            v_Increment := 20000;  
        ELSIF v_Grade = 'Professor' THEN  
            v_Increment := 30000;  
        ELSE  
            v_Increment := 0;
        END IF;  
 
        UPDATE EMPLOYEE  
        SET Salary = Salary + v_Increment  
        WHERE ENo = v_ENo;  
    END LOOP;  

    CLOSE Emp_Cursor;  
    COMMIT;  
END;  
/
