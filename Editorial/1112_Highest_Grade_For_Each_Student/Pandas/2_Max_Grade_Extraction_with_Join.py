import pandas as pd


def highest_grade(enrollments: pd.DataFrame) -> pd.DataFrame:
    max_grades = enrollments.groupby("student_id")["grade"].max().reset_index()
    merged = pd.merge(enrollments, max_grades, on=["student_id", "grade"])
    result = (
        merged.groupby("student_id")
        .apply(lambda x: x.nsmallest(1, "course_id"))
        .reset_index(drop=True)
    )
    return result[["student_id", "course_id", "grade"]]
