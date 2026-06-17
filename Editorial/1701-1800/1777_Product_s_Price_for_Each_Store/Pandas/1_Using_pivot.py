import pandas as pd

def products_price(products: pd.DataFrame) -> pd.DataFrame:
    # Approach: Utilize .pivot() to get unique stores

    # Utilizing product_id as the index, we will destructure the values 
    # as columns and have the values be the price
    df = products.pivot(index='product_id', columns='store', values='price').reset_index()

    return df
