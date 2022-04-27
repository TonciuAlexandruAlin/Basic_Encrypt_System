#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 100

void generare (char sir[], int b){
    int i;
    for (i=0; i<b; i++){
        sir[i]=rand()%94+32;
        //generez sirul random;
    }
    sir[b]='\0';
    //sfarsit de sir
}

char* codif1 (char c){
    static int v[126]={0};
    char *s=(char*)calloc(MAX,sizeof(char));
    int i=(int) c;

    //retine valoare in int a codului ASCII
    char *a=(char*)calloc(MAX,sizeof(char));
    sprintf(a, "%d", v[i]);
    //copiez in sirul a valoarea lui v[i]
    s[0]= c;
    strcpy(s+1,a);
    s[strlen(s)]='\0';
    free(a);
    v[i]++;
    //cresc v[i]
    return s;

}

char* codif2 (char c){
    char *s=(char*)calloc(MAX,sizeof(char));
    c=c ^ 0111;
    //neg bitii 3 si 6 
    int nrbiti = 0;
    char a=c;
    while (a) {
        a=a&(a-1);
        nrbiti++;
    }
    //numar bitii de 1
    c=c | 32;
    // SAU logic cu masca   
    //if (c%2==1) c=c-1;
    c= c & 254;
    // inlocuiesc ultimul bit cu 0
    s[0]=c;
    sprintf(s+1, "%d", nrbiti);
    s[2]='\0';
    return s;
}

char* codif3 (char c){
    char *s=(char*)calloc(MAX,sizeof(char));
    if (c<=122 && c>=97){
        c=c-32;
        //scadem 32 ca sa se tranforme in litera mare conform ASCII
    }
    
    s[0]=c;
    s[1]='\0';
    return s;
}

void modif (char *s, int b, char* (*aleator[3])(char)){
    int i; 
    for (i=0; i<b; i++){
        char *a=aleator[rand()%3](s[i]);
        //se apeleaza aleator prin pointer la functii
        printf("%s",a);
        free(a);
    }
    printf("\n");
}


int main(){
    int a,b,i;
    scanf("%d%d",&a,&b);
    char *sir=(char*)calloc(b,sizeof(char));
    srand(a);
    //setez seed pentru functia rand
    generare(sir,b);
    char* (*aleator[3])(char) = {codif1,codif2,codif3};
    //setez codificarile prin pointer la functii
    modif(sir,b,aleator);
    free(sir);
    return 0;
}