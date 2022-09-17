# Write your MySQL query statement below

SELECT class from Courses GROUP BY class HAVING COUNT(student) >= 5;