SELECT c. * FROM `vacancies`v RIGHT JOIN `companies`c ON v.`company-id` = c.`Id`
WHERE v.`company_id` IS NULL 
