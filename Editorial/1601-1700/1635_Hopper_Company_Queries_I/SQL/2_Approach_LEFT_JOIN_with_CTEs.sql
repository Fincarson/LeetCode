SELECT
    m.month, 
    COUNT(DISTINCT d.driver_id) AS active_drivers,
    COUNT(DISTINCT r.ride_id) AS accepted_rides 
FROM
    Months AS m
LEFT JOIN
    Driver AS d
ON 
    d.month <= m.month
LEFT JOIN
    Ride AS r
ON 
    m.month = r.month
GROUP BY 
    m.month 
ORDER BY 
    m.month
