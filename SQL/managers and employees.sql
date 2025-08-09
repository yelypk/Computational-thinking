WITH RECURSIVE herar AS ( SELECT
e.EmployeeID,e.ManagerID,e.JobTitle, 0 AS depth FROM Employees e
WHERE e.ManagerID IS NULL 
UNION ALL
SELECT e.EmployeeID,e.ManagerID,e.JobTitle, h.depth+1 FROM Employees e 
JOIN herar h ON h.EmployeeID=e.ManagerID)                         
SELECT EmployeeID,ManagerID,JobTitle,depth from herar

--with це допоміжна таблиця, recursive - таблиця, яка заповнюється рекурсівно. Задаю початкове значення таблиці і через UNION ALL кожен раз додаю нові значення на новому кроці рекурсії,
--спираючись на попереднє наповнення таблиці ...