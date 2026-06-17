import pandas as pd
​
def sales_analysis(sales: pd.DataFrame, product: pd.DataFrame) -> pd.DataFrame:
    sales_and_product = sales.merge(
        product,
        on=["product_id"]
        )
    df = sales_and_product[['product_name', 'year', 'price']]

    return df
