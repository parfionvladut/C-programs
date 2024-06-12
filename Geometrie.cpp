#include<iostream>
using namespace std;
int delta(int xa,int ya,int xb,int yb,int xc,int yc){
int d=0;
d=xb*yc+xa*yb+xc*ya-xb*ya-xa*yc-xc*yb;
return d;
}

int main(){
int i, d1, d2, d3, delta1;
int xa=-4,xb=2,xc=-3,xm=1,ya=-3,yb=-3,yc=2,ym=2;
delta1=delta(xa,ya,xb,yb,xc,yc);
d1=delta(xm,ym,xa,ya,xb,yb);
d2=delta(xm,ym,xb,yb,xc,yc);
d3=delta(xm,ym,xc,yc,xa,ya);
cout<<delta1<<"\n";
cout<<d1<<"\n";
cout<<d2<<"\n";
cout<<d3<<"\n";
if(delta1>0){
    if(d1>0&&d2>0&&d3>0) cout<<"M apartine 1";
    if(d1==0&&d2>0&&d3>0) cout<<"M apartine 2";
    if(d1>0&&d2==0&&d3>0) cout<<"M apartine 3";
    if(d1>0&&d2>0&&d3==0) cout<<"M apartine 4";
    if(d1==0&&d2>0&&d3==0) cout<<"M apartine 5";
    if(d1==0&&d2==0&&d3>0) cout<<"M apartine 6";
    if(d1>0&&d2==0&&d3<0) cout<<"M apartine 7";
    if(d1==0&&d2>0&&d3<0) cout<<"M apartine 8";
    if(d1<0&&d2>0&&d3==0) cout<<"M apartine 9";
    if(d1<0&&d2>0&&d3==0) cout<<"M apartine 10";
    if(d1==0&&d2<0&&d3>0) cout<<"M apartine 11";
    if(d1>0&&d2<0&&d3==0) cout<<"M apartine 12";
    if(d1>0&&d2==0&&d3<0) cout<<"M apartine 13";
    if(d1>0&&d2>0&&d3<0) cout<<"M apartine 14";
    if(d1<0&&d2>0&&d3<0) cout<<"M apartine 15";
    if(d1<0&&d2>0&&d3>0) cout<<"M apartine 16";
    if(d1<0&&d2<0&&d3>0) cout<<"M apartine 17";
    if(d1>0&&d2<0&&d3>0) cout<<"M apartine 18";
    if(d1>0&&d2<0&&d3<0) cout<<"M apartine 19";}

  else if(delta1<0){
    if(d1<0&&d2<0&&d3<0) cout<<"M apartine 1";
    if(d1<0&&d2<0&&d3>0) cout<<"M apartine 2";
    if(d1>0&&d2<0&&d3<0) cout<<"M apartine 3";
    if(d1<0&&d2>0&&d3<0) cout<<"M apartine 4";
    if(d1<0&&d2<0&&d3==0) cout<<"M apartine 5";
    if(d1==0&&d2<0&&d3<0) cout<<"M apartine 6";
    if(d1<0&&d2==0&&d3<0) cout<<"M apartine 7";
    if(d1<0&&d2>0&&d3==0) cout<<"M apartine 8";
    if(d1<0&&d2==0&&d3>0) cout<<"M apartine 9";
    if(d1==0&&d2>0&&d3<0) cout<<"M apartine 10";
    if(d1>0&&d2<0&&d3==0) cout<<"M apartine 11";
    if(d1>0&&d2==0&&d3<0) cout<<"M apartine 12";
    if(d1==0&&d2>0&&d3<0) cout<<"M apartine 13";
    if(d1==0&&d2<0&&d3==0) cout<<"M apartine 14";
    if(d1==0&&d2==0&&d3<0) cout<<"M apartine 15";
    if(d1<0&&d2==0&&d3==0) cout<<"M apartine 16";
    if(d1<0&&d2>0&&d3>0) cout<<"M apartine 17";
    if(d1>0&&d2<0&&d3>0) cout<<"M apartine 18";
    if(d1>0&&d2>0&&d3<0) cout<<"M apartine 19";}


    return 0;
}
