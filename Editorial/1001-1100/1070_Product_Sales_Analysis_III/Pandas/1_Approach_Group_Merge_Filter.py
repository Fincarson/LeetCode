import pandas as pd

def sales_analysis(sales: pd.DataFrame, product: pd.DataFrame) -> pd.DataFrame:
  df = sales.groupby('product_id', as_index=False)['year'].min()
  return sales.merge(df, on='product_id', how='inner')\
    .query('year_x == year_y')\
    .rename(columns={'year_x': 'first_year'})\
    [['product_id', 'first_year', 'quantity', 'price']]
