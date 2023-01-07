# Write your MySQL query statement below
# select name from salesperson 
# where sales_id not in 
# (select sales_id from orders 
#   where com_id = (select com_id from company where name = "RED")
# );

select s.name
from salesperson s
where s.sales_id not in
(
  select o.sales_id 
  from orders o left join company c
  on o.com_id = c.com_id
  where c.name = "RED"
);



