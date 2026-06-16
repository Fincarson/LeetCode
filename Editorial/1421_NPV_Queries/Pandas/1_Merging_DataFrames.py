import pandas as pd

def npv_queries(npv: pd.DataFrame, queries: pd.DataFrame) -> pd.DataFrame:
    result = pd.merge(queries, npv, on=['id', 'year'], how='left')
    result['npv'].fillna(0, inplace=True)
    return result
