import pandas as pd

def nth_highest_salary(employee: pd.DataFrame, N: int) -> pd.DataFrame:
    
    dist = employee.drop_duplicates(subset='salary')
    dist['rnk'] = dist['salary'].rank(method='dense', ascending=False)
    ans = dist[dist.rnk == N][['salary']]
    if not len(ans):
        return pd.DataFrame({f'getNthHighestSalary({N})': [None]})
    ans = ans.rename(columns={'salary':f'getNthHighestSalary({N})'})
    return ans
