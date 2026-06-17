cond = customers['customer_id'].isin(df['customer_id'])
return customers[cond].sort_values(by = 'customer_id')
