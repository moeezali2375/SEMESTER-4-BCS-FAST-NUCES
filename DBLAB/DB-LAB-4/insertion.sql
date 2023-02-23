create table salesman(id int NOT NULL,salesman varchar(30),city varchar(30),commission float);

insert into salesman VALUES(5001, 'James Hoog','New York', 0.15);
insert into salesman VALUES(5002, 'Nail Knite', 'Paris', 0.13);
insert into salesman VALUES(5005, 'Pit Alex', 'London', 0.11);
insert into salesman VALUES(5006, 'Mc Lyon' ,'Paris', 0.14);
insert into salesman VALUES(5007, 'Paul Adam' ,'San Jose', 0.13);
insert into salesman VALUES(5003, 'Lauson Hen', 'San Jose', 0.12);

create table orders(order_no int NOT NULL,purchamt float ,ord_date date,customer_id int NOT NULL,salesman_id int);


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
create table customers(id int NOT NULL,name varchar(30),city varchar(30),grade int,salesman_id int);

INSERT INTO customers VALUES(3002, 'Nick Rimando', 'New York', 100 ,5001);
INSERT INTO customers VALUES(3007, 'John Brad Davis', 'New York', 200, 5001);
INSERT INTO customers VALUES(3005, 'Graham Zusi', 'California' ,200, 5002);
INSERT INTO customers VALUES(3008, 'Julian Green', 'London' ,300 ,5002);
INSERT INTO customers VALUES(3004, 'Fabian Johnson', 'Paris' ,300, 5006);
INSERT INTO customers VALUES(3009, 'Geoff Cameron', 'Berlin' ,100, 5003);
INSERT INTO customers VALUES(3003, 'Jozy Altidor', 'Moscow' ,200, 5007);
INSERT INTO customers VALUES(3001, 'John Brad Guzan', 'London', Null, 5005);


