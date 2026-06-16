SELECT 
    a.sale_date, a.sold_num-b.sold_num AS diff
FROM
    Sales a
JOIN
    Sales b
ON 
    a.sale_date = b.sale_date
AND 
    a.fruit IN ('apples') AND b.fruit IN ('oranges')
GROUP BY 1
ORDER BY 1
