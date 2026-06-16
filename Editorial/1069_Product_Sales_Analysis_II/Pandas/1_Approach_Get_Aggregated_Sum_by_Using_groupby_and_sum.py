import pandas as pd
​
def sales_analysis(sales: pd.DataFrame, product: pd.DataFrame) -> pd.DataFrame:

    pd = sales.groupby(['product_id'], as_index = False)['quantity'].sum().rename(columns = {'quantity': 'total_quantity'})

    return pd
