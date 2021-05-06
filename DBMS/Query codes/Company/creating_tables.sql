create database company;
use company;
create table department(
Dep_Name varchar(10) not null,
Dep_Number integer not null,
Manager_SSN char(9) not null,
Manager_start_date char(9),
primary key(Dep_Number),
foreign key (Manager_SSN) references employee (SSN)
);

select * from department;
create table employee(
Emp_Name varchar(20) not null,
SSN varchar(10) not null,
SSN_Bdate varchar(9) not null,
address varchar(30) not null,
gender char(1) not null,
Salary float not null,
Super_SSN varchar(10),
primary key(SSN)
);
alter table employee modify SSN_Bdate varchar(10);
insert into employee values("John","00112233","02-06-2001","Belgavi","M","100","");
insert into employee values("Nixon","01230123","06-02-2001","Belgavi","M","100","");
select * from employee;

alter table employee add designation varchar(10);
alter table employee modify designation varchar(20);
select * from employee;
update employee set designation = "CEO";
select * from employee;
insert into employee values("Nixon","12341234","01-06-2002","Belgavi","M","100","","owner");
select * from employee;

update employee set address="bangalore" where SSN ="00112233";
select * from employee;

delete from employee where SSN="12341234";
select * from employee;


insert into department values("ISE", 1, "00112233","06-05-2021");
alter table department modify Manager_start_date varchar(10);
select * from department;


alter table employee add Dep_Number int;
select * from employee;

alter table employee add foreign key (Dep_Number) references department (Dep_Number);

update employee set Dep_Number =1;
