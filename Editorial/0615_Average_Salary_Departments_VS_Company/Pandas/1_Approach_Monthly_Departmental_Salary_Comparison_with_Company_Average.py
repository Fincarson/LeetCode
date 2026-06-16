import pandas as pd

def average_salary(salary: pd.DataFrame, employee: pd.DataFrame) -> pd.DataFrame:
    salary["pay_month"] = salary["pay_date"].dt.strftime("%Y-%m")
    df = salary.merge(employee, on="employee_id")
    df["comp_avg"] = df.groupby(["pay_month"])["amount"].transform("mean")
    df["dep_avg"] = df.groupby(["pay_month", "department_id"])["amount"].transform(
        "mean"
    )
    df["comparison"] = df.apply(
        lambda row: "lower" if row["dep_avg"] < row["comp_avg"] 
            else ("higher" if row["dep_avg"] > row["comp_avg"] else "same"),
        axis=1
    )
    return df[["pay_month", "department_id", "comparison"]].drop_duplicates()
