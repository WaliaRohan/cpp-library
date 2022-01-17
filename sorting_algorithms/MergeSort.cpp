#include <iostream>
#include <vector>

using namespace std;

void printVector(vector<int> nums)
{
    for (int element : nums)
        cout << element << " ";

    cout << endl;
}

vector<int> merge(vector<int> left, vector<int> right)
{
    // create the vector to return
    vector<int> ret(left.size() + right.size());

    // index trackers for 'left', 'right' and 'ret' vectors
    int left_index{ 0 }, right_index{ 0 }, ret_index{ 0 };

    // fill ret based on 'left' and 'right', comparing elements one-by-one
    while (left_index < left.size() && right_index < right.size())
    {
        if (left[left_index] < right[right_index])
        {
            // simultaneously update index trackers while filling 'ret'
            ret[ret_index++] = left[left_index++];
        }
        else
            ret[ret_index++] = right[right_index++];
    }

    // add elements to ret if something remains in 'left' or 'right'

    while (left_index < left.size())
    {
        ret[ret_index++] = left[left_index++];
    }

    while (right_index < right.size())
    {
        ret[ret_index++] = right[right_index++];
    }

    return ret;
}

vector<int> mergeSort(vector<int> input)
{
    if (input.size() <= 1)
    {
        return input;
    }

    int pivot = input.size() / 2;
    vector<int> left_array(input.begin(), input.begin() + pivot);
    vector<int> right_array(input.begin() + pivot, input.end());

    left_array = mergeSort(left_array);
    right_array = mergeSort(right_array);

    return merge(left_array, right_array);
}

int main()
{
    vector<int> array_to_sort = { 1, 5, 2, 4, 2, 6, 7 };

    printVector(array_to_sort);

    array_to_sort = mergeSort(array_to_sort);

    printVector(array_to_sort);

    return 0;
}
