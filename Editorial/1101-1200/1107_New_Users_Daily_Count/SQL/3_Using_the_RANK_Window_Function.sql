SELECT 
  activity_date AS login_date, 
  COUNT(DISTINCT user_id) AS user_count 
FROM 
  (
    SELECT 
      *, 
      RANK() OVER (
        PARTITION BY user_id 
        ORDER BY 
          activity_date ASC
      ) AS rnk 
    FROM 
      Traffic 
    WHERE 
      activity = 'login'
  ) t0 
WHERE 
  rnk = 1 
  AND DATEDIFF('2019-06-30', activity_date) <= 90 
GROUP BY 
  activity_date
