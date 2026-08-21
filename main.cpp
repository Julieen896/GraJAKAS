#include <iostream>
#include <windows.h> // biblioteka zawierajaca Sleep
#include <conio.h> // odczyt z klawiatury
using namespace std;
int main(){


char plansza[10][50];
int dinoY=8;
int dinoX=4;
char przeszkoda='#';
int przeszkodaX=25;
int przeszkodaY=8;
bool GRA =true;
bool skacze=false;
int licznikSkoku=0;
int wynik=0;




while (GRA){
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
    plansza[przeszkodaY][przeszkodaX]=przeszkoda;




    for(int y=0;y<10;y++){
    cout << y;
    for(int x=0;x<50;x++){
        cout <<plansza[y][x];
    }
    cout << endl;
    }   
    if((przeszkodaX == dinoX)&&(przeszkodaY == dinoY)){
        cout <<"KONIEC GRY";
        GRA=false;

    }
    przeszkodaX-=1;
    if(przeszkodaX<0){
        przeszkodaX=49;
    }
    if(_kbhit()){
        char klawisz =_getch();

        if(klawisz == ' ' && !skacze){
            skacze=true;
            licznikSkoku=0;
            
        }
    }
    if(skacze){
        if(licznikSkoku<3){
            dinoY--;
        }
        else if(licznikSkoku<6){
            dinoY++;
        }
        else{
            dinoY=8;
            skacze=false;
        }
        licznikSkoku++;
    }

    Sleep(100);//czeka 100ms
}


}