CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  RETURN (
      # Write your MySQL query statement below.
      select E1.salary from Employee E1 where N-1 = (select count(distinct salary) from Employee E2 where E2.salary > E1.salary)
      LIMIT 1

  );
END