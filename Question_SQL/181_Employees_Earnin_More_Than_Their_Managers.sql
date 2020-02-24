//这题OJ不懂为什么，答案居然不用去重。。。
# Write your MySQL query statement below
SELECT  e1.Name  Employee FROM Employee e1, Employee e2
WHERE  e1.ManagerId = e2.ID 
AND e1.Salary > e2.Salary