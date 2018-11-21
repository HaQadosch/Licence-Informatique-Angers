-- Q1 et Q2
DROP TABLE PROGRAMMATION,TARIF,SPOT,CAMPAGNE,SOCIETE;
CREATE TABLE SOCIETE (
  CodeSoc INT,
  PRIMARY KEY(CodeSoc),
  Nom VARCHAR(15) NOT NULL,
  Adresse VARCHAR(50)
);

INSERT INTO SOCIETE values
('101','Nescafé','523 rue des grains Paris 13'),
('102','CIC','5 rue du brigand Paris 15'),
('120','Peugeot','36 avenue de la routourne Angers');


CREATE TABLE CAMPAGNE(
  CodeCamp VARCHAR(5) NOT NULL,
  PRIMARY KEY(CodeCamp),
  Titre VARCHAR(50) NOT NULL,
  CodeSoc INT NOT NULL,
  FOREIGN KEY (CodeSoc) REFERENCES SOCIETE(CodeSoc),
  produit VARCHAR(10),
  cible VARCHAR(4) NOT NULL,
  CHECK(cible='MM50' OR cible='TOUS' OR cible='ENF' OR cible='ADO')
);

INSERT INTO CAMPAGNE values
('NE025','Nespresso-Clooney','101','Café','MM50'),
('P208P','208-Pinocchio','120','Voiture','TOUS'),
('BA75','Le monde bouge','102','Banque','MM50');
  

CREATE TABLE SPOT(
  CodeSpot VARCHAR(3),
  Libellé VARCHAR(25),
  Durée INT,
  CodeCamp VARCHAR(5) NOT NULL,
  PRIMARY KEY(CodeSpot),
  FOREIGN KEY(CodeCamp) REFERENCES CAMPAGNE(CodeCamp)
);
INSERT INTO SPOT values
('NS1','Rencontre au bar','135','NE025'),
('NS2','Soirée','115','NE025'),
('P12','Mobile','60','BA75'),
('P13','Premier emploi','75','BA75'),
('P14','Séjour étranger','45','BA75');


CREATE TABLE TARIF(
  Média VARCHAR(7) NOT NULL,
  Moment VARCHAR(7) NOT NULL,
  prix int,
  PRIMARY KEY(Média,Moment),
  constraint chk_tarif CHECK(
    Média='TF1' OR Média='FRANCE2' OR Média='FRANCE3' OR Média='CANAL+' OR Média='FRANCE5' OR Média='M6' OR Média='ARTE' OR
    Moment='JOUR' OR Moment='DEBSOIR' OR Moment='SOIR' OR Moment='FINS'
  )  
);

INSERT INTO TARIF VALUES
('TF1','SOIR','500'),
('TF1','DEBSOIR','400'),
('FRANCE2','JOUR','50'),
('FRANCE3','JOUR','50'),
('FRANCE3','DEBSOIR','200');

CREATE TABLE PROGRAMMATION(
  CodeSpot VARCHAR(3),
  Média VARCHAR(7) NOT NULL,
  Moment VARCHAR(7) NOT NULL,
  datep DATE,
  PRIMARY KEY(CodeSpot,Média,Moment,Datep),
  FOREIGN KEY(Média,Moment) REFERENCES TARIF(Média,Moment),
  FOREIGN KEY(CodeSpot) REFERENCES SPOT(CodeSpot)
);

INSERT INTO PROGRAMMATION VALUES
('NS1','TF1','SOIR','18/02/17'),
('NS1','FRANCE3','JOUR','20/02/17'),
('NS2','TF1','DEBSOIR','20/02/17'),
('P12','TF1','DEBSOIR','19/02/17'),
('P13','TF1','DEBSOIR','20/02/17'),
('P13','FRANCE3','DEBSOIR','20/02/17');

-- Q3

ALTER TABLE TARIF
DROP CONSTRAINT chk_tarif;
ALTER TABLE TARIF
ADD CONSTRAINT chk_tarif CHECK(
  Média='TF1' OR Média='FRANCE2' OR Média='FRANCE3' OR Média='CANAL+' OR Média='FRANCE5' OR Média='M6' OR Média='ARTE' OR Média='W9' OR Média='NT1' OR
  Moment='JOUR' OR Moment='DEBSOIR' OR Moment='SOIR' OR Moment='FINS'
  );
  INSERT INTO TARIF VALUES
('W9','FINS','50'),
('NT1','FINS','80');

--Q4
UPDATE SPOT
SET Libellé='rencontre en soirée' WHERE CodeSpot='NS2';

--Q5
INSERT INTO SOCIETE VALUES ('100','Adidas',NULL);

--Q6&Q7
INSERT INTO SPOT VALUES ('NS3','A la maison',NULL,'NE025');
INSERT INTO PROGRAMMATION VALUES ('NS3','TF1','SOIR','18/02/17');

--Q8
CREATE TABLE SPOT2 AS(
 SELECT CodeSpot,Libellé,Durée FROM SPOT
);

--Q9
