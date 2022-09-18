# Write your MySQL query statement below

# 1st solution
#SELECT MAX(salary) AS SecondHighestSalary FROM Employee WHERE salary < (SELECT MAX(salary) FROM Employee ORDER BY salary DESC);

# 2nd Solution
SELECT DISTINCT(salary) AS SecondHighestSalary FROM Employee UNION SELECT NULL ORDER BY SecondHighestSalary DESC LIMIT 1, 1;

