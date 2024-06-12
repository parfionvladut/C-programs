#include <iostream>
#include<cstdlib>
#include<cstring>
using namespace std;
int Negatia(int i)
{
    if(i==1)
        return 0;
    return 1;
}

int Sau(int i,int j)
{
    if(i==0&&j==0)
        return 0;
    return 1;

}
int Si(int i,int j)
{
    if(i==1&&j==1)
        return 1;
    return 0;

}
int Implica(int i,int j)
{
    if(i==1 && j==0)
        return 0;
    return 1;
}
int Echivalent(int i, int j)
{
    if(i==j)
        return 1;
    return 0;
}

int Forma_Normala_Conjunctiva_Minimala()
{
    int matrice[100][100], vector_nou[100][100], i, coloana=1, linie=1;
    int numara_greseli=0;
    int v[100][100], contor_linie=0,l;
    int  a, j, k, b, c, d, i1, s, s1, i2, s2, e, s3;

    cout << "NrLIn      A    B    C    D   Raspuns"<<endl;
    for(a=0;a<=1;a++)
    {
        for(b=0;b<=1;b++)
        {
            for(c=0;c<=1;c++)
                for(d=0;d<=1;d++)
                {
                v[contor_linie][0]=contor_linie;
                v[contor_linie][1]=a;
                v[contor_linie][2]=b;
                v[contor_linie][3]=c;
                v[contor_linie][4]=d;
                i= Implica(a,b);
                i1=Implica(c,b);
                s=Si(i,i1);
                s1=Sau(a,c);
                i2=Implica(d,s1);
                s2=Si(s,i2);
                e=Echivalent(d,b);
                s3=Si(s2,e);
                v[contor_linie][5]=s3;
                //     cout<<contor_linie<<"          "<<a<<"    "<<b<<"    "<<c<<"    "<<d<<"    "<<s3<<endl;
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
    int a,b,c,d,i,i1,s,s1,i2,s2,e,s3;
     cout << "A   B   C   D Raspuns"<<endl;
    for(a=0;a<=1;a++)
        for(b=0;b<=1;b++)
            for(c=0;c<=1;c++)
                for(d=0;d<=1;d++)
                {
                i=Implica(a,b);
                i1=Implica(c,b);
            s=Si(i,i1);
            s1=Sau(a,c);
            i2=Implica(d,s1);
            s2=Si(s,i2);
            e=Echivalent(d,b);
            s3=Si(s2,e);
            if(s3==0)
                 cout<<a<<"   "<<b<<"   "<<c<<"   "<<d<<"   "<<s3<<endl;

}
}
int Forma_normala_disjunctiva()
{
    int a,b,c,d,i,i1,s,s1,i2,s2,e,s3;
cout << "A   B   C   D Raspuns"<<endl;
    for(a=0;a<=1;a++)
        for(b=0;b<=1;b++)
            for(c=0;c<=1;c++)
                for(d=0;d<=1;d++)
            {
            i= Implica(a,b);
            i1=Implica(c,b);
            s=Si(i,i1);
            s1=Sau(a,c);
            i2=Implica(d,s1);
            s2=Si(s,i2);
            e=Echivalent(d,b);
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
                    cout<<"C v ";
                else cout<<"!C v ";
                if(d==1)
                    cout<<"D) ";
                else cout<<"!D) &";
            }





            }
}
void tabel_adevar()
{
int a,b,c,d,i,i1,s,s1,i2,s2,e,s3;
cout << "A   B   C   D Raspuns"<<endl;
    for(a=0;a<=1;a++)
        for(b=0;b<=1;b++)
            for(c=0;c<=1;c++)
                for(d=0;d<=1;d++)
            {
            i= Implica(a,b);
            i1=Implica(c,b);
            s=Si(i,i1);
            s1=Sau(a,c);
            i2=Implica(d,s1);
            s2=Si(s,i2);
            e=Echivalent(d,b);
            s3=Si(s2,e);


            cout<< a <<" | "<< b <<" | "<< c <<" | "<<  d <<" | "<<s3;
            cout<<" --  ";
            if(s3==0)
                cout<<"FNC";
            else
                cout<<"FND";
            cout<<endl;
            }
cout<<endl;
    if(s3==1)
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
                if(d==0)
                    cout<<"D) ";
                else cout<<"!D) &";
            }

}

int main()
{

    char sir[100] {" (B-(A-C))&(B-A)~(B-(B-C))" };
    cout<<"Formula logica este: "<<sir;
    cout<<endl;
    cout<<"---------------------";
    cout<<endl;
    cout<<"Tabelul de adevar al formulei este: ";
    cout<<endl;
    tabel_adevar();
    cout<<endl<<endl;
    cout<<"-----------------------------------------";
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

