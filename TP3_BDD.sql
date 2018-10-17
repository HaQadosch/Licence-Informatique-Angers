------------ EXERCICE 1-------------
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
FROM PERSONNELS e JOIN PERSONNELS s on e.cdspr=s.cdprs
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
on p.cdsrv=s.cdsrv;

--8
select s.cdsrv,s.nom
from SERVICES s
where not exists(select *
from PERSONNELS P
where p.cdsrv=s.cdsrv);

------------ EXERCICE 3-------------
