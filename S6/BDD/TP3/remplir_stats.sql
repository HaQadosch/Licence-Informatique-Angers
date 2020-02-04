/* calcul de la moyenne de toute l'université */
CREATE OR REPLACE FUNCTION moyNote() RETURNS INT AS $$
	DECLARE
		noteTot int=0;
		coefTot int=0;
		moy float;
		coef int;
		cursdate cursor for select * from TABNOTE;
	BEGIN
		FOR val in cursdate LOOP
			coef=(SELECT M.Coef from MATIERE M where M.NomMat=val.NomMat);
			noteTot=noteTot+(val.Note*coef);
			coefTot=coefTot+coef;
		END LOOP;
		moy = noteTot/coefTot;
		RETURN moy;
	END;
$$ LANGUAGE 'plpgsql';

SELECT E.Nom,E.Prenom,T.Note FROM ETUDIANT E,TABNOTE T WHERE E.NumEt=T.NumEtud and T.Note > moyNote();

/* calcul de la moyenne de la formation entrée en paramètre*/
CREATE OR REPLACE FUNCTION MoyFormat(FORMATION varchar(20)) RETURNS FLOAT AS $$
	DECLARE
		noteTot int=0;
		coefTot int=0;
		moy float;
		coef int;
		cursdate cursor for select * from TABNOTE;
	BEGIN
		FOR val in cursdate LOOP
			coef=(SELECT M.Coef from MATIERE M where val.NomForm=FORMATION and M.NomMat=val.NomMat);
			noteTot=noteTot+(val.Note*coef);
			coefTot=coefTot+coef;
		END LOOP;
		moy = noteTot/coefTot;
		RETURN moy;
	END;
$$ LANGUAGE 'plpgsql';
