#include<iostream>
#include <algorithm>
using namespace std;
int center(int x1,int x2, int x3,int x4,int n){
    int x;
    x=(x1+x2+x3+x4)/n;
    return x;
}
int realign(int xory_i,int xory_g){
xory_i=xory_i-xory_g;
return xory_i;
}
int functionC(int x,int y){
if(x>0&&y>=0)
    return 1;
if(x<=0&&y>0)
    return 2;
if(x<0&&y<=0)
    return 3;
if(x>=0&&y<0)
    return 4;
if(x=y=0)
    return 0;
}
int delta(int xa,int ya,int xo,int yo,int xb,int yb){
int delta=0;
delta=xo*yb+xa*yo+xb*ya-xo*ya-xa*yb-xb*yo;
return delta;
}
int main(){
   int x1=1,y1=3,x2=2,y2=4,x3=-2,y3=4,x4=-1,y4=-1,xm=3,ym=3,xg,yg,n=4,P[10],i,x[4],y[4],m;
   xg=center(x1,x2,x3,x4,n);
   yg=center(y1,y2,y3,y4,n);
    x[0]=realign(x1,xg);
    x[1]=realign(x2,xg);
    x[2]=realign(x3,xg);
    x[3]=realign(x4,xg);
    y[0]=realign(y1,xg);
    y[1]=realign(y2,xg);
    y[2]=realign(y3,xg);
    y[3]=realign(y4,xg);
    for(i=0;i<n;i++){
        P[i]=functionC(x1,y1);
        if(P[i]=P[i-1])
                if(delta(x[i],y[i],xg,yg,x[i+1],y[i+1])>0){
            swap(x[i], x[i+1]);
            swap(y[i], y[i+1]);
        }
    }
    xm=realign(xm,xg);
    ym=realign(ym,yg);
if(xm=ym=0)cout<<"M interior of polygon";
 int d,k=0,d1;
d1=delta(xm,ym,x[3],y[3],x[0],y[0]);
if(d1>0)cout<<"M interior of polygon";
else if(d1<0)cout<<"M exterior of polygon";
else if(d1=0)cout<<"M delta of polygon";
d=delta(xm,ym,x[k],y[k],x[k+1],y[k+1]);
if(d>0)cout<<"M interior of polygon";
else if(d<0)cout<<"M exterior of polygon";
else if(d=0)cout<<"M delta of polygon";
}
