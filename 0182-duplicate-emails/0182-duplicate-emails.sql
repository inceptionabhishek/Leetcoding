# Write your MySQL query statement below
SELECT distinct(email) AS Email FROM Person P1
WHERE email IN (SELECT email FROM Person WHERE id<>P1.id and email=P1.email);