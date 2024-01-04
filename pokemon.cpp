#include <iostream>
#include "pokemon.h"
#include <cstdlib>
#include <fstream>
#include <string>
#include <algorithm>
#include <windows.h>
#include <time.h>
#include "przeciwnik/przeciwnik.h"


using namespace std;

Pokemon::Pokemon()
{
}

void Pokemon::tworzenie()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
    printf(R"EOF(                                  ,'\
    _.----.        ____         ,'  _\   ___    ___     ____
_,-'       `.     |    |  /`.   \,-'    |   \  /   |   |    \  |`.
\      __    \    '-.  | /   `.  ___    |    \/    |   '-.   \ |  |
 \.    \ \   |  __  |  |/    ,','_  `.  |          | __  |    \|  |
   \    \/   /,' _`.|      ,' / / / /   |          ,' _`.|     |  |
    \     ,-'/  /   \    ,'   | \/ / ,`.|         /  /   \  |     |
     \    \ |   \_/  |   `-.  \    `'  /|  |    ||   \_/  | |\    |
      \    \ \      /       `-.`.___,-' |  |\  /| \      /  | |   |
       \    \ `.__,'|  |`-._    `|      |__| \/ |  `.__,'|  | |   |
        \_.-'       |__|    `-._ |              '-.|     '-.| |   |
                                `'                            '-._|)EOF");
    cout<<endl;
    string tekst = "  Wybierz swojego startowego pokemona!";
    transform(tekst.begin(), tekst.end(), tekst.begin(), ::toupper);
    cout<<".-------------------------------------------------------------------.\n";
    printf("%s\n", tekst.c_str());
    cout<<".-------------------------------------------------------------------.\n";
    cout<<"| 1. Bulbasaur                                                      |\n";
    cout<<"| 2. Squirtle                                                       |\n";
    cout<<"| 3. Charmander                                                     |\n";
    cout<<"'-------------------------------------------------------------------'\n";
    cout<<"Odpowiedz: ";
    int wybor;
    cin>>wybor;
    srand(time(NULL));
    switch(wybor)
    {
    case 1:
        cout<<".-------------------.\n";
        cout<<"|Wybrales BULBASAURA|\n";
        cout<<"'-------------------'\n";
        nazwa = "BULBASAUR";
        rodzaj = "TRAWIASTY";
        cp = rand()%1115+11; //minimalne cp = 10
        nr = 1;
        hp = rand()%74+10; //hp
        break;
    case 2:
        cout<<".-----------------.\n";
        cout<<"|Wybrales SQUIRTLA|\n";
        cout<<"'-----------------'\n";
        nazwa = "SQUIRTLE";
        rodzaj = "WODNY";
        cp = rand()%946+11;
        nr = 2;
        hp = rand()%72+10;
        break;
    case 3:
        cout<<".--------------------.\n";
        cout<<"|Wybrales CHARMANDERA|\n";
        cout<<"'--------------------'\n";
        nazwa = "CHARMANDER";
        rodzaj = "OGNISTY";
        cp = rand()%980+11;
        nr = 3;
        hp = rand()%65+9;
        break;
    }
    iv = rand()%101; //iv min = 0 max = 100
    evo = 0;
    exp = 0;
    zapis();
    cout<<"Kliknij ENTER aby przejsc do menu\n";
    getchar();
    getchar();
    menu();
}

void Pokemon::menu()
{
    system("cls");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
    cout<<".-------------------------------------------------------------------.\n";
    cout<<"                             MENU\n";
    cout<<".-------------------------------------------------------------------.\n";
    cout<<"| 1. Wybierz nowego pokemona startowego                             |\n";
    cout<<"| 2. Zobacz informacje o swoim pokemonie                            |\n";
    cout<<"| 3. Walcz!                                                         |\n";
    cout<<"| 4. Wyjdz z programu                                               |\n";
    cout<<"'-------------------------------------------------------------------'\n";
    cout<<"Odpowiedz: ";
    int wybor;
    cin>>wybor;
    switch(wybor)
    {
    case 1:
        cout<<"Napewno chcesz zmienic swojego pokemona startowego (usunie to wszystkie jego ewolucje)?\n";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
        cout<<"1. Tak\n";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
        cout<<"2. Nie\n";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
        cout<<"Odpowiedz: ";
        int wybor2;
        cin>>wybor2;
        switch(wybor2)
        {
        case 1:
            system("cls");
            tworzenie();
            break;
        case 2:
            system("cls");
            menu();
            break;
        }
        break;
    case 2:
        info();
        break;
    case 3:
        system("cls");
        walka();
        break;
    case 4:
        break;
    default:
        system("cls");
        cout << "ERROR!!\n";
        break;
    }
}

void Pokemon::sprawdz() //sprawdza czy w pliku jest zadeklarowany pokemon
{
    //otwarcie pliku
    fstream plik;
    plik.open("txt/pokemon.txt", ios::in);
    if(plik.good()==false)
    {
        cout<<"Nie udalo sie otworzyc pliku, skopiuj plik o nazwie szablon.txt i zmien jego nazwe na pokemon.txt"<<endl;
        getchar();
        exit(0);
    }
    //false - nie zostal przypisany
    //true - zostal przypisany
    string linia;
    getline(plik, linia);
    if(linia == "false")
    {
        cout<<"Nie wybrales jeszcze swojego pokemona"<<endl<<endl;
        tworzenie();
    }
    else if(linia == "true")
    {
        odczyt();
    }
    plik.close(); //zamyka plik
}

void Pokemon::odczyt()
{
    fstream plik;
    plik.open("txt/pokemon.txt", ios::in);
    if(plik.good()==false)
    {
        cout<<"Nie udalo sie otworzyc pliku, skopiuj plik o nazwie szablon.txt i zmien jego nazwe na pokemon.txt"<<endl;
        exit(0);
    }
    string linia;
    getline(plik, linia);

    getline(plik, linia);
    nazwa = linia;

    getline(plik, linia);
    rodzaj = linia;

    getline(plik, linia);
    cp = atoi(linia.c_str());

    getline(plik, linia);
    iv = atoi(linia.c_str());

    getline(plik, linia);
    hp = atoi(linia.c_str());

    getline(plik, linia);
    nr = atoi(linia.c_str());

		getline(plik, linia);
    exp = atoi(linia.c_str());

    getline(plik, linia);
    evo = atoi(linia.c_str());

    plik.close();
    menu();
}

void Pokemon::zapis()
{
    fstream plik;
    plik.open("txt/pokemon.txt", ios::out);
    plik<<"true"<<endl;
    plik<<nazwa<<endl;
    plik<<rodzaj<<endl;
    plik<<cp<<endl;
    plik<<iv<<endl;
    plik<<hp<<endl;
    plik<<nr<<endl;
    plik<<exp<<endl;
    plik<<evo<<endl;
    plik.close();
}



void Pokemon::info()
{
    cout<<"Nazwa: "<<nazwa<<endl;
    cout<<"Rodzaj: "<<rodzaj<<endl;
    cout<<"CP: "<<cp<<endl;
    cout<<"IV: "<<iv<<endl;
    cout<<"HP: "<<hp<<endl;
    cout<<"EXP: "<<exp<<endl;
    ewo();
    cout<<"Ewolucja: ";
    if(evo == 0) cout<<"Nie ma zadnej ewolucji\n";
    else if (evo == 1) cout<<"Ma juz pierwsza ewolucje!";
    else if (evo == 2) cout<<"Ma ostatnia ewolucje";
    cout<<"Wyglad:"<<endl;
    wyglad();
    cout<<"\nKliknij ENTER aby przejsc do menu\n";
    getchar();
    getchar();
    menu();
}

void Pokemon::wyglad()
{
    switch(nr)
    {
    case 1:
        cout<<endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
        printf(R"EOF(                                  ,'\
                                           /
                        _,.------....___,.' ',.-.
                     ,-'          _,.--"        |
                   ,'         _.-'              .
                  /   ,     ,'                   `
                 .   /     /                     ``.
                 |  |     .                       \.\
       ____      |___._.  |       __               \ `.
     .'    `---""       ``"-.--"'`  \               .  \
    .  ,            __               `              |   .
    `,'         ,-"'  .               \             |    L
   ,'          '    _.'                -._          /    |
  ,`-.    ,".   `--'                      >.      ,'     |
 . .'\'   `-'       __    ,  ,-.         /  `.__.-      ,'
 ||:, .           ,'  ;  /  / \ `        `.    .      .'/
 j|:D  \          `--'  ' ,'_  . .         `.__, \   , /
/ L:_  |                 .  "' :_;                `.'.'
.    ""'                  """""'                    V
 `.                                 .    `.   _,..  `
   `,_   .    .                _,-'/    .. `,'   __  `
    ) \`._        ___....----"'  ,'   .'  \ |   '  \  .
   /   `. "`-.--"'         _,' ,'     `---' |    `./  |
  .   _  `""'--.._____..--"   ,             '         |
  | ." `. `-.                /-.           /          ,
  | `._.'    `,_            ;  /         ,'          .
 .'          /| `-.        . ,'         ,           ,
 '-.__ __ _,','    '`-..___;-...__   ,.'\ ____.___.'
 `"^--'..'   '-`-^-'"--    `-^-'`.''"""""`.,^.`.--' )EOF");
        break;
    case 2:
        cout<<endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
        printf(R"EOF(               _,........__
            ,-'            "`-.
          ,'                   `-.
        ,'                        \
      ,'                           .
      .'\               ,"".       `
     ._.'|             / |  `       \
     |   |            `-.'  ||       `.
     |   |            '-._,'||       | \
     .`.,'             `..,'.'       , |`-.
     l                       .'`.  _/  |   `.
     `-.._'-   ,          _ _'   -" \  .     `
`."""""'-.`-...,---------','         `. `....__.
.'        `"-..___      __,'\          \  \     \
\_ .          |   `""""'    `.           . \     \
  `.          |              `.          |  .     L
    `.        |`--...________.'.        j   |     |
      `._    .'      |          `.     .|   ,     |
         `--,\       .            `7""' |  ,      |
            ` `      `            /     |  |      |    _,-'"""`-.
             \ `.     .          /      |  '      |  ,'          `.
              \  v.__  .        '       .   \    /| /              \
               \/    `""\"""""""`.       \   \  /.''                |
                `        .        `._ ___,j.  `/ .-       ,---.     |
                ,`-.      \         ."     `.  |/        j     `    |
               /    `.     \       /         \ /         |     /    j
              |       `-.   7-.._ .          |"          '         /
              |          `./_    `|          |            .     _,'
              `.           / `----|          |-............`---'
                \          \      |          |
               ,'           )     `.         |
                7____,,..--'      /          |
                                  `---.__,--.')EOF");
        break;
    case 3:
        cout<<endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
        printf(R"EOF(              _.--""`-..
            ,'          `.
          ,'          __  `.
         /|          " __   \
        , |           / |.   .
        |,'          !_.'|   |
      ,'             '   |   |
     /              |`--'|   |
    |                `---'   |
     .   ,                   |                       ,".
      ._     '           _'  |                    , ' \ `
  `.. `.`-...___,...---""    |       __,.        ,`"   L,|
  |, `- .`._        _,-,.'   .  __.-'-. /        .   ,    \
-:..     `. `-..--_.,.<       `"      / `.        `-/ |   .
  `,         """"'     `.              ,'         |   |  ',,
    `.      '            '            /          '    |'. |/
      `.   |              \       _,-'           |       ''
        `._'               \   '"\                .      |
           |                '     \                `._  ,'
           |                 '     \                 .'|
           |                 .      \                | |
           |                 |       L              ,' |
           `                 |       |             /   '
            \                |       |           ,'   /
          ,' \               |  _.._ ,-..___,..-'    ,'
         /     .             .      `!             ,j'
        /       `.          /        .           .'/
       .          `.       /         |        _.'.'
        `.          7`'---'          |------"'_.'
       _,.`,_     _'                ,''-----"'
   _,-_    '       `.     .'      ,\
   -" /`.         _,'     | _  _  _.|
    ""--'---"""""'        `' '! |! /
                            `" " -' )EOF");
        break;
    }
}

void Pokemon::walka()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
    cout<<".-------------------------------------------------------------------.\n";
    cout<<"                            WALKA\n";
    cout<<".-------------------------------------------------------------------.\n";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
    cout<<"\n.-------------------------------------------------------------------.\n";
    cout<<"                          "<<this->nazwa<<endl;
    cout<<".-------------------------------------------------------------------.\n";
    Pokemon::wyglad();
    Przeciwnik p1;
    p1.losowanie();
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
    cout<<"\nKliknij dowolny przycisk aby przejsc dalej\n";
    getchar();
    getchar();
    system("cls");

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
    cout<<".-------------------------------------------------------------------.\n";
    cout<<"                          WALCZY Z\n";
    cout<<".-------------------------------------------------------------------.\n";

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);

    cout<<".-------------------------------------------------------------------.\n";
    cout<<"                          "<<p1.nazwa<<endl;
    cout<<"                          "<<p1.hp<<" HP"<<endl;
    cout<<"'-------------------------------------------------------------------'\n";

    p1.wyglad();
    string nazw=this->nazwa;
    int hp =this->hp;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
    cout<<"\nKliknij dowolny przycisk aby przejsc dalej\n";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
    getchar();
    system("cls");
    int wygrana=0;
    int exp_ww = p1.hp;
    p1.walka(nazw, hp, &wygrana);
		int exp_wp = p1.hp;
		if(wygrana==1) //przegrana
    {
				exp+=this->hp-exp_wp;
				zapis();
				cout<<endl<<this->nazwa<<" zdobyl "<<this->hp-exp_wp<<" exp\n";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
        cout<<"\nKliknij dowolny przycisk aby przejsc dalej\n";
        getchar();
        system("cls");
        menu();
		}else if(wygrana==2) //wygrana
    {
				exp+=exp_ww;
				zapis();
				cout<<endl<<this->nazwa<<" zdobyl "<<exp_ww<<" exp\n";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
        cout<<"\nKliknij dowolny przycisk aby przejsc dalej\n";
        getchar();
        system("cls");
        menu();
    }
}

void Pokemon::ewo()
{
	if(exp>300)
	{
		cout<<"EWOLUUWUJ TERAZ!!! *a potem dalej FARM*"<<endl;
	}
	else
	{
		cout<<"Brakuje ci: "<<300-exp<<" exp do EWOLUCJI! FARMIC a nie sie lenic, FARMA FARMA!!"<<endl;
	}
}
