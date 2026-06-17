   SELECT DISTINCT group_id, 
       FIRST_VALUE(TotalScores.player_id) OVER (
           PARTITION BY group_id 
           ORDER BY total_score DESC, TotalScores.player_id
       ) AS player_id
   FROM TotalScores 
   LEFT JOIN players ON TotalScores.player_id = players.player_id
