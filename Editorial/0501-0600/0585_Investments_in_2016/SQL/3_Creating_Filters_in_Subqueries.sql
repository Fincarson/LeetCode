SELECT CONCAT(lat, lon) lat_lon
FROM Insurance
GROUP BY CONCAT(lat, lon)
HAVING COUNT(DISTINCT pid) = 1
