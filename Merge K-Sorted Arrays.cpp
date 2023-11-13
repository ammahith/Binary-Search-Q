#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> mergeKSortedArrays(vector<vector<int>>& arrays) {
    // Create a min-heap
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

    // Insert the first element from each array into the min-heap
    for (int i = 0; i < arrays.size(); i++) {
        if (!arrays[i].empty()) {
            minHeap.push({ arrays[i][0], i });
        }
    }

    vector<int> mergedArray;

    while (!minHeap.empty()) {
        // Extract the minimum element from the heap
        pair<int, int> minElement = minHeap.top();
        minHeap.pop();

        int element = minElement.first;
        int arrayIndex = minElement.second;

        // Add the minimum element to the merged array
        mergedArray.push_back(element);

        // Replace the minimum element with the next element from the same array
        if (!arrays[arrayIndex].empty()) {
            arrays[arrayIndex].erase(arrays[arrayIndex].begin());
            if (!arrays[arrayIndex].empty()) {
                minHeap.push({ arrays[arrayIndex][0], arrayIndex });
            }
        }
    }

    return mergedArray;
}

int main() {
    vector<vector<int>> arrays = {
        {10, 15, 20, 30},
        {2, 5, 8, 14, 24},
        {0, 11, 60, 90}
    };

    // Merge the sorted arrays
    vector<int> mergedArray = mergeKSortedArrays(arrays);

    // Print the merged sorted array
    cout << "Merged Sorted Array: ";
    for (int num : mergedArray) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
