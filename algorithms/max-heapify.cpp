#include <iostream>
#include <vector>

using namespace std;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void Max_Heapify(int nums[], int size, int node)
{
    int left = 2 * node + 1;
    int right = 2 * node + 2;
    int largest = node;
    if (left < size && nums[left] > nums[largest])
    {
        largest = left;
    }
    if (right < size && nums[right] > nums[largest])
    {
        largest = right;
    }
    if (largest != node)
    {
        swap(nums[largest], nums[node]);
        Max_Heapify(nums, size, largest);
    }
}

void print(vector<int> nums)
{
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
}

void print(int nums[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
}

void heapify(int arr[], int n, int i)
{
    int largest = i;   // Initialize largest as root
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2

    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;

    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
        largest = r;

    // If largest is not root
    if (largest != i)
    {
        swap(arr[i], arr[largest]);

        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}

void heapSort(int nums[], int size)
{
    for (int i = size / 2 - 1; i >= 0; i--)
    {
        Max_Heapify(nums, size, i);
    }
    for (int i = size - 1; i >= 0; i--)
    {
        swap(nums[0], nums[i]);
        Max_Heapify(nums, i, 0);
    }
}

int main(int argc, char **argv)
{
    int size, data;
    cin >> size;
    int *nums = new int[size];
    for (int i = 0; i < size; i++)
    {
        cin >> nums[i];
    }
    // print(nums, size);
    // Max_Heapify(nums, size, 0);
    heapSort(nums, size);
    print(nums, size);

    return 0;
}