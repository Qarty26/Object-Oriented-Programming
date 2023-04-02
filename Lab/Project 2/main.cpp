#include <iostream>
#include <vector>
#include <conio.h>
#include <fstream>
#include <windows.h>
using namespace std;

class Sports{

private:
const int IdSport;

protected:
static int contorIdS;
string sportName;
bool requireBall;
int year;
int noMinOfParticipants;

public:

///------------------------------------Constructors----------------------------------------------
Sports():IdSport(contorIdS++){
    sportName="Unknown name";
    requireBall=false;
    year=-1;
    noMinOfParticipants=-1;
}

Sports(string sportName,bool requireBall,int year, int noMinOfParticipants):IdSport(contorIdS++){
    this->sportName=sportName;
    this->requireBall=requireBall;
    this->year=year;
    this->noMinOfParticipants=noMinOfParticipants;
}
///--------------------------------------Functions------------------------------------------------
void printSport()
{
    cout<<"Id: "<<IdSport<<endl;
    cout<<"Sport name: "<<sportName<<endl;
    cout<<"Ball required: ";
    if (requireBall==true)
        cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    cout<<"First played in: "<<year<<endl;
    cout<<"Minimum number of participants: "<<noMinOfParticipants<<endl;
}
///-------------------------------------Read-and-print---------------------------------------------



friend istream& operator>>(istream& in, Sports &obj);
friend ostream& operator<<(ostream& out, const Sports &obj);

};

istream& operator >>(istream& in, Sports &obj)
{
    cout<<"Sport name: ";
    in>>obj.sportName;
    cout<<"Ball required: ";
    in>>obj.requireBall;
    cout<<"First played in: ";
    in>>obj.year;
    cout<<"Minimum number of participants: ";
    in>>obj.noMinOfParticipants;

    return in;
}

ostream& operator <<(ostream& out,const Sports &obj)
{

    out<<"Id: "<<obj.IdSport<<endl;
    out<<"Sport name: "<<obj.sportName<<endl;
    out<<"Ball required: ";
    if (obj.requireBall==true)
        out<<"Yes"<<endl;
    else out<<"No"<<endl;
    out<<"First played in: "<<obj.year<<endl;
    out<<"Minimum number of participants: "<<obj.noMinOfParticipants<<endl;


    return out;
}
int Sports::contorIdS=1;
///__________________________FINISH_SPORTS_____________________________________


class BallSport:public Sports
{

    const int idBallSport;

protected:

    const bool requireBallPerm=true;
    static int contorIdBS;
    string ballType;
    bool armsUsed;
    bool legsUsed;


public:


///-----------------------------CONSTRUCTORI--------------------------------------
BallSport():idBallSport(contorIdBS++)
{
    Sports();
    requireBall=true;
    ballType="Unsigned type";
    armsUsed=false;
    legsUsed=false;
}

BallSport(string sportName,int year,int noMinOfParticipants,string ballType,bool armsUsed,bool legsUsed):idBallSport(contorIdBS++)
{
    Sports(sportName,true,year,noMinOfParticipants);
    this->ballType=ballType;
    this->armsUsed=armsUsed;
    this->legsUsed=legsUsed;
}
///---------------------------------------FUNCTII------------------------------------------------------
void afisareBallSport()
{
    cout<<"Id: "<<idBallSport<<endl;
    cout<<"Sport name: "<<sportName<<endl;
    cout<<"Ball required: ";
    if (requireBallPerm==true)
        cout<<"Yes"<<endl;
    else cout<<"No"<<endl;

    cout<<"First played in: "<<year<<endl;
    cout<<"Minimum number of participants: "<<noMinOfParticipants<<endl;

    cout<<"Ball type: "<<ballType<<endl;
    cout<<"Played with arms: ";
    if (armsUsed==true)
        cout<<"Yes"<<endl;
    else cout<<"No"<<endl;

    cout<<"Played with legs: ";
    if (legsUsed==true)
        cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}

void afisarePlaygroud(char playground[100][100],int n,int m)
{
    system("CLS");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            cout<<playground[i][j];
        cout<<endl;
    }
}


void football()
{

    char playground[100][100],bck,playerMove,test;
    int n,m,i,j,choice;
    int playerX,playerY,ballX,ballY;

    cout<<"Today you will be a football player training for a match"<<endl;
    cout<<"The goal is to avoid all the obstacles maked with 8 and score the goal"<<endl;
    cout<<"You move with WASD, SPACE will make you throw the ball"<<endl;
    cout<<"Hint: places marked with X make you lose the ball and lose the training session. You can still run with your character through it."<<endl;


        ifstream in("map1.in");




    in>>n;
    in>>m;
    in>>playerX;
    in>>playerY;
    in>>ballX;
    in>>ballY;
    in>>noskipws;
    in>>bck;

    for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                in>>playground[i][j];
            }
            in>>bck;
        }


    cout<<endl<<"Press any key to start!"<<endl;
    test=getch();
    afisarePlaygroud(playground,n,m);





    while(playerMove!='0')
    {
        playerMove=getch();
        switch(playerMove)
        {
            case 'w':
                {
                    playground[playerX][playerY]='^';

                    if(playground[playerX-1][playerY]!='8')
                    {
                        if(playground[playerX-1][playerY]=='O')
                        {
                            if(playground[playerX-2][playerY]!='8' && playground[playerX-2][playerY]!='#' && playground[playerX-2][playerY]!='-')
                            {
                                ballX--;
                                playground[ballX][ballY]='O';
                                playground[playerX][playerY]=' ';
                                playerX--;
                                playground[playerX][playerY]='^';
                            }
                        }
                        else
                        {
                            playground[playerX][playerY]=' ';
                            playerX--;
                            playground[playerX][playerY]='^';
                        }
                    }
                    afisarePlaygroud(playground,n,m);
                    break;
                }
            case 's':
                {
                    playground[playerX][playerY]='v';

                    if(playground[playerX+1][playerY]!='8')
                    {
                        if(playground[playerX+1][playerY]=='O')
                        {
                            if(playground[playerX+2][playerY]!='8' && playground[playerX+2][playerY]!='#'&& playground[playerX+2][playerY]!='-')
                            {
                                ballX++;
                                playground[ballX][ballY]='O';
                                playground[playerX][playerY]=' ';
                                playerX++;
                                playground[playerX][playerY]='v';
                            }
                        }
                        else
                        {
                            playground[playerX][playerY]=' ';
                            playerX++;
                            playground[playerX][playerY]='v';
                        }
                    }
                    afisarePlaygroud(playground,n,m);
                    break;
                }
            case 'd':
                {
                    playground[playerX][playerY]='>';

                    if(playground[playerX][playerY+1]!='8')
                    {
                        if(playground[playerX][playerY+1]=='O')
                        {
                            if(playground[playerX][playerY+2]!='8' && playground[playerX][playerY+2]!='#'&& playground[playerX][playerY+2]!='-')
                            {
                                if(playground[playerX][playerY+2]=='|')
                                {

                                    playground[playerX][playerY]=' ';
                                    playerY++;
                                    playground[playerX][playerY]='>';
                                    ballY++;
                                    playground[ballX][ballY]='O';
                                    afisarePlaygroud(playground,n,m);
                                    cout<<"MESSI MESSI MESSI MESSI MESSI MESSI MESSI"<<endl;
                                    cout<<"ANKARA MESSI ANKARA MESSI ANKARA MESSI ANKARA MESSI"<<endl;
                                    cout<<endl<<"GOL GOL GOL GOL GOL GOL GOL GOL GOL GOL GOL GOL GOL GOl"<<endl;

                                    cout<<endl<<"Do you want to play again?(0/1) ";
                                    cin>>choice;
                                    if(choice==0)
                                    {
                                        playerMove='0';
                                        in.close();
                                        break;
                                    }
                                    else
                                    {
                                        system("CLS");
                                        football();
                                    }


                                }
                                    playground[playerX][playerY]=' ';
                                    playerY++;
                                    playground[playerX][playerY]='>';
                                    ballY++;
                                    playground[ballX][ballY]='O';
                            }
                        }
                        else
                        {
                            playground[playerX][playerY]=' ';
                            playerY++;
                            playground[playerX][playerY]='>';
                        }
                    }
                    afisarePlaygroud(playground,n,m);
                    break;
                }
            case 'a':
                {
                    playground[playerX][playerY]='<';

                    if(playground[playerX][playerY-1]!='8')
                    {
                        if(playground[playerX][playerY-1]=='O')
                        {
                            if(playground[playerX][playerY-2]!='8' && playground[playerX][playerY-2]!='#' && playground[playerX][playerY-2]!='-')
                            {
                                ballY--;
                                playground[ballX][ballY]='O';
                                playground[playerX][playerY]=' ';
                                playerY--;
                                playground[playerX][playerY]='<';
                            }
                        }
                        else
                        {
                            playground[playerX][playerY]=' ';
                            playerY--;
                            playground[playerX][playerY]='<';
                        }
                    }
                    afisarePlaygroud(playground,n,m);
                    break;
                }
            case ' ':
                {
                    if(playground[playerX][playerY]=='>' && playground[playerX][playerY+1]=='O')
                    {
                        if(playground[playerX][playerY+3]!='#' && playground[playerX][playerY+3]!='8' && playground[playerX][playerY+3]!='-')
                        {
                            playground[playerX][playerY+1]=' ';
                            playground[playerX][playerY+3]='O';
                            ballY+=2;
                            afisarePlaygroud(playground,n,m);
                        }
                        else if(playground[playerX][playerY+2]!='#' && playground[playerX][playerY+2]!='8' && playground[playerX][playerY+2]!='-')
                        {
                            playground[playerX][playerY+1]=' ';
                            playground[playerX][playerY+2]='O';
                            ballY+=1;
                            afisarePlaygroud(playground,n,m);
                        }
                    }


                    if(playground[playerX][playerY]=='<' && playground[playerX][playerY-1]=='O')
                    {
                        if(playground[playerX][playerY-3]!='#' && playground[playerX][playerY-3]!='8' && playground[playerX][playerY-3]!='-')
                        {
                            playground[playerX][playerY-1]=' ';
                            playground[playerX][playerY-3]='O';
                            ballY-=2;
                            afisarePlaygroud(playground,n,m);
                        }
                        else if(playground[playerX][playerY-2]!='#' && playground[playerX][playerY-2]!='8' && playground[playerX][playerY-2]!='-')
                        {
                            playground[playerX][playerY-1]=' ';
                            playground[playerX][playerY-2]='O';
                            ballY-=1;
                            afisarePlaygroud(playground,n,m);
                        }
                    }


                    if(playground[playerX][playerY]=='^' && playground[playerX-1][playerY]=='O')
                    {
                        if(playground[playerX-3][playerY]!='#' && playground[playerX-3][playerY]!='8'  && playground[playerX-3][playerY]!='-')
                        {
                            playground[playerX-1][playerY]=' ';
                            playground[playerX-3][playerY]='O';
                            ballX-=2;
                            afisarePlaygroud(playground,n,m);
                        }
                        else if(playground[playerX-2][playerY]!='#' && playground[playerX-2][playerY]!='8'  && playground[playerX-2][playerY]!='-')
                        {
                            playground[playerX-1][playerY]=' ';
                            playground[playerX-2][playerY]='O';
                            ballX-=1;
                            afisarePlaygroud(playground,n,m);
                        }
                    }

                    if(playground[playerX][playerY]=='v' && playground[playerX+1][playerY]=='O')
                    {
                        if(playground[playerX+3][playerY]!='#' && playground[playerX+3][playerY]!='8' && playground[playerX+3][playerY]!='-')
                        {
                            playground[playerX+1][playerY]=' ';
                            playground[playerX+3][playerY]='O';
                            ballX+=2;
                            afisarePlaygroud(playground,n,m);
                        }
                        else if(playground[playerX+2][playerY]!='#' && playground[playerX+2][playerY]!='8' && playground[playerX+2][playerY]!='-')
                        {
                            playground[playerX+1][playerY]=' ';
                            playground[playerX+2][playerY]='O';
                            ballX+=1;
                            afisarePlaygroud(playground,n,m);
                        }
                    }
                }
        }
    }



}


///-------------------------------------Read-and-print---------------------------------------------

friend istream& operator>>(istream& in, BallSport &obj);
friend ostream& operator<<(ostream& out, const BallSport &obj);

};
istream& operator >>(istream& in, BallSport &obj)
{
    in>>(Sports&)obj;
    obj.requireBall=true;
    //---
    cout<<"Ball type: ";
    in>>obj.ballType;
    cout<<"Played with arms: ";
    in>>obj.armsUsed;
    cout<<"Played with legs: ";
    in>>obj.legsUsed;


    return in;
}

ostream& operator <<(ostream& out,const BallSport &obj)
{
    out<<(Sports&)obj;
    //---
    out<<"Ball type: "<<obj.ballType<<endl;
    out<<"Played with arms: ";
    if (obj.armsUsed==true)
        out<<"Yes"<<endl;
    else out<<"No"<<endl;

    out<<"Played with legs: ";
    if (obj.legsUsed==true)
        out<<"Yes"<<endl;
    else out<<"No"<<endl;

    return out;
}

int BallSport::contorIdBS=1;
///__________________________________FINISH_BALL-SPORTS_________________________________

class RacingSport:public Sports
{
    const int idRacingSport;

protected:

    const bool requireBallPerm2=false;
    static int contorIdRS;
    int noWheels;
    string surfaceType;
    string raceType; ///time attack, lap, sprint, drag, etc
    bool openWheel;


public:

///---------------------------------constructors--------------------------------------------------
RacingSport():idRacingSport(contorIdRS++)
{
    sportName="Unknown name";
    year=-1;
    noMinOfParticipants=-1;
    noWheels=-1;
    surfaceType="Unknown surface";
    raceType="Unknown type";
    openWheel=false;
}

RacingSport(string sportName,int year,int noMinOfParticipants,int noWheels,string surfaceType,string raceType,bool openWheel):idRacingSport(contorIdRS++)
{
    this->sportName=sportName;
    this->year=year;
    this->noMinOfParticipants=noMinOfParticipants;
    this->noWheels=noWheels;
    this->surfaceType=surfaceType;
    this->raceType=raceType;
    this->openWheel=openWheel;
}

///-----------------------------------functions--------------------------------------------

void afisareRacingSport()
{
    cout<<"Id: "<<idRacingSport<<endl;
    cout<<"Sport name: "<<sportName<<endl;
    cout<<"Ball required: ";
    if (requireBallPerm2==true)
        cout<<"Yes"<<endl;
    else cout<<"No"<<endl;

    cout<<"First played in: "<<year<<endl;
    cout<<"Minimum number of participants: "<<noMinOfParticipants<<endl;
    cout<<"Number of wheels: "<<noWheels<<endl;
    cout<<"Surface type: "<<surfaceType<<endl;
    cout<<"Race type: "<<raceType<<endl;
    cout<<"Open wheel: ";
    if (openWheel==true)
        cout<<"Yes"<<endl;
    else cout<<"No"<<endl;

}
friend istream& operator>>(istream& in, RacingSport &obj);
friend ostream& operator<<(ostream& out, const RacingSport &obj);

void afisareRacetrack(char racetrack[1000][1000],int n,int m,int player1X,int player1Y,int player2X,int player2Y)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            if(i==player1X && j==player1Y)
            {
                HANDLE  hConsole;
                hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(hConsole,9);
                cout<<racetrack[i][j];
                SetConsoleTextAttribute(hConsole,7);
            }
            else if(i==player2X && j==player2Y)
            {
                HANDLE  hConsole;
                hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(hConsole,4);
                cout<<racetrack[i][j];
                SetConsoleTextAttribute(hConsole,7);
            }
            else cout<<racetrack[i][j];
        cout<<endl;
    }
}

void race()
{
    int n,m,i,j;
    int player1X,player1Y,player2X,player2Y;
    int noLaps;
    bool runningRace=true;
    int laps1=0,laps2=0;
    char racetrack[1000][1000],test,underPlayer1,underPlayer2,choice;
    ifstream in("race1.in");

    cout<<"Welcome to the OOP-Ring!"<<endl;
    cout<<"Rules are simple, finish first..."<<endl;
    cout<<"Player 1 will move with WASD and Player 2 will use IJKL."<<endl;
    cout<<"The car will go towards the pointed direction, your only job is to guide it."<<endl;
    cout<<"Be careful to stay on track, going off-track will make you lose speed"<<endl;
    cout<<endl<<"Press any key to start!"<<endl;
    test=getch();
    system("CLS");


    in>>n>>m;
    in>>player1X>>player1Y;
    in>>player2X>>player2Y;
    in>>noLaps;
    noLaps=noLaps*2+1;
    in>>noskipws;
    in>>test;

    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
            in>>racetrack[i][j];
        in>>test;
    }


    underPlayer1=racetrack[player1X][player1Y];
    racetrack[player1X][player1Y]='>';

    underPlayer2=racetrack[player2X][player2Y];
    racetrack[player2X][player2Y]='>';

afisareRacetrack(racetrack,n,m,player1X,player1Y,player2X,player2Y);

while(laps1<=noLaps || laps2<=noLaps)
{
    while(laps1<=noLaps || laps2<=noLaps)
    {

        ///LOOP PLAYER 1
        if(laps1<=noLaps)
        {
            switch(racetrack[player1X][player1Y])
            {
                case '>':
                    {
                        if(player1X==player2X && player1Y+1==player2Y)
                            break;

                        racetrack[player1X][player1Y]=underPlayer1;
                        underPlayer1=racetrack[player1X][player1Y+1];
                        player1Y++;
                        racetrack[player1X][player1Y]='>';
                        break;

                    }
                case '<':
                    {
                        if(player1X==player2X && player1Y-1==player2Y)
                            break;

                        racetrack[player1X][player1Y]=underPlayer1;
                        underPlayer1=racetrack[player1X][player1Y-1];
                        player1Y--;
                        racetrack[player1X][player1Y]='<';
                        break;
                    }
                case '^':
                    {
                        if(player1Y==player2Y && player1X-1==player2X)
                            break;

                        racetrack[player1X][player1Y]=underPlayer1;
                        underPlayer1=racetrack[player1X-1][player1Y];
                        player1X--;
                        racetrack[player1X][player1Y]='^';
                        break;
                    }
                case 'v':
                    {
                        if(player1Y==player2Y && player1X+1==player2X)
                            break;

                        racetrack[player1X][player1Y]=underPlayer1;
                        underPlayer1=racetrack[player1X+1][player1Y];
                        player1X++;
                        racetrack[player1X][player1Y]='v';
                        break;

                    }
            }
        }


        ///LOOP PLAYER 2
        if(laps2<=noLaps)
        {
            switch(racetrack[player2X][player2Y])
            {
                case '>':
                    {
                        if(player1X==player2X && player2Y+1==player1Y)
                            break;

                        racetrack[player2X][player2Y]=underPlayer2;
                        underPlayer2=racetrack[player2X][player2Y+1];
                        player2Y++;
                        racetrack[player2X][player2Y]='>';
                        break;

                    }
                case '<':
                    {
                        if(player1X==player2X && player2Y-1==player1Y)
                            break;

                        racetrack[player2X][player2Y]=underPlayer2;
                        underPlayer2=racetrack[player2X][player2Y-1];
                        player2Y--;
                        racetrack[player2X][player2Y]='<';
                        break;


                    }
                case '^':
                    {
                        if(player1Y==player2Y && player2X-1==player1X)
                            break;

                        racetrack[player2X][player2Y]=underPlayer2;
                        underPlayer2=racetrack[player2X-1][player2Y];
                        player2X--;
                        racetrack[player2X][player2Y]='^';
                        break;

                    }
                case 'v':
                    {
                        if(player1Y==player2Y && player2X+1==player1X)
                            break;

                        racetrack[player2X][player2Y]=underPlayer2;
                        underPlayer2=racetrack[player2X+1][player2Y];
                        player2X++;
                        racetrack[player2X][player2Y]='v';

                        break;

                    }
            }
        }

        if(underPlayer1=='%')
        {
            laps1++;
        }

        if(underPlayer2=='%')
        {
            laps2++;
        }
        if(laps1==noLaps && laps2==noLaps)
            runningRace=false;
        system("CLS");
        afisareRacetrack(racetrack,n,m,player1X,player1Y,player2X,player2Y);
        if (_kbhit())
        {
            choice = _getch();
            if (choice == 'w' || choice == 'a' || choice == 's' || choice == 'd' || choice == 'i' || choice == 'j' || choice == 'k' || choice == 'l') {
                    break;
                }
        }

    }

    switch(choice)
    {
        case 'w':
            {
                racetrack[player1X][player1Y]='^';
                break;
            }
        case 'a':
            {
                racetrack[player1X][player1Y]='<';
                break;
            }
        case 's':
            {
                racetrack[player1X][player1Y]='v';
                break;
            }
        case 'd':
            {
                racetrack[player1X][player1Y]='>';
                break;
            }



        case 'i':
            {
                racetrack[player2X][player2Y]='^';
                break;
            }
        case 'j':
            {
                racetrack[player2X][player2Y]='<';
                break;
            }
        case 'k':
            {
                racetrack[player2X][player2Y]='v';
                break;
            }
        case 'l':
            {
                racetrack[player2X][player2Y]='>';
                break;
            }


    }
}





}
};

istream& operator >>(istream& in, RacingSport &obj)
{
    cout<<"Sport name: ";
    in>>obj.sportName;
    cout<<"First played in: ";
    in>>obj.year;
    cout<<"Minimum number of participants: ";
    in>>obj.noMinOfParticipants;
    //---
    cout<<"Number of wheels: ";
    in>>obj.noWheels;
    cout<<"Surface type: ";
    in>>obj.surfaceType;
    cout<<"Race type: ";
    in>>obj.raceType;
    cout<<"Open wheel: ";
    in>>obj.openWheel;
}

ostream& operator <<(ostream& out,const RacingSport &obj)
{
    out<<endl;
    out<<"Id: "<<obj.idRacingSport<<endl;
    out<<"Sport name: "<<obj.sportName<<endl;
    out<<"Ball required: ";
    if (obj.requireBallPerm2==true)
        out<<"Yes"<<endl;
    else out<<"No"<<endl;
    out<<"First played in: "<<obj.year<<endl;
    out<<"Minimum number of participants: "<<obj.noMinOfParticipants<<endl;
    //---
    out<<"Number of wheels: "<<obj.noWheels<<endl;
    out<<"Surface type: "<<obj.surfaceType<<endl;
    out<<"Race type: "<<obj.raceType<<endl;
    out<<"Open wheel: ";
    if (obj.openWheel==true)
        out<<"Yes"<<endl;
    else out<<"No"<<endl;
    out<<endl;

    return out;
}
int RacingSport::contorIdRS=1;

int main()
{
RacingSport r;

r.race();



    ///IDEI

    /*
    Main class: sport

    side class: racing sport
    side class: fotbal

    bottom class: fotbal cu masini

    */
    return 0;

}
