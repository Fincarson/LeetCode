SELECT 
  reports_to AS employee_id, 
  (
    SELECT name FROM employees e1 WHERE e.reports_to = e1.employee_id
  ) AS name,
