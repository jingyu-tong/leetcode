//@author Jingyu Tong
//@email: jingyutong0806@gmail.com
//常用的排序算法，采用vector作为容器
//方便复习

#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <string.h>
#include <climits>

using namespace std;

//bubble sort time complexity O(n^2) space complexity O(1) stable
template<typename T>
void bubbleSort(vector<T>& arr) {
    for(int i = 0; i < arr.size(); ++i) {
        for(int j = 0; j < arr.size() - 1 - i; ++j) {
            if(arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

//selection sort complexity O(n^2) space complexity O(1) unstable
template<typename T>
void selectionSort(vector<T>& arr) {
    for(int i = 0; i < arr.size(); ++i) {
        int min_ind = i;
        for(int j = i + 1; j < arr.size(); ++j) {
            if(arr[j] < arr[min_ind])
                min_ind = j;
        }
        swap(arr[i], arr[min_ind]);
    }
}

//insertion sort complexity O(n^2) space complexity O(1) unstable
template<typename T>
void insertionSort(vector<T>& arr) {
    for(int i = 1; i < arr.size(); ++i) {
        int ele = arr[i];
        int j = i - 1;
        while( (j >= 0) && (ele < arr[j])) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = ele;
    }
}

//shell sort complexity O(nlogn) ? space complexity O(1) unstable
//Knuth序列
template<typename T>
void shellSort(vector<T>& arr) {
    int length = arr.size();
    int h = 1;
    while (h < length / 3) {
        h = 3 * h + 1;
    }
    while(h >= 1) {
        //insertion sort
        for(int i = h; i < length; ++i) {
            for(int j = i; j >=h && arr[j] < arr[j - h]; j -= h) {
                swap(arr[j], arr[j - h]);
            }
        }
        h = h / 3;
    }
}

//merge sort complexity O(nlogn) space complexity O(n) stable
template<typename T>
void merge(vector<T>&arr, int begin, int mid, int end) {
    vector<T> left_part(arr.begin() + begin, arr.begin() + mid);
    vector<T> right_part(arr.begin() + mid, arr.begin() + end);

    int left_ind = 0;
    int right_ind = 0;
    for(int i = begin; i < end; ++i) {
        if(left_part[left_ind] < right_part[right_ind]) {
            arr[i] = left_part[left_ind++];
        } else {
            arr[i] = right_part[right_ind++];
        }
    }
}
template<typename T>
void mergeSort(vector<T>& arr, int begin, int end) {
    if(end - begin < 2)
        return;
    int mid = begin + (end - begin) / 2;
    mergeSort(arr, begin, mid);
    mergeSort(arr, mid, end);
    merge(arr, begin, mid, end);
}

//quick sort complexity O(nlogn) space complexity O(logn) unstable
//快排partition，全闭
template<typename T>
int partition(vector<T>& arr, int begin, int end) {
    swap(arr[begin], arr[begin + rand() % (end - begin + 1)]);
    T pivot = arr[begin];
    while(begin < end) {
        while( (begin < end) && (pivot <= arr[end])) //�Ҷ�
            --end;
        arr[begin] = arr[end];
        while( (begin < end) && (arr[begin] <= pivot))//����
            ++begin;
        arr[end] = arr[begin];
    }
    arr[begin] = pivot;
    return begin;
}
template<typename T>
void quickSort(vector<T>& arr, int begin, int end) {
    if(end - begin < 2)
        return;
    int mid = partition(arr, begin, end - 1);
    quickSort(arr, begin, mid);
    quickSort(arr, mid + 1, end);
}

//heap sort complexity O(nlogn) space complexity O(1) unstable
//下滤算法
template<typename T>
void percolateDown(vector<T>&arr, int begin, int end) {
    int dad = begin;
    int son = (dad << 1) + 1;
    while(son <= end) {
        if( (son + 1 <= end) && arr[son] < arr[son + 1])//ȡ��������������
            ++son;
        if(arr[dad] >= arr[son])
            return;
        else {
            swap(arr[dad], arr[son]);
            dad = son;
            son = (dad << 1) + 1;
        }
    }
}
template<typename T>
void heapSort(vector<T>&arr) {
    //Floyd算法，自底向上依次下滤
    for(int i = arr.size() / 2 - 1; i >= 0; --i) {
        percolateDown(arr, i, arr.size() - 1);
    }

    for(int i = arr.size() - 1; i > 0; --i) {
        swap(arr[0], arr[i]);
        percolateDown(arr, 0, i - 1);
    }

}

//counting sort complexity O(n + k) k是待排序的范围 space complexity O(k) stable
template<typename T>
void countingSort(vector<T>& arr) {
    vector<T> ans(arr.size(), 0); //sort

    //find the range of the data
    int max = INT_MIN;
    int min = INT_MAX;
    for(auto& ele : arr) {
        max = max > ele ? max : ele;
        min = min < ele ? min : ele;
    }

    //count the element
    vector<T> count(max - min + 1, 0); //from min to max
    for(auto& ele : arr) {
        ++count[ele - min];
    }
    for(int i = 1; i < count.size(); ++i) {
        count[i] += count[i - 1];
    }

    //save the answer
    for(int i = arr.size() - 1; i >= 0; --i) {
        ans[count[arr[i] - min] - 1] = arr[i];
        --count[arr[i] - min];
    }
    swap(ans, arr);
}

//bucket sort complexity O(n + k) k为桶个数 space complexity O(n + k) stable
//为counting sort的升级版，但当元素全部分到一个桶时，可能带来O(n^2)的复杂度

int main() {
    vector<int> arr(103, 0);
    for(auto& ele : arr) {
        ele = rand() % 1000;
        cout << ele << ' ';
    }
    cout << endl;

    countingSort(arr);

    for(const auto& ele : arr) {
        cout << ele << ' ';
    }
    return 0;
}
