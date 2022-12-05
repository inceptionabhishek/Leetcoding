# Write your MySQL query statement below


SELECT name as Employee FROM Employee E1
WHERE salary>(SELECT salary FROM Employee WHERE id=E1.managerId);