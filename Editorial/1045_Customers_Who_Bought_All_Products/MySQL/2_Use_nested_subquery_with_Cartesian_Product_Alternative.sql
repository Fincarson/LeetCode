SELECT DISTINCT
  customer_id
FROM
  Customer
WHERE
  customer_id NOT IN (
    SELECT
      customer_id
    FROM
      (
        SELECT DISTINCT
          Customer.customer_id,
          Product.product_key
        FROM
          Customer,
          Product
      ) AS AllPossibleCases
    WHERE
      (customer_id, product_key) NOT IN (
        SELECT
          customer_id,
          product_key
        FROM
          Customer
      )
  );
