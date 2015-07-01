%option reentrant
%option noyywrap

/* hun_sentclean - mondatra bont� sz�r� kimenet�t alak�tja tov�bb */
/* 2003 (c) N�meth L�szl� <nemethl@gyorsposta.hu> */

/* Makr�defin�ci�k */

/* sz�k�z, vagy �j sor karakter */
SPACE [ \n]

%%

	/* paragrafusok beilleszt�se */
	
"\n</s>\n\n" {
	fprintf(yyout, "</s>\n  </p>\n  <p>\n");
}

"</s>\n\n" {
	fprintf(yyout, "\n</s>\n  </p>\n  <p>\n");
}

	/* �j sorok sz�k�zre t�rt�n� cser�je */

"\n" {
	fprintf(yyout, " ");
}

	/* t�r�s mondathat�rn�l */

"</s>"{SPACE}* {
	fprintf(yyout, "\n</s>\n");
}
