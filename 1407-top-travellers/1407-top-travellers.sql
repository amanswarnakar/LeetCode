# Write your MySQL query statement below
select name, if(r.dis is null, 0, r.dis) as travelled_distance 
from users u left join (
  select user_id, sum(distance) as dis 
  from rides
  group by user_id
) r 
on u.id = r.user_id
order by travelled_distance desc, name asc;
