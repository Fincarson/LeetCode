SELECT
    p1.x,
    p1.y,
    p2.x,
    p2.y,
    SQRT((POW(p1.x - p2.x, 2) + POW(p1.y - p2.y, 2))) AS distance
FROM
    point_2d p1
        JOIN
    point_2d p2 ON p1.x != p2.x OR p1.y != p2.y
;
