#include<iostream>
#include<string.h>
using namespace std;
//28
int impl(int a,int b)///->
{
    if(a==b)
        return 1;
    else
        if((a==1)&&(b==0))
        return 1;
    else
        if((a==0)&&(b==1))
        return 0;
}
int echiv(int a,int b)///<->
{
  if(a==b)
    return 1;
  else
    return 0;
}
int Si(int a,int b)///&
{
 if((a==1)&&(b==1))
    return 1;
 else
    return 0;
}
int Sau(int a,int b) /// V
{
    if((a==0)&&(b==0))
        return 0;
    else
        return 1;
}
int neg(int a) ///!
{
    if(a=1)
        return 0;
    else
        return 1;
}

int formule(int A,int B,int C){
    int r1=Sau(neg(A),B);
    int r2=Sau(neg(C),A);
    int r3=Sau(neg(C),B);
    r2=Sau(neg(r2),r3);
    r1=Sau(neg(r1),r2);
    r1=Sau(neg(C),r1);
    return r1;
}
void truth_table(){
   int r1,a,b,c;
    for(int a=0;a<=1;a++){
        for(int b=0;b<=1;b++){
            for(int c=0;c<=1;c++){
                int f=formule(a,b,c);
                cout<<a<<"    "<<b<<"    "<<c<<"                 "<<f<<"--------";

                if(f==0)
                    cout<<"FNC";
            else
                cout<<"FND";

            cout<<endl;
            if(r1==1)
            {
                if(a==0)
                    cout<<"(A v ";
                else cout<<"(!A v ";
                if(b==0)
                    cout<<"B v ";
                else cout<<"!B v ";
                if(c==0)
                    cout<<"C v ";
                else cout<<"!C v ";
            }
            }
        }
    }

cout<<endl;
    if(r1==1)
            {
                if(a==0)
                    cout<<"(A v ";
                else cout<<"(!A v ";
                if(b==0)
                    cout<<"B v ";
                else cout<<"!B v ";
                if(c==0)
                    cout<<"C v ";
                else cout<<"!C v ";

            }


    }

int Forma_Normala_Conjunctiva_Minimala()
{
    int matrice[100][100], vector_nou[100][100], i, coloana=1, linie=1;
    int numara_greseli=0;
    int v[100][100], contor_linie=0,l;
    int  a, j, k, b, c, i1, s, s1, i2, s2,r1, e, s3,A,B,C;

    cout << "NrLIn      A    B    C      Raspuns"<<endl;
    for(a=0;a<=1;a++)
    {
        for(b=0;b<=1;b++)
        {
            for(c=0;c<=1;c++)
                {
                v[contor_linie][0]=contor_linie;
                v[contor_linie][1]=a;
                v[contor_linie][2]=b;
                v[contor_linie][3]=c;
                i= impl(a,b);
            i1=impl(c,b);
            s=Si(i,i1);
            s1=Sau(a,c);
            s2=Si(s,i2);
            s3=Si(s2,e);
                v[contor_linie][5]=r1;
                    // cout<<contor_linie<<"          "<<a<<"    "<<b<<"    "<<c<<"    "<<"    "<<s3<<endl;
                contor_linie++;
                }
        }
    }
    cout<<endl;
    int o;
               for(l=0;l<=15;l++)
            {
                for(o=0;o<=4;o++)
                {
                    cout<<v[l][o]<<"  ";
                }
                cout<<endl;
            }
     cout<<"-----------------"<<endl;
    for(i=1;i<15;i++)
    {
        for(j=i+1;j<=15;j++)
            {
                for(k=1;k<=4;k++)
                {
                    //vector_nou[][o]=contor_linie;
                    if(v[i][k]==0 && v[j][k]==0)
                        vector_nou[linie][coloana]=0;
                    if(v[i][k]==0 && v[j][k]==1)
                        vector_nou[linie][coloana]=2;    //eu in loc de steluta am folosit numarul 2
                    if(v[i][k]==1 && v[j][k]==0)
                        vector_nou[linie][coloana]=2;
                    if(v[i][k]==1 && v[j][k]==1)
                        vector_nou[linie][coloana]=1;
                    matrice[i][1]=i;
                    matrice[i][2]=j;
                    coloana++;
                    //contor_linie++;
                }
                linie++;
                coloana=1;
            }
    }


 cout<<"------------------------------- "<<endl;

    for(i=0;i<=linie;i++)
    {
        for(j=0;j<=4;j++)
        {
            cout<<vector_nou[i][j]<<" ";
            if(j==4)
                cout<<"("<<matrice[i][1]<<","<<matrice[i][2]<<")";
        }
        cout<<endl;
    }
}


int  Forma_normala_conjunctiva()
{
    int vector[100],h=0,l;
    int a,b,c,i,i1,s,s1,i2,s2,e,s3;
     cout << "A   B   C   Raspuns"<<endl;
    for(a=0;a<=1;a++)
        for(b=0;b<=1;b++)
            for(c=0;c<=1;c++)
                {
               i= impl(a,b);
            i1=impl(c,b);
            s=Si(i,i1);
            s1=Sau(a,c);
            s2=Si(s,i2);
            s3=Si(s2,e);
            if(s3==0)
                 cout<<a<<"   "<<b<<"   "<<c<<"   "<<s3<<endl;

}
}
int Forma_normala_disjunctiva()
{
    int a,b,c,i,i1,s,s1,i2,s2,e,s3;
cout << "A   B   C   Raspuns"<<endl;
    for(a=0;a<=1;a++)cout<<endl;
        for(b=0;b<=1;b++)
            for(c=0;c<=1;c++)
            {
            i= impl(a,b);
            i1=impl(c,b);
            s=Si(i,i1);
            s1=Sau(a,c);
            s2=Si(s,i2);
            s3=Si(s2,e);

            if(s3==0)
            {
                if(a==1)
                    cout<<"(A v ";
                else cout<<"(!A v ";
                if(b==1)
                    cout<<"B v ";
                else cout<<"!B v ";
                if(c==1)
                    cout<<"C)";
                else cout<<"!C)&";
            }
            }

}

int main()
{
    int A=0,B=0,C=0;
    char formula[99]="C&(A->B)<->((C->A)->(C->B))";
    cout<<"The formula is : C&(A->B)<->((C->A)->(C->B))"<<endl;
    cout<<"Truth's table:"<<endl;
    cout<<"A    "<<"B    "<<"C    "<<"C&(A->B)<->((C->A)->(C->B))"<<endl;
    truth_table();
    cout<<"---------------------";
    cout<<endl;
    cout<<"Forma normala conjunctiva a formulei este: ";
    cout<<endl;
    cout<<endl;
    Forma_normala_conjunctiva();
    cout<<endl<<endl;
    cout<<"-----------------------------------------";
    cout<<endl;
    cout<<"Forma normala disjunctiva a formulei este: ";
    cout<<endl;
    Forma_normala_disjunctiva();

    cout<<endl;
}

