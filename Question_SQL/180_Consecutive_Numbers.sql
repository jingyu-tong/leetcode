//利用自连接，在连续三组ID中查找出合适的，最后答案去重
SELECT DISTINCT l1.Num ConsecutiveNums from Logs l1, Logs l2, Logs l3
where l1.Id = l2.Id - 1 AND l2.Id = l3.Id - 1
AND l1.Num = l2.Num AND l2.Num = l3.Num

//利用链接，也可以添加满足两两关系的行
//查了下，JOIN默认是INNER JOIN，所以可以省略
//另外，简单测试了几次，join的方法，比前面的效率高一些，不懂原因
//以后进一步了解mysql之后可能会懂吧
SELECT DISTINCT l1.Num ConsecutiveNums FROM Logs l1
INNER JOIN Logs l2 ON l1.Id = l2.Id - 1
INNER JOIN Logs l3 ON l1.Id = l3.Id - 2
WHERE l1.Num = l2.Num AND l2.Num = l3.Num;