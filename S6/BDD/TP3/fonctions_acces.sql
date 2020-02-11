/* matiere et formations suivies par l'etudiant*/
CREATE OR REPLACE FUNCTION MatForm(numEtudiant int) RETURNS SETOF varchar AS $$
	DECLARE
		bulletin cursor for select * from TABNOTE;
	BEGIN
		FOR bull in bulletin LOOP
			IF bull.NumEtud=numEtudiant THEN
				RETURN NEXT bull.NomMat;
				RETURN NEXT bull.NomForm;
			END IF;
		END LOOP;

		RETURN;
	END;
$$ LANGUAGE 'plpgsql';
SELECT MatForm(1);
