SELECT *,
   COUNT(*)OVER(PARTITION BY tiv_2015) AS tiv_2015_cnt,
   COUNT(*)OVER(PARTITION BY lat, lon) AS loc_cnt
FROM Insurance
