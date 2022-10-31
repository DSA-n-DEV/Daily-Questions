/*
Given an array of numbers and a number k, determine if there are three entries in the array which add up to the specified number k. For example, given [20, 303, 3, 4, 25] and k = 49, return true as 20 + 4 + 25 = 49.
*/
#include <iostream>
#include <bits/stdc++.h>
#define ll long long int
using namespace std;
bool func(int arr[], int k, int n){
    int a, b; //a - first element b - second element
    for (int i = 0; i < n; i++)
    {
       a = i+1; //starting index
       b = n - 1; //ending index
       while(a < b){
        if(arr[i] + arr[a] + arr[b] == k){ 
            return true;
        }
        else if(arr[i] + arr[a] + arr[b] < k){ //if sum is lesser than k then take a high value element hence increase starting index by 1 - in sorted array
            a++;
        }
        //if sum is greater than take a low value element - decrease the ending index by 1
        else{
            b--;
        }
       }
    }
    return false;
    
}
int main()
{
    int arr[] = {20, 303, 3, 4, 25};
    int k = 49;
    int x = sizeof(arr)/sizeof(arr[0]);
    sort(arr, arr+ x);
    int y = func(arr, k , x);
    if(y == 1){
        cout<<"True"<<endl;
    }
    else cout<<"False"<<endl;
    return 0;
}
