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
SELECT cdprs,nom,prnm,qualif FROM PERSONNELS
WHERE qualif='ASSISTANT' 
OR qualif='CHEF DE CLINIQUE'
OR cdprs IN 
(SELECT cdspr FROM PERSONNELS
WHERE qualif='ASSISTANT' 
OR qualif='CHEF DE CLINIQUE');

--4bis
SELECT e.cdprs,e.nom,e.prnm,e.qualif,s.cdprs,s.nom,s.prnm,s.qualif  FROM PERSONNELS e JOIN PERSONNELS s on e.cdspr=s.cdprs
WHERE e.qualif='ASSISTANT' 
OR e.qualif='CHEF DE CLINIQUE';

--5
SELECT PERSONNELS.nom,prnm,sx,datnais,SERVICES.nom 
FROM PERSONNELS JOIN SERVICES ON PERSONNELS.cdsrv=SERVICES.cdsrv
WHERE qualif='CHEF DE SERVICE';

--6)
select s.nom as nomserv,p.nom ,p.prnm,p.sx
from (SELECT *from PERSONNELS where(qualif='CHEF DE SERVICE')) p right outer join SERVICES s
on p.cdsrv=s.cdsrv;

--7)
select s.nom as nomserv,
coalesce(p.nom,'****') as nom,
coalesce(p.prnm,'****') as prnm,
coalesce(p.sx,'****') as sx
from (SELECT *from PERSONNELS where(qualif='CHEF DE SERVICE')) p right outer join SERVICES s
on p.cdsrv=s.cdsrv;

--8


------------ EXERCICE 3-------------
