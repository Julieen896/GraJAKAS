#include <iostream>
#include <windows.h> // biblioteka zawierajaca Sleep
using namespace std;
int main(){


char plansza[10][50];
int dinoY=8;
int dinoX=4;
char przeszkoda='#';
int przeszkodaX=25;
bool GRA =true;



while (true){
    system("cls");//wyczyszcza ekran
    for(int y=0;y<10;y++){
    
    for(int x=0;x<50;x++){
        plansza[y][x]=' ';
    }
}
    for(int x=0;x<50;x++){
    plansza[9][x]='=';
}
    plansza[dinoY][dinoX]='O';
    plansza[8][przeszkodaX]=przeszkoda;




    for(int y=0;y<10;y++){
    cout << y;
    for(int x=0;x<50;x++){
        cout <<plansza[y][x];
    }
    cout << endl;
    }   
    przeszkodaX-=1;
    if(przeszkodaX<0){
        przeszkodaX=49;
    }
    Sleep(100);//czeka 100ms
}


}