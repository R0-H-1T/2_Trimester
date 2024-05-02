#include<vector>
#include<iostream>

using namespace std;

// vector<int> countFrequency(int n, int x, vector<int> &nums) {
//     cout<< "nums[i]     nums[i]-1   freq[nums[i] - 1]   freq[nums[i] - 1]++\n";
//    vector<int> freq(n, 0);
//    for (int i = 0; i < n; i++) {
//         cout << nums[i] << "\t\t" << nums[i] - 1 << "\t\t" <<freq[nums[i] -1] <<"\t\t"  << freq[nums[i] -1]+1 <<endl;
//         freq[nums[i] - 1]++; 
//    }
//     cout << "\n\n";
//     for(int i=0; i<n; i++) 
//         cout << " " << i;
//     cout<<endl;
//    for(int i : freq) 
//         cout << " " << i;
//    return freq;
// }

void bubbleSort(int arr[], int n) 
{
    //2, 3 ,1, 90, 34
    for(int i=0; i<n; i++){
        for(int j=0; j<n-1; j++){
            cout<< arr[i+j] <<" "<< arr[j+1+i] << endl;
        }
        cout<<"\n\n";

    }
//     for(int i=0; i<n; i++){
//         for(int j=0; j<n-1; j++){
//             cout<< arr[i+j] << arr[j+1] << endl;
//             if( arr[i+j] > arr[j+1]){
//                 int temp = arr[j+i];
//                 arr[j+i] = arr[j+1];
//                 arr[j+1] = temp;
//             }
//         }
//    }
}

int main(){
    vector<int> vect{1, 3, 1, 9, 2, 7};
    int arr[] = {2, 3 ,1, 90, 34};
    // cout <<  sizeof(arr)/ sizeof(int);
    bubbleSort(arr, sizeof(arr)/ sizeof(int));
    return 0;
}