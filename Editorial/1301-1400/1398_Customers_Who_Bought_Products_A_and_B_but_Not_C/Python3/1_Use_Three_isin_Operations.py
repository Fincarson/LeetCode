df = customers[condA & condB & condC]
return df.sort_values(by = 'customer_id')
