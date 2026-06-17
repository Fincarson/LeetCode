ROUND(
  COUNT(DISTINCT user_id) * 100.0 / (SELECT COUNT(user_id) FROM Users), 
  2
) AS percentage
