import pandas as pd

def suspicious_bank_accounts(
    accounts: pd.DataFrame, transactions: pd.DataFrame
) -> pd.DataFrame:
    # Assign a new column 'month' representing the transaction month in 'YYYY-MM' format
    monthly_transactions = transactions.assign(
        month=transactions["day"].dt.to_period("M")
    )

    # Filter for 'Creditor' type transactions
    creditor_transactions = monthly_transactions.query("type == 'Creditor'")

    # Calculate the previous month for each transaction
    creditor_transactions = creditor_transactions.assign(
        prev_month=(transactions["day"] - pd.DateOffset(months=1)).dt.to_period("M")
    )

    # Group by account_id, previous month, and current month, and sum the transaction amounts
    monthly_income = creditor_transactions.groupby(
        ["account_id", "prev_month", "month"], as_index=False
    )["amount"].sum()

    # Merge with the accounts dataframe to compare with max_income
    merged_data = monthly_income.merge(accounts, on="account_id")

    # Filter out rows where the monthly income exceeds the max_income
    over_max_income = merged_data.query("amount > max_income")

    # Merge data with itself to find accounts with excessive income for two consecutive months
    suspicious_accounts = over_max_income.merge(
        over_max_income,
        left_on=["account_id", "prev_month"],
        right_on=["account_id", "month"],
    )

    # Return unique account_ids of suspicious accounts
    return suspicious_accounts[["account_id"]].drop_duplicates()
