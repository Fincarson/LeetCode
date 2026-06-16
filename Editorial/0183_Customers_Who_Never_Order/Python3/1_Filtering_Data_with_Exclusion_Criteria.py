# Select the rows which `id` is not present in orders['customerId'].
df = customers[~customers['id'].isin(orders['customerId'])]
