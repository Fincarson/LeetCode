SELECT DISTINCT s.buyer_id
FROM Sales s
JOIN Product p
ON s.product_id = p.product_id
AND p.product_name = 'S8'
LEFT JOIN
    (
    SELECT DISTINCT buyer_id
    FROM Sales s
    JOIN Product p
    ON s.product_id = p.product_id
    AND p.product_name = 'iPhone'
    )a
ON s.buyer_id = a.buyer_id
WHERE a.buyer_id IS NULL
