#include <iostream>
#include "przeciwnik.h"
#include <time.h>
#include <string>
#include <cstdlib>
#include <windows.h>
#include <fstream>
#include "../pokemon.h"
using namespace std;

Przeciwnik::Przeciwnik()
{}

void Przeciwnik::losowanie()
{
    string tab[3];
    tab[0]="RATTATATA";
    tab[1]="MR. MIME";
    tab[2]="PDGEY";
    srand(time(NULL));
		nr = rand()%3;
    nazwa = tab[nr];
    nr++;
		hp=rand()%80+21;
}

void Przeciwnik::wyglad()
{
    switch(nr)
    {
    case 1: //rattata
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
        printf(R"EOF(                                      ,'""`--.
                                     |     __ `-.
                                     |    /  `.  `.
                                      \        ,   `.
                                       `.      \_    `.
                                         `.    | `.    \
                                           `--"    `.   `
                                                     `.  `
                 ,.._                                  \  `
               /_,.  `.                                 \  `
              j/   .   \                  ___            \  \
              |    |   `____         _,--'   `.           .  L
               L  /`--"'    `'--._ ,'   ,-`'\ |            . |
                |-                /  ,''     ||            | |
     -v._      /                   ,'        ||            | |
       `.`-._,'               _     \        |j    _,...   | |
         `,.'             _,-. \     |      /,---""     `- | |
        .'              ,".   ||     `..___/,'            `' |
        |   ,         _/`-'  /,'                            `|
        |-.__.-'"''""' """"""""--`_,...-----''''--...--      `.
         `.____,..              ""   __,..---"""              |
          |       `              --"'.                        `
          |     ,' `._                \'                       `
          | |  .^.    `.             /                          `.
         ,'_]__|  \   / `.          /          /____._            `._
       ,'          \ j    '        /          /       `.             `.
 ___,.' `._       __L/    |     __'          /     _, / \             |
`-._       L,.-"""  .    ,' _.-','          /-----'-./   `--.         |
   '   / ,'         '..'"_,'    /          /  ."'_,'        |.__     '
  / ,.\,'              ""      /         / ,'\ .'        ,.-"'  `.  j
  -'   '                      /        ,'     `"         / __/' .- ,'
                           __.'"`.    /                 `-' | _,L,'
                         .',      `""'                      '/,--
                          / _..' _,,'
                          ,' `-"' )EOF");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
        break;
    case 2: //mr mime
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
        printf(R"EOF(               ,---.    ___
               |(__)| .',-.`.
               `.  j  | \.'.'
               _'  `"'  ,-'___
             ,"         `"',--.\                     _..--.
             |           __`..''                _,.-'      `-.
   ,-""'`-.. '          (  `""'         _...--"'        ,.--..'
 ,'        .' `._____  ,.`-..--"""'----.               /
/   _..._,'   ."     \ `..'|            `.        ___.'
'.-"  .'    ,'        '---"               `.     /
     |    .'.._     ,'                      `.  /
      \   `    `._ /      |  !    !  |        |"
       `.  `.     |   __  |          j  ,--. _|..._
         \   `.""""-.'  `. '           /  ,'"      `-.
          `.   `.    `.  |   _____|   |  /            `.
          |`....'     |_,'   `.   '    `.              |
          |           |---....____....-"`        .--.  '
           .         ,'                  `..._  (    `'
            `--..,.-'      _.--"""'"'.   |,"".`. ,--.. \
                 |       ,'       ."""`. ``-" | |(__)|  `.
                 |      .         |(__) `-'   '"   ,"     |
                / `     |          `--.          .'_,..-"'
               /   `._   ._       ."""`-         ||
               '..._  `._  `-.... (__) __    _.','
              ,'    `.   `---.....`..-"'  `"'"_,".
         ,-""`. _.---+..-'            `"---+-'   `
        /      `.                       ." , \    \
        ._    ,--.                     |  |  |.    \
         _:--'    `.                   |  `._| `..-|
     ,-'"  `.    .' |                  '    `"--...'-.
    .        `""'_.-'                   `.           |
    |         ,-'                         `-.______,.'
    '.     _.'
      `---' )EOF");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
        break;
    case 3: //pidgey
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
        printf(R"EOF(                   .,
            , _.-','
          ""|"    `"""".,
         /'/       __.-'-"/
        ','  _,--""      '-._
    _...`...'."""""".\""-----'
 ,-'          `-.) /  `.  \
+---."-.    |     `.    .  \
     \  `.  |       \   |   L
      `v  ,-j        , .'   |
     .'\,' /        /,'      -._
    ,____.'        .            `-.
        |         /                `-.
       /          `.                  `-.
      /             `. |                 `.                  _.
     .                `|                 ,-.             _.-" .
    j                  |                 |  \         _.'    /
    .                  |               .'    \     ,-'      /
    |                  |            ,-.\      \  ,'      _.-
    |                . '  `.       |   `      `v'  _,.-"/
    ||    \          |  ` |(`'-`.,.j         \ `.-'----+---.
    |'|   |L    \  | |   `|   \'              L \___      /
    ' L   |`     L | |     `.                 | j   `"""-'
       `-'||\    | ||j       `.       ._    ` '.
          `\ '"`^"- '          `.       \    |/|
            `._                  `-.     \   Y |
    __,..-""`..`._                  `-._  `\ `.|
   +.....>+----.' ""----.........,--""" `--.'.'
       ,' _\  ,..--.-"' __>---'  |
      --""  "'  _." }<""          `---""`._
               /..."  L__.+--   _,......'..'
                 /.-""'/   \ ,-'
                     .' ,-""'
                    /.-' )EOF");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
        break;
    }
}

void Przeciwnik::walka(string nazw, int hpp, int* wygrana)
{
		srand(time(NULL));
    int tura=rand()%2;
    if(tura%2==0)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			cout<<"## "<<nazw<<" ZACZYNA ##\n";
		}
    else if(tura%2!=0)
    {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
			cout<<"## "<<this->nazwa<<" ZACZYNA ##\n";
    }
    do {
		tura++;
//		atak(tura, nazw, hpp);
		cout<<".-------------------------------------------------------------------.\n";
		if(atak(tura, nazw, &hpp)<=0) break;
		Sleep(100);
    }while(true);

    if(this->hp==0)
    {
			cout<<nazw<<" WYGRAL!!\n";
			*wygrana=2;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
			printf(R"EOF(     _______________
    |@@@@|     |####|
    |@@@@|     |####|
    |@@@@|     |####|
    \@@@@|     |####/
     \@@@|     |###/
      `@@|_____|##')EOF");
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
           printf(R"EOF(
           (O)
        .-'''''-.
      .'  * * *  `.
     :  *       *  :
    : ~  BRAWO!!  ~ :
    : ~ WYGRALES! ~ :
     :  *       *  :
      `.  * * *  .'
        `-.....-')EOF");
		}
		else if(this->hp>0)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			cout<<nazw<<" PRZEGRAL :(\n";
			*wygrana=1;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
			printf(R"EOF(       __..._   _...__
  _..-"      `Y`      "-._
  \PRZEGRALES | pouczyl   /
  \\  bys sie | czy cos  //
  \\\         |         ///
   \\\ _..---.|.---.._ ///
    \\`_..---.Y.---.._`//
     '`               `')EOF");
		}
}

int Przeciwnik::atak(int tura, string nazw, int* hpp)
{
		if(tura%2==0) //przeciwnik bije pokemon traci zycie
		{
			att=rand()%11;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
			cout<<"->";
			if(att==0) cout<<this->nazwa<<" chybil, "<<nazw<<"OWI zostalo ";
			else if(att<=9) cout<<this->nazwa<<" zadaje "<<att<<" obrazen, "<<nazw<<"OWI zostalo ";
			else if(att==10) cout<<this->nazwa<<" trafia krytycznie, "<<nazw<<"OWI zostalo ";
			else cout<<this->nazwa<<" zadaje "<<att<<" obrazen, "<<nazw<<"OWI zostalo ";
			*hpp-=att;
			if(*hpp<0) *hpp=0;
			cout<<*hpp<<" zycia\n\n";
			return *hpp;
		}
    else if(tura%2!=0) //pokemon bije przeciwnik traci zycie
		{
			att=rand()%11;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			cout<<"<-";
			if(att==0) cout<<nazw<<" chybil, "<<this->nazwa<<"OWI zostalo ";
			else if(att<=9) cout<<nazw<<" zadaje "<<att<<" obrazen, "<<this->nazwa<<"OWI zostalo ";
			else if(att==10) cout<<nazw<<" trafia krytycznie, "<<this->nazwa<<"OWI zostalo ";
			else cout<<nazw<<" zadaje "<<att<<" obrazen, "<<this->nazwa<<"OWI zostalo ";
			this->hp-=att;
			if(this->hp<0) this->hp=0;
			cout<<this->hp<<" zycia\n\n";
			return this->hp;
    }
}
