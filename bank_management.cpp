#include<iostream>
using namespace std;

class account
{
private:
    string name;
    string accno;
    string atype;
public:
    void  getAccountDetails()
    {
        cout<<"\nEnter Customer Name : ";
        cin>>name;
        cout<<"Enter Account Number  : ";
        cin>>accno;
        cout<<"Enter Account Type    : ";
        cin>>atype;
    }
    void displayDetails()
    {
        cout<<"\n\nCustomer Name : "<<name;
        cout<<"\nAccount Number  : "<<accno;
        cout<<"\nAccount Type    : "<<atype;
    }
};
class current_account : public account
{
private:
    float balance;
public:
    void c_display()
    {
        cout<<"\nBalance :"<<balance;
    }
    void c_deposit()
    {
        float deposit;
        cout<<"\nEnter amount to Deposit :  ";
        cin>>deposit;
        balance = balance + deposit;
    }
    void c_withdraw()
    {
        float withdraw;
        cout<<"\n\nBalance : "<<balance;
        cout<<"\nEnter amount to be withdraw :";
        cin>>withdraw;
        if(balance > 1000)
        {
            balance=balance-withdraw;
            cout<<"\nBalance Amount After Withdraw: "<<balance;
        }
        else
        {
            cout<<"\n Insufficient Balance";
        }
 
    }
 
 
};
 
class saving_account : public account
{
private:
    float sav_balance;
public:
    void s_display()
    {
        cout<<"\nBalance :  "<<sav_balance;
    }
    void s_deposit()
    {
        float deposit,interest;
        cout<<"\nEnter amount to Deposit :  ";
        cin>>deposit;
        sav_balance = sav_balance + deposit;
        interest=(sav_balance*2)/100;
        sav_balance=sav_balance+interest;
    }
    void s_withdraw()
    {
        float withdraw;
        cout<<"\nBalance :- "<<sav_balance;
        cout<<"\nEnter amount to be withdraw : ";
        cin>>withdraw;
        if(sav_balance > 500)
        {
            sav_balance=sav_balance-withdraw;
            cout<<"\nBalance Amount After Withdraw: "<<sav_balance;
        }
        else
        {
            cout<<"\n Insufficient Balance";
        }
    }
};
 
 
 
int main()
{
    current_account cur;
    saving_account sav;
    char type;
    cout<<"\nEnter S for saving customer and C for current a/c customer : ";
    cin>>type;
    int choice;
    if(type=='s' || type=='S')
    {
        sav.getAccountDetails();
        while(1)
        {
            cout<<"\nChoose Your Choice"<<endl;
            cout<<"1)   Deposit Money"<<endl;
            cout<<"2)   Withdraw Money"<<endl;
            cout<<"3)   Display Balance"<<endl;
            cout<<"4)   Display with full Details"<<endl;
            cout<<"5)   Exit"<<endl;
            cout<<"Enter Your choice: ";
            cin>>choice;
            switch(choice)
            {
            case 1 :
                sav.s_deposit();
                break;
            case 2 :
                sav.s_withdraw();
                break;
            case 3 :
                sav.s_display();
                break;
            case 4 :
                sav.displayDetails();
                sav.s_display();
                break;
            case 5 :
                goto end;
            default:
                cout<<"\n\nEntered choice is invalid,\"TRY AGAIN\"";
            }
        }
    }
    else if(type=='c' || type=='C')
    {
        cur.getAccountDetails();
        while(1)
        {
            cout<<"\nChoose Your Choice"<<endl;
            cout<<"1)   Deposit"<<endl;
            cout<<"2)   Withdraw"<<endl;
            cout<<"3)   Display Balance"<<endl;
            cout<<"4)   Display with full Details"<<endl;
            cout<<"5)   Exit"<<endl;
            cout<<"Enter Your choice: ";
            cin>>choice;
            switch(choice)
            {
            case 1 :
                cur.c_deposit();
                break;
            case 2 :
                cur.c_withdraw();
                break;
            case 3 :
                cur.c_display();
                break;
            case 4 :
                cur.displayDetails();
                cur.c_display();
                break;
            case 5 :
                goto end;
            default:
                cout<<"\n\nEntered choice is invalid,\"TRY AGAIN\"";
            }
        }
    }
    else
    {
        cout<<"\nInvalid Account Selection";
    }
end:
    cout<<"\nThank You";
    return 0;
}
