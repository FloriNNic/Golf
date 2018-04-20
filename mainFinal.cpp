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
    {4 ,4}
};

static unsigned long long g;            // variabila ajutatoare

//a = pozitie curenta, b = cupa curenta, d = winner, a[x][0] = a, a[x][1] = A, a[!x][0] = j, a[!x][1] = J;
// h - numarul de linii, w - numarul de coloane
void f(char h, char w)
{
    static int b[2],a[2][2],A,J,x,d,t[2],i;
    string l;
    
    if(!g++)
        *b=b[1]=*a[0]=a[0][1] = *a[1] = a[1][1]= 1,d=x=*t=t[1]=0,l="";
    
    if (b[x] > c)
        x = !x;
    
    A = *a[x] += h;
    J = a[x][1] += w;
    
    
    if (A == *p[b[x]-1] && J == p[b[x]-1][1])
        l = " (hit)";
    else
        for(i = 0; i<c; i++)
            if(A==*p[i]&&J==p[i][1]||A>m||A<1||J>n||J<1)
            { *a[x] -= h,a[x][1] -= w;
                break;
            }
    
    if(c/b[x]){
        t[x]++;
        printf("A lovit jucatorul %d. Total lovituri: %d. Cupa curenta: %d%s. Pozitie curenta (%d,%d)\n",x+1,t[x],b[x],l.c_str(),*a[x],a[x][1]);
        
        
        if (l!="")
            b[x]++;
        
        if (b[x]>c)
            if (c/b[!x])
                d = x;
            else goto U;
        
        x = !x;
    }
    else if(b[!x]>c) U: {
        cout<<"Jocul s-a incheiat. ";
        if (t[x] == t[!x])
            cout<<"Egalitate\n";
        else printf("A castigat jucatorul %d cu %d lovituri\n",d+1,t[d]);
    };
}
int main()
{
    f(1,1); f(2,2); f(1,0); f(-1,-1); f(1,2); f(4,0); f(2,1); f(0,1); f(2,2);
    
    g=0;
    f(0, 0); f(1, 1); f(0, 0); f(2, 2); f(0, 0); f(0, 0);
    
    g=0;
    f(1, 1); f(1, 1); f(2, 2); f(2, 2); f(0, 0); f(0, 0);
    
    g=0;
    f(3,3); f(1,1); f(1,1); f(2,2); f(2,2);
    
    
}
