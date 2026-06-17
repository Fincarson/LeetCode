import pandas as pd

def students_and_examinations(students: pd.DataFrame, subjects: pd.DataFrame, examinations: pd.DataFrame) -> pd.DataFrame:
    # Group by id and subject and count the number of exams.
    grouped = examinations.groupby(['student_id', 'subject_name']).size().reset_index(name='attended_exams')

    # Get all combinations of (id, subject) 
    all_id_subjects = pd.merge(students, subjects, how='cross')

    # Left join to retain all combinations.
    id_subjects_count = pd.merge(all_id_subjects, grouped, on=['student_id', 'subject_name'], how='left')
    
    # Data cleaning.
    id_subjects_count['attended_exams'] = id_subjects_count['attended_exams'].fillna(0).astype(int)
    
    # Sort DataFrame in ascending based on 'student_id', 'subject_name'.
    id_subjects_count.sort_values(['student_id', 'subject_name'], inplace=True)

    return id_subjects_count[['student_id', 'student_name', 'subject_name', 'attended_exams']]
