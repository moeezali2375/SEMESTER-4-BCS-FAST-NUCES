create table salesman(
id int NOT NULL,
NAME varchar(30),
city varchar(30),
commission float);

insert into salesman VALUES(5001, 'James Hoog','New York', 0.15);
insert into salesman VALUES(5002, 'Nail Knite', 'Paris', 0.13);
insert into salesman VALUES(5005, 'Pit Alex', 'London', 0.11);
insert into salesman VALUES(5006, 'Mc Lyon' ,'Paris', 0.14);
insert into salesman VALUES(5007, 'Paul Adam' ,'San Jose', 0.13);
insert into salesman VALUES(5003, 'Lauson Hen', 'San Jose', 0.12);

create table orders(
order_no int NOT NULL,
purchamt float ,
ord_date date,
customer_id int NOT NULL,
salesman_id int);


INSERT INTO orders VALUES(70001, 150.5, '2012-10-05', 3005, 5006);
INSERT INTO orders VALUES(70009, 270.65, '2011-09-10', 3001 ,5005);
INSERT INTO orders VALUES(70002, 65.26, '2014-10-05' ,3002 ,5001);
INSERT INTO orders VALUES(70004, 110.5, '2011-08-17' ,3009 ,5003);
INSERT INTO orders VALUES(70007, 948.5, '2012-09-10', 3005 ,5006);
INSERT INTO orders VALUES(70005, 2400.6, '2010-07-27', 3007 ,5001);
INSERT INTO orders VALUES(70008, 5760, '2013-09-10' ,3002 ,5001);
INSERT INTO orders VALUES(70010, 1983.43, '2010-10-10', 3004 ,5005);
INSERT INTO orders VALUES(70003, 2480.4, '2013-10-10', 3009 ,5003);
INSERT INTO orders VALUES(70012, 250.45, '2010-06-27', 3008 ,5002);
INSERT INTO orders VALUES(70011, 75.29, '2014-08-17', 3003 ,NULL);
INSERT INTO orders VALUES(70013, 3045.6, '2010-04-25', 3002 ,NULL);

create table customers(
id int NOT NULL,
name varchar(30),
city varchar(30),
grade int,
salesman_id int);

INSERT INTO customers VALUES(3002, 'Nick Rimando', 'New York', 100 ,5001);
INSERT INTO customers VALUES(3007, 'John Brad Davis', 'New York', 200, 5001);
INSERT INTO customers VALUES(3005, 'Graham Zusi', 'California' ,200, 5002);
INSERT INTO customers VALUES(3008, 'Julian Green', 'London' ,300 ,5002);
INSERT INTO customers VALUES(3004, 'Fabian Johnson', 'Paris' ,300, 5006);
INSERT INTO customers VALUES(3009, 'Geoff Cameron', 'Berlin' ,100, 5003);
INSERT INTO customers VALUES(3003, 'Jozy Altidor', 'Moscow' ,200, 5007);
INSERT INTO customers VALUES(3001, 'John Brad Guzan', 'London', Null, 5005);

Alter table SALESMAN ADD primary key (ID);
Alter table ORDERS add primary key (ORDER_NO);
Alter table CUSTOMERS add primary key (ID);


ALTER TABLE ORDERS ADD FOREIGN KEY (salesman_id) REFERENCES SALESMAN(ID)ON DELETE SET NULL ON UPDATE CASCADE;
ALTER TABLE ORDERS ADD FOREIGN KEY (CUSTOMER_id) REFERENCES CUSTOMERS(ID)ON DELETE CASCADE;
ALTER TABLE CUSTOMERS ADD FOREIGN KEY (SALESMAN_ID) REFERENCES SALESMAN(ID)ON DELETE SET NULL ON UPDATE CASCADE;

SELECT *FROM SALESMAN;
SELECT *FROM ORDERS;
SELECT *FROM CUSTOMERS;

--Q3
SELECT ID, CITY
FROM salesman
--Q4
SELECT NAME
FROM CUSTOMERS
ORDER BY NAME ASC
--Q5
SELECT NAME AS FULLNAME FROM SALESMAN
--Q6
SELECT NAME 
FROM CUSTOMERS 
WHERE NAME LIKE '%JOHN%'
AND CITY = 'New York' OR CITY = 'Paris' OR CITY = 'London';
--Q7
SELECT NAME 
FROM CUSTOMERS 
WHERE NAME LIKE '%a%'
--Q8
SELECT order_no,ord_date
FROM ORDERS
ORDER BY ord_date DESC
--Q9
SELECT order_no,ord_date
FROM ORDERS
WHERE MONTH (ORD_DATE) = '1'
--Q10

SELECT DATEPART(year, ORD_DATE) AS YEAR,
DATEPART(MONTH, ORD_DATE) AS MONTH,
DATEPART(DAY, ORD_DATE) AS DAY,
DATEPART(WEEK, ORD_DATE) AS WEEK,
DATEPART(DAYOFYEAR, ORD_DATE) AS DAYNAME,
DATEPART(WEEKDAY, ORD_DATE) AS WEEKDAY
FROM orders
WHERE MONTH(ORD_DATE) = '10'
--Q11
select distinct a.customer_id
from orders as a, orders as b
where a.customer_id = b.customer_id And a.ord_date like '2012-%' and b.ord_date like '2014-%'
--Q12
select distinct a.customer_id
from orders as a, orders as b
where a.customer_id = b.customer_id And a.ord_date like '2012-%'
except 
select distinct a.customer_id
from orders as a, orders as b
where a.customer_id = b.customer_id And a.ord_date like '2014-%'
--Q13
SELECT 3*purchamt AS HUUHHUIIUHUIHUIH
FROM ORDERS
AS PURCHAMT

--Q14
SELECT COMMISSION+0.5
FROM salesman
AS COMMISSION
--Q15
select NAME, ord_date, commission
from (salesman join orders on id = salesman_id)


