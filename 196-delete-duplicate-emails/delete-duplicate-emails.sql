# Write your MySQL query statement below
DELETE FROM Person p1 WHERE id NOT IN (SELECT * FROM (SELECT MIN(p2.id) FROM Person p2 GROUP BY p2.email)t);