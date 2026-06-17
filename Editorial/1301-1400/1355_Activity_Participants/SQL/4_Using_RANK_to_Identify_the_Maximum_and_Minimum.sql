SELECT activity, 
    RANK () OVER (ORDER BY(COUNT(id))) AS rank_asc,
    RANK () OVER (ORDER BY(COUNT(id))DESC) AS rank_desc
FROM Friends
GROUP BY activity
