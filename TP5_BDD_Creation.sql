DROP TABLE SOCIETE;
CREATE TABLE SOCIETE (
  CodeSoc INT,
  PRIMARY KEY(CodeSoc),
  Nom VARCHAR(15) NOT NULL,
  Adresse VARCHAR(50) NOT NULL
);

INSERT INTO SOCIETE values
('101','Nescafé','523 rue des grains Paris 13'),
('102','CIC','5 rue du brigand Paris 15'),
('120','Peugeot','36 avenue de la routourne Angers');

DROP TABLE CAMPAGNE;
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
  
DROP TABLE SPOT;
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

DROP TABLE TARIF;
CREATE TABLE TARIF(
  Média VARCHAR(7) NOT NULL,
  Moment VARCHAR(7) NOT NULL,
  prix int,
  PRIMARY KEY(Média,Moment),
  CHECK(
    Média='TF1' OR Média='FRANCE2' OR Média='FRANCE3' OR Média='CANAL+' OR Média='FRANCE5' OR Média='M6' OR Média='ARTE' OR
    Moment='JOUR' OR Moment='DEBSOIR' OR Moment='SOIR' OR Moment='FINS'
  )  
);

