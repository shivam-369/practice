#include <iostream>
using namespace std;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void Min_Heapify(int nums[], int size, int node)
{
    int left = 2 * node + 1;
    int right = 2 * node + 2;
    int smallest = node;
    if (left < size && nums[left] < nums[smallest])
    {
        smallest = left;
    }
    if (right < size && nums[right] < nums[smallest])
    {
        smallest = right;
    }
    if (smallest != node)
    {
        swap(nums[smallest], nums[node]);
        Min_Heapify(nums, size, smallest);
    }
}

void Heapsort(int nums[], int size)
{
    for (int i = size / 2 - 1; i >= 0; i--)
    {
        Min_Heapify(nums, size, i);
    }
    for (int i = size - 1; i >= 0; i--)
    {
        swap(nums[i], nums[0]);
        Min_Heapify(nums, i, 0);
    }
}

void print(int nums[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
}

int main(int argc, char **argv)
{
    int size;
    cin >> size;
    int *nums = new int[size];
    for (int i = 0; i < size; i++)
    {
        cin >> nums[i];
    }
    print(nums, size);
    Heapsort(nums, size);
    print(nums, size);
    return 0;
}