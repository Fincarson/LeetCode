import pandas as pd

def find_investments(insurance: pd.DataFrame) -> pd.DataFrame:

   df = insurance[insurance.duplicated(subset=['tiv_2015'], keep=False) & ~insurance.duplicated(subset=['lat', 'lon'], keep=False)]

   return df.agg(tiv_2016 = ('tiv_2016', 'sum')).round(2)
