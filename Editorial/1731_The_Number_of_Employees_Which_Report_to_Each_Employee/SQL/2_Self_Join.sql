SELECT 
  mgr.employee_id, 
  mgr.name, 
  COUNT(emp.employee_id) AS reports_count, 
  ROUND(AVG(emp.age)) AS average_age
