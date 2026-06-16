import pandas as pd
​
def sales_analysis(product: pd.DataFrame, sales: pd.DataFrame) -> pd.DataFrame:

sales_and_product = sales.merge(product, on = 'product_id')

iphone_sales = sales_and_product[sales_and_product['product_name'] == 'iPhone']

s8_sales = sales_and_product[sales_and_product['product_name'] == 'S8']

df = s8_sales[~s8_sales.buyer_id.isin(iphone_sales['buyer_id'])]

return df[['buyer_id']].drop_duplicates()
