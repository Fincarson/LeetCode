import pandas as pd

def find_customers(customers: pd.DataFrame, orders: pd.DataFrame) -> pd.DataFrame:
    buyA = orders.loc[orders['product_name'] == 'A', 'customer_id']
    buyB = orders.loc[orders['product_name'] == 'B', 'customer_id']
    buyC = orders.loc[orders['product_name'] == 'C', 'customer_id']

    condA = customers['customer_id'].isin(buyA)
    condB = customers['customer_id'].isin(buyB)
    condC = ~customers['customer_id'].isin(buyC)
    df = customers[condA & condB & condC]
    return df.sort_values(by = 'customer_id')
