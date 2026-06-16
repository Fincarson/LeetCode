import pandas as pd
​
def median_employee_salary(employee: pd.DataFrame) -> pd.DataFrame:

    employee['rank'] = pd.to_numeric(employee.sort_values(['salary','id']).groupby('company').cumcount() + 1)

    df = employee.groupby('company', as_index=False)['id'].count().rename(columns={'id': 'cnt'})

    df2 = df.merge(employee, on='company')

    df2 = df2.loc[(df2['rank'] >= df2['cnt'] / 2) & (df2['rank'] <= df2['cnt'] / 2 + 1)]

    return df2[['id', 'company', 'salary']]
