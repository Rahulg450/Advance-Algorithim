#include<iostream>
using namespace std;

class Node
{
public:
    int row;
    int col;
    int data;
    Node *next;
};

void create_new_node(Node **p, int row_index, int col_index, int x)
{
    Node *temp = *p;
    Node *r;

    if (temp == NULL)
    {
        temp = new Node();
        temp->row = row_index;
        temp->col = col_index;
        temp->data = x;
        temp->next = NULL;
        *p = temp;
    }
    else
    {
        while (temp->next != NULL)
            temp = temp->next;

        r = new Node();
        r->row = row_index;
        r->col = col_index;
        r->data = x;
        r->next = NULL;
        temp->next = r;
    }
}

void printList(Node *start)
{
    Node *ptr = start;
    cout << "row_position:";
    while (ptr != NULL)
    {
        cout << ptr->row << " ";
        ptr = ptr->next;
    }
    cout << endl;
    cout << "column_position:";

    ptr = start;
    while (ptr != NULL)
    {
        cout << ptr->col << " ";
        ptr = ptr->next;
    }
    cout << endl;
    cout << "Value:";
    ptr = start;

    while (ptr != NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
}

int main()
{
    int rows, cols;

    cout << "Enter the number of rows and columns in the sparse matrix: ";
    cin >> rows >> cols;

    int sparseMatrix[rows][cols];
    
    cout << "Enter the elements of the sparse matrix:" << endl;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cin >> sparseMatrix[i][j];
        }
    }

    Node *first = NULL;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (sparseMatrix[i][j] != 0)
                create_new_node(&first, i, j, sparseMatrix[i][j]);
        }
    }

    cout << "Compact representation of the sparse matrix:" << endl;
    printList(first);

    return 0;
}
