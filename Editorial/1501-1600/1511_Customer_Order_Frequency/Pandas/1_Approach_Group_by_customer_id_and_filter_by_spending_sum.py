import pandas as pd

def customer_order_frequency(
    customers: pd.DataFrame, product: pd.DataFrame, orders: pd.DataFrame
) -> pd.DataFrame:

    # Merge and filter for year 2020
    merged_df = pd.merge(
        pd.merge(orders, customers, on="customer_id"), product, on="product_id"
    )
    merged_df["order_date"] = pd.to_datetime(merged_df["order_date"])
    merged_df = merged_df[merged_df["order_date"].dt.year == 2020]

    # Group by customer_id and calculate monthly sums
    grouped = merged_df.groupby(["customer_id", merged_df["order_date"].dt.month])
    monthly_sums = grouped.apply(lambda x: (x["quantity"] * x["price"]).sum()).unstack()

    # Filter for customers meeting criteria in both June (6) and July (7)
    valid_customers = monthly_sums[
        (monthly_sums[6] >= 100) & (monthly_sums[7] >= 100)
    ].index

    # Final DataFrame with customer details
    result = customers[customers["customer_id"].isin(valid_customers)]

    return result[["customer_id", "name"]]
