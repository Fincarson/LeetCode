import pandas as pd

def second_highest_salary(employee: pd.DataFrame) -> pd.DataFrame:
    # 1. drop any duplicate salaries.
    employee = employee.drop_duplicates(["salary"])
    
    # 2. If there are less than two unique salaries, return `np.NaN`.
    if len(employee["salary"].unique()) < 2:
        return pd.DataFrame({"SecondHighestSalary": [np.NaN]})
    
    # 3. Sort the table by `salary` in descending order.
    employee = employee.sort_values("salary", ascending=False)
    
    # 4. Drop the `id` column.
    employee.drop("id", axis=1, inplace=True)
    
    # 5. Rename the `salary` column.
    employee.rename({"salary": "SecondHighestSalary"}, axis=1, inplace=True)
    
    # 6, 7. Return the second highest salary.
    return employee.head(2).tail(1)
