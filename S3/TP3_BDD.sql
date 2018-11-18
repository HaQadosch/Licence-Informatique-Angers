------------ EXERCICE 1-------------

--1
SELECT DISTINCT nomf, c.nomp ,prix
FROM FOURNISSEUR f JOIN PRODUIT p ON f.numf = p.numf JOIN COMMANDE c ON p.nomp = c.nomp JOIN CLIENT cl ON cl.numc = cl.numc
WHERE cl.nomc = 'Jean';

--2
SELECT DISTINCT nomf, c.nomp ,prix
FROM  FOURNISSEUR f JOIN PRODUIT p ON f.numf = p.numf JOIN COMMANDE c ON p.nomp = c.nomp JOIN CLIENT cl ON cl.numc = cl.numc
WHERE cl.nomc = 'Jean'
ORDER BY nomp DESC, nomf ASC;

--3
SELECT nomp FROM  PRODUIT
WHERE prix = (SELECT MIN(prix) FROM PRODUIT);

--4
SELECT nomp, AVG(prix) moy FROM  PRODUIT
GROUP BY nomp;

--5
SELECT nomp, AVG(prix) moy FROM PRODUIT
GROUP BY nomp
HAVING AVG(prix) > 1000;

--6
SELECT nomp, AVG(prix) moy FROM  PRODUIT
GROUP BY nomp
HAVING AVG(prix) > (SELECT AVG(prix) FROM PRODUIT);
                    
--7
SELECT nomp, AVG(prix) moy FROM  PRODUIT
GROUP BY nomp
HAVING COUNT (prix) > 2;
                    
--8
SELECT p.nomp, AVG(prix) moy
FROM  FOURNISSEUR f JOIN PRODUIT p ON f.numf = p.numf JOIN COMMANDE c ON p.nomp = c.nomp JOIN CLIENT cl ON cl.numc = cl.numc
GROUP BY p.nomp , cl.villec , f.villef
HAVING cl.villec LIKE '%Paris' AND f.villef LIKE '%ANGERS';

------------ EXERCICE 2-------------

--1
SELECT nom FROM PERSONNELS
WHERE qualif='INFIRMIERE'

INTERSECT

SELECT nom FROM PERSONNELS
WHERE qualif='SECRETAIRE MEDICALE';

--2
SELECT nom,prnm FROM PERSONNELS

INTERSECT 

SELECT nom, prnm FROM PATIENTS;

--3
SELECT nom,prnm FROM PERSONNELS
WHERE qualif='SECRETAIRE MEDICALE'

EXCEPT

SELECT nom,prnm FROM PATIENTS;


--4
SELECT e.cdprs,e.nom,e.prnm,e.qualif,s.cdprs,s.nom,s.prnm,s.qualif 
FROM PERSONNELS e JOIN PERSONNELS s ON e.cdspr=s.cdprs
WHERE e.qualif='ASSISTANT' 
OR e.qualif='CHEF DE CLINIQUE';

--5
SELECT PERSONNELS.nom,prnm,sx,datnais,SERVICES.nom 
FROM PERSONNELS JOIN SERVICES ON PERSONNELS.cdsrv=SERVICES.cdsrv
WHERE qualif='CHEF DE SERVICE';

--6
SELECT s.nom as nomserv,p.nom ,p.prnm,p.sx FROM 
(SELECT * FROM PERSONNELS WHERE (qualif='CHEF DE SERVICE')) p RIGHT OUTER JOIN SERVICES s
ON p.cdsrv=s.cdsrv;

--7
SELECT s.nom as nomserv,
coalesce(p.nom,'****') as nom,
coalesce(p.prnm,'****') as prnm,
coalesce(p.sx,'****') as sx
FROM 
(SELECT * FROM PERSONNELS WHERE (qualif='CHEF DE SERVICE')) p RIGHT OUTER JOIN SERVICES s
ON p.cdsrv=s.cdsrv;

--8
SELECT s.cdsrv,s.nom FROM SERVICES s
WHERE NOT exists
(SELECT *FROM  PERSONNELS P WHERE p.cdsrv=s.cdsrv);

------------ EXERCICE 3-------------
                                 
SELECT SUM(c.Qte) FROM COMMANDE c JOIN CLIENT cl ON c.NumC=cl.NumC
WHERE cl.nomc='Jean';
