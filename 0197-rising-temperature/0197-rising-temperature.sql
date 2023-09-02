# Write your MySQL query statement below
select t2.id from Weather t1,Weather t2 where datediff(t2.recordDate,t1.recordDate)=1 and t2.temperature>t1.temperature