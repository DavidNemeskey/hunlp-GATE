%option reentrant
%option noyywrap

/* hun_clean - karaktereket t�rl�, illetve �talak�t� sz�r� */
/* 2003 (c) N�meth L�szl� <nemethl@gyorsposta.hu> */

/* Makr�defin�ci�k */

/* Sz�k�z �rt�k� szekvenci�k: sz�k�z, tabul�tor, nem t�r� sz�k�z. */

/* Az &nbsp; entit�st, �s a ,,kocsi vissza'' karaktert is felvessz�k ide */

SPACE ([ 	\240]|"&nbsp"";"?|"\r")

/* �j sor �rt�k� szekvenci�k */

/* A kocsi vissza karaktert az MS-DOS sz�vegek redund�ns k�dol�sa miatt */
/* nem �j sor, hanem sz�k�z �rt�k� karakternek k�doltuk. */

/* \n: �j sor */
/* \f: lapdob�s */
/* \v: f�gg�leges tabul�tor */

NEWLINE [\n\f\v]

%%

	/* bekezd�shat�rok */
	/* bemenet: legal�bb k�t sort�r�s + sz�k�z�k */
	/* kimenet: k�t sort�r�s */

	/* A k�vetkez�kkel nem foglalkozunk: */
	/* XXX Az &nbspvalami szekvenci�kb�l is t�r�lj�k az &nbsp-t */

	/* BE: Bekezd�shat�rok. A sorokban tabul�torok �s sz�k�z�k:	 */
	/* BE: 		 */
	/* BE:           */
	/* BE: 	   V�ge. */

	/* KI: Bekezd�shat�rok. A sorokban tabul�torok �s sz�k�z�k: */
	/* KI:  */
	/* KI: V�ge. */

{SPACE}*{NEWLINE}({SPACE}*{NEWLINE})+{SPACE}* {
		fprintf(yyout, "\n\n");
	}

	/* sort�r�s */
	/* bemenet: egy sort�r�s sorv�gi �s k�vetkez� sor eleji sz�k�z�kkel */
	/* kimenet: egy sort�r�s */

	/* BE: Sort�r�s. Sz�k�z �s tabul�tor: 	 */
	/* BE: 		 Itt is a sor elej�n. */

	/* KI: Sort�r�s. Sz�k�z �s tabul�tor: */
	/* KI: Itt is a sor elej�n. */

{SPACE}*{NEWLINE}{SPACE}* {
		fprintf(yyout, "\n");
	}

	/* els� sor elej�n l�v� sz�k�z�k t�rl�se */
^{SPACE}*

	/* sz�k�zsorozat �s nem t�r� sz�k�z�k lecser�l�se  egy sz�k�zre */
	/* bemenet: t�bb sz�k�z, vagyis SPACE szekvencia egym�s ut�n */
	/* kimenet: egy sz�k�z */

	/* BE: Sz�k�zsorozat. T�bb	     	sz�k�z �s   	  tabul�tor. */

	/* KI: Sz�k�zsorozat. T�bb sz�k�z �s tabul�tor. */

	/* BE: Nem t�r� sz�k�z:�V�ge. */

	/* KI: Nem t�r� sz�k�z: V�ge. */

{SPACE}* {
		fprintf(yyout, " ");
	}

	/* < �s > �tk�dol�sa */
	/* bemenet: <, vagy > */
	/* kimenet: &lt; vagy &gt; */

	/* BE: <> */

	/* KI: &lt;&gt; */
	
"<" {
	fprintf(yyout, "&lt;");
}

">" {
	fprintf(yyout, "&gt;");
}

	/* Windows karakterk�dok egy r�sz�nek �talak�t�sa */

"&#128"";"?|[\200] { fprintf(yyout, "&euro;"); }
"&#130"";"?|[\202] { fprintf(yyout, "&lsquor;"); } /* HTML 4.0-ban sbquo; */
"&#132"";"?|[\204] { fprintf(yyout, "&ldquor;"); }  /* HTML 4.0-ban bdquo; */
"&#133"";"?|[\205] { fprintf(yyout, "..."); }

"&#139"";"?|[\213] { fprintf(yyout, "\""); }

"&#145"";"?|[\221] { fprintf(yyout, "&lsquo;"); } /* 6 */
"&#146"";"?|[\222] { fprintf(yyout, "&rsquo;"); } /* 9 */
"&#147"";"?|[\223] { fprintf(yyout, "&ldquo;"); } /* 66 */
"&#148"";"?|[\224] { fprintf(yyout, "&rdquo;"); } /* 99 */

"&#150"";"?|[\226] { fprintf(yyout, "&ndash;"); } /* -- */
"&#151"";"?|[\227] { fprintf(yyout, "&mdash;"); } /* --- */

"&#153"";"?|[\231] { fprintf(yyout, "&trade;"); } /* TM */

	/* decim�lis karakterk�d */
	/* feltessz�k, hogy az input latin-2, �s a 256-n�l kisebb k�dok
	/* is erre vonatkoznak. */

	/* bemenet: "&" max. 5 jegy� sz�m �s esetleg pontosvessz� */
	/* kimenet: latin-2 karakter, vagy a v�ltozatlan k�d, illetve */
	/* ha a sz�m a < �s > karakterek k�dja -> &lt; �s &gt; entit�s */
	/* �tk�dol�sra ker�lnek az UNICODE nagyk�t�jelek, �s id�z�jelek is */

	/* BE: (EEC&#041; (EEC&#041;	&#107	&#60;	&#337;	&#3456;	&#2343235325; */

	/* KI: (EEC) (EEC) k &lt; � &#3456; &#2343235325; */

"&#"[0-9]{1,5}";"? {
	// decim�lis karakterk�dok kezel�se
	// nem latin-1 eset�ben csak a magyar ����
	int i;
	i = atoi(yytext + 2);
	if (i == 38) fprintf(yyout, "&amp;"); // & jel
	else if (i == 60) fprintf(yyout, "&lt;"); // < jel
	else if (i == 62) fprintf(yyout, "&gt;"); // > jel
	else if (i < 256) fprintf(yyout, "%c", i); // latin-1
	else if (i == 337) fprintf(yyout, "�");
	else if (i == 336) fprintf(yyout, "�");
	else if (i == 369) fprintf(yyout, "�");
	else if (i == 368) fprintf(yyout, "�");
	// ismeretlen k�dot nem v�ltoztatjuk
	else ECHO;
}

		/* Ha hosszabb, mint 5 karakter a sz�m, nem v�ltoztatunk */
"&#"[0-9]{6,}";"? {
	ECHO;
}

	/* hexadecim�lis karakterk�d */
	/* XXX most nem foglalkozunk ezzel (ritka) */

	/* BE: &#xF456 &#Xabc; &#xABCDEF; */

	/* KI: &#xF456 &#Xabc; &#xABCDEF; */

"&#"[xX][0-9a-fA-F]+";"? {
	ECHO;
}

	/* XXX speci�lis �s szimb�lum HTML 4.0 entit�sokkal nem foglalkoztunk m�g */

	/* kiv�ve a 3 pont, �s a &quot; �talak�t�s�t */

	/* BE: &hellip; */

	/* KI: ... */

"&hellip"";"? { fprintf(yyout, "..."); }

"&quot"";"? { fprintf(yyout, "\""); }

	/* magyar id�z�jelek: HTML 4.0 -> SGML  */

	/* BE: &bdquo; */

	/* KI: &ldquor; */

"&bdquo"";"? { fprintf(yyout, "&ldquor;"); }

"&sbquo"";"? { fprintf(yyout, "&lsquor;"); }

	/* latin-1 HTML entit�sok r�szleges �talak�t�sa (most m�g latin-2-re) */
	/* �talak�t�s ott t�rt�nik, ahol a latin-2 megegyezik a latin-1-gyel */

	/* BE: &aacute; &Aacute; &otilde; &Otilde; &ucirc; &Ucirc; &ndash; &mdash; */

	/* KI: � � � � � � &ndash; &mdash; */

	/* "&nbsp"";"? { fprintf(yyout, "%c",(char) 160); } */ // ez m�r lecser�lve */

	/* "&iexcl"";"? { fprintf(yyout, "%c",(char) 161); } */ // ford�tott felki�lt�jel

	/* "&cent"";"? { fprintf(yyout, "%c",(char) 162); } */
	/* "&pound"";"? { fprintf(yyout, "%c",(char) 163); } */

"&curren"";"? { fprintf(yyout, "%c",(char) 164); }

	/* "&yen"";"? { fprintf(yyout, "%c",(char) 165); } */
	/* "&brvbar"";"? { fprintf(yyout, "%c",(char) 166); } */
	
"&sect"";"? { fprintf(yyout, "%c",(char) 167); }

	/* "&uml"";"? { fprintf(yyout, "%c",(char) 168); } */
	/* "&copy"";"? { fprintf(yyout, "%c",(char) 169); } */
	/* "&ordf"";"? { fprintf(yyout, "%c",(char) 170); } */
	/* "&laquo"";"? { fprintf(yyout, "%c",(char) 171); } */
	/* "&not"";"? { fprintf(yyout, "%c",(char) 172); } */

	/* BE: &shy&shy; */

	/* KI:  */

"&shy"";"? // elv�laszt�si hely jel�nek (felt�teles v. l�gy k�t�jel) t�rl�se

	/* "&reg"";"? { fprintf(yyout, "%c",(char) 174); } */
	/* "&macr"";"? { fprintf(yyout, "%c",(char) 175); } */

	/* BE: &deg; */

	/* KI: � */

"&deg"";"? { fprintf(yyout, "%c",(char) 176); } // fokjel, megegyezik latin-2-vel

	/* "&plusmn"";"? { fprintf(yyout, "%c",(char) 177); } */
	/* "&sup2"";"? { fprintf(yyout, "%c",(char) 178); } */
	/* "&sup3"";"? { fprintf(yyout, "%c",(char) 179); } */

	/* BE: &acute; */

	/* KI: � */

"&acute"";"? { fprintf(yyout, "%c",(char) 180); } // vessz� �kezet, megegyezik a latin-2-vel

	/* "&micro"";"? { fprintf(yyout, "%c",(char) 181); } */
	/* "&para"";"? { fprintf(yyout, "%c",(char) 182); } */
	/* "&middot"";"? { fprintf(yyout, "%c",(char) 183); } */

	/* BE: &cedil; */

	/* KI: � */

"&cedil"";"? { fprintf(yyout, "%c",(char) 184); } // cedilla �kezet, megegyezik a latin-2-vel

	/* "&sup1"";"? { fprintf(yyout, "%c",(char) 185); } */
	/* "&ordm"";"? { fprintf(yyout, "%c",(char) 186); } */
	/* "&raquo"";"? { fprintf(yyout, "%c",(char) 187); } */
	/* "&frac14"";"? { fprintf(yyout, "%c",(char) 188); } */
	/* "&frac12"";"? { fprintf(yyout, "%c",(char) 189); } */
	/* "&frac34"";"? { fprintf(yyout, "%c",(char) 190); } */
	/* "&iquest"";"? { fprintf(yyout, "%c",(char) 191); } */
	/* "&Agrave"";"? { fprintf(yyout, "%c",(char) 192); } */ // bet�

	/* BE: &Aacute; */

	/* KI: � */

"&Aacute"";"? { fprintf(yyout, "%c",(char) 193); }

	/* BE: &Acirc; */

	/* KI: � */

"&Acirc"";"? { fprintf(yyout, "%c",(char) 194); }

	/* "&Atilde"";"? { fprintf(yyout, "%c",(char) 195); } // bet�

	/* BE: &Auml; */

	/* KI: � */

"&Auml"";"? { fprintf(yyout, "%c",(char) 196); }

	/* "&Aring"";"? { fprintf(yyout, "%c",(char) 197); } */ // bet�
	/* "&AElig"";"? { fprintf(yyout, "%c",(char) 198); } */ // bet�

	/* BE: &Ccedil; */

	/* KI: � */

"&Ccedil"";"? { fprintf(yyout, "%c",(char) 199); }

	/* "&Egrave"";"? { fprintf(yyout, "%c",(char) 200); } */ // bet�

	/* BE: &Eacute; */

	/* KI: � */

"&Eacute"";"? { fprintf(yyout, "%c",(char) 201); }

	/* "&Ecirc"";"? { fprintf(yyout, "%c",(char) 202); } */ // bet�

	/* BE: &Euml; */

	/* KI: � */

"&Euml"";"? { fprintf(yyout, "%c",(char) 203); }

	/* "&Igrave"";"? { fprintf(yyout, "%c",(char) 204); } */ // bet�

	/* BE: &Iacute; */

	/* KI: � */

"&Iacute"";"? { fprintf(yyout, "%c",(char) 205); }

	/* BE: &Icirc; */

	/* KI: � */

"&Icirc"";"? { fprintf(yyout, "%c",(char) 206); }

	/* "&Iuml"";"? { fprintf(yyout, "%c",(char) 207); } */ // bet�
	/* "&ETH"";"? { fprintf(yyout, "%c",(char) 208); } */ // bet�
	/* "&Ntilde"";"? { fprintf(yyout, "%c",(char) 209); } */ // bet�
	/* "&Ograve"";"? { fprintf(yyout, "%c",(char) 210); } */ // bet�

	/* BE: &Oacute; */

	/* KI: � */

"&Oacute"";"? { fprintf(yyout, "%c",(char) 211); }

	/* BE: &Ocirc; */

	/* KI: � */

"&Ocirc"";"? { fprintf(yyout, "%c",(char) 212); }

	/* XXX Tipikus t�veszt�s: hull�mvonalas O jav�t�sa �-re */

	/* BE: &Otilde; */

	/* KI: � */

"&Otilde"";"? { fprintf(yyout, "%c",(char) 213); }

	/* BE: &Ouml; */

	/* KI: � */

"&Ouml"";"? { fprintf(yyout, "%c",(char) 214); }

	/* BE: &times; */

	/* KI: � */

"&times"";"? { fprintf(yyout, "%c",(char) 215); }

	/* "&Oslash"";"? { fprintf(yyout, "%c",(char) 216); } */ // bet�
	/* "&Ugrave"";"? { fprintf(yyout, "%c",(char) 217); } */ // bet�

	/* BE: &Uacute; */

	/* KI: � */

"&Uacute"";"? { fprintf(yyout, "%c",(char) 218); }

	/* XXX Tipikus t�veszt�s: pontos U jav�t�sa �-re */

	/* BE: &Ucirc; */

	/* KI: � */

"&Ucirc"";"? { fprintf(yyout, "%c",(char) 219); }

	/* BE: &Uuml; */

	/* KI: � */

"&Uuml"";"? { fprintf(yyout, "%c",(char) 220); }

	/* BE: &Yacute; */

	/* KI: � */

"&Yacute"";"? { fprintf(yyout, "%c",(char) 221); }

	/* "&THORN"";"? { fprintf(yyout, "%c",(char) 222); } */ // bet�

	/* BE: &szlig; */

	/* KI: � */

"&szlig"";"? { fprintf(yyout, "%c",(char) 223); }

	/* "&agrave"";"? { fprintf(yyout, "%c",(char) 224); } */ // bet�

	/* BE: &aacute; */

	/* KI: � */

"&aacute"";"? { fprintf(yyout, "%c",(char) 225); }

	/* BE: &acirc; */

	/* KI: � */

"&acirc"";"? { fprintf(yyout, "%c",(char) 226); }

	/* "&atilde"";"? { fprintf(yyout, "%c",(char) 227); } */ // bet�

	/* BE: &auml; */

	/* KI: � */

"&auml"";"? { fprintf(yyout, "%c",(char) 228); }

	/* "&aring"";"? { fprintf(yyout, "%c",(char) 229); } */ // bet�
	/* "&aelig"";"? { fprintf(yyout, "%c",(char) 230); } */ // bet�

	/* BE: &ccedil; */

	/* KI: � */

"&ccedil"";"? { fprintf(yyout, "%c",(char) 231); }

	/* "&egrave"";"? { fprintf(yyout, "%c",(char) 232); } */ // bet�

	/* BE: &eacute; */

	/* KI: � */

"&eacute"";"? { fprintf(yyout, "%c",(char) 233); }

	/* "&ecirc"";"? { fprintf(yyout, "%c",(char) 234); } */ // bet�

	/* BE: &euml; */

	/* KI: � */

"&euml"";"? { fprintf(yyout, "%c",(char) 235); }

	/* "&igrave"";"? { fprintf(yyout, "%c",(char) 236); } */ // bet�

	/* BE: &iacute; */

	/* KI: � */

"&iacute"";"? { fprintf(yyout, "%c",(char) 237); }

	/* BE: &icirc; */

	/* KI: � */

"&icirc"";"? { fprintf(yyout, "%c",(char) 238); }

	/* "&iuml"";"? { fprintf(yyout, "%c",(char) 239); } */ // bet�
	/* "&eth"";"? { fprintf(yyout, "%c",(char) 240); } */ // bet�
	/* "&ntilde"";"? { fprintf(yyout, "%c",(char) 241); } */ // bet�
	/* "&ograve"";"? { fprintf(yyout, "%c",(char) 242); } */ // bet�

	/* BE: &oacute; */

	/* KI: � */

"&oacute"";"? { fprintf(yyout, "%c",(char) 243); }

	/* BE: &ocirc; */

	/* KI: � */

"&ocirc"";"? { fprintf(yyout, "%c",(char) 244); }

	/* XXX Tipikus t�veszt�s: hull�mvonalas o jav�t�sa �-re */

	/* BE: &otilde; */

	/* KI: � */

"&otilde"";"? { fprintf(yyout, "%c",(char) 245); }

	/* BE: &ouml; */

	/* KI: � */

"&ouml"";"? { fprintf(yyout, "%c",(char) 246); }

	/* BE: &divide; */

	/* KI: � */

"&divide"";"? { fprintf(yyout, "%c",(char) 247); }

	/* "&oslash"";"? { fprintf(yyout, "%c",(char) 248); } */ // bet�
	/* "&ugrave"";"? { fprintf(yyout, "%c",(char) 249); } */ // bet�

	/* BE: &uacute; */

	/* KI: � */

"&uacute"";"? { fprintf(yyout, "%c",(char) 250); }

	/* BE: &ucirc; */

	/* KI: � */

	/* XXX Tipikus t�veszt�s: pontos u jav�t�sa �-re */

"&ucirc"";"? { fprintf(yyout, "%c",(char) 251); }

	/* BE: &uuml; */

	/* KI: � */

"&uuml"";"? { fprintf(yyout, "%c",(char) 252); }

	/* BE: &yacute; */

	/* KI: � */

"&yacute"";"? { fprintf(yyout, "%c",(char) 253); }

	/* "&thorn"";"? { fprintf(yyout, "%c",(char) 254); } */ // bet�
	/* "&yuml"";"? { fprintf(yyout, "%c",(char) 255); } */ // bet�
