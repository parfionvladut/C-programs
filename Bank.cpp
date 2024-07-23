#include <iostream>
#include <cmath>
void showBalance(double balance){
    std::cout<<"Your balance is: "<<balance<<'\n';
}
void deposit(int *balance , int sum){
    *balance = *balance + sum;
}

void extract(int *balance , int sum){
    *balance = *balance - sum;
}
int main()
{
    int balance, sum, response;
    balance = 30;
    sum =0;
    do{
        do{
            std::cout<<"What would you like to do:"<<'\n';
            std::cout<<"1.Deposit balance"<<'\n';
            std::cout<<"2.Extract balance"<<'\n';
            std::cout<<"3.Check balance"<<'\n';
            std::cout<<"4.Exit"<<'\n';
            std::cin>>response;
        }while(response == NULL);

        switch(response){
            case 1:
                std::cout<<"Enter the sum you would like to deposit:"<<'\n';
                std::cin>>sum;
                deposit(&balance, sum);
                std::cout<<"Your balance now is "<<balance<<'\n';
                break;
            case 2:
                std::cout<<"Enter the sum you would like to extract:"<<'\n';
                std::cin>>sum;
                extract(&balance, sum);
                std::cout<<"Your balance now is "<<balance<<'\n';
                break;
            case 3:
                showBalance(balance);
                break;
        }
    }while(response != 4);
    return 0;
}
