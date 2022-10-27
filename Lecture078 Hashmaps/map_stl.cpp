#include <bits/stdc++.h>
using namespace std;
int main()
{
    unordered_map<string, int> m;
    m["mango"] = 100;
    m["apple"] = 120;
    m["banana"] = 20;
    // and using pair class
    pair<string, int> p = make_pair("guava", 60);
    m.insert(p);
    // iterate over all the key value pairs
    for (auto p : m)
    {
        cout << p.first << " and " << p.second << endl;
    }
    // for finding a particular fruit
    // if it is not present then it will return 0
    cout << m["mango"] << endl;
    // another way to find a particular fruit
    // if it is not present then it will return m.end()
    if (m.count("mango"))
    {
        cout << "price of mango is " << m["mango"] << endl;
    }
    else
    {
        cout << "mango is not present" << endl;
    }
    // erase a particular fruit
    m.erase("mango");
    // another way to find a particular fruit
    // if it is not present then it will return m.end()
    // m.count("mango") is 0 if mango is not present and 1 if mango is present
    if (m.count("mango"))
    {
        cout << "price of mango is " << m["mango"] << endl;
    }
    else
    {
        cout << "mango is not present" << endl;
    }

    //***************//
    // search in a map
    //***************//
    cout << "***************" << endl;
    // if the key is not present then it will throw an error
    cout << m.at("mangoes") << endl;
    // if the key is not present then it will not throw an error and it will insert the key with value 0
    cout << m["mangoes"] << endl;

    //*********************************************************************************//
    // iterator is a pointer which points to a particular key value pair in the map
    // begin() returns the iterator which points to the first key value pair
    // end() returns the iterator which points to the position after the last key value pair
    for (auto it = m.begin(); it != m.end(); it++)
    {
        cout << it->first << " and " << it->second << endl;
    }
    // find function
    // if the key is not present then it will return m.end()
    auto it = m.find("mango");
    if (it != m.end())
    {
        cout << "price of mango is " << m["mango"] << endl;
    }
    else
    {
        cout << "mango is not present" << endl;
    }
    return 0;
}