DROP TABLE STAT_RESULTAT;
DROP TABLE TABNOTE;
DROP TABLE MATIERE;
DROP TABLE FORMATION;
DROP TABLE ENSEIGNANT;
DROP TABLE ETUDIANT;


CREATE TABLE IF NOT EXISTS ETUDIANT(
	NumEt int primary key,
	Nom varchar(20),
	Prenom varchar(20)
);

CREATE TABLE IF NOT EXISTS ENSEIGNANT(
	NumEns int primary key,
	NomEns varchar(20),
	PrenomEns varchar(20)
);


CREATE TABLE IF NOT EXISTS FORMATION(
	NomForm varchar(20) primary key,
	NbrEtud int,
	EnseigResponsable int,
	foreign key(EnseigResponsable) references ENSEIGNANT(NumEns) on delete cascade
);

CREATE TABLE IF NOT EXISTS MATIERE(
	NomMat varchar(20),
	NomForm varchar(20),
	foreign key(NomForm) references FORMATION(NomForm) on delete cascade,
	primary key (NomMat,NomForm),
	NumEns int,
	foreign key(NumEns) references ENSEIGNANT(NumEns) on delete cascade,
	Coef int
);

CREATE TABLE IF NOT EXISTS TABNOTE(
	NumEtud int,
	foreign key(NumEtud) references ETUDIANT(NumEt) on delete cascade,
	NomMat varchar(20),
	NomForm varchar(20) references FORMATION(NomForm) on delete cascade,
	primary key(NumEtud,NomMat,NomForm),
	note int
);

CREATE TABLE IF NOT EXISTS STAT_RESULTAT(
	NomFormation varchar(20),
	foreign key (NomFormation) references FORMATION(NomForm) on delete cascade,
	MoyGenerale float,
	NbrRecu int,
	NbrEtdPres int,
	NoteMax int,
	NoteMin int
);

INSERT INTO ETUDIANT VALUES
	(1,'Delepine','Pierre-Yves'),
	(2,'Rossard','Nathan'),
	(3,'Bisnoit','Maxime'),
	(4,'Mousty','Lydie');

INSERT INTO ENSEIGNANT VALUES
	(1,'Richer','Jean-Michel'),
	(2,'Jacob','Bruno'),
	(3,'petigro','decra');

INSERT INTO FORMATION VALUES ('l3info',4,2);
INSERT INTO MATIERE VALUES
	('programmation','l3info',2,10),
	('assembleur','l3info',1,6),
	('scripts','l3info',3,4);

INSERT INTO TABNOTE VALUES
	(1,'programmation','l3info',14),
	(1,'assembleur','l3info',11),
	(1,'scripts','l3info',16),
	(2,'programmation','l3info',10),
	(2,'assembleur','l3info',7),
	(2,'scripts','l3info',11),
	(3,'programmation','l3info',6),
	(3,'assembleur','l3info',2),
	(3,'scripts','l3info',3),
	(4,'programmation','l3info',16),
	(4,'assembleur','l3info',15),
	(4,'scripts','l3info',12);
