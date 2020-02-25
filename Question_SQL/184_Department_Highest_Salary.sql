# 这题，要输出两个表中的内容，我们用JOIN将两个表链接(利用Id)
# 然后找到部门内薪水最高的行
SELECT d.Name AS Department, e1.Name AS Employee, e1.Salary FROM Employee e1
JOIN Department d ON e1.DepartmentId = d.Id WHERE e1.Salary IN 
(SELECT MAX(e2.Salary) FROM Employee e2 WHERE e1.DepartmentId = e2.DepartmentId);



# 官方给出了另一种方式
# 首先，利用GROUP BY 可以求出每个部门最高的薪水的表格
# 然后，利用(Id, Salary) IN 匹配这个表，即可
SELECT
    Department.name AS 'Department',
    Employee.name AS 'Employee',
    Salary
FROM
    Employee
        JOIN
    Department ON Employee.DepartmentId = Department.Id
WHERE
    (Employee.DepartmentId , Salary) IN
    (   SELECT
            DepartmentId, MAX(Salary)
        FROM
            Employee
        GROUP BY DepartmentId
	)
;
