#include<stdint.h>
#include<stdio.h>
#include<string>
#include<vector>
#include<iostream>
#include<cstring>

using namespace std;

class Account{
    private:
        int accountNumber;
        string accountName;
        int balance;
    public:
        Account();
        void setAccount();
        int getBalance();
        void withdrawMoney();
        void sendMoney();
        void checkBalance();
};

Account::Account(){
    this -> accountNumber = 0;
    this -> accountName = " ";
    this -> balance = 0;
}

int Account::getBalance(){
    return this -> balance;
}
void Account::setAccount(){
    printf("Enter your account number:");
    scanf("%d",&(this -> accountNumber));
    printf("Enter your account name:");
    // getline(cin, this -> accountName);
    scanf("%s",&(this -> accountName));
    printf("Enter your account balance:");
    // cin.ignore(100,'\n');
    scanf("%d",&(this -> balance));
}

void Account::withdrawMoney(){
    int withdraw;
    printf("Enter your money you want withdraw:");
    scanf("%d", &withdraw);
    if(withdraw > balance){
        printf("Can't withdraw money.");
    }else{
        balance -= withdraw;
    printf("The remaining amount: %d",balance);
    }

}

void Account::sendMoney(){
    int send;
    printf("Enter your money you want to send:");
    scanf("%d", &send);
    balance += send;
    printf("The remaining amount: %d",balance);
}

void Account::checkBalance(){
    int balanceMoney = this -> balance;
    printf("The blance money: %d", balanceMoney);
}

int main(){
    Account account;
    account.setAccount();
    int key = 1;
    int choice;
    printf("---------------------------------------------------------");
    
    do
    {
        printf("\nThis is program checking the money of bank account");
        printf("\n1.sendMoney\n2.withdrawMoney\n3.checkMoney\n");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            account.sendMoney();
            break;
        case 2:
            account.withdrawMoney();
            break;    
        case 3:
            account.checkBalance();
            break;
        default:
            break;
        }
    } while (key);
    return 0;
}