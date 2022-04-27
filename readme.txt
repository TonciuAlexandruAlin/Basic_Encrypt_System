PROBLEMA 1

DURATA APROXIMATIV 4 ORE;
    Am creat functia de litere care verifica daca tot sirul este format doar 
din litere, urmata de functia multiplicare, care imi mareste cheia pentru a 
fi la acelasi nivel cu cel al sirului. Dupa initializare si citire, am apelat
functia multiplicare, am verificat daca toate caracterele sunt litere, ulterior 
afisand INVALID daca nu. Am ales un sir care reprezinta alfabetul scris de 2 ori
ca sa cautam in el caracterele dorite. Am aflat distanta si am adaugat-o in pozitia
curenta.

Problema 3

    Am creat functia de generare care imi genereaza sirul random. Dupa am creat
cate o functie pentru fiecare codificare. In codificare1 am alocat memorie unui 
vector declarat static, am retinut valoarea caracterului intr-un int pentru a putea
sa retin in vector numarul de aparitii al fiecarui cod ASCII, si ulteiror am 
completat sirul, crescand v[i] dupa fiecare apelare. La codiicarea 2 am negat bitii,
am numarat fiecare bit de 1, am comparat cu masca data, am transformat ultimul bit
in 0 si am completat sirul. La codificarea 3 am verificat daca este litera mica, 
si daca este, am transformat-o in litera mare. In functia modif am apelat random
fiecare codificare printr-un vector de functii. In main am setat seed-ul randomului
si am apelat functiile.