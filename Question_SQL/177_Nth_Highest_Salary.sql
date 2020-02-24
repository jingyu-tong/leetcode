//可以直接调用176题方法，只要把NSET到N-1即可
CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
    SET N = N - 1;
    RETURN (
        # Write your MySQL query statement below.
        SELECT (
            SELECT DISTINCT Salary 
            FROM Employee ORDER BY Salary DESC LIMIT N, 1 
        ) AS SecondHighestSalary
    );
END