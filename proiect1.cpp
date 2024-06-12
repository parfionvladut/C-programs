#include <iostream>
#include <cstring>
#include <fstream>
#include <string.h>
#include <string>
#include <cstring>
using namespace std;

struct Node
{
char word[30];
int wordpozition;
 Node *left,*right;
};

class Word_tree{
private:
    struct Node *root;
    Node * createNewNode(char * word,int wordpozition) {
        Node *newNode = new Node;
        strcpy(newNode->word,word);
        newNode->wordpozition = wordpozition;
        newNode->right = NULL;
        newNode->left = NULL;
        return newNode;
    }
    void readTextfile();
public:
    Node*getRoot()
{
    return root;
}

     void insert(int key, Node *leaf);
};
 void readTextfile(){  //reads text from test.txt
            string str;
            char cstr[str.size() + 1];
            char word[30][30]; //can store 30 words of 30 characters
            int k,i,j,cnt;
            ifstream myfile;

            myfile.open("test.txt");//file adress
            if(!myfile){
                cout<<"File does not exist."<<endl;
                }
                else
                    cout<<"File opened."<<endl;
                    getline(myfile,str);//coppies text to string
                    strcpy(cstr, str.c_str());//converts string to array of char
                    j=0; cnt=0;
                    for(i=0;i<=strlen(cstr);i++){

                         // if space or NULL found, assign NULL into word[cnt]
                        if(cstr[i]==' '||cstr[i]=='\0')
                            {

                                word[cnt][j]='\0';
                                cnt++;  //for next word
                                j=0;    //for next word, init index to 0
                            }
                            else
                                {
                                    word[cnt][j]=cstr[i];
                                    j++;
                                }
                    }
return ;
myfile.close();
}

int main(){

 cout<<"Input the word you would like to search"<<endl;
readTextfile();
 cout<<"The word has been found"<<" "/*<<counter*/<<"times on the"<<" "/*<<Nr_prop*/<<"'th propozition"<<endl;

}
