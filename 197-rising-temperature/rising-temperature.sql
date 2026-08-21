# Write your MySQL query statement below
SELECT w1.id
FROM Weather w1 INNER JOIN Weather w2
WHERE SUBDATE(w1.recordDate,1)=w2.recordDate AND
w1.temperature > w2.temperature