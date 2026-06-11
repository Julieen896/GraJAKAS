#include <iostream>
#include <windows.h> // biblioteka zawierajaca Sleep
#include <conio.h> // biblioteka zawierajaca _kbhit() i _getch()
using namespace std;
int main(){


char plansza[11][50];
int dinoY=8;
int dinoX=4;
char przeszkoda='#';
int wynik=0;
plansza[11][1]=wynik;


int przeszkodaX=25;

bool GRA =true;



while (GRA){
    
    system("cls");//wyczyszcza ekran
    if (_kbhit()) {
    int key = _getch();
    if (key == 32 && dinoY==8 ) {  // spacja
        if (dinoY > 0) {
            dinoY -= 1;
        }
    }
}
    if (dinoY < 8) {
        dinoY += 1; // grawitacja
    }


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
    
    if(przeszkodaX==dinoX && dinoY==8){
        GRA=false;
        cout << "PRZEGRALES!" << endl;
        break;
    }
    Sleep(100);//czeka 100ms



    wynik++;
}


}