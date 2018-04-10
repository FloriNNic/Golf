#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string.h>
#include <list>
#include <bitset>
#include <vector>

using namespace std;

const unsigned char MAX_CUPE = 255;

static unsigned char m = 5;
static unsigned char n = 5;
static unsigned char c = 2;

static unsigned char p[MAX_CUPE][2] = {
    {2, 2},
    {4, 4}
};

static unsigned long long g;            // variabila ajutatoare


// h - numarul de linii, w - numarul de coloane
void f(char h, char w)
{
    static int cupaCurenta[2]={1,1};
    static int pozitieCurenta[2][2] = {{1,1},{1,1}};
    string lovit = "";
    static int x =0,
    t[2] = {0,0};
    int winner;

    if(g++==0){
        cupaCurenta[0]=cupaCurenta[1]=pozitieCurenta[0][0]=pozitieCurenta[0][1] = pozitieCurenta[1][0] = pozitieCurenta[1][1]= 1;
        x=t[0]=t[1]= 0;
        lovit="";
    }

    if (cupaCurenta[x] == c+1){
        x = !x;
    }
    pozitieCurenta[x][0] += h;
    pozitieCurenta[x][1] += w;


    if (pozitieCurenta[x][0] == p[cupaCurenta[x]-1][0] && pozitieCurenta[x][1] == p[cupaCurenta[x]-1][1])
        lovit = " (hit)";
    else {
        for(char i = 0; i<c; i++){
            if(pozitieCurenta[x][0] == p[i][0] && pozitieCurenta[x][1] == p[i][1] || pozitieCurenta[x][0]>m || pozitieCurenta[x][0]<1 || pozitieCurenta[x][1]>n || pozitieCurenta[x][1]<1){
                pozitieCurenta[x][0] -= h;
                pozitieCurenta[x][1] -= w;
            }
        }

    }
    if(cupaCurenta[x]<=c){
        t[x]++;
        cout<<"A lovit jucatorul "<<x+1<<". Total lovituri: "<<t[x]<<". Cupa curenta: "<<cupaCurenta[x]<<lovit;
        cout<<". Pozitie curenta ("<<pozitieCurenta[x][0]<<','<<pozitieCurenta[x][1]<<')'<<endl;


        if (lovit!="")
            cupaCurenta[x]++;

        if (cupaCurenta[x]>c&&cupaCurenta[!x]<=c)
            winner = x;

        if (cupaCurenta[x]>c&&cupaCurenta[!x]>c) {
            printf("Jocul s-a incheiat. ");
            if (t[x] == t[!x])
                printf("Egalitate\n");
            else printf("A castigat jucatorul %d cu %d lovituri\n",winner+1,t[winner]);
        }
        x = !x;
    }
    else if(cupaCurenta[!x]>c){
        printf("Jocul s-a incheiat. ");
        if (t[x] == t[!x])
            printf("Egalitate\n");
        else printf("A castigat jucatorul %d cu %d lovituri\n",winner+1,t[winner]);
    }
}
int main()
{
    f(1,1);
    f(2,2);
    f(1,0);
    f(-1,-1);
    f(1,2);
    f(4,0);
    f(2,1);
    f(0,1);
    f(2,2);

    g=0;
    f(0, 0); f(1, 1); f(0, 0); f(2, 2); f(0, 0); f(0, 0);

    g=0;
    f(1, 1); f(1, 1); f(2, 2); f(2, 2); f(0, 0); f(0, 0);
}
