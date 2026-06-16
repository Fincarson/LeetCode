UNION 
SELECT 
  'bear' AS word, 
  SUM(
    CASE WHEN content REGEXP '( bear )' THEN 1 ELSE 0 END
  ) AS count 
FROM 
  Files
