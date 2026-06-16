import pandas as pd

def human_traffic(stadium: pd.DataFrame) -> pd.DataFrame:

    df = stadium[stadium['people'] >= 100]
    
    df['flag'] = ((df['id'].diff() == 1) & (df['id'].diff().shift(1) == 1))
    
    df = df[(df['flag'] == True)| (df['flag'].shift(-1) == True) | (df['flag'].shift(-2) == True)]
    
    rreturn df.loc[:, df.columns != 'flag'].sort_values(by='visit_date')
