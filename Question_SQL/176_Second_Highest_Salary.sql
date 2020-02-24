//这题要求挑选出某一列中第二大的值，第一反应就是利用LIMIT语句和ORDER BY配合进行挑选
SELECT Salary FROM Employee order by Salary DESC LIMIT 1, 1

//上面的语句大致能够完成题目要求，但是当不存在第二大的值时，返回的不是NULL
//我们可以通过嵌套select进行更改
SELECT (
    SELECT Salary FROM Employee ORDER BY Salary DESC LIMIT 1, 1
) AS SecondHighestSalary;

//上面的唯一问题是没有去重，答案可能还是不对，利用DISTINCT关键字去重后正确
SELECT (
    SELECT DISTINCT Salary FROM Employee ORDER BY Salary DESC LIMIT 1, 1
) AS SecondHighestSalary;

