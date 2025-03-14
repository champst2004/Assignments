create database assgn6;
use assgn6;

create table bank(name varchar(100), 
                    acc_no int primary key, 
                    branch_name varchar(40) check (branch_name in ("nsk", "pune")),
                    balance int);

create table admin(name varchar(50) primary key, pin char(4) not null);
insert into admin values("cst4", 2004);
