# Write your MySQL query statement below
select firstname, lastname, city, state from person left join address on person.personId = address.personId;