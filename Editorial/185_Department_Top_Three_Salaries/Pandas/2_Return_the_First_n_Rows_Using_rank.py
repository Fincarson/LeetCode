import pandas as pd
​
def top_three_salaries(employee: pd.DataFrame, department: pd.DataFrame) -> pd.DataFrame:

    top_salary = employee[employee.groupby('departmentId').salary.rank(method='dense', ascending=False) <= 3]

    employee_department = top_salary.merge(department, left_on='departmentId', right_on='id')[['name_y', 'name_x', 'salary']]

    return employee_department.rename(columns = {'name_y': 'Department', 'name_x': 'Employee', 'salary': 'Salary'})
