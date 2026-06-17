import pandas as pd

def highest_grade(enrollments: pd.DataFrame) -> pd.DataFrame:
    sorted_df = enrollments.sort_values(
        by=["student_id", "grade", "course_id"], ascending=[True, False, True]
    )
    result = sorted_df.groupby("student_id").head(1).reset_index(drop=True)
    return result
