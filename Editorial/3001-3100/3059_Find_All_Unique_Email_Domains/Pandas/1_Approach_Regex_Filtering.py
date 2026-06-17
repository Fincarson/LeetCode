import pandas as pd

def find_unique_email_domains(emails: pd.DataFrame) -> pd.DataFrame:
    return (
        emails[emails["email"].str.endswith(".com")]
        .assign(email_domain=lambda df: df["email"].str.extract("@([^@]+)$"))
        .groupby("email_domain")["id"]
        .nunique()
        .reset_index(name="count")
        .sort_values(by="email_domain", ascending=True)
    )
