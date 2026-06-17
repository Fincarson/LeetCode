import pandas as pd

def sales_by_day(orders: pd.DataFrame, items: pd.DataFrame) -> pd.DataFrame:
  
    df = items.merge(orders, how='left', on='item_id').rename(columns={'item_category': 'category'})

    all_weekdays = pd.CategoricalDtype(
        categories = ['MONDAY', 'TUESDAY', 'WEDNESDAY', 'THURSDAY', 'FRIDAY', 'SATURDAY', 'SUNDAY'], 
        ordered=True)

    df['dayofweek'] = df['order_date'].dt.day_name().str.upper().astype(all_weekdays)

    df = df.pivot_table(index='category', columns='dayofweek', values='quantity', aggfunc='sum').reset_index()

    return df
