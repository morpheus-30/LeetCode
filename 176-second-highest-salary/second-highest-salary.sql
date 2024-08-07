# Write your MySQL query statement below
-- SELECT SALARY AS SecondHighestSalary from Employee as e1 where 1=(SELECT COUNT(SALARY) FROM Employee as e2 where e2.salary>e1.salary) limit 1;
SELECT MAX(Salary) AS SecondHighestSalary from Employee where salary!=(SELECT MAX(SALARY) from Employee);