SELECT 
    DISTINCT p.product_name,
    p.product_id,
    o.order_id,
    o.order_date
FROM 
    Products p 
JOIN 
    Orders o
ON 
    p.product_id = o.product_id
