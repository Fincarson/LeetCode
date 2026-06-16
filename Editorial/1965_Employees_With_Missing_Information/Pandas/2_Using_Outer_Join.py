import pandas as pd

def find_employees(employees: pd.DataFrame, salaries: pd.DataFrame) -> pd.DataFrame:
    # Merge the employees and salaries DataFrames on 'employee_id', including all records from both.
    merged_df = pd.merge(employees, salaries, on="employee_id", how="outer")

    # Identify rows with missing values in any column.
    missing_data_df = merged_df[merged_df.isna().any(axis=1)]

    # Select only the 'employee_id' column and sort the IDs.
    result_df = missing_data_df[["employee_id"]].sort_values(by="employee_id")

    return result_df
