#include<iostream>
#include<vector>

using namespace std;

vector<int> recur(vector<int> &v, int i, int n){
    if(i == n+1){
        return v;
    }
    v.push_back(i);
    return recur(v, i+1, n);
}

vector<int> printNos(int x){
    vector<int> v;
    return recur(v, 1, x);
}

vector<int> recur1(vector<int> &v, int x){
    if(x == 0) return v;
    v.push_back(x);
    return recur1(v, x-1);
}

vector<int> printNTo1(int x){
    vector<int> v;
    return recur1(v, x);   
}


// long long getSum(long long n, int i){
    
// }

long long sumFirstN(long long n){
    if (n == 0) return 0;        
    return (n + sumFirstN(n-1));
}

bool recur(int i, string &str){
    if( i >= str.size()/2) return true;
    if(str[i] != str[str.size()-i-1]) return false;
    return recur(i+1, str);
}

bool isPalindrome(string &str) {
    // Write your code here.
    return recur(0, str);
}


int main(void){
    // vector<int> v = printNTo1(5);
    // for(int i=0; i < v.size(); i++){
    //     cout << v[i] << " ";
    // }
    const char *name = "Rohit Tank";
    char const *name2 = "Reynolds"; 
    char *const name1 = ""; //const pointer, can change the value at the address
                            // but not the addres it is pointing to.
    cout << name;

    const char *name = "Like this only";
    // this is a pointer to a constant. In the sense that -  we can change the address
    // it is pointing to but not the value

    cout << sumFirstN(3);

    return 0;
}