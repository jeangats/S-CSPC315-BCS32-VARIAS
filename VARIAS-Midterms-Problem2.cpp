#include <iostream>
#include <vector>

using namespace std;

// Bubble Sort
vector<int> BubbleSort(vector<int> DeliveryTimesList) {
    int N = DeliveryTimesList.size();
    for (int i = 0; i < N; i++) {
        bool swapped = false;
        for (int j = 0; j < N - i - 1; j++) {
            if (DeliveryTimesList[j] > DeliveryTimesList[j + 1]) {
                swap(DeliveryTimesList[j], DeliveryTimesList[j + 1]);
                swapped = true;
            }
        }
        if (!swapped)
            break;
    }
    return DeliveryTimesList;
}

// Merge Sort
void Merge(vector<int>& DeliveryTimesList, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> LeftHalf(n1);
    vector<int> RightHalf(n2);

    for (int i = 0; i < n1; i++)
        LeftHalf[i] = DeliveryTimesList[left + i];
    for (int j = 0; j < n2; j++)
        RightHalf[j] = DeliveryTimesList[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (LeftHalf[i] <= RightHalf[j]) {
            DeliveryTimesList[k] = LeftHalf[i];
            i++;
        } else {
            DeliveryTimesList[k] = RightHalf[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        DeliveryTimesList[k] = LeftHalf[i];
        i++;
        k++;
    }

    while (j < n2) {
        DeliveryTimesList[k] = RightHalf[j];
        j++;
        k++;
    }
}

void MergeSort(vector<int>& DeliveryTimesList, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        MergeSort(DeliveryTimesList, left, mid);
        MergeSort(DeliveryTimesList, mid + 1, right);

        Merge(DeliveryTimesList, left, mid, right);
    }
}

int main() {
    vector<int> DeliveryTimesList;
    int N;

    cout << "Enter number of deliveries: ";
    cin >> N;

    for (int i = 0; i < N; i++) {
        int DeliveryTime;
        cout << "Enter delivery time (in minutes) for delivery " << i + 1 << ": ";
        cin >> DeliveryTime;
        DeliveryTimesList.push_back(DeliveryTime);
    }

    // Bubble Sort
    vector<int> BubbleSortedList = BubbleSort(DeliveryTimesList);
    cout << "\nBubble Sorted: ";
    for (int i : BubbleSortedList) {
        cout << i << " ";
    }
    cout << "\nTime Complexity: O(n^2)" << endl;

    // Merge Sort
    vector<int> MergeSortedList = DeliveryTimesList;
    MergeSort(MergeSortedList, 0, N - 1);
    cout << "\nMerge Sorted: ";
    for (int i : MergeSortedList) {
        cout << i << " ";
    }
    cout << "\nTime Complexity: O(n log n)" << endl;

    return 0;
}
