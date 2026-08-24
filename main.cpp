#include <iostream>
#include <windows.h> // biblioteka zawierajaca Sleep

#include <conio.h> // odczyt z klawiatury

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

int przeszkodaY=8;



bool GRA =true;
bool start=false;
bool skacze=false;
int licznikSkoku=0;




cout <<"========================================"<< endl;
cout <<"            GOOGLE DINOZAUR"<<endl;
cout <<"        wcisnij ENTER aby zaczac"<<endl;
cout <<"========================================"<<endl;
while(!start){
if (_kbhit()){
    int key=_getch();
    if (key==13){
        start=true;
    }
}
}
system("cls"); // czysci tekst startowy
while (GRA){
    

    COORD pozycja;
    pozycja.X = 0;
    pozycja.Y = 0;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pozycja); // czysci plansze
        

    cout<<"Punkty: "<<wynik;
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

    plansza[8][przeszkodaX]=przeszkoda;
    






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


    
    if(przeszkodaX==dinoX && dinoY==8){
        GRA=false;
        cout << "PRZEGRALES!" << endl;
        break;
    }

    Sleep(100);//czeka 100ms

    cout << endl;
    
    wynik+=1;
}


}