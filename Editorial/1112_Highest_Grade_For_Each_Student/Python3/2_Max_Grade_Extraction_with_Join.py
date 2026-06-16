result = (
    merged.groupby("student_id")
    .apply(lambda x: x.nsmallest(1, "course_id"))
    .reset_index(drop=True)
)
