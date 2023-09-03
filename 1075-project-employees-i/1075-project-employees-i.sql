with cte as(
select p.project_id,e.experience_years as exp from Project p inner join Employee e on p.employee_id=e.employee_id
)
select project_id,round(avg(exp),2) as average_years from cte group by project_id