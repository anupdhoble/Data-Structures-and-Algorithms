// Note subsequence is different from subset or substring
#include <iostream>
#include <vector>
using namespace std;

void subsequence(int i, vector<int> v, int arr[], int n)
{
    if (i >= n)
    {   cout<<"#";   //this is cout so this we can see if null is printed
        for (int num : v)
            cout << num << " ";
        cout<<"#";
        cout << endl;
        return;
    }
    v.push_back(arr[i]);
    subsequence(i + 1, v, arr, n);
    v.pop_back();
    subsequence(i + 1, v, arr, n);
}
int main()
{
    int arr[] = {3, 2, 1};
    int n = size(arr);
    vector<int> v;
    subsequence(0, v, arr, n);
    return 0;
}