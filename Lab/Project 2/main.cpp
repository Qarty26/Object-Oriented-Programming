#include <iostream>
#include <vector>
#include <conio.h>
#include <fstream>
#include <windows.h>
using namespace std;


class IOinterface{
public:
    virtual istream& citire(istream&) = 0;
    virtual ostream& afisare(ostream&) const = 0;
};


class Sports: public IOinterface{

protected:

const int IdSport;
static int contorIdS;
string sportName;
bool requireBall;
int year;
int noMinOfParticipants;

public:
///-----------------------------------Getter----------------------------------------------------
int GetId()
{
    return this->IdSport;
}
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

Sports(const Sports &obj):IdSport(obj.IdSport){
    this->sportName=obj.sportName;
    this->requireBall=obj.requireBall;
    this->year=obj.year;
    this->noMinOfParticipants=obj.noMinOfParticipants;
}
///------------------------------------Operator--------------------------------------------------
Sports& operator =(const Sports& obj)
{
    this->sportName=obj.sportName;
    this->requireBall=obj.requireBall;
    this->year=obj.year;
    this->noMinOfParticipants=obj.noMinOfParticipants;

    return *this;
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


istream& citire(istream& in)
{
    cout<<"Sport name: ";
    in>>this->sportName;
    cout<<"Ball required: ";
    in>>this->requireBall;
    cout<<"First played in: ";
    in>>this->year;
    cout<<"Minimum number of participants: ";
    in>>this->noMinOfParticipants;

    return in;
}

ostream& afisare (ostream& out) const{

    out<<"Id: "<<this->IdSport<<endl;
    out<<"Sport name: "<<this->sportName<<endl;
    out<<"Ball required: ";
    if (this->requireBall==true)
        out<<"Yes"<<endl;
    else out<<"No"<<endl;
    out<<"First played in: "<<this->year<<endl;
    out<<"Minimum number of participants: "<<this->noMinOfParticipants<<endl;

    return out;
}
///----------------------------------------Destructor--------------------------------------------------

~Sports(){

    sportName="";
    requireBall=false;
    year=0;
    noMinOfParticipants=0;

}

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
///__________________________FINISH_SPORTS________________________________________________________________________________________________________________________


class BallSport: virtual public Sports
{

protected:

    string ballType;
    bool armsUsed;
    bool legsUsed;


public:
///-----------------------------CONSTRUCTORI--------------------------------------
BallSport():Sports()
{
    requireBall=true;
    ballType="Unsigned type";
    armsUsed=false;
    legsUsed=false;
}

BallSport(string sportName,int year,int noMinOfParticipants,string ballType,bool armsUsed,bool legsUsed): Sports(sportName,true,year,noMinOfParticipants)
{
    this->ballType=ballType;
    this->armsUsed=armsUsed;
    this->legsUsed=legsUsed;
}

BallSport(const BallSport& obj):Sports(obj)
{
    this->ballType=obj.ballType;
    this->armsUsed=obj.armsUsed;
    this->legsUsed=obj.legsUsed;
}
///--------------------------------------Operator-----------------------------------------------------
BallSport& operator = (const BallSport &obj)
{
    if(this!=&obj)
    {
        Sports::operator=(obj);
        this->ballType=obj.ballType;
        this->armsUsed=obj.armsUsed;
        this->legsUsed=obj.legsUsed;
    }

    return *(this);
}
///---------------------------------------FUNCTII------------------------------------------------------
void afisareBallSport()
{
    cout<<"Id: "<<IdSport<<endl;
    cout<<"Sport name: "<<sportName<<endl;
    cout<<"Ball required: ";
    if (requireBall==true)
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

istream& citire(istream& in)
{
    Sports::citire(in);
    cout<<"Ball type: ";
    in>>this->ballType;
    cout<<"Played with arms: ";
    in>>this->armsUsed;
    cout<<"Played with legs: ";
    in>>this->legsUsed;

    return in;
}

ostream& afisare(ostream& out) const{

    Sports::afisare(out);
    out<<"Ball type: "<<this->ballType<<endl;
    out<<"Played with arms: ";
    if (this->armsUsed==true)
        out<<"Yes"<<endl;
    else out<<"No"<<endl;

    out<<"Played with legs: ";
    if (this->legsUsed==true)
        out<<"Yes"<<endl;
    else out<<"No"<<endl;

    return out;
}

///----------------------------------------Destructor---------------------------------------------------
virtual ~BallSport()
{
    //~Sports();
    ballType="";
    armsUsed=false;
    legsUsed=false;

}
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

///__________________________________FINISH_BALL-SPORTS_______________________________________________________________________________________________________

class RacingSport:virtual public Sports
{

protected:

    int noWheels;
    string surfaceType;
    string raceType; ///time attack, lap, sprint, drag, etc
    bool openWheel;


public:

///---------------------------------constructors--------------------------------------------------
RacingSport():Sports()
{

    noWheels=-1;
    surfaceType="Unknown surface";
    raceType="Unknown type";
    openWheel=false;
    requireBall=false;

}

RacingSport(string sportName,int year,int noMinOfParticipants,int noWheels,string surfaceType,string raceType,bool openWheel):Sports(sportName,false,year,noMinOfParticipants)
{
    this->noWheels=noWheels;
    this->surfaceType=surfaceType;
    this->raceType=raceType;
    this->openWheel=openWheel;
}

RacingSport(const RacingSport &obj):Sports(obj)
{
    this->noWheels=obj.noWheels;
    this->surfaceType=obj.surfaceType;
    this->raceType=obj.raceType;
    this->openWheel=obj.openWheel;
}
///-----------------------------------operators---------------------------------------------

RacingSport& operator=(const RacingSport &obj)
{
    this->noWheels=obj.noWheels;
    this->surfaceType=obj.surfaceType;
    this->raceType=obj.raceType;
    this->openWheel=obj.openWheel;

    return *this;
}
///-----------------------------------functions--------------------------------------------

void afisareRacingSport()
{
    cout<<"Sport name: "<<sportName<<endl;
    cout<<"Ball required: ";
    if (requireBall==true)
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
    int st=0,nd=0;
    bool slowdown=false;
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
            if(laps1==noLaps)
                {
                    if(st==0)
                        st=1;
                    else
                        nd=1;
                }

        }

        if(underPlayer2=='%')
        {
            laps2++;
            if(laps2==noLaps)
                {
                    if(st==0)
                        st=2;
                    else
                        nd=2;
                }
        }

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

cout<<"Player "<<st<<" finished first!"<<endl;
cout<<"Player "<<nd<<", better luck next time!"<<endl;



}

///--------------------------------------citire-afisare--------------------------------------
friend istream& operator>>(istream& in, RacingSport &obj);
friend ostream& operator<<(ostream& out, const RacingSport &obj);

ifstream& citire(ifstream& in)
{
    Sports::citire(in);
    cout<<"Number of wheels: ";
    in>>this->noWheels;
    cout<<"Surface type: ";
    in>>this->surfaceType;
    cout<<"Race type: ";
    in>>this->raceType;
    cout<<"Open wheel: ";
    in>>this->openWheel;

    return in;
}

ostream& afisare(ostream& out) const{

    Sports::afisare(out);
    out<<"Number of wheels: "<<this->noWheels<<endl;
    out<<"Surface type: "<<this->surfaceType<<endl;
    out<<"Race type: "<<this->raceType<<endl;
    out<<"Open wheel: ";
    if (this->openWheel==true)
        out<<"Yes"<<endl;
    else out<<"No"<<endl;

    return out;
}

///------------------------------------destructor--------------------------------------------------
virtual ~RacingSport()
{
    noWheels=0;
    surfaceType="";
    raceType="";
    openWheel=false;
}
};

istream& operator >>(istream& in, RacingSport &obj)
{
    in>>(Sports&)obj;
    obj.requireBall=false;
    //---
    cout<<"Number of wheels: ";
    in>>obj.noWheels;
    cout<<"Surface type: ";
    in>>obj.surfaceType;
    cout<<"Race type: ";
    in>>obj.raceType;
    cout<<"Open wheel: ";
    in>>obj.openWheel;

    return in;
}
ostream& operator <<(ostream& out,const RacingSport &obj)
{
    out<<(Sports&)obj;
    //---
    out<<"Number of wheels: "<<obj.noWheels<<endl;
    out<<"Surface type: "<<obj.surfaceType<<endl;
    out<<"Race type: "<<obj.raceType<<endl;
    out<<"Open wheel: ";
    if (obj.openWheel==true)
        out<<"Yes"<<endl;
    else out<<"No"<<endl;

    return out;
}




class RocketLeague: public RacingSport, public BallSport
{
    bool reverseAllowed;

public:
///---------------------------Setter------------------------------------------------------------------

void setReverseAllowed(bool reverseAllowed)
{
    this->reverseAllowed=reverseAllowed;
}

///-------------------------Constructors-------------------------------------------------------------------------------------------------
    RocketLeague():RacingSport(),BallSport()
    {
        reverseAllowed=false;
        this->requireBall=true;
    }

    RocketLeague(string sportName,int year,int noMinOfParticipants,string ballType,bool armsUsed,bool legsUsed,int noWheels,string surfaceType,string raceType,bool openWheel,bool reverseAllowed):
            BallSport(sportName,year,noMinOfParticipants,ballType,armsUsed,legsUsed),
            RacingSport(sportName,year,noMinOfParticipants,noWheels,surfaceType,raceType,openWheel)
    {
        this->reverseAllowed=reverseAllowed;
        this->requireBall=true;
    }

    RocketLeague(RocketLeague& obj):RacingSport(obj),BallSport(obj)
    {
        this->reverseAllowed=obj.reverseAllowed;
        this->requireBall=true;
    }

///--------------------------------citire-afisare-------------------------------------------------------------------------------------------
friend istream& operator>>(istream& in, RocketLeague &obj);
friend ostream& operator<<(ostream& out, const RocketLeague &obj);

istream& citire(istream& in)
{
    BallSport::citire(in);
    cout<<"Number of wheels: ";
    in>>this->noWheels;
    cout<<"Surface type: ";
    in>>this->surfaceType;
    cout<<"Race type: ";
    in>>this->raceType;
    cout<<"Open wheel: ";
    in>>this->openWheel;
    cout<<"Reversed allowed: ";
    in>>this->reverseAllowed;

    return in;
}
ostream& afisare(ostream& out) const
{
    BallSport::afisare(out);
    out<<"Number of wheels: "<<this->noWheels<<endl;
    out<<"Surface type: "<<this->surfaceType<<endl;
    out<<"Race type: "<<this->raceType<<endl;
    out<<"Open wheel: ";
    if (this->openWheel==true)
        out<<"Yes"<<endl;
    else out<<"No"<<endl;

    out<<"Reversed allowed: ";
    if (this->reverseAllowed==true)
        out<<"Yes"<<endl;
    else out<<"No"<<endl;

    return out;

}
///-------------------------------------JOCULET---------------------------------------------------------------------------------------------

void afisareTrack(char track[100][100],int n,int m,int player1X,int player1Y,int player2X,int player2Y,int ballX,int ballY)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            if(i==player1X && j==player1Y)
            {
                HANDLE  hConsole;
                hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(hConsole,9);
                cout<<track[i][j];
                SetConsoleTextAttribute(hConsole,7);
            }
            else if(i==player2X && j==player2Y)
            {
                HANDLE  hConsole;
                hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(hConsole,4);
                cout<<track[i][j];
                SetConsoleTextAttribute(hConsole,7);
            }
            else if(i==ballX && j==ballY)
            {
                HANDLE  hConsole;
                hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(hConsole,2);
                cout<<track[i][j];
                SetConsoleTextAttribute(hConsole,7);
            }
            else cout<<track[i][j];
        cout<<endl;
    }
}

void RL()
{
    int n,m,i,j;
    int player1X,player1Y,player2X,player2Y,ballX,ballY;
    bool runningRace=true;
    int score1=0,score2=0;
    int maxScore;
    int st=0,nd=0;
    char track[100][100],test,underPlayer1,underPlayer2,underBall,choice;
    ifstream in("rocketleague.in");


    cout<<"Press any key to start!"<<endl;
    test=getch();
    system("CLS");


    in>>n>>m;
    in>>player1X>>player1Y;
    in>>player2X>>player2Y;
    in>>ballX>>ballY;
    in>>maxScore;
    in>>noskipws;
    in>>test;

    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
            in>>track[i][j];
        in>>test;
    }

    underPlayer1=track[player1X][player1Y];
    underPlayer2=track[player2X][player2Y];
    underBall=track[ballX][ballY];
    track[player1X][player1Y]='>';
    track[player2X][player2Y]='<';
    track[ballX][ballY]='O';

    afisareTrack(track,n,m,player1X,player1Y,player2X,player2Y,ballX,ballY);


    while(score1<maxScore && score2<maxScore)
    {
        choice=getch();
        system("CLS");
        switch(choice)
        {
        ///player1
        case 'w':
            {
                switch(track[player1X][player1Y])
                {
                case '>':
                    {
                        if((player1X==player2X && player1Y+1==player2Y) ||(player1X==player2X && player1Y+2==player2Y && player1X==ballX && player1Y+1==ballY))
                            break;

                        if(track[player1X][player1Y+1]=='O')
                        {
                            track[player1X][player1Y]=underPlayer1;
                            player1Y++;
                            underPlayer1=underBall;
                            track[player1X][player1Y]='>';
                            ballY++;
                            underBall=track[ballX][ballY];
                            track[ballX][ballY]='O';
                        }
                        else
                        {
                            track[player1X][player1Y]=underPlayer1;
                            player1Y++;
                            underPlayer1=track[player1X][player1Y];
                            track[player1X][player1Y]='>';
                        }

                        break;
                    }


                case '<':
                    {
                        if((player1X==player2X && player1Y-1==player2Y) ||(player1X==player2X && player1Y-2==player2Y && player1X==ballX && player1Y-1==ballY))
                            break;

                        if(track[player1X][player1Y-1]=='O')
                        {
                            track[player1X][player1Y]=underPlayer1;
                            player1Y--;
                            underPlayer1=underBall;
                            track[player1X][player1Y]='<';
                            ballY--;
                            underBall=track[ballX][ballY];
                            track[ballX][ballY]='O';
                        }
                        else
                        {
                            track[player1X][player1Y]=underPlayer1;
                            player1Y--;
                            underPlayer1=track[player1X][player1Y];
                            track[player1X][player1Y]='<';
                        }

                        break;
                    }

                case '^':
                    {
                        if((player1Y==player2Y && player1X-1==player2X) ||(player1Y==player2Y && player1X-2==player2X && player1Y==ballY && player1X-1==ballX))
                            break;

                        if(track[player1X-1][player1Y]=='O')
                        {
                            track[player1X][player1Y]=underPlayer1;
                            player1X--;
                            underPlayer1=underBall;
                            track[player1X][player1Y]='^';
                            ballX--;
                            underBall=track[ballX][ballY];
                            track[ballX][ballY]='O';
                        }
                        else
                        {
                            track[player1X][player1Y]=underPlayer1;
                            player1X--;
                            underPlayer1=track[player1X][player1Y];
                            track[player1X][player1Y]='^';
                        }

                        break;
                    }

                case 'v':
                    {
                        if((player1Y==player2Y && player1X+1==player2X) ||(player1Y==player2Y && player1X+2==player2X && player1Y==ballY && player1X+1==ballX))
                            break;

                        if(track[player1X+1][player1Y]=='O')
                        {
                            track[player1X][player1Y]=underPlayer1;
                            player1X++;
                            underPlayer1=underBall;
                            track[player1X][player1Y]='v';
                            ballX++;
                            underBall=track[ballX][ballY];
                            track[ballX][ballY]='O';
                        }
                        else
                        {
                            track[player1X][player1Y]=underPlayer1;
                            player1X++;
                            underPlayer1=track[player1X][player1Y];
                            track[player1X][player1Y]='v';
                        }

                        break;
                    }
                }

                break;
            }

        case 's':
            {
                if(reverseAllowed==false)
                    break;

                switch(track[player1X][player1Y])
                {
                case '>':
                    {
                        if((player1X==player2X && player1Y-1==player2Y) ||(player1X==player2X && player1Y-2==player2Y && player1X==ballX && player1Y-1==ballY))
                            break;

                        if(track[player1X][player1Y-1]=='O')
                        {
                            track[player1X][player1Y]=underPlayer1;
                            player1Y--;
                            underPlayer1=underBall;
                            track[player1X][player1Y]='>';
                            ballY--;
                            underBall=track[ballX][ballY];
                            track[ballX][ballY]='O';
                        }
                        else
                        {
                            track[player1X][player1Y]=underPlayer1;
                            player1Y--;
                            underPlayer1=track[player1X][player1Y];
                            track[player1X][player1Y]='>';
                        }

                        break;

                    }


                case '<':
                    {
                        if((player1X==player2X && player1Y+1==player2Y) ||(player1X==player2X && player1Y+2==player2Y && player1X==ballX && player1Y+1==ballY))
                            break;

                        if(track[player1X][player1Y+1]=='O')
                        {
                            track[player1X][player1Y]=underPlayer1;
                            player1Y++;
                            underPlayer1=underBall;
                            track[player1X][player1Y]='<';
                            ballY++;
                            underBall=track[ballX][ballY];
                            track[ballX][ballY]='O';
                        }
                        else
                        {
                            track[player1X][player1Y]=underPlayer1;
                            player1Y++;
                            underPlayer1=track[player1X][player1Y];
                            track[player1X][player1Y]='<';
                        }

                        break;
                    }

                case '^':
                    {
                        if((player1Y==player2Y && player1X+1==player2X) ||(player1Y==player2Y && player1X+2==player2X && player1Y==ballY && player1X+1==ballX))
                            break;

                        if(track[player1X+1][player1Y]=='O')
                        {
                            track[player1X][player1Y]=underPlayer1;
                            player1X++;
                            underPlayer1=underBall;
                            track[player1X][player1Y]='^';
                            ballX++;
                            underBall=track[ballX][ballY];
                            track[ballX][ballY]='O';
                        }
                        else
                        {
                            track[player1X][player1Y]=underPlayer1;
                            player1X++;
                            underPlayer1=track[player1X][player1Y];
                            track[player1X][player1Y]='^';
                        }

                        break;
                    }

                case 'v':
                    {
                        if((player1Y==player2Y && player1X-1==player2X) ||(player1Y==player2Y && player1X-2==player2X && player1Y==ballY && player1X-1==ballX))
                            break;

                        if(track[player1X-1][player1Y]=='O')
                        {
                            track[player1X][player1Y]=underPlayer1;
                            player1X--;
                            underPlayer1=underBall;
                            track[player1X][player1Y]='v';
                            ballX--;
                            underBall=track[ballX][ballY];
                            track[ballX][ballY]='O';
                        }
                        else
                        {
                            track[player1X][player1Y]=underPlayer1;
                            player1X--;
                            underPlayer1=track[player1X][player1Y];
                            track[player1X][player1Y]='v';
                        }


                        break;
                    }
                }

                break;
            }

        case 'a':
            {
                if(track[player1X][player1Y]=='^')
                    track[player1X][player1Y]='<';

                else if(track[player1X][player1Y]=='<')
                    track[player1X][player1Y]='v';

                else if(track[player1X][player1Y]=='v')
                    track[player1X][player1Y]='>';

                else if(track[player1X][player1Y]=='>')
                    track[player1X][player1Y]='^';

                break;
            }

        case 'd':
            {
                if(track[player1X][player1Y]=='^')
                    track[player1X][player1Y]='>';

                else if(track[player1X][player1Y]=='<')
                    track[player1X][player1Y]='^';

                else if(track[player1X][player1Y]=='v')
                    track[player1X][player1Y]='<';

                else if(track[player1X][player1Y]=='>')
                    track[player1X][player1Y]='v';

                break;
            }


        case 'i':
            {
                switch(track[player2X][player2Y])
                {
                case '>':
                    {
                        if((player2X==player1X && player2Y+1==player1Y) ||(player2X==player1X && player2Y+2==player1Y && player2X==ballX && player2Y+1==ballY))
                            break;

                        if(track[player2X][player2Y+1]=='O')
                        {
                            track[player2X][player2Y]=underPlayer2;
                            player2Y++;
                            underPlayer2=underBall;
                            track[player2X][player2Y]='>';
                            ballY++;
                            underBall=track[ballX][ballY];
                            track[ballX][ballY]='O';
                        }
                        else
                        {
                            track[player2X][player2Y]=underPlayer2;
                            player2Y++;
                            underPlayer2=track[player2X][player2Y];
                            track[player2X][player2Y]='>';
                        }

                        break;
                    }


                case '<':
                    {
                        if((player2X==player1X && player2Y-1==player1Y) ||(player2X==player1X && player2Y-2==player1Y && player2X==ballX && player2Y-1==ballY))
                            break;

                        if(track[player2X][player2Y-1]=='O')
                        {
                            track[player2X][player2Y]=underPlayer2;
                            player2Y--;
                            underPlayer2=underBall;
                            track[player2X][player2Y]='<';
                            ballY--;
                            underBall=track[ballX][ballY];
                            track[ballX][ballY]='O';
                        }
                        else
                        {
                            track[player2X][player2Y]=underPlayer2;
                            player2Y--;
                            underPlayer2=track[player2X][player2Y];
                            track[player2X][player2Y]='<';
                        }

                        break;
                    }

                case '^':
                    {
                        if((player2Y==player1Y && player2X-1==player1X) ||(player2Y==player1Y && player2X-2==player1X && player2Y==ballY && player2X-1==ballX))
                            break;

                        if(track[player2X-1][player2Y]=='O')
                        {
                            track[player2X][player2Y]=underPlayer2;
                            player2X--;
                            underPlayer2=underBall;
                            track[player2X][player2Y]='^';
                            ballX--;
                            underBall=track[ballX][ballY];
                            track[ballX][ballY]='O';
                        }
                        else
                        {
                            track[player2X][player2Y]=underPlayer2;
                            player2X--;
                            underPlayer2=track[player2X][player2Y];
                            track[player2X][player2Y]='^';
                        }

                        break;
                    }

                case 'v':
                    {
                        if((player2Y==player1Y && player2X+1==player1X) ||(player2Y==player1Y && player2X+2==player1X && player2Y==ballY && player2X+1==ballX))
                            break;

                        if(track[player2X+1][player2Y]=='O')
                        {
                            track[player2X][player2Y]=underPlayer2;
                            player2X++;
                            underPlayer2=underBall;
                            track[player2X][player2Y]='v';
                            ballX++;
                            underBall=track[ballX][ballY];
                            track[ballX][ballY]='O';
                        }
                        else
                        {
                            track[player2X][player2Y]=underPlayer2;
                            player2X++;
                            underPlayer2=track[player2X][player2Y];
                            track[player2X][player2Y]='v';
                        }

                        break;
                    }
                }

                break;
            }

        case 'k':
            {
                if(reverseAllowed==false)
                    break;

                switch(track[player2X][player2Y])
                {
                case '>':
                    {
                        if((player2X==player1X && player2Y-1==player1Y) ||(player2X==player1X && player2Y-2==player1Y && player2X==ballX && player2Y-1==ballY))
                            break;

                        if(track[player2X][player2Y-1]=='O')
                        {
                            track[player2X][player2Y]=underPlayer2;
                            player2Y--;
                            underPlayer2=underBall;
                            track[player2X][player2Y]='>';
                            ballY--;
                            underBall=track[ballX][ballY];
                            track[ballX][ballY]='O';
                        }
                        else
                        {
                            track[player2X][player2Y]=underPlayer2;
                            player2Y--;
                            underPlayer2=track[player2X][player2Y];
                            track[player2X][player2Y]='>';
                        }

                        break;

                    }


                case '<':
                    {
                        if((player2X==player1X && player2Y+1==player1Y) ||(player2X==player1X && player2Y+2==player1Y && player2X==ballX && player2Y+1==ballY))
                            break;

                        if(track[player2X][player2Y+1]=='O')
                        {
                            track[player2X][player2Y]=underPlayer2;
                            player2Y++;
                            underPlayer2=underBall;
                            track[player2X][player2Y]='<';
                            ballY++;
                            underBall=track[ballX][ballY];
                            track[ballX][ballY]='O';
                        }
                        else
                        {
                            track[player2X][player2Y]=underPlayer2;
                            player2Y++;
                            underPlayer2=track[player2X][player2Y];
                            track[player2X][player2Y]='<';
                        }

                        break;
                    }

                case '^':
                    {
                        if((player2Y==player1Y && player2X+1==player1X) ||(player2Y==player1Y && player2X+2==player1X && player2Y==ballY && player2X+1==ballX))
                            break;

                        if(track[player2X+1][player2Y]=='O')
                        {
                            track[player2X][player2Y]=underPlayer2;
                            player2X++;
                            underPlayer2=underBall;
                            track[player2X][player2Y]='^';
                            ballX++;
                            underBall=track[ballX][ballY];
                            track[ballX][ballY]='O';
                        }
                        else
                        {
                            track[player2X][player2Y]=underPlayer2;
                            player2X++;
                            underPlayer2=track[player2X][player2Y];
                            track[player2X][player2Y]='^';
                        }

                        break;
                    }

                case 'v':
                    {
                        if((player2Y==player1Y && player2X-1==player1X) ||(player2Y==player1Y && player2X-2==player1X && player2Y==ballY && player2X-1==ballX))
                            break;

                        if(track[player2X-1][player2Y]=='O')
                        {
                            track[player2X][player2Y]=underPlayer2;
                            player2X--;
                            underPlayer2=underBall;
                            track[player2X][player2Y]='v';
                            ballX--;
                            underBall=track[ballX][ballY];
                            track[ballX][ballY]='O';
                        }
                        else
                        {
                            track[player2X][player2Y]=underPlayer2;
                            player2X--;
                            underPlayer2=track[player2X][player2Y];
                            track[player2X][player2Y]='v';
                        }


                        break;
                    }
                }

                break;
            }

        case 'j':
            {
                if(track[player2X][player2Y]=='^')
                    track[player2X][player2Y]='<';

                else if(track[player2X][player2Y]=='<')
                    track[player2X][player2Y]='v';

                else if(track[player2X][player2Y]=='v')
                    track[player2X][player2Y]='>';

                else if(track[player2X][player2Y]=='>')
                    track[player2X][player2Y]='^';

                break;
            }

        case 'l':
            {
                if(track[player2X][player2Y]=='^')
                    track[player2X][player2Y]='>';

                else if(track[player2X][player2Y]=='<')
                    track[player2X][player2Y]='^';

                else if(track[player2X][player2Y]=='v')
                    track[player2X][player2Y]='<';

                else if(track[player2X][player2Y]=='>')
                    track[player2X][player2Y]='v';

                break;
            }

        }

        if(underBall==']')
        {
            ifstream in("rocketleague.in");
            score1++;
            in>>n>>m;
            in>>player1X>>player1Y;
            in>>player2X>>player2Y;
            in>>ballX>>ballY;
            in>>maxScore;
            in>>noskipws;
            in>>test;

            for(i=0;i<n;i++)
            {
                for(j=0;j<m;j++)
                    in>>track[i][j];
                in>>test;
            }

            underPlayer1=track[player1X][player1Y];
            underPlayer2=track[player2X][player2Y];
            underBall=track[ballX][ballY];
            track[player1X][player1Y]='>';
            track[player2X][player2Y]='<';
            track[ballX][ballY]='O';
        }

        else if(underBall=='[')
        {
            ifstream in("rocketleague.in");
            score2++;
            in>>n>>m;
            in>>player1X>>player1Y;
            in>>player2X>>player2Y;
            in>>ballX>>ballY;
            in>>maxScore;
            in>>noskipws;
            in>>test;

            for(i=0;i<n;i++)
            {
                for(j=0;j<m;j++)
                    in>>track[i][j];
                in>>test;
            }

            underPlayer1=track[player1X][player1Y];
            underPlayer2=track[player2X][player2Y];
            underBall=track[ballX][ballY];
            track[player1X][player1Y]='>';
            track[player2X][player2Y]='<';
            track[ballX][ballY]='O';
        }

        cout<<"SCORE(P1-P2): "<<score1<<" : "<<score2<<endl;
        afisareTrack(track,n,m,player1X,player1Y,player2X,player2Y,ballX,ballY);
    }

    if(score1==maxScore)
        cout<<"Player 1 Won!"<<endl;

    if(score2==maxScore)
        cout<<"Player 2 Won!"<<endl;

    cout<<"Press X to exit!"<<endl;

    while(test!='X' || test!='x')
    {
        test=getch();
    }

}


///----------------------------------------destructor----------------------------------------------------------
~RocketLeague()
{
    reverseAllowed=false;
}
};

istream& operator >>(istream& in, RocketLeague &obj)
{
    in>>(BallSport&)obj;
    cout<<"Number of wheels: ";
    in>>obj.noWheels;
    cout<<"Surface type: ";
    in>>obj.surfaceType;
    cout<<"Race type: ";
    in>>obj.raceType;
    cout<<"Open wheel: ";
    in>>obj.openWheel;
    cout<<"Reversed allowed: ";
    in>>obj.reverseAllowed;

    return in;
}
ostream& operator <<(ostream& out,const RocketLeague &obj)
{
    out<<(BallSport&)obj;
    out<<"Number of wheels: "<<obj.noWheels<<endl;
    out<<"Surface type: "<<obj.surfaceType<<endl;
    out<<"Race type: "<<obj.raceType<<endl;
    out<<"Open wheel: ";
    if (obj.openWheel==true)
        out<<"Yes"<<endl;
    else out<<"No"<<endl;

    out<<"Reversed allowed: ";
    if (obj.reverseAllowed==true)
        out<<"Yes"<<endl;
    else out<<"No"<<endl;

    return out;
}

class SportList
{
    Sports* sports;
    double cota;

public:

    friend istream& operator>>(istream& in, SportList& obj)
    {
        cout<<"What type of sport do you wanna add?"<<endl;
        cout<<"1->Basic Sport  2->Ball Sport  3->Racing Sport  4->Racing Ball Sport"<<endl;
        int choice;
        cin>>choice;
        if(choice==1)
            obj.sports = new Sports();
        else if(choice==2)
            obj.sports = new BallSport();
        else if(choice==3)
            obj.sports = new RacingSport();
        else if(choice==4)
            obj.sports = new RocketLeague();

        in>>*obj.sports;
        cout<<"Cota: ";
        in>>obj.cota;

        return in;
    }

    friend ostream& operator<<(ostream& out, const SportList& obj)
    {
        out<<*obj.sports;
        out<<"Cota: "<<obj.cota<<endl;

        return out;
    }

    Sports* GetSport(){
        return this->sports;
    }
};


class BettingHouse
{

    vector<Sports*> games;
    vector<SportList> listofSports;

public:
    void addList()
    {
        SportList sport;
        cin>>sport;
        listofSports.push_back(sport);
    }

    void showList()
    {
        for(int i=0;i<listofSports.size();i++)
            cout<<listofSports[i]<<endl;
    }

    void addGame()
    {
        int id_choice;
        cout<<"Choose the sport by id:"<<endl;
        cin>>id_choice;

        for(int i=0;i<listofSports.size();i++)
            if(listofSports[i].GetSport()->GetId()==id_choice)
            {
                games.push_back(listofSports[i].GetSport());
                break;
            }
    }

    void showGame()
    {
        for(int i=0;i<games.size();i++)
            cout<<*games[i]<<endl;
    }

};

int main()
{
int brench1,brench2,brench3;

cout<<"Hello!";
cout<<"Choose between our options-> 1) Playing Games  2) Creating your own Sports Betting House"<<endl;
cin>>brench1;

switch(brench1)
{
    case 1:
        {
            cout<<"What kind of sport do you want to use?"<<endl;
            cout<<"1->Basic 2->Ball Sport 3->Racing Sport 4->Racing Ball Sport"<<endl;
            cin>>brench2;

            switch(brench2)
            {
                case 1:
                    {
                        cout<<"What kind of attributes do you want to use?"<<endl;
                        cout<<"1->Default 2->Custom"<<endl;
                        cin>>brench3;

                        switch(brench3)
                        {
                            case 1:
                            {
                                Sports s;
                                cout<<"Here is your sport:"<<endl;
                                cout<<s;
                                break;
                            }

                            case 2:
                            {
                                Sports s;
                                cin>>s;
                                cout<<"Here is your sport:"<<endl;
                                cout<<s;
                                break;
                            }

                        }

                        break;
                    }

                case 2:
                    {
                        cout<<"What kind of attributes do you want to use?"<<endl;
                        cout<<"1->Default 2->Custom"<<endl;
                        cin>>brench3;

                        switch(brench3)
                        {
                            case 1:
                            {
                                BallSport b;
                                cout<<"Here is your sport:"<<endl;
                                cout<<b;
                                cout<<"Now let's play!!!"<<endl;
                                b.football();
                                break;
                            }

                            case 2:
                            {
                                BallSport b;
                                cin>>b;
                                cout<<"Here is your sport:"<<endl;
                                cout<<b;
                                cout<<"Now let's play!!!"<<endl;
                                b.football();
                                break;
                            }

                        }

                        break;
                    }

                case 3:
                    {
                        cout<<"What kind of attributes do you want to use?"<<endl;
                        cout<<"1->Default 2->Custom"<<endl;
                        cin>>brench3;

                        switch(brench3)
                        {
                            case 1:
                            {
                                RacingSport r;
                                cout<<"Here is your sport:"<<endl;
                                cout<<r;
                                cout<<"Now let's play!!!"<<endl;
                                r.race();
                                break;
                            }

                            case 2:
                            {
                                RacingSport r;
                                cin>>r;
                                cout<<"Here is your sport:"<<endl;
                                cout<<r;
                                cout<<"Now let's play!!!"<<endl;
                                r.race();
                                break;
                            }

                        }

                        break;
                    }

                case 4:
                    {
                        cout<<"What kind of attributes do you want to use?"<<endl;
                        cout<<"1->Default 2->Custom"<<endl;
                        cin>>brench3;

                        switch(brench3)
                        {
                            case 1:
                            {
                                RocketLeague rl;
                                cout<<"Here is your sport:"<<endl;
                                cout<<rl;
                                cout<<"Now let's play!!!"<<endl;
                                rl.RL();
                                break;
                            }

                            case 2:
                            {
                                RocketLeague rl;
                                cin>>rl;
                                cout<<"Here is your sport:"<<endl;
                                cout<<rl;
                                cout<<"Now let's play!!!"<<endl;
                                rl.RL();
                                break;
                            }

                        }
                        break;
                    }
                break;
            }
        break;
    }
}

    return 0;

}
