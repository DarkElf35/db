#include <iostream>
#include <vector>
#include <initializer_list>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

class Table
{
private:
    int j = 1;
public:

    vector<vector<string>> t;
    multimap<string, int>hesh;
    string tname;

    Table(string name)
    {
        tname = name;
    }

    void add(string i, string s1, string s2)
    {
        t.push_back(vector<string>(1));
        t[j - 1].push_back(i);
        t[j - 1].push_back(s1);
        t[j - 1].push_back(s2);
        j++;
    }

    void print()
    {
        for (int k = 0; k < j - 1; k++)
        {
            for (int i = 1; i <= 3; i++)
            {
                cout << ' ' << t[k][i];
            }
            cout << endl;
        }
        cout << endl;
    }

    void select(string s, int x)
    {
        for (int k = 0; k < j - 1; k++)
        {
            if (t[k][x] == s)
            {
                cout << t[k][1] << ' ' << t[k][2] << ' ' << t[k][3] << endl << endl;
            }
        }
    }

};

class DB
{
private:

public:
    vector<Table*> allTables;

    void create(string name)
    {
        Table* tab = new Table(name);
        allTables.push_back(tab);
    }


    void addInTab(string name, string i, string s1, string s2)
    {
        

        for (int j = 0; j < allTables.size(); j++)
        {
            if (name == allTables[j]->tname)
            {
                Table* tab = allTables[j];
                tab->add(i, s1, s2);
            }
        }
    }

    void selectInTab(string name, string s, int x)
    {
        

        for (int i = 0; i < allTables.size(); i++)
        {
            if (name == allTables[i]->tname)
            {
                Table* tab = allTables[i];
                tab->select(s, x);
            }
        }
    }


    void printTab(string name)
    {
        for (int i = 0; i < allTables.size(); i++)
        {
            if (name == allTables[i]->tname)
            {
                Table* tab = allTables[i];
                tab->print();
            }
        }
    }

};

int main()
{
    
    DB datab;
    datab.create("Sotrydniki");
    datab.addInTab("Sotrydniki", "1", "Kiselev Dimitri", "28.10.2000");
    datab.addInTab("Sotrydniki", "2", "Maksim Kyznetcov", "25.08.2001");
    datab.addInTab("Sotrydniki", "3", "Vladislav Bakulev", "05.03.2002");
    datab.printTab("Sotrydniki");
    datab.selectInTab("Sotrydniki", "Maksim Kyznetcov", 2);

    datab.create("Klients");
    datab.addInTab("Klients", "1", "Sidorov Ivan", "10.03.2001");
    datab.addInTab("Klients", "2", "Osokin Artyr", "23.09.1998");
    datab.printTab("Klients");

    return 0;
}




