SELECT
  id,
  MIN(
    CASE
      WHEN month = "Jan" THEN revenue
    END
  ) AS Jan_Revenue,
  ...
FROM
  Department
GROUP BY
  id;
