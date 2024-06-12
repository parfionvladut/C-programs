#include<iostream>
#include<string.h>

using namespace std;
//28
int sau(int a,int b)///v
{
    if((a==0)&&(b==0)){
        return 0;
    }

    else return 1;
}
int impl(int a,int b)///->
{
    if(a==b)
        return 1;
    else
        if((a==1)&&(b==0))
        return 0;
    else
        if((a==0)&&(b==1))
        return 1;
}
int echiv(int a,int b)///<->
{
  if(a==b)
    return 1;
  else
    return 0;
}
int si(int a,int b)///&
{
 if((a==1)&&(b==1))
    return 1;
 else
    return 0;
}

int formule(int A,int B,int C){
    int r1=sau(A,B);cout<<r1;
    int r2=sau(C,A);cout<<r2;
    int r3=impl(r1,r2);
cout<<r3;
    return r3;
}

int aparitii[100]={0};

void propozitii(char *formula)
{   int propozitii=0;
    for(char j='A';j<='Z';j++)
    {
        if(aparitii[j]>0)
            propozitii++;
    }
    cout<<"nr of propozitions : "<<propozitii<<endl;
}
int ordin_formula(char *formula)
{   ///nr de conectori
    int i;
    int ordin=0;
    for(i=0;i<strlen(formula);i++)
    {
        if(formula[i]=='!'||formula[i]=='&'||formula[i]=='-'||formula[i]=='->'||formula[i]=='~'||formula[i]=='<->'||formula[i]=='v')
        {
            ordin++;
        }
    }

    return ordin;

}

int subformula(char *formula)
{   int rez=0;
    int nr_variabile=0;
        int i;
        for(i=0;i<strlen(formula);i++)
        {
            if(formula[i]>='A'&&formula[i]<='Z')
            {
                nr_variabile++;
            }
        }

        rez=nr_variabile+ordin_formula(formula)+1;
        return rez;

}///nr variabile+nr ordin +1

void nr_aparitii(char *formula)
{   //int aparitii[100]={0};
    int A=0,B=0,C=0;
    int i;
    for(i=0;i<strlen(formula);i++)
    {
        aparitii[formula[i]]++;
    }

    for(char j='A';j<='Z';j++)
    {
        if(aparitii[j]>0)
            cout<<j<<" appears "<<aparitii[j]<<" times ."<<endl;
    }

}
void truth_table(){
    for(int a=0;a<=1;a++){
        for(int b=0;b<=1;b++){
            for(int c=0;c<=1;c++){
                int f=formule(a,b,c);
                cout<<a<<"    "<<b<<"    "<<c<<"                 "<<f<<endl;
            }
        }
    }
}
void conjuctive_normall_form(){

}
int main()
{
    int A=0,B=0,C=0;
    char formula[99]="(AvB)->(CvA)";
    cout<<"The formula is : (AvB)->(CvA)"<<endl;
    nr_aparitii(formula);
    cout<<endl;
    cout<<"order formula (logicall lenght) = "<<ordin_formula(formula)<<endl;
    ordin_formula(formula);
    cout<<"nr of subforms = "<<subformula(formula)<<endl;
    propozitii(formula);
    cout<<"Truth's table:"<<endl;

    cout<<"A    "<<"B    "<<"C    "<<"        (AvB)->(CvA)"<<endl;
    truth_table();

}
