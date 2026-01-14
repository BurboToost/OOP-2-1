#include <bits/stdc++.h>
using namespace std;

struct Package
{
    string type;
    int amount;
    int validity;
};

class Sim
{
public:
    virtual void showInfo() = 0;
};

class Robi : public Sim
{
private:
    double balance;
    int minutes, sms;
    int data;
    vector<Package> activePackages;

public:
    Robi()
    {
        ifstream in("robi_db.txt");
        if (in.is_open())
        {
            int pkgCount;
            in >> balance >> minutes >> sms >> data >> pkgCount;
            for (int i = 0; i < pkgCount; i++)
            {
                Package p;
                in >> p.type >> p.amount >> p.validity;
                activePackages.push_back(p);
            }
            in.close();
        }
        else
        {
            balance = 100;
            minutes = 50;
            sms = 100;
            data = 500;
        }
    }

    void saveToFile()
    {
        ofstream out("robi_db.txt");
        out << balance << " " << minutes << " " << sms << " " << data << " ";
        out << activePackages.size() << endl;
        for (auto &p : activePackages)
        {
            out << p.type << " " << p.amount << " " << p.validity << endl;
        }
        out.close();
    }

    double getBalance() { return balance; }

    void showInfo()
    {
        cout << endl
             << "--- ROBI SIM INFO ---" << endl;
        cout << "Balance: " << balance << " Tk" << endl;
        cout << "Minutes: " << minutes << endl;
        cout << "SMS: " << sms << endl;
        cout << "Data: " << data << " MB" << endl;
    }

    bool deduct(double cost)
    {
        if (balance >= cost)
        {
            balance -= cost;
            return true;
        }
        cout << "Insufficient balance!" << endl;
        return false;
    }

    void activatePackage(const string &type, int amount, double cost, int days)
    {
        if (!deduct(cost))
            return;

        Package p{type, amount, days};
        activePackages.push_back(p);

        if (type == "DATA")
            data += amount;
        else if (type == "MIN")
            minutes += amount;
        else if (type == "SMS")
            sms += amount;

        cout << "Package activated (" << days << " days)" << endl;
    }

    void showActivePackages()
    {
        cout << endl
             << "--- ACTIVE PACKAGES ---" << endl;
        if (activePackages.empty())
        {
            cout << "No active packages." << endl;
            return;
        }

        for (auto &p : activePackages)
        {
            cout << p.type << " | Amount: " << p.amount
                 << " | Validity: " << p.validity << " days" << endl;
        }
    }

    friend void recharge(Robi &r, double amount);
};

void recharge(Robi &r, double amount)
{
    r.balance += amount;
    cout << "Recharge successful!" << endl;
}

void buyDataMenu(Robi &r)
{
    int ch;
    while (true)
    {
        cout << endl
             << "--- BUY DATA PACKAGES ---" << endl;
        cout << "1. 1GB for 50 Tk (30 days)" << endl;
        cout << "2. 3GB for 120 Tk (30 days)" << endl;
        cout << "3. 5GB for 200 Tk (30 days)" << endl;
        cout << "9. Back" << endl
             << "0. Exit" << endl;
        cin >> ch;

        if (ch == 1)
            r.activatePackage("DATA", 1024, 50, 30);
        else if (ch == 2)
            r.activatePackage("DATA", 3 * 1024, 120, 30);
        else if (ch == 3)
            r.activatePackage("DATA", 5 * 1024, 200, 30);
        else if (ch == 9)
            return;
        else if (ch == 0)
            exit(0);
    }
}

void buyMinutesMenu(Robi &r)
{
    int ch;
    while (true)
    {
        cout << endl
             << "--- BUY MINUTES ---" << endl;
        cout << "1. 50  | 3d  | 5 Tk" << endl;
        cout << "2. 100 | 3d  | 9 Tk" << endl;
        cout << "3. 200 | 7d  | 18 Tk" << endl;
        cout << "4. 300 | 7d  | 25 Tk" << endl;
        cout << "5. 500 | 15d | 40 Tk" << endl;
        cout << "6. 1000| 15d | 70 Tk" << endl;
        cout << "7. 2000| 30d | 130 Tk" << endl;
        cout << "8. 5000| 30d | 300 Tk" << endl;
        cout << "9. Back" << endl
             << "0. Exit" << endl;
        cin >> ch;

        if (ch == 1)
            r.activatePackage("MIN", 50, 5, 3);
        else if (ch == 2)
            r.activatePackage("MIN", 100, 9, 3);
        else if (ch == 3)
            r.activatePackage("MIN", 200, 18, 7);
        else if (ch == 4)
            r.activatePackage("MIN", 300, 25, 7);
        else if (ch == 5)
            r.activatePackage("MIN", 500, 40, 15);
        else if (ch == 6)
            r.activatePackage("MIN", 1000, 70, 15);
        else if (ch == 7)
            r.activatePackage("MIN", 2000, 130, 30);
        else if (ch == 8)
            r.activatePackage("MIN", 5000, 300, 30);
        else if (ch == 9)
            return;
        else if (ch == 0)
            exit(0);
    }
}

void buySMSMenu(Robi &r)
{
    int ch;
    while (true)
    {
        cout << endl
             << "--- BUY SMS ---" << endl;
        cout << "1. 50  | 3d  | 5 Tk" << endl;
        cout << "2. 100 | 3d  | 8 Tk" << endl;
        cout << "3. 200 | 7d  | 15 Tk" << endl;
        cout << "4. 300 | 7d  | 20 Tk" << endl;
        cout << "5. 500 | 15d | 30 Tk" << endl;
        cout << "6. 1000| 15d | 50 Tk" << endl;
        cout << "7. 2000| 30d | 80 Tk" << endl;
        cout << "8. 5000| 30d | 150 Tk" << endl;
        cout << "9. Back" << endl
             << "0. Exit" << endl;
        cin >> ch;

        if (ch == 1)
            r.activatePackage("SMS", 50, 5, 3);
        else if (ch == 2)
            r.activatePackage("SMS", 100, 8, 3);
        else if (ch == 3)
            r.activatePackage("SMS", 200, 15, 7);
        else if (ch == 4)
            r.activatePackage("SMS", 300, 20, 7);
        else if (ch == 5)
            r.activatePackage("SMS", 500, 30, 15);
        else if (ch == 6)
            r.activatePackage("SMS", 1000, 50, 15);
        else if (ch == 7)
            r.activatePackage("SMS", 2000, 80, 30);
        else if (ch == 8)
            r.activatePackage("SMS", 5000, 150, 30);
        else if (ch == 9)
            return;
        else if (ch == 0)
            exit(0);
    }
}

void buyMainMenu(Robi &r)
{
    int ch;
    while (true)
    {
        cout << endl
             << "--- BUY MENU ---" << endl;
        cout << "1. Data" << endl
             << "2. Minutes" << endl
             << "3. SMS" << endl
             << "4. Active Packages" << endl;
        cout << "9. Back" << endl
             << "0. Exit" << endl;
        cin >> ch;

        if (ch == 1)
            buyDataMenu(r);
        else if (ch == 2)
            buyMinutesMenu(r);
        else if (ch == 3)
            buySMSMenu(r);
        else if (ch == 4)
            r.showActivePackages();
        else if (ch == 9)
            return;
        else if (ch == 0)
            exit(0);
    }
}

int main()
{
    Robi r;

    string dial;
    cout << "Dial USSD Code: ";
    cin >> dial;

    if (dial != "*1#")
    {
        cout << "Invalid USSD\n";
        return 0;
    }

    int ch;
    while (true)
    {
        cout << endl
             << "--- ROBI SIM MENU ---" << endl;
        cout << "1. Show Info" << endl
             << "2. Recharge" << endl
             << "3. Buy Packages" << endl
             << "0. Exit" << endl;
        cout << endl
             << "Enter your choice: ";
        cin >> ch;

        if (ch == 1)
            r.showInfo();
        else if (ch == 2)
        {
            double amount;
            cout << "Enter recharge amount: ";
            cin >> amount;
            recharge(r, amount);
        }
        else if (ch == 3)
            buyMainMenu(r);
        else if (ch == 0)
        {
            r.saveToFile();
            exit(0);
        }
    }
    return 0;
}
