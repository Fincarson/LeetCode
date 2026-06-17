SELECT 
  DISTINCT user_id 
FROM 
  RankedCalls 
WHERE 
  rank_earliest_call = 1 
  OR rank_latest_call = 1 -- Filtering for first and last calls
GROUP BY 
  user_id, 
  call_date 
HAVING 
  COUNT(DISTINCT other_participant_id) = 1;
