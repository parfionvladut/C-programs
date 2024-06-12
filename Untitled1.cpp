#include<iostream>
#include<string>
using namespace std;

void problem1(){
string input;
getline(cin,input);
if(input==""||input=="00"||input=="110")
    cout<<"YES \n";
else cout<<"NO \n";
}
void problem2(){
string input, strings="1";
int i;
cin>>input;
for(i=0;i<input.length();i++){
    if(input==strings)
    cout<<"YES \n";
        else cout<<"NO \n";
    strings='0'+strings;
}
}
void problem3(){
string input, strings="";
int i;
getline(cin,input);
for(i=0;i<input.length();i++){
    if(input==strings)
    cout<<"YES \n";
        else
            cout<<"NO \n";
    strings=strings+'1';
     strings='0'+strings;
}
}
void problem4(){
string input, strings="";
int i;
getline(cin,input);
for(i=0;i<input.length();i++){
    strings='0'+strings;
}
for(i=0;i<=input.length();i++){
        if(input==strings)
    cout<<"YES \n";
        else
            cout<<"NO \n";
    strings.erase(0,1);
    strings=strings+'1';
}
}
void problem5(){
    string input, strings="";
int i;
cin>>input;
if(input.length()%3!=0)
     cout<<"NO \n";
else
for(i=0;i<input.length()/3;i++){
    strings='0'+strings;
}
for(i=0;i<input.length()/3;i++){
    strings=strings+'1';
}
for(i=0;i<input.length()/3;i++){
    strings=strings+'0';
}
    if(input==strings)
    cout<<"YES \n";
        else
            cout<<"NO \n";
}
void problem6(){
    string input, strings="";
int i;
cin>>input;
for(i=0;i<input.length();i++){
    strings='0'+strings;
}
       bool isPrime = true;
  for(i = 2; i <= input.length() / 2; ++i)
  {
      if(input.length() % i == 0)
      {
          isPrime = false;
          break;
      }
  }
  if (isPrime&&strings==input)
      cout << "YES";
  else
      cout << "NO";

}
int main(){
//problem3();
problem4();
//problem5();
//problem6();
return 0;
}
