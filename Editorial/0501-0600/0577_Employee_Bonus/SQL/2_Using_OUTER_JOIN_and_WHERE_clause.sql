SELECT
    Employee.name, Bonus.bonus
FROM
    Employee
        LEFT OUTER JOIN
    Bonus ON Employee.empid = Bonus.empid
;
