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

void reverseList(node **head)
{
    node *temp = *head;
    if (temp == NULL)
        return;
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        node *newhead = temp;
        node *temp2 = *head;
        if (temp != temp2)
        {
            while (temp2->next != temp)
            {

                while (temp2->next != temp)
                {
                    temp2 = temp2->next;
                }
                temp->next = temp2;
                temp = temp2;
                temp2 = *head;
            }
            temp->next = temp2;
            temp2->next = NULL;
            *head = newhead;
        }
    }
}

void reverse(node **head)
{
    node *prev = NULL;
    node *curr = *head;
    node *next = NULL;

    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    *head = prev;
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

    traverseList(head);

    reverseList(&head);

    traverseList(head);

    reverse(&head);

    traverseList(head);
    return 0;
}