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
char przeszkoda='#';
int wynik=0;

int przeszkodaX=25;
int przeszkodaY=8;
int przeszkodaWysokosc = 3;

bool GRA =false;
bool start=false;
bool skacze=false;
bool chceGrac=true;
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
while(chceGrac){
    dinoX = 4;
    dinoY = 8;

    przeszkodaX = 49;
    przeszkodaY = 8;

    GRA = true;
    skacze = false;
    licznikSkoku = 0;
    wynik = 0;


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

        
        for (int y=0; y<przeszkodaWysokosc;y++){
            plansza[8-y][przeszkodaX]='#';
        }
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
            przeszkodaWysokosc = rand() % 3 + 1; // losowanie wysokosci kaktusa (od 1 do 3)
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
            break;
            
            
            
            
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