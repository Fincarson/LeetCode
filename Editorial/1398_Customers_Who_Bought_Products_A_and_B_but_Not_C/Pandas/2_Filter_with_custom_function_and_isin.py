import pandas as pd

def find_customers(customers: pd.DataFrame, orders: pd.DataFrame) -> pd.DataFrame:
    def valid(subdf):
        purchased = set(subdf['product_name'])
        return  'A' in purchased and \
                'B' in purchased and \
                'C' not in purchased

    df = orders.groupby('customer_id').filter(valid)

    cond = customers['customer_id'].isin(df['customer_id'])
    return customers[cond].sort_values(by = 'customer_id')
