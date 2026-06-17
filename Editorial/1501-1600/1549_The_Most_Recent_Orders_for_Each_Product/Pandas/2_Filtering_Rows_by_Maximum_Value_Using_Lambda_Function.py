import pandas as pd
​
def most_recent_orders(customers: pd.DataFrame, orders: pd.DataFrame, products: pd.DataFrame) -> pd.DataFrame:

    df = orders.merge(products, on='product_id').reset_index()

    df = df.groupby('product_id').apply(lambda x:x[x.order_date == x.order_date.max()]).reset_index(drop=True)

    return df[['product_name', 'product_id', 'order_id', 'order_date']].sort_values(['product_name', 'product_id', 'order_id'])
