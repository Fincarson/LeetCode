import pandas as pd


def highest_grade(enrollments: pd.DataFrame) -> pd.DataFrame:
    max_grades = enrollments.groupby("student_id")["grade"].transform("max")
    filtered = enrollments[enrollments["grade"] == max_grades]
    result = (
        filtered.groupby("student_id")
        .apply(lambda group: group.nsmallest(1, "course_id"))
        .reset_index(drop=True)
    )
    return result[["student_id", "course_id", "grade"]]
