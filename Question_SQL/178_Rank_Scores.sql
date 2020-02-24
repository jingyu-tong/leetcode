//这题引用了自身的数据，所以用了自连接的方式
//排名用的是不大于自身的score的个数
# Write your MySQL query statement below
SELECT Score, 
(SELECT COUNT(DISTINCT Score) FROM Scores b WHERE b.Score >= a.Score) Rank
FROM Scores a ORDER BY Score DESC

//还有一种利用变量的方式
//注意，sql中引用变量要在前面+@
//<>运算true为1，false为0
//这里思路也不难，利用的就是排序后非升序列的特性来改变rank变量
SELECT Score,
@rank := @rank + (@pre <> (@pre := Score)) Rank
FROM Scores, (SELECT @rank := 0, @pre := -1) INIT 
ORDER BY Score DESC;