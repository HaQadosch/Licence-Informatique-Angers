/* création et remplissage des tables produit */
DROP TABLE produit ;

CREATE TABLE produit (
	NumProd INT NOT NULL,
	PRIMARY KEY(NumProd),
	Designation VARCHAR(50),
	Prix FLOAT
);

DROP TABLE produit2;
	
CREATE TABLE produit2 (NumProd INT NOT NULL,
	PRIMARY KEY(NumProd),
	Designation VARCHAR(50),
	Prix INT NOT NULL
);

insert into produit values (1,'une bonne moyenne',100),(2,'alibaba',NULL);

/* fonction créant la table produit2 à partir de produit */
CREATE FUNCTION construP2() returns void AS $$
	DECLARE
		cursdate cursor FOR SELECT * FROM produit;
	BEGIN
		IF EXISTS(SELECT * FROM produit) THEN 
				FOR val IN cursdate LOOP
					IF val.prix IS NULL THEN val.prix=0 ENDIF;
					INSERT INTO produit2 VALUES(
						val.NumProd,
						UPPER(val.Designation),
						ROUND(val.Prix*(1/6.55957))
						);
				ENDLOOP;

		 ELSE 
			INSERT INTO produit2 VALUES (0,'Pas de produit',NULL);
		 ENDIF;
	END;
$$ LANGUAGE 'plpgsql';
