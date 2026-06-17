(
  SELECT 
    event_type, 
    AVG(occurrences) AS avg 
  FROM 
    Events 
  GROUP BY 
    event_type
) t0
