WITH
  min_data AS (
    SELECT
      A.player_id,
      MIN(A.event_date) AS event_date
    FROM
      Activity A
    GROUP BY
      A.player_id
  )
SELECT
  A2.player_id,
  A2.device_id
FROM
  Activity A2
  INNER JOIN min_data M ON M.player_id = A2.player_id
  AND M.event_date = A2.event_date;
