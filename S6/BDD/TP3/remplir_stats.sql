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

--test
SELECT E.Nom,E.Prenom,T.Note FROM ETUDIANT E,TABNOTE T WHERE E.NumEt=T.NumEtud and T.Note > moyNote();

/* calcul de la moyenne de la formation entrée en paramètre*/
CREATE OR REPLACE FUNCTION MoyFormat(formation varchar(20)) RETURNS FLOAT AS $$
	DECLARE
		noteTot int=0;
		coefTot int=0;
		moy float;
		coef int;
		cursdate cursor for select * from TABNOTE;
	BEGIN
		FOR val in cursdate LOOP
			coef=(SELECT M.Coef from MATIERE M where val.NomForm=formation and M.NomMat=val.NomMat);
			noteTot=noteTot+(val.Note*coef);
			coefTot=coefTot+coef;
		END LOOP;
		moy = noteTot/coefTot;
		RETURN moy;
	END;
$$ LANGUAGE 'plpgsql';

/* remplissage de la table de stats */
CREATE OR REPLACE FUNCTION stat_form() RETURNS VOID AS $$
	DECLARE
		cursNotes cursor for select * from TABNOTE;
		cursFormation cursor for select * from FORMATION;
		Nom_Form varchar(20);
		Moy_Gene float = 0.0;
		Nbr_Recu int = 0;
		Nbr_Etd_Pres int = 0;
		Note_Max int = 0;
		Note_Min int = 20;
		noteActu int = 0;
	BEGIN
		delete from STAT_RESULTAT; -- on vide STAT_RESULTAT au cas ou on aurait fait des tests dessus
		FOR form in cursFormation LOOP
			Nom_Form=form.NomForm;
			Moy_Gene=MoyFormat(Nom_Form);
			Nbr_Recu=count(distinct E.NumEt) from ETUDIANT as E join TABNOTE as T on E.NumEt=T.NumEtud where T.note>10 and T.NomForm=Nom_Form;
			Nbr_Etd_Pres=count(distinct E.NumEt) from ETUDIANT as E join TABNOTE as T on E.NumEt=T.NumEtud where T.NomForm=Nom_Form;
			FOR NotEtu in cursNotes LOOP
				IF NotEtu.NomForm=Nom_Form THEN
					noteActu=NotEtu.note;
					IF noteActu>Note_Max THEN
						Note_Max=noteActu;
					END IF;
					IF noteActu<Note_Min THEN
						Note_Min=noteActu;
					END IF;
				END IF;
			END LOOP;
			INSERT INTO STAT_RESULTAT values (Nom_Form,Moy_Gene,Nbr_Recu,Nbr_Etd_Pres,Note_Max,Note_Min);
		END LOOP;
	END;
$$ LANGUAGE 'plpgsql';

--test
SELECT stat_form();
SELECT * FROM STAT_RESULTAT;
