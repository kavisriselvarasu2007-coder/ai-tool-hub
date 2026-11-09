CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  -- Declare a variable to store the offset (N - 1)
  DECLARE offset_val INT;
  SET offset_val = N - 1;

  RETURN (
      SELECT DISTINCT salary 
      FROM Employee 
      ORDER BY salary DESC 
      LIMIT 1 OFFSET offset_val
  );
END