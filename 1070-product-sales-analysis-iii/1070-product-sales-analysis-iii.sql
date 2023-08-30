# Write your MySQL query statement below
# with cte as(
# select product_id,min(year) as first_year,quantity,price from Sales group by product_id)

# select p.product_id,cte.first_year,cte.quantity,cte.price from cte inner join Sales p on cte.product_id=p.product_id and cte.first_year=p.year

SELECT product_id, year AS first_year, quantity, price
FROM Sales
WHERE (product_id, year)
IN(SELECT product_id, MIN(year) AS year 
FROM Sales
GROUP BY product_id);