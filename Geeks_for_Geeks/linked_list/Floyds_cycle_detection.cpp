#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};

void insertNode(node *n, node **head)
{

    if (*head == NULL)
        (*head) = n;
    else
    {
        node *temp = (*head);
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = n;
    }
}

void traverseList(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "\n";
}

void deleteNode(int data, node **head)
{
    node *temp = *head;
    if (temp == NULL)
        return;
    else
    {
        node *temp2 = *head;
        if ((*head)->data == data)
        {
            *head = (*head)->next;
            delete temp;
            return;
        }

        temp = temp->next;
        while (temp != NULL && temp->data != data)
        {
            temp2 = temp;
            temp = temp->next;
        }
        if (temp == NULL)
            return;

        if (temp->data == data)
        {
            node *todelete = temp;
            temp2->next = temp->next;
            temp->next = NULL;
            delete todelete;
        }
    }
}

bool containCycle(node *head)
{
    node *slow = head;
    node *fast = head;

    while (slow != NULL && fast != NULL)
    {
        slow = slow->next;
        if (fast->next != NULL)
            fast = fast->next->next;
        else
            return 0;

        if (slow == fast)
            return 1;
    }
    return 0;
}

int main(int argc, char **argv)
{
    int n, data;
    node *head = NULL;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        node *a = new node;
        cin >> a->data;
        a->next = NULL;
        insertNode(a, &head);
    }

    // traverseList(head);

    // cout << "data to delete: ";
    // cin >> data;
    // cout << "\n";

    // deleteNode(data, &head);
    // traverseList(head);
    return 0;
}