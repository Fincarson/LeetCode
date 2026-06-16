import pandas as pd

def project_employees(project: pd.DataFrame, employee: pd.DataFrame) -> pd.DataFrame:

    project_and_employee = project.merge(employee, on = 'employee_id')

    only_max = project_and_employee.groupby(['project_id'], as_index = False)['experience_years'].max()

    df = project_and_employee.merge(only_max, on = ['project_id', 'experience_years'])[['project_id', 'employee_id']]

    return df
