#include<iostream>
#include<sys/time.h>
using namespace std;

long getTimeinMicroSeconds() {
    struct timeval start;
    gettimeofday(&start, NULL);
    return start.tv_sec * 1000000 + start.tv_usec;
}

void merge(int input[], int si, int ei) {
    int* temp = new int[ei - si + 1];
    int mid = (si + ei) / 2;
    
    int i = si, j = mid + 1, nextIndex = 0;
    
    // Merge inside temp [si..mid] [mid+1..ei]
    while(i <= mid && j <= ei) {
        if(input[i] < input[j]) {
            temp[nextIndex] = input[i];
            i++;
        } else {
            temp[nextIndex] = input[j];
            j++;
        }
        nextIndex += 1;
    }
    while(i <= mid) {
        temp[nextIndex] = input[i];
        nextIndex++;
        i++;
    }
     while(j <= ei) {
        temp[nextIndex] = input[j];
        nextIndex++;
        j++;
    }
    
    // Copy to arr[si....ei]
    nextIndex = 0;
    for(int k = si; k <= ei; k++) {
    	input[k] = temp[nextIndex];
        nextIndex++;
    }
    delete[] temp;
}
void mergeSortHelper(int input[], int si, int ei) {
    // Base
    if(si >= ei)
        return;
    int mid = (si + ei) / 2;
    mergeSortHelper(input, si, mid);
    mergeSortHelper(input, mid + 1, ei);
    merge(input, si, ei);
}
void mergeSort(int input[], int size){
    mergeSortHelper(input, 0, size - 1);    
}
void selectionSort(int arr[], int n) {
	// Loop for Rounds
	for(int i = 0; i < n - 1; i++) {
		// Round i -> (i-n) minimum value -> ith index swap with the location of minimum value
		int minValue = arr[i];
		int location = i;
		for(int j = i + 1; j <= n - 1; j++) {
			if(arr[j] < minValue) {
				minValue = arr[j];
				location = j;
			}
		}
		// i->minValue
		// loc->arr[i]
		// Swap arr[i] with arr[loc]
		int temp = arr[i];
		arr[i] = minValue;
		arr[location] = temp;
	}
}
int main() {
    for(int n = 10; n <= 1000000; n *= 10) {
        int *arr = new int[n];
        long starttime, endtime;
        // 10, 9, 8, 7, 6, 5, 4, 3, 2, 1
        for(int i = 0; i < n; i++) {
            arr[i] = n - i;
        }
        starttime = getTimeinMicroSeconds();
        selectionSort(arr, n);
        endtime = getTimeinMicroSeconds();
        cout << "Selection Sort n = " << n << " time = " << endtime - starttime << endl;
    }
}