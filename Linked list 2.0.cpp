#include<iostream>
#include<cstring>
using namespace std;
struct Node{
	char name[100];
	int PIN;
	int code;
	Node *next;
};

Node *first =NULL;
Node *first2=NULL;

void Display(Node *first){
	while(first!=NULL){
	 cout<<first->name<<" "<<first->PIN<<first->code<<endl;
	 first=first->next;
    }

}
void addBegining(Node * &first,char *name,int PIN,int code)
{
	Node *el=new Node;
	strcpy(el->name,name);
	el->PIN=PIN;
	el->code=code;
	el->next=first;
	first=el;

}
void addFinal(Node *&first,char *name,int PIN,int code){
	Node *el=new Node;
	strcpy(el->name,name);
	el->PIN=PIN;
	el->code=code;
	el->next=NULL;

	if(first==NULL)
	  first=el;
	else
	{
		Node *list=first;
		while(list->next!=NULL)
		 list=list->next;
		list->next=el;
	}
}
Node* searchName(Node * el,char *sir)
{
	while(el != NULL && strcmp(el->name,sir)!=0)
	 el=el->next;
	return el;
}
int main()
{
    Node *el=new Node;
	Node *el2=new Node;
	Node *first=new Node;
	Node *first2=new Node;
	char answer;
    char name[100];
    int  i=2,n=2;
    int PIN;
    int code=001;
    cout<<"name: "; cin>>name;
    cout<<"PIN: "; cin>>PIN;
    cout<<"The account code is :"<<code<<endl;
    strcpy(el->name,name);
    el->PIN=PIN;
    el->next=NULL;
    first=el;
    do{
      cout<<"Add another person(y/n)? "; cin>>answer;
      if(answer=='y'){
        cout<<"name: "; cin>>name;
        cout<<"PIN: "; cin>>PIN;
        code++;
        cout<<"The account code is :"<<code<<endl;
        addBegining(el,name,PIN,code);
        n++;
      }
      else
        if(answer=='n')
      {

          i++;
      }

    }
     while(i<n);
    return 0;



}
