/**************************************************************************************************************************************************************
                                                                Title:OOPS Mini Project
                                                                Name:Nigel da Rosa Fernandes
                                                                Roll NO.:20CO32
                                                                Class:SE COMP                                27/12/21
 *************************************************************************************************************************************************************/
#include <iostream>
//#include <conio.h>
#include <curses.h>
#include <stdlib.h>

using namespace std;

int computer = 10, harddrives = 10, cpu = 10, ram = 5, keyboard = 10, mouse = 4, n = 90000, prof = 0;
int c = 60000, h = 5000, cp = 10000, ra = 16000, ke = 800, mo = 400;
int mc = 50000, mh = 4500, mcp = 8500, mra = 15000, mke = 650, mmo = 350;
class cash
{
public:
    int balance()
    {
        system("tput clear");
        // system("cls");
        cout << "YOUR BALANCE IS  " << n << endl
             << endl;
        return n;
    }
    int balanceupdate(int x)
    {
        int l = x;
        n -= l;
        return n;
        // return balance;
    }
    void depobalance(int bal)
    {
        n += bal;
    }
    int profitupdate(int o)
    {
        prof += o;
        return prof;
    }
    int profitdecrement(int pro)
    {
        prof -= pro;
        return prof;
    }
    // exception handling
    int balancechecker(int price)
    {
        int q = 0;
        try
        {
            if (price > n)
            {
                throw price;
            }
            else
            {
                balanceupdate(price);
                profitupdate(price);
                q = 0;
                cout << "ITEM PURCHASED OF AMOUNT " << price << "/-\n";
            }
        }
        catch (int q)
        {
            cout << "Insufficient balance (Exception Handling)\n";
        }
        return q;
    }
    // exception handeling for profit
    int profitchecker(int curprof, int qprice)
    {
        int q = 0;
        try
        {
            if (qprice > curprof)
                throw qprice;
            else
                q = 1;
        }

        catch (int qprice)
        {
            cout << "Amount exceeds the profit value (Exception handling)\n";
        }
        return q;
    }
};
class stock
{
public:
    int stockchecker(int z, int s)
    {
        if (z > s)
        {
            cout << "Quantity entered has exceeded the stock quantity\n";
            return 0;
            // exit(1);
        }
        else
            return 1;
    }

    void display()
    {
        cout << "================================================\n";
        cout << "Products \tStock available\t \tPrice\n";
        cout << "1 computers\t" << computer << "\t\t\t" << c << "/-"
             << "\n"
             << "2 harddrives\t" << harddrives << "\t\t\t" << h << "/-"
             << "\n3 CPU \t\t" << cpu << "\t\t\t" << cp << "/-"
             << "\n4 RAM(16gbs)\t" << ram << "\t\t\t" << ra << "/-"
             << "\n5 Keyboards\t" << keyboard << "\t\t\t" << ke << "/-"
             << "\n6 Mouse \t" << mouse << "\t\t\t" << mo << "/-" << endl
             << endl;

        cout << "================================================\n";
    }

    void MRPdisplay()
    {
        cout << "================================================\n";
        cout << "Products \tStock available\t \tMRP Price\n";
        cout << "1 computers\t" << computer << "\t\t\t" << mc << "/-"
             << "\n"
             << "2 harddrives\t" << harddrives << "\t\t\t" << mh << "/-"
             << "\n3 CPU \t\t" << cpu << "\t\t\t" << mcp << "/-"
             << "\n4 RAM(16gbs)\t" << ram << "\t\t\t" << mra << "/-"
             << "\n5 Keyboards\t" << keyboard << "\t\t\t" << mke << "/-"
             << "\n6 Mouse \t" << mouse << "\t\t\t" << mmo << "/-" << endl
             << endl;
        cout << "================================================\n";
    }
};

class dealer : public stock, public cash
{
public:
    int dd;

    int quantity;
    void add()
    {
        int pc;
        dd = prof;
        system("tput clear");
        // system("cls");
        int k = 0;
        MRPdisplay();
        cout << "\nselect item to add ";
        cin >> k;
        if (k == 1)
        {
            system("tput clear");
            // system("cls");
            cout << " enter quantity for computer ";
            cin >> quantity;
            pc = profitchecker(dd, quantity * mc);
            if (pc == 1)
            {
                computer += quantity;
                profitdecrement(quantity * mc);
            }
        }
        else if (k == 2)
        {
            system("tput clear");
            // system("cls");
            cout << "enter quantity for harddrives ";
            cin >> quantity;
            pc = profitchecker(dd, quantity * mh);
            if (pc == 1)
            {
                harddrives += quantity;
                profitdecrement(quantity * mh);
            }
        }
        else if (k == 3)
        {
            system("tput clear");
            // system("cls");
            cout << "Enter quantity for CPU ";
            cin >> quantity;
            pc = profitchecker(dd, quantity * mcp);
            if (pc == 1)
            {
                cpu += quantity;
                profitdecrement(quantity * mcp);
            }
        }
        else if (k == 4)
        {
            system("tput clear");
            // system("cls");
            cout << "Enter quantity for RAM ";
            cin >> quantity;
            pc = profitchecker(dd, quantity * mra);
            if (pc == 1)
            {
                ram += quantity;
                profitdecrement(quantity * mra);
            }
        }
        else if (k == 5)
        {
            system("tput clear");
            // system("cls");
            cout << "Enter quantity for Keyboard ";
            cin >> quantity;
            pc = profitchecker(dd, quantity * mke);
            if (pc == 1)
            {
                keyboard += quantity;
                profitdecrement(quantity * mke);
            }
        }
        else if (k == 6)
        {
            system("tput clear");
            // system("cls");
            cout << "Enter quantity for Mouse ";
            cin >> quantity;
            pc = profitchecker(dd, quantity * mmo);
            if (pc == 1)
            {
                mouse += quantity;
                profitdecrement(quantity * mmo);
            }
        }
    }
    void profit()
    {
        cout << "CURRENT PROFIT IS " << prof << "/-" << endl
             << endl;
    }
};

class customer : public stock, public cash
{
    int q;

public:
    int quantityc, quantityhd, quantitycpu, quantityram, quantitykeyboard, quantitymouse, v;
    void getdata()
    {
        int cprice, bb, bd;
        cout << "enter your choice ";
        cin >> v;
        if (v == 1)
        {
            system("tput clear");
            // system("cls");
            cout << "\t\t\t\t\t\t Balance " << n << endl;
            cout << "COMPUTERS\n";
            cout << "enter number of items to purchase ";
            cin >> quantityc;
            bd = stockchecker(quantityc, computer);
            if (bd == 1)
            {
                cprice = quantityc * c;
                bb = balancechecker(cprice);
                if (bb < 1)
                    computer -= quantityc;
            }
        }
        else if (v == 2)
        {
            int hddprice;
            system("tput clear");
            // system("cls");
            cout << "\t\t\t\t\t\t Balance " << n << endl;
            cout << "HARD DRIVES\n";
            cout << "enter number of items to purchase";
            cin >> quantityhd;
            bd = stockchecker(quantityhd, harddrives);
            if (bd == 1)
            {
                hddprice = quantityhd * h;
                bb = balancechecker(hddprice);
                if (bb < 1)
                    harddrives -= quantityhd;
            }
        }
        else if (v == 3)
        {
            int cpuprice;
            system("tput clear");
            // system("cls");
            cout << "\t\t\t\t\t\t Balance " << n << endl;
            cout << "CPU\n";
            cout << "enter number of items to purchase ";
            cin >> quantitycpu;
            bd = stockchecker(quantitycpu, cpu);
            if (bd == 1)
            {
                cpuprice = quantitycpu * cp;
                bb = balancechecker(cpuprice);
                if (bb < 1)
                    cpu -= quantitycpu;
            }
        }

        else if (v == 4)
        {
            int ramprice;
            system("tput clear");
            // system("cls");
            cout << "\t\t\t\t\t\t Balance " << n << endl;
            cout << "RAM\n";
            cout << "enter number of items to purchase";
            cin >> quantityram;
            bd = stockchecker(quantityram, ram);
            if (bd == 1)
            {
                ramprice = quantityram * ra;
                bb = balancechecker(ramprice);
                if (bb < 1)
                    ram -= quantityram;
            }
        }
        else if (v == 5)
        {
            int keyboardprice;
            system("tput clear");
            // system("cls");
            cout << "\t\t\t\t\t\t Balance " << n << endl;
            cout << "KEYBOARD\n";
            cout << "enter number of items to purchase";
            cin >> quantitykeyboard;
            bd = stockchecker(quantitykeyboard, keyboard);
            if (bd == 1)
            {
                keyboardprice = quantitykeyboard * ke;
                bb = balancechecker(keyboardprice);
                if (bb < 1)
                    keyboard -= quantitykeyboard;
            }
        }
        else if (v == 6)
        {
            int mouseprice;
            system("tput clear");
            // system("cls");
            cout << "\t\t\t\t\t\t Balance " << n << endl;
            cout << "MOUSE\n";
            cout << "enter number of items to purchase";
            cin >> quantitymouse;
            bd = stockchecker(quantitymouse, mouse);
            if (bd == 1)
            {
                mouseprice = quantitymouse * mo;
                bb = balancechecker(mouseprice);
                if (bb < 1)
                    mouse -= quantitymouse;
            }
        }
    }
    void buy()
    {
        system("tput clear");
        // system("cls");
        cout << "\t\t\t\t\t\t Balance " << n << endl;
        display();
        getdata();
    }

    void deposit()
    {
        system("tput clear");
        // system("cls");
        cout << "\t\t\t\t\t\t Balance " << n << endl;
        int depo;
        cout << "Enter an amount to deposit- ";
        cout << "\n\n";
        cin >> depo;
        system("tput clear");
        depobalance(depo);
    }
};

int main()
{
    dealer a;
    customer b;
    int j, c;
mainmenu:
    system("tput clear");
    // system("cls");
    cout << "\n\t\t   STORE MANAGEMENT SYSTEM\n";
    cout << "=============================================================";
    cout << "\n\n\t\t   1. Dealer Menu\n\n\t\t   2. Customer Menu\n\n\t\t ";
    cout << "\n\n=============================================================\n";
    cout << "enter your choice ";
    cin >> c;
    system("tput clear");
    // system("cls");
    if (c == 1)
    {
    dealermenu:
        cout << "========================== \n 1 add item\n 2 display stock\n 3 to display profit \n 0 exit to main menu \n========================== ";
        cin >> j;
        if (j == 1)
        {
            a.add();
            goto dealermenu;
        }
        else if (j == 2)
        {
            system("tput clear");
            // system("cls");
            a.display();
            // getch();
            goto dealermenu;
        }
        else if (j == 3)
        {
            system("tput clear");
            // system("cls");
            a.profit();
            goto dealermenu;
        }
        else
            goto mainmenu;
    }
    else if (c == 2)
    {
        int e;
    customermenu:
        cout << "\t\t\t\t\t\t Balance " << n << endl;
        cout << "==========================\n1 purchase item"
             << "\n2 To deposit balance\n0 to back \n========================== ";
        cin >> e;
        if (e == 1)
        {
            // cout<<"\t\t\t Balance "<<n<<endl;
            b.buy();
            // system("tput clear");
            goto customermenu;
        }
        else if (e == 2)
        {

            b.deposit();
            goto customermenu;
        }
        else if (e == 0)
            goto mainmenu;
    }
    /*dealer:
    system("cls");


    cout<<"go to\n\n";
    b.buy();
    a.display();
    cout<<" add item\n ";
    a.add();
    a.display();
    goto dealer;*/
    return 0;
}
