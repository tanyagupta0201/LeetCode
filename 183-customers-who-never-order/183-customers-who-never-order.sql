# Write your MySQL query statement below

SELECT name as 'Customers' FROM CUSTOMERS WHERE ID NOT IN(SELECT customerId FROM ORDERS);