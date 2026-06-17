import pandas as pd

def find_primary_department(employee: pd.DataFrame) -> pd.DataFrame:
    # 1. Calculate EmployeeCount as the number of rows for each employee_id
    employee["EmployeeCount"] = employee.groupby("employee_id")[
        "employee_id"
    ].transform("size")

    # 2. Filter based on the EmployeeCount or primary_flag
    result = employee[
        (employee["EmployeeCount"] == 1) | (employee["primary_flag"] == "Y")
    ][["employee_id", "department_id"]]

    # 3. Return result
    return result
