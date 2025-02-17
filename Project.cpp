#include<conio.h>
#include<iostream>
#include<fstream>
#include<string>

using namespace std;
void Title();
void water();
void gas();
void electricity();
void school();
void payment();
void Payment_Title();
void fastCash();
void FastCash_Title();
void withdraw();
void withdraw_Title();
void login_page();
void funds_transfer();
void Balance_Inquiry();
void Mini_Statement_Title();
void mini_statement();
void PinChange_Title();
int account_balance=350000,funds=0,account_number,cash_withdraw=0,flag=0;
string mini="Your Mini Statement is: ",mini_cash1,mini_cash2,mini_cash3,mini_cash4,mini_cash5,mini_cash6,mini_cash7;
string mini_cash8,mini_gas,mini_water,mini_electric,mini_city,mini_allied,mini_beacon,mini_smart;
string ID_1,ID_2,pass_2,current_pass,new_pass,new_pass_2,pass_1,acc_balance_1,acc_balance_2,ID;
main()
{
    login:
    int select;   
    string pass;
    ifstream read("practice2.txt");
    getline(read,acc_balance_1);
    getline(read,ID_1);
    getline(read,pass_1);
    getline(read,acc_balance_2);
    getline(read,ID_2);
    getline(read,pass_2);
    read.close(); 
    system("cls");
    login_page();
    cout<<"\nEnter Your ID: ";
    cin>>ID;
    if(ID.compare(ID_2)!=0 && ID.compare(ID_1)!=0)
    {
        cout<<"Incorrect ID";
        cout<<"\nPress any key to continue";
        getch();
        goto login; 
    }
    cout<<"\nEnter Your Password: ";
    fflush(stdin);
    getline(std::cin, pass);
    if(ID==ID_1 && pass==pass_1 || ID==ID_2 && pass==pass_2)
    {
        main_menu:
        system("cls");
        Title();
        cout<<"\n1. Fast Cash           2. Cash Withdrawal\n";
        cout<<"3. Balance Inquiry     4. Mini Statement\n";
        cout<<"5. Pin Change          6. Funds Transfer\n";
        cout<<"7. Payments            8. Sign Out\n";
        cout<<"Select the operation you want to perform:";
        cin>> select;
        system("cls");
        ifstream read("practice2.txt");
        switch (select)
        {
        case 1:
            fastCash();                  
            break;
            case 2:
                withdraw();
                goto main_menu;
            break; 
            case 3:                              
                Balance_Inquiry();
                cout<<"You currently have "<<account_balance<<"rs in your account\n";
                cout<<"\nPress any key to continue";
                getch();    
                goto main_menu;
            break;
            case 4:                              
                system("cls");
                Mini_Statement_Title();
                mini_statement();
            break;
            case 5:          	
                login_change:
                system("cls");
                PinChange_Title();
                cout<<"Enter your current password: ";
                getline(read,acc_balance_1);
                getline(read,ID_1);
                getline(read,pass);
                getline(read,acc_balance_2);
                getline(read,ID_2);
                getline(read,pass_2);
                
                fflush(stdin);
                getline(std::cin,current_pass);
                if(current_pass==pass_1 || current_pass==pass_2)
                {
                    cout<<"Enter new password: ";
                    
                    if(ID.compare(ID_2)==0)
                    {
                        fflush(stdin);
                        getline(std::cin,new_pass_2);
                    }
                    else
                    {
                        fflush(stdin);
                        getline(std::cin,new_pass);
                    }
                    ofstream write("temp.txt");
                    ID_1="Taha123";
                    ID_2="Jethanand321";
                    write<<acc_balance_1<<"\n";
                    write<<ID_1;
                    if(ID.compare(ID_1)==0)
                    {
                        write<<"\n"<<new_pass<<"\n";
                        
                    }
                    else
                    {
                        write<<"\n"<<pass_1<<"\n";
                    
                    }
                    write<<acc_balance_2<<"\n";
                    write<<ID_2;
                    if(ID.compare(ID_2)==0)
                    {

                        write<<"\n"<<new_pass_2<<"\n";
                       
                    }
                    else
                    {
                        write<<"\n"<<pass_2<<"\n";
                 
                    }
                    write.close();
                    read.close();
                    remove("practice2.txt");
                    rename("temp.txt","practice2.txt");
                    goto login;
                }
                else
                {
                    cout<<"Incorrect pass";
                    getch();
                    goto login_change;
                }
                break;
            case 6:                            
                funds_transfer();
                goto main_menu;
                break;               
            case 7:                                 
                payment();
                break;
                case 8:
                goto login;
                break;
            default:
                cout<<"Incorrect input\n";
                cout<<"\nPress any key to continue";
                getch();
                break;      
    }
    goto main_menu;
    }
    else
    {
        cout<<"Incorrect Password";
        cout<<"\nPress any key to continue";
        getch();
        system("cls");
        goto login;
    }
}
void PinChange_Title()
{
    cout<<("============================================\n");
    cout<<("                PIN CHANGE          \n");
    cout<<("============================================\n\n");
}
void Funds_Transfer()
{
    cout<<("============================================\n");
    cout<<("           FUNDS TRANSSFER          \n");
    cout<<("============================================\n\n");
}
void Balance_Inquiry()
{
    cout<<("============================================\n");
    cout<<("             BALANCE INQUIRY          \n");
    cout<<("============================================\n\n");
}
void Withdraw_Title(){
{
    cout<<("============================================\n");
    cout<<("            CASH WITHDRAWAL          \n");
    cout<<("============================================\n\n");
}
}
void FastCash_Title()
{
    cout<<("============================================\n");
    cout<<("                FAST CASH          \n");
    cout<<("============================================\n\n");
}
void Payment_Title()
{
    cout<<("============================================\n");
    cout<<("                PAYMENT          \n");
    cout<<("============================================\n\n");
}
void Mini_Statement_Title()
{
    cout<<("============================================\n");
    cout<<("              MINI STATEMENT          \n");
    cout<<("============================================\n\n");
}
void login_page()
{
    cout<<("============================================\n");
    cout<<("              LOGIN PAGE          \n");
    cout<<("============================================\n\n");
}    
    
void Title()
{
    cout<<("============================================\n");
    cout<<("              WELCOME TO ATM !          \n");
    cout<<("============================================\n");
}       
void water()
{
    string address;
    int bill;
    system("cls");
    cout<<"\nEnter your house address: ";
    cin>>address;
    system("cls");
    getline(cin,address);
    cout<<"\nYour bill is 3000rs";
    cout<<"\nDo you want to pay the bill to Water-Board ?";
    cout<<"\n1. Yes \n2. No\n";
    cin>>bill;
    
    switch(bill)
    {
        case 1:
            system("cls");
            if(3000>account_balance)
            {
                cout<<"\nNot enough balance";
                cout<<"\nPress any key to continue";
                getch();
            }
            else
            {
            mini_water="\n==>3000rs were paid to Water-Board\n";
            account_balance=account_balance-3000;
            cout<<"You have successfully paid the bill to Water-Board !\n";
            cout<<"Press any key to continue";
            getch();
            }
        break;
        case 2:
            system("cls");
            cout<<"The bill was not paid!\n";
            cout<<"Press any key to continue";
            getch();
        break;
        default:
            system("cls");
            cout<<"Incorrect input\n";
            cout<<"\nPress any key to continue";
            getch();
            break;
    }
}
void gas(){
        string address;
    int bill;
    system("cls");
    cout<<"\nEnter your house address: ";
    cin>>address;
    getline(cin,address);
    system("cls");
    cout<<"\nYour bill is 5000rs";
    cout<<"\nDo you want to pay the bill to SUI-Gas ?";
    cout<<"\n1. Yes \n2. No\n";
    cin>>bill;
    switch(bill)
    {
        case 1:
            if(5000>account_balance)
            {
                cout<<"\nNot enough balance";
                cout<<"\nPress any key to continue";
                getch();
            }
            else
            {
            system("cls");
            mini_gas="\n==>5000rs were paid to Sui-Gas\n";
            account_balance=account_balance-5000;
            cout<<"You have successfully paid the bill to SUI-Gas !\n";
            cout<<"Press any key to continue";
            getch();
            }
        break;
        case 2:
            system("cls");
            cout<<"The bill was not paid!\n";
            cout<<"Press any key to continue";
            getch();
        break;
        default:
            system("cls");
            cout<<"Incorrect input\n";
            cout<<"\nPress any key to continue";
            getch();
            break;
    }
}
void electricity()
{
    string address;
    int bill;
    system("cls");
    cout<<"\nEnter your house address: ";
    cin>>address;
    getline(cin,address);
    cout<<"\nYour bill is 35500rs";
    cout<<"\nDo you want to pay the bill to K-electric ?";
    cout<<"\n1. Yes \n2. No\n";
    cin>>bill;
    
    switch(bill)
    {
        case 1:
            if(35500>account_balance)
            {
                cout<<"\nNot enough balance";
                cout<<"\nPress any key to continue";
                getch();
            }
            else
            {
            system("cls");
            mini_electric="\n==>35000rs were paid to K-Electric\n";
            account_balance=account_balance-35500;
            cout<<"You have successfully paid the bill to K-electric ";
            getch();
            }
        break;
        case 2:
            system("cls");
            cout<<"The bill was not paid!\n";
            cout<<"Press any key to continue";
            getch();
        break;
        default:
            system("cls");
            cout<<"Incorrect input\n";
            cout<<"\nPress any key to continue";
            getch();
            break;
    }
}
void school(){
    int school,STD_ID,school_fee;
        system("cls");
        Payment_Title();
        cout<<"\n1. City school\n";
        cout<<"2. Allied school\n";
        cout<<"3. Beacon house\n";
        cout<<"4. The smart school\n";
        cout<<"5. Back\n\n";
        cout<<"Select Your school:";
        cin>>school; 
        switch (school)
        {
            case 1:      
               system("cls");       
                Payment_Title();        
                cout<<"\nEnter your student ID: ";
                cin>>STD_ID;
                system("cls");

                cout<<"\nYour due fee is: 2500rs";
                cout<<"\nDo you want to pay the fee?";
                cout<<"\n1. Yes\n2. No\n";
                cin>>school_fee;
                switch (school_fee)
                {
                    case 1:           
                        system("cls");
                        Payment_Title();         
                        if(2500>account_balance)
                        {
                            cout<<"\nNot enough balance";
                            cout<<"\nPress any key to continue";
                            getch();
                        }
                        else
                        {
                        mini_city="\n==>3000rs were paid to City School\n";
                        account_balance=account_balance-2500;
                        cout<<"You have successfully paid the fees !";
                        cout<<"\nPress any key to continue";
                        getch();
                        }
                        break;
                    case 2:
                        system("cls");
                        Payment_Title();
                        cout<<"The fees was not paid!\n";
                        cout<<"Press any key to continue";
                        getch();
                        break;
                    default:
                        system("cls");
                        Payment_Title();
                        cout<<"Incorrect input\n";
                        cout<<"\nPress any key to continue";
                        getch();
                        break;
                }                
                break;             
                case 2:  
                system("cls");
                Payment_Title();
                cout<<"\nEnter your student ID: ";
                cin>>STD_ID;
                system("cls");
                cout<<"\nYour due fee is: 5000rs";
                cout<<"\nDo you want to pay the fee?";
                cout<<"\n1. Yes\n2. No\n";
                    cin>>school_fee;
                switch (school_fee)
                {
                    case 1:
                        system("cls");
                        Payment_Title();
                        if(5000>account_balance)
                        {
                            cout<<"\nNot enough balance";
                            cout<<"\nPress any key to continue";
                            getch();
                        }
                        else
                        {
                        mini_allied="\n==>5000rs were paid to Allied School\n";
                        account_balance=account_balance-5000;
                        cout<<"You have successfully paid the fees";
                        cout<<"\nPress any key to continue";
                        getch();
                        }
                        break;
                    case 2:
                        system("cls");
                        Payment_Title();
                        cout<<"The fees was not paid!\n";
                        cout<<"Press any key to continue";
                        getch();
                        break;
                    default:
                        system("cls");
                        Payment_Title();
                        cout<<"Incorrect input\n";
                        cout<<"\nPress any key to continue";
                        getch();
                        break;
                }                
                break;            
                case 3:        
                system("cls");  
                Payment_Title();
                cout<<"\nEnter your student ID: ";
                cin>>STD_ID;
                system("cls");
                cout<<"\nYour due fees is: 10000rs";
                cout<<"\nDo you want to pay the fees?";
                cout<<"\n1. Yes\n2. No\n";
                cin>>school_fee;
                switch (school_fee)
                {
                    case 1:
                        system("cls");
                        Payment_Title();
                        if(10000>account_balance)
                        {
                            cout<<"\nNot enough balance";
                            cout<<"\nPress any key to continue";
                            getch();
                        }
                        else
                        {
                            mini_beacon="\n==>10000rs were paid to Beacon house School\n";
                            account_balance=account_balance-10000;
                            cout<<"You have successfully paid the fees";
                            cout<<"\nPress any key to continue";
                            getch();
                        }
                        break;
                    case 2:
                        system("cls");
                        Payment_Title();
                        cout<<"The fees was not paid!\n";
                        cout<<"Press any key to continue";
                        getch();
                        break;
                    default:
                        system("cls");
                        Payment_Title();
                        cout<<"Incorrect input\n";
                        cout<<"\nPress any key to continue";
                        getch();
                       }
                        break;                           
                break;
                case 4:   
                system("cls");
                Payment_Title();       
                cout<<"\nEnter your student ID: ";
                cin>>STD_ID;
                system("cls");
                cout<<"\nYour due fees is: 3000rs";
                cout<<"\nDo you want to pay the fee?";
                cout<<"\n1. Yes\n2. No\n";
                cin>>school_fee;
                switch (school_fee)
                {
                    case 1:
                        system("cls");
                        Payment_Title();
                        if(3000>account_balance)
                        {
                            cout<<"\nNot enough balance";
                            cout<<"\nPress any key to continue";
                            getch();
                        }
                        else
                        {
                            mini_smart="\n==>5000rs were paid to The smart School\n";
                            account_balance=account_balance-3000;
                            cout<<"You have successfully paid the fees";
                            cout<<"\nPress any key to continue";
                            getch();
                        }
                        break;
                    case 2:
                        system("cls");
                        Payment_Title();
                        cout<<"The fees was not paid!\n";
                        cout<<"Press any key to continue";
                        getch();
                        break;
                    default:
                        system("cls");
                        Payment_Title();
                        cout<<"Incorrect input\n";
                        cout<<"\nPress any key to continue";
                        getch();
                        break;
                }                
                break;
                case 5:
                break;
            default:
                system("cls");
                Payment_Title();
                cout<<"Incorrect input\n";
                cout<<"\nPress any key to continue";
                getch();
                break;
        }                     
}
void payment(){
    Payment_Title();
    cout<<"1. School fees\n2. Electricity bill\n";
    cout<<"3. Gas bill\n4. Water bill\n";
    cout<<"5. back\n";
    cout<<"Enter the action you want to perform: ";
    int payment;
    cin>>payment;
    switch (payment)
    {
    case 1:
        school();
        break;
    case 2:
        electricity();
        break;
    case 3:
        gas();
        break;
    case 4:
        water();
        break;
    case 5:  
        break;
    default:
        system("cls");
        cout<<"Incorrect input\n";
        cout<<"\nPress any key to continue";
        getch();
        break;
    }    
}
void fastCash()
{
    int fast_cash;
    FastCash_Title();
    cout<<"1. 500rs      2.1000rs\n";
    cout<<"3. 3000rs     4.5000rs\n";
    cout<<"5. 7000rs     6.15000rs\n";
    cout<<"7. 25000rs    8.30000rs\n";
    cout<<"9. Back\n";
    cout<<"Select the action you want to perform: ";
    cin>>fast_cash;
    cout<<"\n";
    switch (fast_cash)
        {
        case 1:
        system("cls");
        FastCash_Title();                
        if(account_balance<0)
        {
            cout<<"Not enough balance\n";
            cout<<"Press any key to continue";
            getch();
        }
        else
        {
            account_balance=account_balance-500;
            mini_cash1="\n==>500Rs were withdrawn\n";
            cout<<"You have Successfully withdrawn 500rs\n\n";
            cout<<"Press any key to continue";
            getch();
        }
        break;
        case 2:
        system("cls");
        FastCash_Title();              
            if(account_balance<0)
            {
                cout<<"Not enough balance\n";
                cout<<"Press any key to continue";
                getch();
            }
            else
            {
                account_balance=account_balance-1000;
                mini_cash2="\n==>1000Rs were with withdrawn\n";
                cout<<"You have Successfully withdrawn 1000rs\n\n";
                cout<<"Press any key to continue";
                getch();
            }
        break;
        case 3:
        system("cls");
        FastCash_Title();
            if(account_balance<0)
            {
                cout<<"Not enough balance\n";
                cout<<"Press any key to continue";
                getch();
            }
        else
        {
            account_balance=account_balance-3000;
            mini_cash3="\n==>3000Rs were with withdrawn\n";
            cout<<"You have Successfully withdrawn 3000rs\n\n";
            cout<<"Press any key to continue";
            getch();
        }
        break;
        case 4:
            system("cls");
            FastCash_Title();
                if(account_balance<0)
                {
                    cout<<"Not enough balance\n";
                    cout<<"Press any key to continue";
                    getch();
                }
                else
                {
                    account_balance=account_balance-5000;
                    mini_cash4="\n==>5000Rs were with withdrawn\n";
                    cout<<"You have Successfully withdrawn 5000rs\n\n";
                    cout<<"Press any key to continue";
                    getch();
                }
            break;
            case 5:
                system("cls");
                FastCash_Title();
                    if(account_balance<0)
                    {
                        cout<<"Not enough balance\n";
                        cout<<"Press any key to continue";
                        getch();
                    }
                    else
                    {
                        account_balance=account_balance-7000;
                        mini_cash5="\n==>7000Rs were with withdrawn\n";
                        cout<<"You have Successfully withdrawn 7000rs\n\n";
                        cout<<"Press any key to continue";
                        getch();
                    }
                break;
                case 6:
                system("cls");
                FastCash_Title();
                    if(account_balance<0)
                    {
                        cout<<"Not enough balance\n";
                        cout<<"Press any key to continue";
                        getch();
                    }
                    else
                    {
                        account_balance=account_balance-15000;
                        mini_cash6="\n==>15000Rs were with withdrawn\n";
                        cout<<"You have Successfully withdrawn 15000rs\n\n";
                        cout<<"Press any key to continue";
                        getch();
                    }
                break;
    case 7:
    system("cls");
    FastCash_Title();
    if(account_balance<0)
    {
        cout<<"Not enough balance\n";
        cout<<"Press any key to continue";
        getch();
    }
    else
    {
        account_balance=account_balance-25000;
        mini_cash7="\n==>25000Rs were with withdrawn\n";
        cout<<"You have Successfully withdrawn 25000rs\n\n";
        cout<<"Press any key to continue";
        getch();
    }
    break;
    case 8:
        system("cls");
        FastCash_Title();
            if(account_balance<0)
            {
                cout<<"Not enough balance\n";
                cout<<"Press any key to continue";
                getch();
            }       
            else{
        account_balance=account_balance-30000;
        mini_cash8="\n==>30000Rs were with withdrawn\n";
        cout<<"You have Successfully withdrawn 30000rs\n\n";
        cout<<"Press any key to continue";
        getch();
            }
        break;
        case 9:
        break;
        default:                              
        system("cls");
        cout<<"Incorrect Input\n\n";
        cout<<"\nPress any key to continue";
        getch();
        break;
    }
}
void withdraw()
{
    Withdraw_Title();
    cout<<"Enter the amount of money you want to withdraw:";
    cin>>cash_withdraw;
    if(cash_withdraw>account_balance)
    {
        flag=1;
        cout<<"Not enough balance";
        cout<<"\nPress any key to continue";
        getch();
    }
    else
    {
        system("cls");
        Withdraw_Title();
        cout<<"\nYou have successfully withdrawn "<<cash_withdraw<<"rs\n";
        cout<<"\nPress any key to continue";
        account_balance=account_balance-cash_withdraw;
        getch();
    }
}
void funds_transfer()
{
    Funds_Transfer();
    cout<<"Enter the account No. you want to transfer funds to:";
    cin>>account_number;
    cout<<"Enter the amount of money you want to transfer: ";
    cin>>funds;
    if(funds>account_balance)
    {
        flag=1;
        system("cls");
        Funds_Transfer();
        cout<<"\nNot enough balance";
        cout<<"\nPress any key to continue";
        getch();
    }
    else
    {
    system("cls");
    Funds_Transfer();
    account_balance=account_balance-funds;
    cout<<"\nYou have successfully transfered "<<funds<<"rs to the account number "<<account_number<<"\n";
    cout<<"\nPress any key to continue";
    getch();
    }
}
void mini_statement()
{
    cout<<mini<<mini_cash1<<mini_cash2<<mini_cash3<<mini_cash4<<mini_cash5<<mini_cash6<<mini_cash7<<mini_cash8;
    if(flag==0){
    if(cash_withdraw>0)
    {
      cout<<"\n==>"<<cash_withdraw<<"Rs were with wihtdrawn\n";
    }
    }
    if(flag==0){
    if(funds>0)
    {
        cout<<"\n==>"<<funds<<"Rs were transfered to account No. "<<account_number<<"\n";
    }
    }
    cout<<mini_city<<mini_allied<<mini_beacon<<mini_smart<<mini_electric<<mini_gas<<mini_water;
    cout<<"\nPress any key to continue";
    getch();
}
