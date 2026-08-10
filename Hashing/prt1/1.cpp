#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// Implementing HashTable
class Node
{
public:
    std::string key;
    int val;
    Node *next;
    Node(std::string key, int val)
    {
        this->key = key;
        this->val = val;
    }

    ~Node()
    {
        next = nullptr;
    }
};

class HashTable
{

    int totsize;
    int cursize;
    Node **table;

    int HashFunction(std::string key, int size)
    {
        int idx = 0;

        for (int i = 0; i < key.size(); i++)
        {
            idx = (idx + (key[i] * key[i])) % size;
        }
        return idx;
    }

    void insertNode(std::string key, int val, Node **targetTable, int size)
    {
        int idx = HashFunction(key, size);
        Node *newNode = new Node(key, val);
        newNode->next = targetTable[idx];
        targetTable[idx] = newNode;
    }

    void Rehash()
    {
        int oldsize = totsize;
        Node **oldtable = table;

        Node **newtable = new Node *[2 * oldsize];
        for (int i = 0; i < 2 * oldsize; i++)
        {
            newtable[i] = nullptr;
        }

        for (int i = 0; i < oldsize; i++)
        {
            Node *tmp = oldtable[i];
            while (tmp != nullptr)
            {
                Node *nextNode = tmp->next;
                insertNode(tmp->key, tmp->val, newtable, 2 * oldsize);
                tmp = nextNode;
            }
        }

        table = newtable;
        totsize = 2 * oldsize;
        delete[] oldtable;
    }

public:
    HashTable(int size = 5)
    {
        totsize = size;
        cursize = 0;

        table = new Node *[size];

        for (int i = 0; i < totsize; i++)
        {
            table[i] = NULL;
        }
    }
    void insert(std::string key, int val)
    {
        int idx = HashFunction(key, totsize);
        Node *newNode = new Node(key, val);

        newNode->next = table[idx];
        table[idx] = newNode;
        cursize++;

        double lambda = static_cast<double>(cursize) / totsize;
        if (lambda > 1)
        {
            Rehash();
        }
    }
    bool exist(std::string key)
    {
        int idx = HashFunction(key, totsize);

        if (table[idx] != nullptr)
        {
            Node *tmp = table[idx];
            while (tmp != nullptr)
            {
                if (tmp->key == key)
                {
                    return true;
                }
                tmp = tmp->next;
            }
        }
        return false;
    }

    int search(std::string key)
    {
        int idx = HashFunction(key, totsize);

        if (table[idx] != nullptr)
        {
            Node *tmp = table[idx];
            while (tmp != nullptr)
            {
                if (tmp->key == key)
                {
                    return tmp->val;
                }
                tmp = tmp->next;
            }
        }
        return -1;
    }

    void remove(std::string key)
    {
        int idx = HashFunction(key, totsize);

        Node *tmp = table[idx];
        Node *prev = tmp;

        while (tmp != NULL)
        {
            if (tmp->key == key)
            {
                if (tmp == prev)
                {
                    table[idx] = tmp->next;
                }
                else
                {
                    prev->next = tmp->next;
                }
                break;
            }
            prev = tmp;
            tmp = tmp->next;
        }
    }

    void print()
    {
        for (int i = 0; i < totsize; i++)
        {
            Node *tmp = table[i];
            while (tmp != NULL)
            {
                cout << "indexes " << i << "keys " << tmp->key << " value  " << tmp->val << endl;
                tmp = tmp->next;
            }
        }
    }
};

int main()
{
    HashTable h1;

    h1.insert("India", 20);
    h1.insert("Canada", 120);
    h1.insert("China", 250);
    h1.insert("US", 280);
    h1.insert("Pakistan", 200);

    if (h1.exist("India"))
    {
        int val = h1.search("India");
        std::cout << "Val for India is " << val << std::endl;
    }
    h1.print();
    h1.remove("India");
    cout << endl;
    h1.print();

    return 0;
}