with cte1 as
(select s.student_id,s.student_name,sub.subject_name 
 from Students s, Subjects sub),

cte2 as
(
    select student_id,count(student_id) as c,subject_name 
    from Examinations 
    group by student_id,subject_name
)

select cte1.student_id,cte1.student_name,cte1.subject_name,case when c is NULL then 0 else c end as attended_exams from cte1 left join cte2 on cte1.student_id=cte2.student_id and cte1.subject_name=cte2.subject_name order by cte1.student_id, cte1.subject_name
