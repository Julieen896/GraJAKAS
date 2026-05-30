#include <iostream>
using namespace std;
int main(){
cout << "Hello World!" << endl;

char plansza[10][50];
for(int y=0;y<10;y++){
    
    for(int x=0;x<50;x++){
        plansza[y][x]=' ';
    }
}
for(int x=0;x<50;x++){
    plansza[9][x]='=';
}



for(int y=0;y<10;y++){
    cout << y;
    for(int x=0;x<50;x++){
        cout <<plansza[y][x];
    }
    cout << endl;
}



}