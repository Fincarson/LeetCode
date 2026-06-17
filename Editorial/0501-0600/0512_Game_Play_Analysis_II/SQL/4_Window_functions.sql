SELECT DISTINCT
  A.player_id,
  LAST_VALUE(A.device_id) OVER (
    PARTITION BY
      A.player_id
    ORDER BY
      A.event_date DESC RANGE BETWEEN UNBOUNDED PRECEDING
      AND UNBOUNDED FOLLOWING
  ) AS device_id
FROM
  Activity A;
