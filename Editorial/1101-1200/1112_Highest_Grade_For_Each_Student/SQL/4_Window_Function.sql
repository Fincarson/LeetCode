SELECT 
  student_id, 
  course_id, 
  grade 
FROM 
  (
    SELECT 
      student_id, 
      course_id, 
      grade, 
      DENSE_RANK() OVER (
        PARTITION BY student_id 
        ORDER BY 
          grade DESC, 
          course_id ASC
      ) AS rnk 
    FROM 
      Enrollments
  ) AS ranked 
WHERE 
  rnk = 1 
ORDER BY 
  student_id;
