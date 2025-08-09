SELECT Cart1.item,Cart2.item FROM Cart1 
LEFT JOIN Cart2 on Cart1.Item=Cart2.Item 
UNION
SELECT Cart1.item,Cart2.item FROM Cart1 
RIGHT JOIN Cart2 on Cart1.Item=Cart2.Item

--MySQL не підтримує FULL OUTER JOIN, тому через UNION я злипила результати лівого та правого джойна. Суть завдання в тому, щоб знайти данні, що перетинаються в обох таблицях, а також вивести значення унікальні для кожної з таблиці 
