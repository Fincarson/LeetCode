import pandas as pd

def find_customers(visits: pd.DataFrame, transactions: pd.DataFrame) -> pd.DataFrame:

   visits_no_trans = visits[~visits.visit_id.isin(transactions.visit_id)]
   
   df = visits_no_trans.groupby('customer_id', as_index=False)['visit_id'].count()
    
   return df.rename(columns={'visit_id': 'count_no_trans'})
