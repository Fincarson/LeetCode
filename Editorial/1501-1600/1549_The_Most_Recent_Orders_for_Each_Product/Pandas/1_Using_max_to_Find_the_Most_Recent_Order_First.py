import pandas as pd
​
def most_recent_orders(customers: pd.DataFrame, orders: pd.DataFrame, products: pd.DataFrame) -> pd.DataFrame:

    df = orders.groupby(['product_id'], as_index=False).order_date.max()

    df = df.merge(orders, on=['product_id', 'order_date'])

    df = df.merge(products, on='product_id')

    return df[['product_name', 'product_id', 'order_id', 'order_date']].sort_values(['product_name', 'product_id', 'order_id'])
