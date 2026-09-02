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

const int MAXCHMUREK=3;
int chmurkaX[MAXCHMUREK];
int chmurkaY[MAXCHMUREK];


int poziom=1;
int predkosc=150;

const int MINODSTEP=8;
const int MAXODSTEP=20;

int Najelpszywynik=0;
int licznikCzasu = 0;

while(chceGrac){
    cout << "========================================" << endl;
    cout << "            GOOGLE DINOZAUR" << endl;
    cout << "              SPACJA-SKOK "<<endl;
    cout << "        Wcisnij ENTER aby zaczac" << endl;
    cout << "           ESC - WYJSCIE"<<endl;
    cout << "========================================" << endl;
    while(!start)
    {
        if(_kbhit())
            {
            char klawisz = _getch();

            if(klawisz == 13)
            {
                start = true;
            }
            else if(klawisz == 27)
            {
                chceGrac = false;
                break;
            }
            }
    }
    
        system("cls"); // czysci tekst startowy
        kaktusX[0] = 25;
        //kaktusX[1] = 45;
        //kaktusX[2] = 65;
        //kaktusX[3] = 85;
        //kaktusX[4] = 105;
        for(int i=1;i<MAXKAKTUSOW;i++){
            int odstep=rand() % (MAXODSTEP-MINODSTEP+1)+MINODSTEP;
            kaktusX[i]=kaktusX[i-1]+odstep;
        }
        for (int i=0;i<MAXCHMUREK;i++){
            chmurkaX[i]=15+i*10;
            chmurkaY[i]=2+rand() % 3;
        }

        dinoX = 4;
        dinoY = 8;

        GRA = true;
        skacze = false;
        licznikSkoku = 0;
        poziom = 1;
        predkosc = 150;
        wynik = 0;
        for(int i = 0; i < MAXKAKTUSOW; i++)
        {
            do
            {
                kaktusWysokosc[i] = rand() % 2 + 1;
                kaktusSzerokosc[i] = rand() % 2 + 1;
            }
            while(kaktusWysokosc[i] == 2 && kaktusSzerokosc[i] == 2);
        }

        while (GRA){
            
            
            COORD pozycja;
            pozycja.X = 0;
            pozycja.Y = 0;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pozycja); // czysci plansze
            cout<<"Punkty: "<<wynik<<"  Poziom: "<<poziom;

            
            for(int y=0;y<10;y++){
            
            for(int x=0;x<50;x++){
                plansza[y][x]=' ';  //rysowanie planszy
            }
        }
            for(int x=0;x<50;x++){
            plansza[9][x]='=';
        }
            plansza[dinoY][dinoX]='O'; 

            
            for(int i = 0; i < MAXKAKTUSOW; i++)    //rysowanie kaktusa
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
        for (int i=0;i<MAXCHMUREK;i++){
            for (int x=0;x<3;x++){
                int X=chmurkaX[i]+x;
                if(X>=0 && X<50){
                    plansza[chmurkaY[i]][X]='~';
                }
            }
        }

            for(int y=0;y<10;y++){ //rysowanie planszy
            cout << y;
            for(int x=0;x<50;x++){
                cout <<plansza[y][x];
                
            }
            cout << endl;
            }   
            
            for(int i = 0; i < MAXKAKTUSOW; i++) //system kolizji
            {
            bool kolizjaX =
                dinoX >= kaktusX[i] &&  dinoX < kaktusX[i] + kaktusSzerokosc[i];
                

            bool kolizjaY =
                dinoY >= 8 - kaktusWysokosc[i] &&   dinoY <= 8;
                

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
            for(int i = 0; i < MAXCHMUREK; i++)
            {
                chmurkaX[i]--;

                if(chmurkaX[i] < -3)
                {
                    chmurkaX[i] = 50 + rand() % 20;
                    chmurkaY[i] = 2 + rand() % 3;
                }
            }

            for(int i = 0; i < MAXKAKTUSOW; i++)
            {
                kaktusX[i]--;

                if(kaktusX[i] < -2)
                {
                    int najdalszyKaktus = kaktusX[0];

                    for(int j = 1; j < MAXKAKTUSOW; j++)
                    {
                        if(kaktusX[j] > najdalszyKaktus)
                        {
                            najdalszyKaktus = kaktusX[j];
                        }
                    }

                    int odstep = rand() % (MAXODSTEP - MINODSTEP + 1)  + MINODSTEP;
                                

                    kaktusX[i] = najdalszyKaktus + odstep;

                    do
                    {
                        kaktusWysokosc[i] = rand() % 2 + 1;
                        kaktusSzerokosc[i] = rand() % 2 + 1;
                    }
                    while(kaktusWysokosc[i] == 2 && kaktusSzerokosc[i] == 2);
                }
            }
            
            
            wynik +=10 ;

            if(wynik < 500)
            {
                poziom = 1;
            }
            else if(wynik < 1500)
            {
                poziom = 2;
            }
            else if(wynik < 4500)
            {
                poziom = 3;
            }
            else if(wynik < 10000)
            {
                poziom = 4;
            }
            else if(wynik < 25000)
            {
                poziom = 5;
            }
            else
            {
                poziom = 6;
            }

            predkosc = 150 - (poziom - 1) * 15;

            if(predkosc < 75)
            {
                predkosc = 75;
            }
            
            
            Sleep(predkosc);//czeka 

            cout << endl;
            
            
        }
        system("cls");
        if (wynik>Najelpszywynik){
            Najelpszywynik=wynik;
        }
        cout << "==============================" << endl;
        cout << "          GAME OVER" << endl;
        cout << "       Wynik: " << wynik << endl;
        cout << "       Rekord: "<<Najelpszywynik<<endl;
        cout << endl;
        cout << "   ENTER - zagraj ponownie" << endl;
        cout << "   ESC   - wyjdz" << endl;
        cout << "==============================" << endl;

    
    while(true)
    {
        if(_kbhit())
        {
            char klawisz = _getch();

            // ENTER = ponowna gra
            if(klawisz == 13)
            {
                break;
            }


            // ESC = wyjście
            if(klawisz == 27)
            {
                chceGrac = false;
                break;
            }
        }
    }


}
}