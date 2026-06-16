import pandas as pd

def count_trusted_contacts(
    customers: pd.DataFrame, contacts: pd.DataFrame, invoices: pd.DataFrame
) -> pd.DataFrame:
    # Merge contacts with customers
    contact_customer = (
        pd.merge(
            contacts, customers, left_on="contact_email", right_on="email", how="left"
        )
        .groupby("user_id")
        .agg(contacts_cnt=("user_id", "count"), trusted_contacts_cnt=("email", "count"))
        .reset_index()
    )

    # Merge invoices with customers and then with the contact_customer DataFrame
    invoice_customer = (
        pd.merge(
            pd.merge(
                invoices,
                customers,
                left_on="user_id",
                right_on="customer_id",
                how="left",
            ),
            contact_customer,
            on="user_id",
            how="left",
        )
        .fillna(0)
        .sort_values("invoice_id")
    )

    # Select and return the relevant columns
    return invoice_customer[
        ["invoice_id", "customer_name", "price", "contacts_cnt", "trusted_contacts_cnt"]
    ]
