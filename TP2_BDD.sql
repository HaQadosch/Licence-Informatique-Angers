--1
\d

--2
SELECT * FROM nomtable;

--3
SELECT nom,localis,batim FROM SERVICES

--4
SELECT cdsrv,nom FROM SERVICES;

--5
SELECT nom,prnm,datnais FROM PERSONNELS 
WHERE qualif='CHEF DE SERVICE';

--6
SELECT nom,prnm,sx,qualif FROM PERSONNELS 
WHERE vactn is NULL or vactn=0;

--7
SELECT DISTINCT qualif FROM PERSONNELS
WHERE vactn is NULL or vactn=0;

--8
SELECT nom,prnm,sx,qualif,trtmnt FROM PERSONNELS
WHERE trtmnt BETWEEN 25000 AND 35000;

--9

--10
SELECT nom,prnm,datnais,sx,qualif FROM PERSONNELS
WHERE qualif='ASSISTANT' or qualif='CHEF DE SERVICE';

--11
SELECT nom,prnm,sx,qualif FROM PERSONNELS
WHERE nom like 'BOU%';

-- 12 
SELECT nom,prnm,sx,qualif FROM PERSONNELS
WHERE nom like '_AR%';

--13
SELECT nom,prnm,datnais,sx,qualif FROM PERSONNELS
WHERE sx='2'
and (qualif='INTERNE' or qualif='DOCTEUR');

--14
SELECT nom,prnm,datnais,sx,qualif FROM PERSONNELS
WHERE (sx='2' and qualif='DOCTEUR') 
or qualif='INTERNE';

--15
SELECT nom,prnm,dattit,sx,qualif FROM PERSONNELS
WHERE dattit > '1990-01-01';

--16
SELECT nom,prnm,datnais,sx,qualif,trtmnt FROM PERSONNELS
WHERE (qualif='CHEF DE SERVICE' or qualif='ASSISTANT')
ORDER BY trtmnt;

--17
SELECT nom,prnm,datnais,sx,qualif,trtmnt FROM PERSONNELS
WHERE (qualif='CHEF DE SERVICE' or qualif='ASSISTANT')
ORDER BY datnais;

--18
SELECT nom,prnm,datnais,sx,qualif,trtmnt FROM PERSONNELS
WHERE (qualif='CHEF DE SERVICE' or qualif='ASSISTANT')
ORDER BY trtmnt DESC;
