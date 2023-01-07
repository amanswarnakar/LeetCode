# Write your MySQL query statement below
# select name 
# from users 
# where account
select users.name, a.balance
from users join (
  select account, balance 
  from (
    select account, sum(amount) as balance
    from transactions
    group by account
  ) t where balance > 10000
) a on users.account = a.account;