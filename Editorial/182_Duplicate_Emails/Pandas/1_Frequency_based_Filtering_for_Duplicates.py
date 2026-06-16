import pandas as pd

def duplicate_emails(person: pd.DataFrame) -> pd.DataFrame:   
  # Group by 'Email' and count occurrences
  email_counts = person.groupby('email').size().reset_index(name='num')
  
  # Filter for emails that occur more than once
  duplicated_emails_df = email_counts[email_counts['num'] > 1][['email']]
  
  return duplicated_emails_df
