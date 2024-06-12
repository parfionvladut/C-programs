#include<iostream>
using namespace std;

int d1(int xa, int xb,int xm,int ya,int yb,int ym){
    int d1=0;
d1=xa*yb+xm*ya+xb*ym-xa*ym-xm*yb-xb*ya;
return d1;
}
int main(){
int x[4]={-4,  2, -3, 1};
int y[4]={ 3, -3,  2, 2};
int xm=4;
int ym=5;
int xa,ya,xb,yb,xc,yc;
int i,c=0,n=sizeof(x)/sizeof(int);
for(i=0;i<n;i++){
    if(y[i]=y[i+1]){
         if(x[i]<x[n]&&x[n]<=x[i+1])
    cout<<"M apartine {A["<<i<<"],A["<<i+1<<"]}\n";
    }
       else if(y[i]<y[i+1]){
        xa=x[i];xb=x[i+1];
            ya=y[i];yb=y[i+1];
       }
            else
                xa=x[i+1];xb=x[i];
                ya=y[i+1];yb=y[i];
        if(d1(xa,xb,xm,ya,yb,ym)==0&&ya<ym&&ym<=yb){
            cout<<"M apartine [AB]\n";
        }
        if(d1(xa,xb,xm,ya,yb,ym)>0&&ya<ym&&ym<yb)
            c++;
}
if(c!=2)
    cout<<"M interior\n";
else
    cout<<"M exterior\n";
return 0;
}
