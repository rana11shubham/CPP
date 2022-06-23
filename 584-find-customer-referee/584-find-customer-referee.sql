# Write your MySQL query statement below
select name from Customer where id not in (Select id from Customer where referee_id=2)