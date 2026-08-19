#include <iostream>
#include <string>
#include <list>

#include <algorithm>
using namespace std;

// Linked list implementation

// so here Node class represents the the entire node which contains the data and the pointer pointting to the next elements
// and the other class List represents the linked list itself which contains the info of head and tail

//  and now we are going to implement methods and functions of linked list
// push_fornt
// push_back
// pop front
// push back

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        next = nullptr;
    }
    // ~Node()
    // {
    //     if (next != NULL)
    //     {
    //         cout << "Destructuor of Node" << data << endl;
    //         delete next;
    //         next = NULL;
    //     }
    // }
};

class List
{
public:
    Node *Head;
    Node *Tail;

    List()
    {
        Head = NULL;
        Tail = NULL;
    }
    // ~List()
    // {
    //     if (Head != NULL)
    //     {
    //         cout << "List" << endl;
    //         delete Head;
    //         Head = NULL;
    //     }
    // }
    void push_front(int val)
    {
        Node *newNode = new Node(val);

        if (Head == NULL)
        {
            Head = Tail = newNode;
        }
        else
        {
            newNode->next = Head;
            Head = newNode;
        }
    }
    void push_back(int val)
    {
        Node *newNode = new Node(val);
        if (Head == NULL)
        {
            Head = Tail = newNode;
        }
        else
        {
            Tail->next = newNode;
            Tail = newNode;
        }
    }

    void Print_LL()
    {
        if (Head == NULL)
        {
            cout << "List is empty" << endl;
            return;
        }
        Node *tmp = Head;
        while (tmp->next != NULL)
        {
            cout << tmp->data << " -> ";
            tmp = tmp->next;
        }
        cout << tmp->data << endl;
    }
    void Insert(int pos, int val)
    {
        if (pos == 1)
        {
            push_front(val);
            return;
        }
        Node *newNode = new Node(val);
        Node *tmp = Head;
        for (int i = 0; i < pos - 1; i++)
        {
            if (tmp == NULL)
            {
                cout << "Position invalid " << endl;
                return;
            }
            tmp = tmp->next;
        }
        if (tmp == NULL)
        {
            cout << "Position invalid" << endl;
            return;
        }
        // building the connection
        newNode->next = tmp->next;
        tmp->next = newNode;
        if (newNode->next == NULL)
        {
            Tail = newNode;
        }
    }
    void DeleteEntireList()
    {
        Node *tmp = Head;
        while (tmp->next != NULL)
        {
            Node *current = tmp;
            tmp = tmp->next;
            cout << "deletd node" << current->data << endl;
            delete current;
        }
        Head = nullptr;
    }

    void pop_front()
    {
        Node *tmp = Head;
        Head = Head->next;

        delete tmp;
    }

    void pop_back()
    {
        Node *tmp = Head;
        while (tmp->next->next != NULL)
        {
            tmp = tmp->next;
        }

        Node *delete_node = Tail;
        tmp->next = NULL;
        Tail = tmp;
        delete delete_node;
    }

    int Search_Iteratively(int Key)
    {
        Node *tmp = Head;
        int idx = 0;

        while (tmp->next != NULL)
        {
            if (tmp->data == Key)
            {

                return idx;
            }
            idx++;
            tmp = tmp->next;
        }
        return -1;
    }

    int Helper(Node *Head, int key)
    {
        if (Head == NULL)
        {
            return -1;
        }
        if (Head->data == key)
        {
            return 0;
        }
        int idx = Helper(Head->next, key);
        if (idx == -1)
        {
            return -1;
        }
        return idx + 1;
    }

    int Search_Reacursively(int key)
    {
        return Helper(Head, key);
    }

    // Lets reverse a linked list

    Node *Reverse_ll()
    {
        if (Head == NULL)
        {
            return NULL;
        }

        Node *curr = Head;
        Node *prev = NULL;

        while (curr != NULL)
        {
            Node *next = curr->next;
            curr->next = prev;

            // update in variables
            prev = curr;
            curr = next;
        }

        Tail = Head;
        Head = prev;
        return Head;
    }
    void DeleteNthNodeFromEnd(int n)
    {
        if (Head == NULL)
            return;

        // Step 1: Find size
        int size = 0;
        Node *curr = Head;
        while (curr != NULL)
        {
            size++;
            curr = curr->next;
        }

        if (n > size || n <= 0)
            return;

        if (n == size)
        {
            Node *temp = Head;
            Head = Head->next;
            delete temp;
            return;
        }

        Node *prev = Head;
        for (int i = 1; i < size - n; i++)
        {
            prev = prev->next;
        }

        Node *target = prev->next;
        prev->next = target->next;
        delete target;
    }
    // writting a function that could tell whether a linked list is a palindrome or not
    // Not very optimal but kind of basic thoughts
    bool is_Palindrome()
    {
        if (Head == NULL)
        {
            return false;
        }
        Node *tmp = Head;
        std::string str = "";

        while (tmp != NULL)
        {
            str += to_string(tmp->data);
            tmp = tmp->next;
        }

        for (int i = 0; i < str.size() / 2; i++)
        {
            if (str[i] != str[str.size() - i - 1])
            {
                return false;
            }
        }
        return true;
    }

    // Detecting a cycle in a linked list using floyd cycle detecting algorithm
    // optimal approach while the naive approach is simply travrese the list and move by putting down each and every
    // node in an hashset once if a node al;ready exist it simply means that list contain cycle

    bool detect_cycle()
    {
        Node *slow = Head;
        Node *fast = Head;

        while (slow && fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
            {
                return true;
            }
        }
        return false;
    }

    // writting the code for the removal of the cycle in an linked list

    void removal_of_cycle()
    {
        Node *slow = Head;
        Node *fast = Head;

        slow = slow->next;
        fast = fast->next->next;

        // lets first detect the cycle in an linked list before we remove
        while (slow && fast)
        {
            if (slow == fast)
            {
                break;
            }
            slow = slow->next;
            fast = fast->next->next;
        }

        if (slow == fast)
        {
            slow = Head; // this check is necessary as per the algom

            if (slow == fast) // if it builds the complete cycle then do this
            {
                while (fast->next != slow)
                {
                    fast = fast->next;
                }
            }
            else // else do this
            {
                while (slow->next != fast->next)
                {
                    slow = slow->next;
                    fast = fast->next;
                }
            }

            fast->next = nullptr;
        }
    }
};
Node *split_List(Node *Head)
{
    Node *slow = Head;
    Node *fast = Head;
    Node *prev = NULL;

    while (fast != NULL && fast->next != NULL)
    {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    if (prev != NULL)
    {
        prev->next = NULL; // cut the list
    }
    return slow; // start of right half
}

Node *merge(Node *left, Node *right)
{
    List ans; // your class List with push_back and Head

    while (left != NULL && right != NULL) // FIXED condition
    {
        if (left->data <= right->data)
        {
            ans.push_back(left->data);
            left = left->next;
        }
        else
        {
            ans.push_back(right->data);
            right = right->next;
        }
    }

    while (left != NULL) // FIXED condition
    {
        ans.push_back(left->data);
        left = left->next;
    }
    while (right != NULL) // FIXED condition
    {
        ans.push_back(right->data);
        right = right->next;
    }

    return ans.Head; // return head of merged list
}

Node *merge_sort(Node *Head)
{
    if (Head == NULL || Head->next == NULL)
    {
        return Head; // base case
    }

    Node *rightHead = split_List(Head);
    Node *left = merge_sort(Head);
    Node *right = merge_sort(rightHead);

    return merge(left, right);
}

int main()
{
    List ll;
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);

    ll.push_back(4);
    ll.push_back(1);

    // Now lets build a function to print our linked list
    ll.Print_LL();
    // ll.Insert(2, 40);
    // cout << "Before Reversing" << endl;
    // ll.DeleteNthNodeFromEnd(5);
    // cout << "After Deleting last 5th node" << endl;
    // ll.Print_LL();
    // ll.DeleteEntireList();

    // ll.pop_front();
    // cout << "after deleting first element" << endl;
    // ll.Print_LL();
    // ll.pop_back();
    // cout << "after deleting last element" << endl;
    // ll.Print_LL();
    // int val = ll.Search_Iteratively(40);
    // if (val)
    // {
    //     cout << val << endl;
    // }
    // else
    // {
    //     cout << "Not found" << endl;
    // }
    // return 0;

    // int val2 = ll.Search_Reacursively(40);
    // if (val)
    // {
    //     cout << val << endl;
    // }
    // else
    // {
    //     cout << "Not found" << endl;
    // }
    // ll.Reverse_ll();
    // cout << "After Reversing" << endl;
    // ll.Print_LL();
    ll.Head = merge_sort(ll.Head);
    cout << "After sorting the linked list " << endl;
    ll.Print_LL();
}
