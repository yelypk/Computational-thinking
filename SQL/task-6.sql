SELECT c.name, COUNT(v.Id) FROM `companies`c INNER JOIN `vacancies`v on v.company_id = c.Id
GROUP BY v.company_id
ORDER BY 2 DESC LIMIT 10