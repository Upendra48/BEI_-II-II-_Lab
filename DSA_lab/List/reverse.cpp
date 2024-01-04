// Create a list and reverse it using stack

#include <iostream>
#include <stack>
using namespace std;

int main(){
    stack<int> s;
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements: ";
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    for(int i = 0; i < n; i++){
        s.push(arr[i]);
    }
    cout << "The reversed list is: ";
    while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
    return 0;
}