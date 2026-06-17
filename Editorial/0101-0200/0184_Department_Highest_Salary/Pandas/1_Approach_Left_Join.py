import pandas as pd

def department_highest_salary(employee: pd.DataFrame, department: pd.DataFrame) -> pd.DataFrame:
    # Merge tables and rename
    df = employee.merge(department, left_on='departmentId', right_on='id', how='left')
    df.rename(columns={'name_x': 'Employee', 'name_y': 'Department', 'salary': 'Salary'}, inplace=True)
    
    # Select employees whose salary is equal to the department highest salary
    max_salary = df.groupby('Department')['Salary'].transform('max')
    df = df[df['Salary'] == max_salary]
    
    return df[['Department', 'Employee', 'Salary']]
