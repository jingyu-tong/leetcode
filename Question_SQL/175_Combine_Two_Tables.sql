//因为题目要有不符合的行，所以是外部链接，并且需要的外部行来自Person，这里采用LEFT JOIN
SELECT Person.FirstName, Person.LastName, Address.City, Address.State 
FROM Person LEFT OUTER JOIN Address 
ON Person.PersonId = Address.PersonId;
