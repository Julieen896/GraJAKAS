#include <iostream>
#include <windows.h> // biblioteka zawierajaca Sleep



#include <conio.h> // biblioteka zawierajaca _kbhit() i _getch()
#include <cstdlib> // losowanie rand() i srand()
#include <ctime> //time(0)

using namespace std;
int main(){
srand(time(0));


char plansza[11][50];
int dinoY=8;
int dinoX=4;
int wynik=0;



bool GRA =false;
bool start=false;
bool skacze=false;
bool chceGrac=true;
int licznikSkoku=0;

const int MAXKAKTUSOW=5;
int kaktusX[MAXKAKTUSOW];
int kaktusWysokosc[MAXKAKTUSOW];
int kaktusSzerokosc[MAXKAKTUSOW];


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
while(chceGrac){
    kaktusX[0] = 25;
    kaktusX[1] = 45;
    kaktusX[2] = 65;
    kaktusX[3] = 85;
    kaktusX[4] = 105;
    dinoX = 4;
    dinoY = 8;

    GRA = true;
    skacze = false;
    licznikSkoku = 0;
    wynik = 0;
    for(int i = 0; i < MAXKAKTUSOW; i++)
    {
        kaktusWysokosc[i] = rand() % 2 + 1;
        kaktusSzerokosc[i] = rand() % 2 + 1;
    }



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

        
        for(int i = 0; i < MAXKAKTUSOW; i++)
    {
        for(int y = 0; y < kaktusWysokosc[i]; y++)
        {
            for(int x = 0; x < kaktusSzerokosc[i]; x++)
            {
                if(kaktusX[i] + x >= 0 && kaktusX[i] + x < 50)
                {
                    plansza[8-y][kaktusX[i]+x] = '#';
                }
            }
        }
    }
        
        


        for(int y=0;y<10;y++){
        cout << y;
        for(int x=0;x<50;x++){
            cout <<plansza[y][x];
            
        }
        cout << endl;
        }   
        
        for(int i = 0; i < MAXKAKTUSOW; i++)
        {
        bool kolizjaX =
            dinoX >= kaktusX[i] &&
            dinoX < kaktusX[i] + kaktusSzerokosc[i];

        bool kolizjaY =
            dinoY >= 8 - kaktusWysokosc[i] &&
            dinoY <= 8;

        if(kolizjaX && kolizjaY)
        {
            GRA = false;
            break;
        }
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

        for(int i=0;i<MAXKAKTUSOW;i++){
            kaktusX[i]--;
            if(kaktusX[i]<-2){
                kaktusX[i]=49;
                 kaktusWysokosc[i] = rand() % 2 + 1;
                kaktusSzerokosc[i] = rand() % 2 + 1;
            }
        }
        
        
        wynik+=1;
        Sleep(100);//czeka 100ms

        cout << endl;
        
        
    }
    system("cls");
    cout << "==============================" << endl;
    cout << "          GAME OVER" << endl;
    cout << "       Wynik: " << wynik*10 << endl;
    cout << endl;
    cout << "   ENTER - zagraj ponownie" << endl;
    cout << "   ESC   - wyjdz" << endl;
    cout << "==============================" << endl;
    while(true)
    {
        if(_kbhit())
        {
            char klawisz = _getch();

            if(klawisz == 13) // ENTER
            {
                break;
            }

            if(klawisz == 27) // ESC
            {
                chceGrac = false;
                break;
            }
        }
    }
}

}