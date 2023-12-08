#include<iostream>
using namespace std;

char space[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
string n1 = "",n2 ="";
int row,col;
char token = 'X';
bool tie = false;

void function_one(){
    
    cout<<"   |    |   "<<endl;
    cout<<" "<<space[0][0]<<" | "<<space[0][1]<<"  | "<<space[0][2]<<" "<<endl;
    cout<<"___|____|___"<<endl;
    cout<<"   |    |   "<<endl;
    cout<<" "<<space[1][0]<<" | "<<space[1][1]<<"  | "<<space[1][2]<<" "<<endl;
    cout<<"___|____|___"<<endl;
    cout<<"   |    |   "<<endl;
    cout<<" "<<space[2][0]<<" | "<<space[2][1]<<"  | "<<space[2][2]<<" "<<endl;
    cout<<"   |    |   \n"<<endl;

}

void function_two(){

    int digit;

    if(token == 'X'){
        cout<<n1<<" please Enter"<<endl;
        cin>>digit;
    }else if(token == 'O'){
        cout<<n2<<" please Enter"<<endl;
        cin>>digit;
    }


    if(digit == 1){
        row = 0;
        col = 0;
    }else if(digit == 2){
        row = 0;
        col = 1;
    }else if(digit == 3){
        row = 0;
        col = 2;
    }else if(digit == 4){
        row = 1;
        col = 0;
    }else if(digit == 5){
        row = 1;
        col = 1;
    }else if(digit == 6){
        row = 1;
        col = 2;
    }else if(digit == 7){
        row = 2;
        col = 0;
    }else if(digit == 8){
        row = 2;
        col = 1;
    }else if(digit == 9){
        row = 2;
        col = 2;
    }else{
        cout<<"Invalid!!!"<<endl;
    }


    if(token == 'X' && space[row][col] != 'X' && space[row][col] != 'O'){
        space[row][col] = 'X';
        token = 'O';
    }else if(token == 'O' && space[row][col] != 'X' && space[row][col] != 'O'){
        space[row][col] = 'O';
        token = 'X';
    }else{
        cout<<"there is already entered space....."<<endl;
        function_two();
    }

    function_one();
}

bool function_three(){

    for(int i=0 ; i<3 ; i++)
        if((space[i][0] == space[i][1] && space[i][0] == space[i][2]) ||(space[0][i] == space[1][i] && space[0][i] == space[2][i]))
            return true;   
    
    
    if((space[0][0] == space[1][1] && space[0][0] == space[2][2]) ||(space[0][2] == space[1][1] && space[0][2] == space[2][0]))
        return true;
    
    for(int i=0 ; i<3 ; i++){
        for(int j=0 ; j<3 ;j++){
            if(space[i][j] != 'X' && space[i][j] != 'O'){
              return false;
            }
        }
    }    
    
    tie = true;
    return false;
}


int main(){

    cout<<"Enter the name of first player : ";
    getline(cin, n1);
    cout<<"Enter the name of second player : ";
    getline(cin, n2);

    cout<<n1<<" is player-1 so he/she will play first..."<<endl;
    cout<<n2<<" is player-2 so he/she will play second..."<<endl;
    
    while(!function_three()){
        function_one();
        function_two();
        function_three();
    }

    if(token == 'X' && tie == false){
        cout<<n2<<" is WINNER...."<<endl;
    }else if(token == 'O' && tie == false){
        cout<<n1<<" is WINNER...."<<endl;
    }else if(tie == true){
        cout<<" the game is DRAW...."<<endl;
    }
    
    return 0;
}