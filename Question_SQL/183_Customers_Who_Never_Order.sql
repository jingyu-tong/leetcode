// 利用左链接链接两个表，然后找出在Orders中不存在的即可
SELECT c.Name Customers FROM Customers c
LEFT JOIN Orders o ON c.Id = o.CustomerId
WHERE o.CustomerId IS NULL;

//还可以利用嵌套select，挑选出不在Orders中的Id
SELECT Name AS Customers FROM Customers 
WHERE Id NOT IN (SELECT CustomerId FROM Orders);