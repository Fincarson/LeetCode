import pandas as pd

def sales_analysis(product: pd.DataFrame, sales: pd.DataFrame) -> pd.DataFrame:
    # Calculate total sales price for each seller
    aggregated_sales = sales.groupby("seller_id").agg({"price": "sum"})

    # Filter the sellers with maximum total sales price
    best_sellers = aggregated_sales[
        aggregated_sales["price"] == aggregated_sales["price"].max()
    ].reset_index()

    return best_sellers[["seller_id"]]
