#include <iostream>
#include <windows.h> // biblioteka zawierajaca Sleep
<<<<<<< HEAD
#include <conio.h> // odczyt z klawiatury
=======
#include <conio.h> // biblioteka zawierajaca _kbhit() i _getch()
>>>>>>> 4f3427128510c84061b2fc8430b413b13edebfc3
using namespace std;
int main(){


char plansza[11][50];
int dinoY=8;
int dinoX=4;
char przeszkoda='#';
int wynik=0;
plansza[11][1]=wynik;


int przeszkodaX=25;
<<<<<<< HEAD
int przeszkodaY=8;
=======

>>>>>>> 4f3427128510c84061b2fc8430b413b13edebfc3
bool GRA =true;
bool skacze=false;
int licznikSkoku=0;
int wynik=0;



<<<<<<< HEAD

while (GRA){
=======
while (GRA){
    
>>>>>>> 4f3427128510c84061b2fc8430b413b13edebfc3
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
<<<<<<< HEAD
    plansza[przeszkodaY][przeszkodaX]=przeszkoda;
=======
    plansza[8][przeszkodaX]=przeszkoda;
    

>>>>>>> 4f3427128510c84061b2fc8430b413b13edebfc3




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
<<<<<<< HEAD
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

=======
    
    if(przeszkodaX==dinoX && dinoY==8){
        GRA=false;
        cout << "PRZEGRALES!" << endl;
        break;
    }
>>>>>>> 4f3427128510c84061b2fc8430b413b13edebfc3
    Sleep(100);//czeka 100ms



    wynik++;
}


}