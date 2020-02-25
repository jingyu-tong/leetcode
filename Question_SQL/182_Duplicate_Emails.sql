//这题要求解重复的元素
//利用GROUP BY对Email进行分组，然后输出个数超过1的分组即可
SELECT Email FROM Person GROUP BY Email
HAVING COUNT(*) > 1;

//利用自连接也可以
SELECT DISTINCT p1.Email FROM Person p1
JOIN Person p2 ON p2.Email = p1.Email
WHERE p2.Id <> p1.Id 