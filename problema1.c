#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 13501

int litera (char v[]){
    int i,c=1;
    for (i=0; i<strlen(v); i++) {
        if (v[i]<65 || v[i]>122 || ((v[i])>90 && v[i]<97))
            c=0;   
            //verific daca in cheie sau sir se gasesc doar litere
        }  
    if(c==1) return 1;
    else return 0; 
}

void multiplicare(char cheie[], char v[]){
    char *a=(char*) malloc(strlen(cheie)+1);
    //aloc dinamic memorie pentru un sir copie al cheii
    
    strcpy(a,cheie);
    //copiez cheia in copie
    while(strlen(cheie)<strlen(v)){
        strcat(cheie,a);
        //concatenez pana se ajunge la o marime mai mare decat al sirului meu
    }
    while(strlen(cheie)>strlen(v)){
        cheie[strlen(cheie)-1]='\0';
        //elimin cate un element din cheie pana cand ajunge la acelasi nivel 
        //cu vectorul pe care il avem de codificat
    }
    free(a);
}


int main(){
    char cheie[2*MAX], v[MAX];
    int i;
    scanf("%s%s", cheie,v);
    //citim cheie si vectorul pentru codificare
    char alfabet[MAX]="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    //am scris alfabetul de 2 ori in caz ca trebuie sa sara de la litera mare
    //catre litera mica
    multiplicare(cheie,v);
    //multiplic cheia

    if (litera(v)==0 || litera(cheie)==0) printf("INVALID\n");
    //in caz ca sirul sau cheia nu sunt formate doar din litere
    //scriem "INVALID"
    else if (litera(v)==1 && litera(cheie)==1){
        for(i=0;i<strlen(v);i++){ //deplasez litera in v[i] cu cate pozitii e cheia tot in i mai departe fata de 'a'
            char*p= strchr(alfabet,cheie[i]);
            //cautam adresa la care se gaseste litera din cheie de pe
            //pozitia i pentru a afla distanta fata de a

            int d= p-alfabet;
            //calculam distanta(alfabet inseamna adresa primului element din
            //vector)
            char*q= strchr(alfabet,v[i]);
            //cautam adresa la care se gaseste in alfabet litera din vector
            //pentru a stii la ce adaugam distanta
            q=q+d;
            //adaugam distanta pentru a deplasa litera
            v[i]=q[0];
            //adaugam noua litera in pozitia i in vector(ramane q[0] mereu
            //deoarece litera precedenta va fi reinitializara cu adresa noii
            //litere)
        }
        printf("%s\n",v);
        //afisam vectorul criptat
    }
    
    return 0;
}