# Write your MySQL query statement below
select a.id as id
from weather a join weather b
on a.temperature > b.temperature 
and datediff(a.recordDate, b.recordDate) = 1;