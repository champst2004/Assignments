create database assign3;
use assign3;

create table employee(empno int, ename varchar(20), job varchar(20), mgr int, hiredate date, salary int, commission int, deptno int);
create table dept(deptno int, dname varchar(20), loc varchar(20));

INSERT INTO employee VALUES (7369, "Smith", "Clerk", 7902, "1980-12-17", 800, 300, 20);
INSERT INTO employee VALUES (7499, "Allen", "Salesman", 7698, "1981-02-20", 1600, 300, 30);
INSERT INTO employee VALUES (7521, "Ward", "Salesman", 7698, "1981-02-22", 1250, 500, 30);
INSERT INTO employee VALUES (7566, "Jones", "Manager", 7839, "1981-04-02", 2975, 210, 20);
INSERT INTO employee VALUES (7698, "Blake", "Manager", 7839, "1981-05-01", 2850, 340, 30);
INSERT INTO employee VALUES (7782, "Clark", "Manager", 7839, "1981-06-09", 2450, 110, 10);
INSERT INTO employee VALUES (7788, "Scott", "Analyst", 7566, "1987-04-19", 3000, 100, 20);
INSERT INTO employee VALUES (7839, "King", "President", 7516, "1981-11-17", 5000, 120, 10);
INSERT INTO employee VALUES (7844, "Turner", "Salesman", 7698, "1981-09-08", 1500, 690, 30);
INSERT INTO employee VALUES (7876, "Adams", "Clerk", 7788, "1987-05-23", 1100, 410, 20);

INSERT INTO dept VALUES (10, "Accounting", "New York");
INSERT INTO dept VALUES (20, "Research", "Dallas");
INSERT INTO dept VALUES (30, "Sales", "Chicago");
INSERT INTO dept VALUES (40, "Operations", "Boston");
INSERT INTO dept VALUES (50, "Marketing", "San Francisco");
INSERT INTO dept VALUES (60, "HR", "Seattle");
INSERT INTO dept VALUES (70, "IT", "Austin");
INSERT INTO dept VALUES (80, "Logistics", "Denver");
INSERT INTO dept VALUES (90, "Legal", "Washington");
INSERT INTO dept VALUES (100, "Support", "Atlanta");


SELECT deptno, ename, (salary * 12 + commission) AS annual_salary FROM employee ORDER BY deptno;

SELECT ename, salary FROM employee ORDER BY salary ASC LIMIT 5;

SELECT * FROM employee WHERE deptno NOT IN (SELECT deptno FROM dept);

SELECT ename, salary FROM employee WHERE MOD(salary, 2) <> 0;

SELECT ename, salary FROM employee WHERE salary BETWEEN 100 AND 999;

SELECT ename, hiredate FROM employee WHERE MONTH(hiredate) = 12;

SELECT ename FROM employee WHERE ename LIKE '%A%';

SELECT MAX(salary) AS max_salary, MIN(salary) AS min_salary, AVG(salary) AS avg_salary FROM employee;

SELECT ename, hiredate, DAYNAME(hiredate) AS day_of_week FROM employee;

SELECT ename, LENGTH(REPLACE(ename, ' ', '')) AS char_count FROM employee;

SELECT ename, salary FROM employee WHERE salary < 1000 ORDER BY salary ASC;