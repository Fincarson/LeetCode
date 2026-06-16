import pandas as pd
​
def find_investments(insurance: pd.DataFrame) -> pd.DataFrame:

   df = insurance.assign(
       tiv_2015_cnt = insurance.groupby('tiv_2015')['pid'].transform('count'),
       loc_cnt = insurance.groupby(['lat', 'lon'])['pid'].transform('count')
   )

   df = df[(df['tiv_2015_cnt'] > 1) & (df['loc_cnt'] == 1)]

   return df.agg(tiv_2016 = ('tiv_2016', 'sum')).round(2)
