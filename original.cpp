#include<iostream>
#include<cstring>
#include<fstream>
using namespace std;

struct Node {
    char ID[30];
    Node *right, *left; };

class BinarySearchTree {
    private:
        struct Node *root;
        Node *createNewNode(char ID[]) {
            Node *newNode = new Node;
            strcpy(newNode->ID,ID);
            newNode->right = NULL;
            newNode->left = NULL;
            return newNode;  }
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
            if (temp != NULL) {
                travPostorder(temp->left);
                travPostorder(temp->right);
                cout<<temp->ID<<endl;   }}
        void deleteTree(Node *temp) {
            if(temp!=NULL) {
                deleteTree(temp->left);
                deleteTree(temp->right);
                delete temp;    }}
        int height(Node *temp) {
            if(temp==NULL) return 0;
            int hleft=height(temp->left), hright=height(temp->right);
            if(hleft>=hright) return hleft+1;
            else return hright+1; }
    public:
        BinarySearchTree() {
            root = NULL;    }
        ~BinarySearchTree() {
            deleteTree(root);   }
        struct Node* getRoot() {
            return root; }
        void addNode(char vID[]) {
            if(root==NULL) root=createNewNode(vID);
            else{
                Node *temp=root;
                while(true) {
                    if(strcmp(vID,temp->ID)<0) {
                        if(temp->left == NULL) {
                            temp->left = createNewNode(vID);
                            break;  }
                        else temp = temp->left; }
                    else if(strcmp(vID,temp->ID)>=0) {
                            if(temp->right == NULL) {
                                temp->right = createNewNode(vID);
                                break;  }
                            else temp = temp->right;    } } } }
        int heightTree() {
            return height(root); }
        void inorder() {
            cout << endl << "Inorder traversal: "<< endl;
            travInorder(root); }
        void preorder() {
            cout<<endl<<"Preorder traversal: "<<endl;
            travPreorder(root); }
        void postorder() {
            cout<<endl<<"Postorder traversal: "<<endl;
            travPostorder(root); }
        Node* searchID(char vID[]) {
            Node *temp=root;
            if(strcmp(vID,temp->ID)==0) return temp;
            while(1) {
                if(strcmp(vID,temp->ID)<0) {
                    temp=temp->left;
                    if(temp==NULL) return NULL;
                    if(strcmp(vID,temp->ID)==0) return temp; }
                else if(strcmp(vID,temp->ID)>=0) {
                    temp=temp->right;
                    if(temp==NULL) return NULL;
                    if(strcmp(vID,temp->ID)==0) return temp; } } }
        Node *parent(char vID[]) {
            Node *temp=root;
            if(strcmp(vID,temp->ID)==0) return NULL;
            while(1) {
                if(strcmp(vID,temp->ID)<0) {
                    if(strcmp(vID,temp->left->ID)==0) return temp;
                    temp=temp->left;
                    if(temp==NULL) return NULL; }
                else if(strcmp(vID,temp->ID)>=0) {
                    if(strcmp(vID,temp->right->ID)==0) return temp;
                    temp=temp->right;
                    if(temp==NULL) return NULL; } } }
        void addFromFile() {
            ifstream f("test.txt");
            char word[30];  int i;
            while(f>>word) {
                for(i=0;i<strlen(word);i++) {
                    if(word[i]=='.' || word[i]==',' || word[i]==';' || word[i]==':') {
                        strcpy(word+i,word+i+1);
                        i--;  } }
                addNode(word); }
            f.close();  }
        void readTextfile(){  //reads text from test.txt
            string str;
            char cstr[str.size() + 1];
            char word[30];
            char wordy[30][30]; //can store 30 words of 30 characters
            int k=0,i,j,cnt;
            ifstream myfile;

            myfile.open("test.txt");//file adress
            if(!myfile)
                cout<<"File does not exist."<<endl;
                else getline(myfile,str);//coppies text to string
                strcpy(cstr, str.c_str());//converts string to array of char
                j=0; cnt=0;
                for(i=0;i<=strlen(cstr);i++) {   // if space or NULL found, assign NULL into word[cnt]
                    if(cstr[i]==' '||cstr[i]=='\0')  {
                        wordy[cnt][j]='\0';
                        cnt++;  //for next word
                        j=0;    //for next word, init index to 0
                        }
                        else {
                            wordy[cnt][j]=cstr[i];
                            j++;  } }
                cout<<"Input from file:"<<endl;
                for(i=0;i < cnt;i++) {
                    cout<<wordy[i]<<" ";
                    addNode(wordy[i]);  }
                cout<<endl;
                myfile.close(); }
};

void treeMenu(BinarySearchTree BST) {
    int x; char word[30];
    cout<<"1.Add node\n2.Search node\n3.Parent\n4.Height\n5.Preorder\n6.Inorder\n7.Postorder\n8.Input from file\n9.Exit"<<endl;
    while(1) {
        cout<<"Do: "; cin>>x;
        switch(x) {
            case 1:{ cout<<"Word to add: "; cin>>word; BST.addNode(word); break; }
            case 2:{ cout<<"Word to search: "; cin>>word;
                if(BST.searchID(word)->ID==NULL) {cout<<"Word not in tree."<<endl; break;}
                else {cout<<"Word is in tree."<<endl; break;}}
            case 3:{ cout<<"Parent of: "; cin>>word;
                if(BST.parent(word)->ID!=NULL) {cout<<"Parent is "<<BST.parent(word)->ID<<"."<<endl; break;}
                else {cout<<word<<" doesn't have a parent."<<endl; break;}}
            case 4:{ cout<<"Height of tree is "<<BST.heightTree()<<"."<<endl; break;}
            case 5:{ BST.preorder(); break;}
            case 6:{ BST.inorder(); break;}
            case 7:{ BST.postorder(); break;}
            case 8:{cout<<"Inputing form file\n";BST.readTextfile();break;}
        }
        if(x==9) return;
    }
}
int main() {
    BinarySearchTree BST;

    treeMenu(BST);
    return 0;   }
