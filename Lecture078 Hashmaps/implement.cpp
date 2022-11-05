#include<bits/stdc++.h>
using namespace std;


// MapNode class
template <typename V>
class MapNode
{
public:
    MapNode *next;
    V value;
   string key ;
    MapNode(string key, V value)
    {
        this->next = NULL;
        this->value = value;
        this->key = key;
    }
    ~MapNode()
    {
        delete next;
    }
};

// Map class
template <typename V>
class StringMap
{
public:
    MapNode<V> **bucketArr;
    int bucketSize;
    int count;

    StringMap(int size)
    {
        this->bucketSize = size;
        this->count = 0;
        this->bucketArr = new MapNode<V> *[size];
        for (int i = 0; i < size; i++)
        {
            this->bucketArr[i] = NULL;
        }
    }
    int reHashing
    int getHashCode(string s){
        // Arshad = .... h*p2 + a*p1 + d*p0
        int currentFactor =1;
        int hashValue = 0;
        for (int i = s.size()-1; i>=0;i--)
        {
            hashValue += s[i] * currentFactor;
            currentFactor *= 37;
            // here we compress the values because we have limited space in the array so we compress the values to fit in the array space.()
            hashValue %= bucketSize;
            currentFactor %= bucketSize;
        }
        hashValue %= bucketSize;
        return hashValue;
    }
    void insert(string key, V value)
    {
        int bucketIndex = getHashCode(key);
        MapNode<V> *head = bucketArr[bucketIndex];
        while (head != NULL)
        {
            if (head->key == key)
            {
                head->value = value;
                return;
            }
            head = head->next;
        }
        head = bucketArr[bucketIndex];
        MapNode<V> *node = new MapNode<V>(key, value);
        node->next = head;
        bucketArr[bucketIndex] = node;
        count++;
    }
    int size()
    {
        return count;
    }
    V deleteKey (string key)
    {
        int bucketIndex = getHashCode(key);
        MapNode<V> *head = bucketArr[bucketIndex];
        MapNode<V> *prev = NULL;
        while (head != NULL)
        {
            if (head->key == key)
            {
                if (prev == NULL)
                {
                    bucketArr[bucketIndex] = head->next;
                }
                else
                {
                    prev->next = head->next;
                }
                V value = head->value;
                head->next = NULL;
                delete head;
                count--;
                return value;
            }
            prev = head;
            head = head->next;
        }
        return 0;
    }

    V getValue(string key)
    {
        int bucketIndex = getHashCode(key);
        MapNode<V> *head = bucketArr[bucketIndex];
        while (head != NULL)
        {
            if (head->key == key)
            {
                return head->value;
            }
            head = head->next;
        }
        return 0;
    }

    ~StringMap()
    {
        for (int i = 0; i < bucketSize; i++)
        {
            delete bucketArr[i];
        }
        delete[] bucketArr;
    }
};



int main()
{
    StringMap<int> map(5);
    map.insert("Arshad", 10);
    map.insert("space", 20);
    map.insert("time", 30);


    cout << map.getValue("Arshad") << endl;
    cout << map.getValue("space") << endl;


    cout << map.size() << endl;
    cout << map.deleteKey("Arshad") << endl;
    cout << map.size() << endl;
    cout << map.getValue("Arshad") << endl;


    return 0;
}