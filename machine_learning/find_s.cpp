#include<iostream>
using namespace std;
void find_s(char arr[4][7], char*);
int main(){
        char arr[4][7] = 
        {{'S','W','L','S','W','S','Y'}, 
         {'S','W','H','S','W','S','Y'}, 
         {'R','C','H','S','W','C','N'}, 
         {'S','W','H','S','C','C','Y'}}; 

        char hypothesis[6] = {'$','$','$','$','$','$'};
        find_s(arr,hypothesis);
        for(int i = 0; i<6; i++)
                cout<<hypothesis[i]<<" ";
        cout<<endl;
        return 0;
}

void find_s(char arr[4][7], char hypothesis[6]){
        for(int i = 0; i<4; i++) {
                if(arr[i][6] == 'Y') {  
                        for(int j = 0; j<6; j++) {
                                if(arr[i][j] == hypothesis[j])
                                        continue;
                                else if(hypothesis[j] == '?')
                                        continue;
                                else {
                                        if(hypothesis[j] == '$')
                                                hypothesis[j] = arr[i][j];
                                        else 
                                                hypothesis[j] = '?';
                                }
                        }
                }
        }
}
