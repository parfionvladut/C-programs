#include<iostream>
#include<string.h>
#include<stdio.h>
#include <stdlib.h>
using namespace std;
struct node
{
char *word;
struct node *left,*right;
};


struct node *inserttree(struct node *tree,char *s)
{
int i;

if (tree==NULL)
{
if ((tree=(struct node *) malloc(sizeof (struct node)))!=NULL)
if ((tree->word=(char *) malloc(strlen(s)+1))==NULL)
    {
    free(tree);
    tree=NULL;
    }
    else
    {
    tree->left=NULL;
    tree->right=NULL;
    strcpy(tree->word,s);
    }
}
else if ((i=strcmp(tree->word,s))>0) tree->left=inserttree(tree->left,s);
else if (i<0) tree->right=inserttree(tree->right,s);
return tree;
}


void printtree(struct node *tree)
{
if (tree!=NULL)
{
printtree(tree->left);
cout<<" "<<tree->word;
printtree(tree->right);
}
}


void freetree(struct node *tree)
{
if (tree!=NULL)
{
free(tree->word);
freetree(tree->left);
freetree(tree->right);
free(tree);
}
}


int main(void)
{
FILE *f;
char s[32]; /*assumes a word cannot be longer than 1023 chars*/
struct node *tree=NULL;

if ((f=fopen("Test.txt","r"))==NULL)
cout<<"Unable to open Test.txt";
else
{
while (fscanf(f,"%1023s",s)!=EOF)
tree=inserttree(tree,s);
fclose(f);
printtree(tree);
freetree(tree);
}
return 0;
}
