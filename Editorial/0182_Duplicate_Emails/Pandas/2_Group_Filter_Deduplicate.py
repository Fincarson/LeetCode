import pandas as pd

def duplicate_emails(person: pd.DataFrame) -> pd.DataFrame:
  duplicated_emails_df = person.groupby('email').filter(lambda x: len(x) > 1)[['email']].drop_duplicates()
  
  return duplicated_emails_df
