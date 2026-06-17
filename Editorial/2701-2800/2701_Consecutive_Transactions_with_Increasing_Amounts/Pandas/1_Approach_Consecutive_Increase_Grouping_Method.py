import pandas as pd

def consecutive_increasing_transactions(transactions: pd.DataFrame) -> pd.DataFrame:
    # Sort transactions by customer_id and transaction_date, then reset index
    transactions_sorted = (
        transactions.sort_values(["customer_id", "transaction_date"])
        .reset_index()
    )

    # Create a group identifier for consecutive days ('day_group')
    # Subtracting the transaction date from a fixed date to get the number of days since that date
    # and then subtracting the row index to form groups of consecutive days
    transactions_sorted["day_group"] = (
        transactions_sorted["transaction_date"] - pd.to_datetime("2023-01-01")
    ).dt.days - transactions_sorted.index

    # Create a group identifier for increasing transaction amounts ('amount_group')
    # Formed by cumulatively summing where the transaction amount is not greater than the previous amount
    transactions_sorted["amount_group"] = (
        (transactions_sorted.amount <= transactions_sorted.amount.shift(1))
        .cumsum()
        .fillna(0)
    )

    # Group by customer_id, day_group, and amount_group and perform aggregations
    grouped_transactions = (
        transactions_sorted.groupby(["customer_id", "day_group", "amount_group"])
        .agg(
            count=("index", "count"),
            consecutive_start=("transaction_date", "min"),
            consecutive_end=("transaction_date", "max"),
        )
        .reset_index()
    )

    # Filter groups with at least three consecutive increasing transactions and select relevant columns
    result = grouped_transactions.query("count > 2")[
        ["customer_id", "consecutive_start", "consecutive_end"]
    ]

    return result
