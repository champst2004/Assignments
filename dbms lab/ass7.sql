create database assgn7;
use assgn7;

create table parts(pno int primary key, pname varchar(100) not null, qty int check (qty >= 0), price decimal(6,2) check (price >= 0), level varchar(100));

insert into parts values(1, "Motor", 250, 50, "low"), (2, "Tyre", 1000, 3500, "mid"), (3, "Seatbelt", 860, 250, "high");

delimiter $$
create procedure update_price()
begin
    update parts set price =
        case
            when qty > 200 then price * 0.8
            else price * 0.7
    end;
end $$

delimiter ;

select * from parts;

call update_price();

select * from parts;