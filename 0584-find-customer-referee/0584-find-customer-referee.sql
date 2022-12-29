# Write your MySQL query statement below
# select name from customer where customer.id not in (select id from customer where referee_id = 2);
select name from customer where referee_id <> 2 or referee_id is null;