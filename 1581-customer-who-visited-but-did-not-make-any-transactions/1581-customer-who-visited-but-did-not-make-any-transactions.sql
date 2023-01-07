# Write your MySQL query statement below
select visits.customer_id, count(*) as count_no_trans 
from visits
where visits.visit_id not in (select distinct visit_id from transactions)
group by visits.customer_id;