# Write your MySQL query statement below
with cte as(
select user_id,round(sum(case when action="confirmed" then 1 else 0 end)/count(*),2) as confirmation_rate from Confirmations group by user_id)

# select * from cte
select s.user_id,(case when c.confirmation_rate is null then 0 else c.confirmation_rate end ) as confirmation_rate from Signups as s left join cte as c on s.user_id=c.user_id 