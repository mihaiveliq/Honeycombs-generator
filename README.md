# Honeycombs-generator

    Programul functioneaza in felul urmator:

	1.Declar o serie de elemente (cele semnificative avand utilitatea comentata in cod),
    care vor fi folosite in procesul de creere a fagurelui.

	2.Citesc un sir de caractere care va contine imputul sub formatul din cerinta.
  
	->Creez un while (ce contine toate instructiunile creerii fagurelui) pentru a 
    putea citi mai multi faguri. La inceputul lui reinitializez anumite date ajutatoare.
	
	3.a)Introduc intr-un vector de celule,(convertind folosindu-ma de codul ASCII 
    "caracterele-numar" in numere de tip intreg) toate numerele pana la litera care 
    indica pozitionarea primei coloane (coborata sau ridicata), reusind astfel sa 
    manipulez mai usor numarul de celule si de coloane ale fagurelui.
  
	b)Efectuez un vector similar pentru coordonatele reginelor (convertind 
    folosindu-ma de codul ASCII "caracterele-numar" in numere de tip intreg).

	4. Initializez matricea cu spatii.

	5. Generez fagurele dupa forma specificata in cerinta pe baza unor reguli matematice.
  
	a)corpul celulei este construit cu ajutorul elementelor din vectorul de celule.
  
	b)reginele sunt adaugate cu ajutorul elementelor din vectorul de regine, 
    daca acesta exista.

	6. Odata generat fagurele, trebuie sa elimin spatiile suplimentare pe baza unor 
    conditii calculate matematic.

	7. Tot ce mai ramane de facut este sa afisez matricea si sa repet citirea pe baza 
    while-ului specificat la punctul 1, asta in cazul in care se mai doreste construirea 
    unui nou fagure.
