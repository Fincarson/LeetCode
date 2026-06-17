import pandas as pd
​
def sales_analysis(product: pd.DataFrame, sales: pd.DataFrame) -> pd.DataFrame:

product_and_sales = product.merge(sales, on = 'product_id')

buyer_score = product_and_sales.groupby('buyer_id').agg(s8_sum = ('product_name', lambda x:(x == 'S8').sum()), iphone_sum = ('product_name', lambda x:(x == 'iPhone').sum())).reset_index()

df = buyer_score[(buyer_score['s8_sum'] > 0)&(buyer_score['iphone_sum'] == 0)]

return df[['buyer_id']]
