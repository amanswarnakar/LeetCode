# Write your MySQL query statement below
# select actor_id, director_id 
# from (
#   select actor_id, director_id, count(timestamp) as coop
#   from actordirector
#   group by actor_id, director_id
# ) t
# where coop >= 3;

select actor_id, director_id
from actordirector
group by actor_id, director_id
having count(timestamp) >= 3;