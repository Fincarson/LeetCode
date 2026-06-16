import pandas as pd

def replace_employee_id(employees: pd.DataFrame, employee_uni: pd.DataFrame) -> pd.DataFrame:
    employee_name_uni = pd.merge(employees, employee_uni, on='id', how='left')
    answer = employee_name_uni[['unique_id', 'name']]

    return answer
