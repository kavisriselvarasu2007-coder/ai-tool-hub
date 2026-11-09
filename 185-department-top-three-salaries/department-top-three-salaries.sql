# Write your MySQL query statement below
SELECT 
    d.name AS Department,
    e.name AS Employee,
    e.salary AS Salary
FROM (
    SELECT 
        name,
        salary,
        departmentId,
        DENSE_RANK() OVER (PARTITION BY departmentId ORDER BY salary DESC) AS rk
    FROM Employee
) e
JOIN Department d ON e.departmentId = d.id
WHERE e.rk <= 3;