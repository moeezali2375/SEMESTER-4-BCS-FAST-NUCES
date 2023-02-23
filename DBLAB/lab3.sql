select *from Products

insert into Products values(1,'Lays Salted 200mg',1,18)
insert into Products values(2,'Coca Cola 500 ml',1,19)
insert into Products values(3,'Dairy Milk Chocolate 100 mg',2,10)
insert into Products values(4,'Nestle Water Bottle 250ml',2,22)
insert into Products values(5,'Lipton Tea 500 mg',2,21.35)
insert into Products values(6,'Kitkat 100mg',2,25)
insert into Products values(7,'Pears Soap',7,30)
insert into Products values(8,'Coca Cola Diet 500 ml',2,40)
insert into Products values(9,'Sprite 1.5L',6,97)
insert into Products values(10,'Pepsi 1.5L',8,31)
insert into Products values(11,'Dollar Pen',4,21)
insert into Products values(12,'Aquafina Water Bottle 250ml',4,38)
insert into Products values(13,'Notebook',8,6)
insert into Products values(14,'Wallet',7,230)
insert into Products values(15,'Keychain Batman',2,15.5)
insert into Products values(16,'Lu Gala',3,17.45)


insert into Orders values(10248,9,'04/07/1996')
insert into Orders values(10249,2,'05/07/1996')
insert into Orders values(10250,3,'08/07/1996')
insert into Orders values(10251,1,'08/07/1996')
insert into Orders values(10252,4,'09/07/1996')
insert into Orders values(10253,5,'10/07/1996')
insert into Orders values(10254,6,'11/07/1996')

select * from Orders




select *from OrderDetails

insert into OrderDetails values(1,10248,1,12)
insert into OrderDetails values(2,10248,2,10)
insert into OrderDetails values(3,10248,7,5)
insert into OrderDetails values(4,10249,1,9)
insert into OrderDetails values(5,10249,2,40)
insert into OrderDetails values(6,10250,2,10)
insert into OrderDetails values(7,10250,2,35)
insert into OrderDetails values(8,10250,4,15)
insert into OrderDetails values(9,10251,5,6)
insert into OrderDetails values(10,10251,6,15)
insert into OrderDetails values(11,10251,9,20)
insert into OrderDetails values(12,10252,10,40)
insert into OrderDetails values(13,10252,2,25)
insert into OrderDetails values(14,10252,3,40)
insert into OrderDetails values(15,10253,3,20)
insert into OrderDetails values(16,10253,5,42)
insert into OrderDetails values(17,10253,8,40)
insert into OrderDetails values(18,10254,7,15)
insert into OrderDetails values(19,10254,12,21)





insert into  Customers values(1,'furqan','lahore')
insert into  Customers values(2,'ahmad','lahore')
insert into  Customers values(3,'ali','karachi')
insert into  Customers values(4,'hamza','islamabad')
insert into  Customers values(5,'ayesha','sahiwal')
insert into  Customers values(6,'fatima','lahore')
insert into  Customers values(7,'nabeel','queta')
insert into  Customers values(8,'asad','lahore')
insert into  Customers values(9,'imtiaz','peshawar')
insert into  Customers values(10,'kashif','rawalpindi')
insert into  Customers values(11,'hammad','lahore')
insert into  Customers values(12,'burhan','islamabad')
insert into  Customers values(13,'rida','karachi')

select * from Customers 

--Queries here--------------------------------


--Q1
select distinct CustomerName, ProductName,Price
from (((Customers join Orders on Customers.CustomerID= Orders.CustomerID)
 join OrderDetails on Orders.OrderID=OrderDetails.OrderID )
 join Products on  OrderDetails.ProductId=Products.ProductID );


 --Q2
 select CustomerName,sum(Products.Price) as totalcost
from (((Customers join Orders on Customers.CustomerID= Orders.CustomerID)
 join OrderDetails on Orders.OrderID=OrderDetails.OrderID )
 join Products on  OrderDetails.ProductId=Products.ProductID )
 Group by CustomerName;


 --Q3
 select CustomerName
from (((Customers join Orders on Customers.CustomerID= Orders.CustomerID)
 join OrderDetails on Orders.OrderID=OrderDetails.OrderID )
 join Products on  OrderDetails.ProductId=Products.ProductID )
 where ProductName='Coca Cola 500 ml';

  --Q4
 select ProductName
from (((Customers join Orders on Customers.CustomerID= Orders.CustomerID)
 join OrderDetails on Orders.OrderID=OrderDetails.OrderID )
 join Products on  OrderDetails.ProductId=Products.ProductID )
 where CustomerName='Ayesha';

   --Q5
select Customers.CustomerName ,count(CustomerName)
from (((Customers join Orders on Customers.CustomerID= Orders.CustomerID)
 join OrderDetails on Orders.OrderID=OrderDetails.OrderID )
 join Products on  OrderDetails.ProductId=Products.ProductID )
  Group by CustomerName;
 

    --Q6
 select CustomerName,sum(Products.Price) as totalcost
from (((Customers join Orders on Customers.CustomerID= Orders.CustomerID)
 join OrderDetails on Orders.OrderID=OrderDetails.OrderID )
 join Products on  OrderDetails.ProductId=Products.ProductID )
 Group by CustomerName;


 --Q7
  select ProductName,count (OrderDetails.ProductId)
from (((Customers join Orders on Customers.CustomerID= Orders.CustomerID)
 join OrderDetails on Orders.OrderID=OrderDetails.OrderID )
 join Products on  OrderDetails.ProductId=Products.ProductID )
 group by ProductName;

 --Q8

 select Customers.CustomerName ,count(CustomerName) 
from (((Customers join Orders on Customers.CustomerID= Orders.CustomerID)
 join OrderDetails on Orders.OrderID=OrderDetails.OrderID )
 join Products on  OrderDetails.ProductId=Products.ProductID )
  Group by CustomerName having count(CustomerName)>1









