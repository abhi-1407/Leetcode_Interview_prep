# Write your MySQL query statement below

select id,movie,description,rating from Cinema where description <> "boring" and mod(id,2)!=0 order by rating desc  