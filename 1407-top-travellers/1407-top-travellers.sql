# Write your MySQL query statement below
select name, case 
  when r.user_id is null then 0 
  else sum(r.distance) 
end as travelled_distance 
from users u left join rides r
on u.id = r.user_id
group by u.id
order by travelled_distance desc, name;


# select name, if(r.dis is null, 0, r.dis) as travelled_distance 
# from users u left join (
#   select user_id, sum(distance) as dis 
#   from rides
#   group by user_id
# ) r 
# on u.id = r.user_id
# order by travelled_distance desc, name asc;
