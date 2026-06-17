SELECT
  S.id AS S_ID,
  S.score AS S_Score,
  T.id AS T_ID,
  T.score AS T_Score
FROM
  Scores S
  INNER JOIN Scores T ON S.score <= T.score
ORDER BY
  S.id,
  T.score;
