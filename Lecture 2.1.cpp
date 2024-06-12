
#include<iostream>
#include<cstring>
using namespace std;
struct Node{
	char name[100];
	int year;
	Node *next;
};

Node *first =NULL;
Node *first2=NULL;

void Display(Node *first){
	while(first!=NULL){
	 cout<<first->name<<" "<<first->year<<endl;
	 first=first->next;
    }

}

void addBegining(Node * &first,char *name,int year)
{
	Node *el=new Node;
	strcpy(el->name,name);
	el->year=year;
	el->next=first;
	first=el;

}

void addFinal(Node *&first,char *name,int year){
	Node *el=new Node;
	strcpy(el->name,name);
	el->year=year;
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

void deleteElement(Node * el)
{
	Node * elSterg=el->next;
	el->next=el->next->next;
	delete elSterg;
}

void delElemVal(Node *&el,int nr)
{
	if (el->year==nr)
	{
		Node * elSterg=el;
		el= el->next;
		delete elSterg;
	}
	Node *elem =el;
	while (elem->next!=NULL && elem->next->year!=nr)
	  elem=elem->next;
	if(elem->next!=NULL)
	  deleteElement(elem);
}

void delElemName(Node *&el,char *sir)
{
	if(strcmp(el->name,sir)==0)
	{
		Node * elSterg=el;
		el= el->next;
		delete elSterg;
	}
	Node *elem =el;
	while (elem->next!=NULL && strcmp(elem->next->name,sir)!=0)
	  elem=elem->next;
	if(elem->next!=NULL)
	  deleteElement(elem);
}

void concatenate() {};

int main(){

	Node *el=new Node;
	Node *el2=new Node;
	Node *first=new Node;
	Node *first2=new Node;
    char name[100];
    int year;
    cout<<"name: "; cin>>name;
    cout<<"year: "; cin>>year;
    strcpy(el->name,name);
    el->year=year;
    el->next=NULL;
    first=el;
    Display(el);
    cout<<"name: "; cin>>name;
    cout<<"year: "; cin>>year;
    addBegining(el,name,year);
    Display(el);
    cout<<"name: "; cin>>name;
    cout<<"year: "; cin>>year;
    addFinal(el,name,year);
    Display(el);



    cout<<"Delete name: ";
    cout<<"name: "; cin>>name;
    delElemName(el,name);
    Display(el);


 





	return 0;
}
// el->next->next==NULL  (penultimul element)
//  ant->next=el->next;
//  delete(el);
