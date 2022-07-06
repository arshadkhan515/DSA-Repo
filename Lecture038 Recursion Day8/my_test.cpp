#include <bits/stdc++.h>
using namespace std;
void replacePi(char input[]) {
	// Write your code here
    if(strlen(input) == 1 || strlen(input) == 0)
        return;
    
    if(input[0] == 'p' && input[1] == 'i'){
        int old = strlen(input);
        
        // input[strlen(input)+1] = 0;
        // input[strlen(input)+2] = 0;
        
        for(int i=strlen(input);i>0;i--){
            input[i] = input[i-1];
        }	
        cout<<input<<endl;
        // input[0] = '3';
        // input[1] = '.';
        // input[2] = '1';
        // input[3] = '4';
        // input[strlen(input)+3] = '\0';        
    }
    // replacePi(input+1);
}
int main() {
    char input[10000];
    cin.getline(input, 10000);
    replacePi(input);
    cout << input << endl;
}
