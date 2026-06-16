SELECT id, visit_date, people 
FROM stadium_with_rnk
WHERE island IN (SELECT island 
                 FROM stadium_with_rnk 
                 GROUP BY island 
                 HAVING COUNT(*) >= 3)
ORDER BY visit_date
