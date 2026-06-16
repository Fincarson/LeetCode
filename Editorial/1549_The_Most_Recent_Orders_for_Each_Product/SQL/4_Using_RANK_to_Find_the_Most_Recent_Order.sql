SELECT 
    order_id, 
    order_date, 
    product_id,
    RANK() OVER (PARTITION BY product_id ORDER BY order_date DESC) AS rnk
FROM 
    Orders
