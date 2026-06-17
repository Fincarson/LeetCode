SELECT a.user_id, MAX(DATEDIFF(b.visit_date, a.visit_date)) AS biggest_window
FROM rnk a, rnk b
WHERE a.user_id = b.user_id
AND b.date_rnk = a.date_rnk + 1
GROUP BY a.user_id
