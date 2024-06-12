#include<iostream>
#include<cstring>
#include<fstream>
#include<vector>
using namespace std;

struct Node {
    char ID[30];        ///the word
    int nr;             ///nr. of times it appears
    vector<int> v;      ///positions it appears on
    Node *right, *left; };

class BinarySearchTree {
    private:
        struct Node *root;
        struct Node *createNewNode(char ID[30],int pos) {
            Node *temp = new Node;
            strcpy(temp->ID,ID);
            temp->nr=1;                 ///create node implies it appeared for the first time, so nr=1
            temp->v.push_back(pos);     ///add the 1st position it appears on
            temp->right = NULL;
            temp->left = NULL;
            return temp;  }
        void travInorder(Node *temp) {
            if (temp != NULL) {
                travInorder(temp->left);
                cout<<temp->ID<<endl;
                travInorder(temp->right);   }}
        void travPreorder(Node *temp) {
            if (temp != NULL) {
                cout<<temp->ID<<endl;
                travPreorder(temp->left);
                travPreorder(temp->right);   }}
        void travPostorder(Node *temp) {
            if (temp!=NULL) {
                travPostorder(temp->left);
                travPostorder(temp->right);
                cout<<temp->ID<<endl;   }}
        void deleteTree(struct Node *temp) {
            if(temp!=NULL) {
                deleteTree(temp->left);
                deleteTree(temp->right);
                delete temp;    }}
        int height(Node *temp) {    ///height of tree
            if(temp==NULL) return 0;
            int hleft=height(temp->left), hright=height(temp->right);
            if(hleft>=hright) return hleft+1;
            else return hright+1; }
    public:
        BinarySearchTree() {
            root=NULL;    }
        ~BinarySearchTree() {
            deleteTree(root);   }
        void addNode(char ID[30],int pos) {
            if(root==NULL) root=createNewNode(ID,pos);
            else {
                Node *temp=root;
                while(1) {
                    if(strcmp(ID,temp->ID)<0) {
                        if(temp->left==NULL) {
                            temp->left=createNewNode(ID,pos);
                            break;  }
                        else temp=temp->left; }
                    else if(strcmp(ID,temp->ID)>0) {
                        if(temp->right==NULL) {
                            temp->right=createNewNode(ID,pos);
                            break;  }
                        else temp=temp->right;    }
                    else {      ///if equal, increase only nr. of apparitions and add next position
                        temp->nr++;
                        temp->v.push_back(pos); break;  }}}}
        void clearTree() {
            deleteTree(root); }
        int heightTree() {
            return height(root); }
        void inorder() {
            cout<<endl<<"Inorder traversal: "<< endl;
            travInorder(root); }
        void preorder() {
            cout<<endl<<"Preorder traversal: "<<endl;
            travPreorder(root); }
        void postorder() {
            cout<<endl<<"Postorder traversal: "<<endl;
            travPostorder(root); }
        struct Node *searchID(char ID[30]) {
            Node *temp=root;
            if(strcmp(ID,temp->ID)==0) return temp;
            while(1) {
                if(strcmp(ID,temp->ID)<0) {
                    temp=temp->left;
                    if(temp==NULL) return NULL;
                    if(strcmp(ID,temp->ID)==0) return temp; }
                else if(strcmp(ID,temp->ID)>=0) {
                    temp=temp->right;
                    if(temp==NULL) return NULL;
                    if(strcmp(ID,temp->ID)==0) return temp; } } }
        struct Node *parent(char ID[30]) {
            Node *temp=root;
            if(strcmp(ID,temp->ID)==0) return NULL;
            while(1) {
                if(strcmp(ID,temp->ID)<0) {
                    if(strcmp(ID,temp->left->ID)==0) return temp;
                    temp=temp->left;
                    if(temp==NULL) return NULL; }
                else if(strcmp(ID,temp->ID)>=0) {
                    if(strcmp(ID,temp->right->ID)==0) return temp;
                    temp=temp->right;
                    if(temp==NULL) return NULL; } } }
        void addFromFile() {    ///add words from a text file as nodes
            char fileName[30];
            cout<<"File name: "; cin>>fileName;  ///with extension at the end
            ifstream f(fileName);
            if(!f) {
                cout<<"File doesn't exist.\n";
                return;  }
            char word[30];  int i,pos=1;    ///pos - position of word
            while(f>>word) {
                for(i=0;i<strlen(word);i++)    ///remove next chars. from the word
                    if(word[i]=='.' || word[i]==',' || word[i]==';' || word[i]==':' || word[i]=='"' || word[i]=='?' || word[i]=='!' || word[i]=='(' || word[i]==')') {
                        strcpy(word+i,word+i+1); i--; }    ///remove the character
                addNode(word,pos); pos++; }  ///add the word and increase position
            f.close();  }
};

void treeMenu(BinarySearchTree BST) {
    int x,i; char word[30];
    Node *temp=NULL;
    while(1) {
    cout<<"  1.Input from file"<<endl;
    cout<<"  2.Search word"<<endl;  ///also displays number
    cout<<"  3.Parent"<<endl;
    cout<<"  4.Height"<<endl;
    cout<<"  5.Preorder"<<endl;
    cout<<"  6.Inorder"<<endl;
    cout<<"  7.Postorder"<<endl;
    cout<<"  8.Positions"<<endl;
    cout<<"  9.Clear the tree (not working)"<<endl;
    cout<<"  10.Exit"<<endl;
        cout<<"Do: "; cin>>x;
        switch(x) {
            case 1: BST.addFromFile(); break;
            case 2: cout<<"Word to search: "; cin>>word;
                temp=BST.searchID(word);
                if(temp==NULL) {cout<<"Word not in tree."<<endl; break;}
                cout<<word<<" is in tree and appears "<<temp->nr<<" times."<<endl; break;
            case 3: cout<<"Parent of: "; cin>>word;
                temp=BST.parent(word);
                if(temp!=NULL) {cout<<"Parent is "<<temp->ID<<"."<<endl; break;}
                    else {cout<<word<<" doesn't have a parent."<<endl; break;}
            case 4: cout<<"Height of tree is "<<BST.heightTree()<<"."<<endl; break;
            case 5: BST.preorder(); break;
            case 6: BST.inorder(); break;
            case 7: BST.postorder(); break;
            case 8: cout<<"Show positions of: "; cin>>word;
                temp=BST.searchID(word);
                if(temp==NULL) cout<<word<<" isn't in tree."<<endl;
                else {
                    cout<<word<<" appears on the following positions:"<<endl;
                    for(i=0;i<temp->v.size();i++)
                        cout<<temp->v[i]<<" ";
                    cout<<endl; }
                break;
            case 9: BST.clearTree(); break;
        }
        if(x==10) return;
    } }
int main() {
    BinarySearchTree Tree1;
    treeMenu(Tree1);
    return 0;   }
