# Write your MySQL query statement below
select Em.unique_id,e.name from Employees e left join EmployeeUNI Em on e.id=Em.id