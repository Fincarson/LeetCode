def find_latest_salaries(salary: pd.DataFrame) -> pd.DataFrame:
    df = salary.sort_values(by = 'salary', ascending = False)
    df = df.drop_duplicates(subset = 'emp_id')
    return df.sort_values(by = 'emp_id')
