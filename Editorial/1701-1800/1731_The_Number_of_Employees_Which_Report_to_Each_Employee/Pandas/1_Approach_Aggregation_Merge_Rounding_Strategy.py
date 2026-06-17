import pandas as pd

def count_employees(employees: pd.DataFrame) -> pd.DataFrame:
    # Group employees by their manager to calculate the count of reports and the average age
    by_manager = employees.groupby("reports_to", as_index=False).agg(
        reports_count=("employee_id", "size"),  # Count of reports per manager
        average_age=("age", "mean"),  # Average age of reports
    )

    # Adjust for banker's rounding by adding a very small number before rounding
    by_manager["average_age"] = (by_manager["average_age"] + 1e-12).round(0)

    # Merge the aggregated data with the original employees DataFrame to get the names of managers
    merged = by_manager.merge(
        employees[["employee_id", "name"]],
        how="left",
        left_on="reports_to",
        right_on="employee_id",
    )

    # Since the merge introduces '_x' and '_y' suffixes for overlapping column names, correct this
    # Also, directly rename columns to match expected output format without intermediate steps
    merged.rename(
        columns={
            "employee_id_y": "employee_id",  # This is the actual manager's ID
        },
        inplace=True,
    )

    # Select the columns in the order that matches the expected output
    final_output = merged[["employee_id", "name", "reports_count", "average_age"]]

    return final_output
