# Write your MySQL query statement below
# select users.name, a.balance
# from users join (
#   select account, balance 
#   from (
#     select account, sum(amount) as balance
#     from transactions
#     group by account
#   ) t where balance > 10000
# ) a on users.account = a.account;

select u.name as name, sum(t.amount) as balance
from users u join transactions t
on u.account = t.account
group by u.account
having balance > 10000;