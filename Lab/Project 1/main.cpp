#include <iostream>
#include <cstring>
#include<vector>
#include <stdlib.h>
#include <unistd.h>
using namespace std;

class Racetracks{

///date--------------------------------------------------------------------------------------------------------------------------
static int contorId;
const int idTrack;
string trackName;
string location;
float length;
bool clockwise;
int noCorners;


public:
///Getters--------------------------------------------------------------------------------------------------------------------------
const int GetIdTrack()const{
    return idTrack;
}
string GetTrackName()const{
    return trackName;
}
string GetLocation()const{
    return location;
}
float GetLength()const{
    return length;
}
bool GetClockwise()const{
    return clockwise;
}
int GetNoCorners()const{
    return noCorners;
}
///Setters--------------------------------------------------------------------------------------------------------------------------
void SetTrackName(string trackName){
    this->trackName=trackName;
}
void SetLocation(string location){
     this->location=location;
}
void SetLength(float length){
     this->length=length;
}
void SetClockwise(bool clockwise){
     this->clockwise=clockwise;
}
void SetNoCorners(int noCorners){
    this->noCorners=noCorners;
}

///Constructori--------------------------------------------------------------------------------------------------------------------------

//Circuit fara parametri
Racetracks():idTrack(contorId++){
trackName="Unknown name";
location="Unknown location";
length=0;
clockwise=NULL; ///il fac pointer sa pointeze catre null
noCorners=0;
}
//Circuit neconstruit inca, se cunoaste doar numele si locatia
Racetracks(string trackName,string location):idTrack(contorId++){
this->trackName=trackName;
this->location=location;
length=0;
clockwise=NULL;
noCorners=0;
}
//Circuit construit ce suporta concurarea in ambele sensuri(nu s-a stabilit sensul de mers)
Racetracks(string trackName,string location,float length,int noCorners):idTrack(contorId++){
this->trackName=trackName;
this->location=location;
this->length=length;
clockwise=NULL;
this->noCorners=noCorners;
}
//Toti parametri
Racetracks(string trackName,string location,float length,bool clockwise,int noCorners):idTrack(contorId++){
this->trackName=trackName;
this->location=location;
this->length=length;
this->clockwise=clockwise;
this->noCorners=noCorners;
}

///-----------------------copiere-------------------------------

Racetracks(const Racetracks& obj):idTrack(obj.idTrack){
this->trackName=obj.trackName;
this->location=obj.location;
this->length=obj.length;
this->clockwise=obj.clockwise;
this->noCorners=obj.noCorners;
}
///SUPRAINCARCARE


///-------------------------------------------EGAL----------------------------------------------
Racetracks& operator = (const Racetracks& obj){


    this->trackName=obj.trackName;
    this->location=obj.location;
    this->length=obj.length;
    this->clockwise=obj.clockwise;
    this->noCorners=obj.noCorners;

    return *this;
}

///------------------------MIC----------------------
bool operator <(const Racetracks& obj){

 if(this->length<obj.length)
    return true;
else return false;

}
///------------------------MARE----------------------
bool operator >(const Racetracks& obj){

 if(this->length>obj.length)
    return true;
else return false;

}
///------------------------EGAL-EGAL--------------------------
bool operator ==(const Racetracks& obj){

    bool valid=true;

    if(valid!=false)
        if(this->trackName!=obj.trackName)
            valid=false;

    if(valid!=false)
        if(this->location!=obj.location)
            valid=false;

    if(valid!=false)
        if(this->length!=obj.length)
            valid=false;

    if(valid!=false)
        if(this->clockwise!=obj.clockwise)
            valid=false;

    if(valid!=false)
        if(this->noCorners!=obj.noCorners)
            valid=false;

    return valid;

}
///------------------------PLUS-CU-OBIECTE--------------------
Racetracks operator +(Racetracks obj){

    obj.length=obj.length+this->length;
    obj.noCorners=obj.noCorners+this->noCorners;

    return obj;
}
///------------------------PLUS-CU-CONSTANTA--------------------
Racetracks operator +(float addedLength){

    Racetracks cop(*this);

    cop.length=cop.length+addedLength;
    cop.noCorners=cop.noCorners+(int)(addedLength/200);
    ///pentru fiecare 200 de metri se mai adauga un viraj

    return cop;
}
///------------------------MINUS-CU-OBIECTE--------------------
Racetracks operator -(Racetracks obj){

    obj.length=obj.length-this->length;
    obj.noCorners=obj.noCorners-this->noCorners;

    return obj;
}
///------------------------MINUS-CU-CONSTANTA--------------------
Racetracks operator -(float substractedLength){
    Racetracks cop(*this);

    cop.length=cop.length+substractedLength;
    cop.noCorners=cop.noCorners+(int)(substractedLength/200);
    ///pentru fiecare 200 de metri se mai elimina un viraj

    return cop;
}

///--------------------------PLUS-PLUS-CEVA-------------------------------------
Racetracks& operator++(){
    this->noCorners++;
    return *this;
}

///---------------------------CEVA-PLUS-PLUS----------------------------------
Racetracks operator ++(int){
    Racetracks aux(*this);
    //this->noCorners++;
    ++(*this);

    return aux;
}

///---------------CONSTANTA-CU-PLUS---------------------------------
friend Racetracks operator+(int x,const Racetracks obj);

///--------------CAST----------------------------------------------
operator int() const{
        return this->noCorners;
}

///----------------SCRIERE SI CITIRE--------------------------------
friend ostream& operator <<(ostream& out, const Racetracks& obj);
friend istream& operator >>(istream& in, Racetracks& obj);


///---------DESTRCUTOR------------------------
~Racetracks(){
    this->trackName="";
    this->location="";
    this->length=0;
    this->clockwise=false;
    this->noCorners=0;

}

///_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_FUNCTII_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-
void afisare()
{
    cout<<"Id: "<<idTrack<<endl;
    cout<<"Track name: "<<trackName<<endl;
    cout<<"Location: "<<location<<endl;
    cout<<"Track length: "<<length<<endl;
    cout<<"Direction clockwise: "<<clockwise<<endl;
    cout<<"Number of corners: "<<noCorners<<endl;
}

void afisareClockwise()
{
for(int i=0;i<3;i++)
{
    if(clockwise==true)
    {

        system("CLS");

        cout<<"     -    "<<endl;
        cout<<"##########"<<endl;
        cout<<"#        #"<<endl;
        cout<<"#        #"<<endl;
        cout<<"#        #"<<endl;
        cout<<"#        #"<<endl;
        cout<<"##########"<<endl;
        usleep(300000);
        system("CLS");


        cout<<"     --   "<<endl;
        cout<<"##########"<<endl;
        cout<<"#        #"<<endl;
        cout<<"#        #"<<endl;
        cout<<"#        #"<<endl;
        cout<<"#        #"<<endl;
        cout<<"##########"<<endl;
        usleep(300000);
        system("CLS");

        cout<<"     ---  "<<endl;
        cout<<"##########"<<endl;
        cout<<"#        #"<<endl;
        cout<<"#        #"<<endl;
        cout<<"#        #"<<endl;
        cout<<"#        #"<<endl;
        cout<<"##########"<<endl;
        usleep(300000);
        system("CLS");

        cout<<"     ---- "<<endl;
        cout<<"##########"<<endl;
        cout<<"#        #"<<endl;
        cout<<"#        #"<<endl;
        cout<<"#        #"<<endl;
        cout<<"#        #"<<endl;
        cout<<"##########"<<endl;
        usleep(300000);
        system("CLS");

        cout<<"     -----"<<endl;
        cout<<"##########"<<endl;
        cout<<"#        #"<<endl;
        cout<<"#        #"<<endl;
        cout<<"#        #"<<endl;
        cout<<"#        #"<<endl;
        cout<<"##########"<<endl;
        usleep(300000);
        system("CLS");

        cout<<"     ------"<<endl;
        cout<<"########## |"<<endl;
        cout<<"#        #"<<endl;
        cout<<"#        #"<<endl;
        cout<<"#        #"<<endl;
        cout<<"#        #"<<endl;
        cout<<"##########"<<endl;
        usleep(300000);
        system("CLS");

        cout<<"     ------"<<endl;
        cout<<"########## |"<<endl;
        cout<<"#        # |"<<endl;
        cout<<"#        #"<<endl;
        cout<<"#        #"<<endl;
        cout<<"#        #"<<endl;
        cout<<"##########"<<endl;
        usleep(300000);
        system("CLS");


        cout<<"     ------"<<endl;
        cout<<"########## |"<<endl;
        cout<<"#        # |"<<endl;
        cout<<"#        # |/"<<endl;
        cout<<"#        #"<<endl;
        cout<<"#        #"<<endl;
        cout<<"##########"<<endl;
    }
    else
        {

        system("CLS");

        cout<<"      -     "<<endl;
        cout<<"  ##########"<<endl;
        cout<<"  #        #"<<endl;
        cout<<"  #        #"<<endl;
        cout<<"  #        #"<<endl;
        cout<<"  #        #"<<endl;
        cout<<"  ##########"<<endl;
        usleep(300000);
        system("CLS");


        cout<<"     --     "<<endl;
        cout<<"  ##########"<<endl;
        cout<<"  #        #"<<endl;
        cout<<"  #        #"<<endl;
        cout<<"  #        #"<<endl;
        cout<<"  #        #"<<endl;
        cout<<"  ##########"<<endl;
        usleep(300000);
        system("CLS");

        cout<<"    ---     "<<endl;
        cout<<"  ##########"<<endl;
        cout<<"  #        #"<<endl;
        cout<<"  #        #"<<endl;
        cout<<"  #        #"<<endl;
        cout<<"  #        #"<<endl;
        cout<<"  ##########"<<endl;
        usleep(300000);
        system("CLS");

        cout<<"   ----     "<<endl;
        cout<<"  ##########"<<endl;
        cout<<"  #        #"<<endl;
        cout<<"  #        #"<<endl;
        cout<<"  #        #"<<endl;
        cout<<"  #        #"<<endl;
        cout<<"  ##########"<<endl;
        usleep(300000);
        system("CLS");

        cout<<"  -----     "<<endl;
        cout<<"  ##########"<<endl;
        cout<<"  #        #"<<endl;
        cout<<"  #        #"<<endl;
        cout<<"  #        #"<<endl;
        cout<<"  #        #"<<endl;
        cout<<"  ##########"<<endl;
        usleep(300000);
        system("CLS");

        cout<<"------     "<<endl;
        cout<<"| ##########"<<endl;
        cout<<"  #        #"<<endl;
        cout<<"  #        #"<<endl;
        cout<<"  #        #"<<endl;
        cout<<"  #        #"<<endl;
        cout<<"  ##########"<<endl;
        usleep(300000);
        system("CLS");

        cout<<"------     "<<endl;
        cout<<"| ##########"<<endl;
        cout<<"| #        #"<<endl;
        cout<<"  #        #"<<endl;
        cout<<"  #        #"<<endl;
        cout<<"  #        #"<<endl;
        cout<<"  ##########"<<endl;
        usleep(300000);
        system("CLS");


        cout<<"------     "<<endl;
        cout<<"| ##########"<<endl;
        cout<<"| #        #"<<endl;
        cout<<"|/#        #"<<endl;
        cout<<"  #        #"<<endl;
        cout<<"  #        #"<<endl;
        cout<<"  ##########"<<endl;
        usleep(300000);
        }

    }
}


};

///--------------------------------CONSTANTA-PLUS-OBIECT------------------------
Racetracks operator+(int x, Racetracks obj){
    return obj+x;

        //sau

    /*
    Racetracks aux(*this);
    aux.length+=x;
    return aux;
    */

}
///--------------------SCRIERE-RACETRACKS---------------------------------------
ostream& operator <<(ostream& out, const Racetracks& obj){

    out<<"Id: "<<obj.idTrack<<endl;
    out<<"Track name: "<<obj.trackName<<endl;
    out<<"Location: "<<obj.location<<endl;
    out<<"Track length: "<<obj.length<<endl;
    out<<"Direction clockwise: "<<obj.clockwise<<endl;
    out<<"Number of corners: "<<obj.noCorners<<endl;


    return out;
}
///--------------------------CITIRE-RACETRACKS-------------------------------------------
istream& operator >>(istream& in, Racetracks& obj){


    cout << "New Track Name: " << endl;
    in>>obj.trackName;
    cout<<"New Location: ";
    in>>obj.location;
    cout<<"New Track Length: ";
    in>>obj.length;
    cout<<"New direction clockwise: ";
    in>>obj.clockwise;
    cout<<"New Number of Corners: ";
    in>>obj.noCorners;

    return in;

}



class Races{

///date
static int contorId;
const int idRace;
string raceTrack;
string startDate;
bool nightRace;
int noParticipants;
int noSponsors;
char* mainSponsor;



public:

///Getters

const int GetIdRace()const{
    return idRace;
}
string GetRaceTrack()const{
    return raceTrack;
}
string GetStartDate()const{
    return startDate;
}
bool GetNightRace()const{
    return nightRace;
}
int GetNoParticipants()const{
    return noParticipants;
}
int GetNoSponsors()const{
    return noSponsors;
}
char* GetMainSponsor()const{
    return mainSponsor;
}

///Setters

void SetRaceTrack(string raceTrack){
    this->raceTrack=raceTrack;
}
void SetStartDate(string startDate){
    this->startDate=startDate;
}
void SetNightRace(bool nightRace){
    this->nightRace=nightRace;
}
void SetNoParticipants(int noParticipants){
    this->noParticipants=noParticipants;
}
void SetNoSponsors(int noSponsors){
    this->noSponsors=noSponsors;
}
void SetMainSponsor(char* mainSponsor){

    if(strcmp(this->mainSponsor,"Not assigned")==0 && noSponsors==0)
        this->noSponsors=1;
    if(this->mainSponsor!=NULL)
       {
            delete[] this->mainSponsor;
            this->mainSponsor=NULL;
       }

    this->mainSponsor=new char[1000];
    strcpy(this->mainSponsor,mainSponsor);

}

///Constructors

Races():idRace(contorId++){
    raceTrack="Unknown track";
    startDate="TBA";
    nightRace=false;
    noParticipants=0;
    noSponsors=0;
    mainSponsor=new char[strlen("Not assigned")+1];
    strcpy(mainSponsor,"Not assigned");
}
Races(string raceTrack,string startDate,bool nightRace,int noParticipants,int noSponsors,char* mainSponsor):idRace(contorId++){
    this->raceTrack=raceTrack;
    this->startDate=startDate;
    this->nightRace=nightRace;
    this->noParticipants=noParticipants;
    this->noSponsors=noSponsors;
    this->mainSponsor=new char[strlen(mainSponsor)+1];
    strcpy(this->mainSponsor,mainSponsor);
}
Races(string startDate,int noParticipants,char* mainSponsor):idRace(contorId++){
    this->raceTrack="Unknown track";
    this->startDate=startDate;
    this->nightRace=false;
    this->noParticipants=noParticipants;
    this->noSponsors=0;
    this->mainSponsor=new char[strlen(mainSponsor)+1];
    strcpy(this->mainSponsor,mainSponsor);
}
Races(string raceTrack,bool nightRace,int noSponsors):idRace(contorId++){
    this->raceTrack=raceTrack;
    this->startDate="TBA";
    this->nightRace=nightRace;
    this->noParticipants=0;
    this->noSponsors=noSponsors;
    this->mainSponsor=new char[100];
    strcpy(this->mainSponsor,"Not assigned");
}
///------------------copiere-------------------------------
Races(const Races& obj):idRace(obj.idRace){
    this->raceTrack=obj.raceTrack;
    this->startDate=obj.startDate;
    this->nightRace=obj.nightRace;
    this->noParticipants=obj.noParticipants;
    this->noSponsors=obj.noSponsors;
    this->mainSponsor=new char[strlen(obj.mainSponsor)];
    strcpy(this->mainSponsor,obj.mainSponsor);
}

///SUPRAINCARCARE

///-----------------------EGAL----------------------------------------------
Races& operator = (const Races& obj){


    this->raceTrack=obj.raceTrack;
    this->startDate=obj.startDate;
    this->nightRace=obj.nightRace;
    this->noParticipants=obj.noParticipants;
    this->noSponsors=obj.noSponsors;
    this->mainSponsor=new char[strlen(obj.mainSponsor)+1];
    strcpy(this->mainSponsor,obj.mainSponsor);

    return *this;
}

///------------------------MIC----------------------
bool operator <(const Races& obj){

 if(this->noParticipants<obj.noParticipants)
    return true;
else return false;

}
///------------------------MARE----------------------
bool operator >(const Races& obj){

 if(this->noParticipants>obj.noParticipants)
    return true;
else return false;

}

///------------------------EGAL-EGAL--------------------------
bool operator ==(const Races& obj){

    bool valid=true;

    if(valid!=false)
        if(this->raceTrack!=obj.raceTrack)
            valid=false;

    if(valid!=false)
        if(this->startDate!=obj.startDate)
            valid=false;

    if(valid!=false)
        if(this->nightRace!=obj.nightRace)
            valid=false;

    if(valid!=false)
        if(this->noParticipants!=obj.noParticipants)
            valid=false;

    if(valid!=false)
        if(this->noSponsors!=obj.noSponsors)
            valid=false;

    if(valid!=false)
        if(strcmp(this->mainSponsor,obj.mainSponsor)!=0)
            valid=false;

    return valid;

}

///-------------------------PLUS-CU-OBIECTE--------------------------------
Races operator +(Races obj){

    obj.noParticipants=this->noParticipants+obj.noParticipants;

    return obj;
}
///-------------------------PLUS-CU-OBIECTE-ALTA-CLASA-------------------------------
Races operator +(Racetracks& obj){


    Races cop(*this);
    cop.raceTrack=obj.GetTrackName();
    cop.startDate=cop.startDate+" - "+obj.GetLocation();


    return cop;
}

///------------------------PLUS-CU-CONSTANTA--------------------

Races operator +(float addedParticipants){

    Races cop(*this);

    cop.noParticipants=cop.noParticipants+addedParticipants;

    return cop;
}

///------------------------MINUS-CU-OBIECTE--------------------

Races operator -(Races obj){

    obj.noParticipants=this->noParticipants-obj.noParticipants;

    return obj;
}

///------------------------MINUS-CU-CONSTANTA--------------------
Races operator -(float substractedParticipants){

    Races cop(*this);

    cop.noParticipants=cop.noParticipants-substractedParticipants;
    return cop;
}

///-------------PLUS-PLUS-CEVA-------------------------------------
Races& operator++(){
    this->noParticipants++;
    return *this;
}

///-----------------CEVA-PLUS-PLUS----------------------------------
Races operator ++(int){
    Races aux(*this);
    //this->noParticipants++;
    ++(*this);

    return aux;
}

///---------------CONSTANTA-CU-PLUS---------------------------------
friend Races operator+(int, Races obj);

///--------------CAST----------------------------------------------
operator int() const{
        return this->noSponsors;
}

///----------------SCRIERE SI CITIRE--------------------------------
friend ostream& operator <<(ostream& out, const Races& obj);
friend istream& operator >>(istream& in, Races& obj);

///------------------DESTRUCTOR--------------------------------------
~Races()
{

    if(this->mainSponsor!=NULL)
    {
        delete[] this->mainSponsor;
        this->mainSponsor=NULL;
    }

    this->raceTrack="";
    this->startDate="";
    this->nightRace=false;
    this->noParticipants=0;
    this->noSponsors=0;

}

///_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_FUNCTII_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-
void afisare()
{
    cout<<"Id: "<<idRace<<endl;
    cout<<"Race track: "<<raceTrack<<endl;
    cout<<"First day of the event: "<<startDate<<endl;
    cout<<"Night Race: "<<nightRace<<endl;
    cout<<"Number of participants: "<<noParticipants<<endl;
    cout<<"Number of sponsors: "<<noSponsors<<endl;
    cout<<"Main sponsor: "<<mainSponsor<<endl;
}

};///________________________________FINAL_RACES____________________________________________

///--------------------------------CONSTANTA-PLUS-OBIECT------------------------
Races operator+(int x, Races obj){
    return obj+x;

        //sau

    /*
    Races aux(*this);
    aux.noParticipants+=x;
    return aux;
    */

}
///--------------------SCRIERE-RACES---------------------------------------
ostream& operator <<(ostream& out, const Races& obj){

    out<<"Id: "<<obj.idRace<<endl;
    out<<"Race track: "<<obj.raceTrack<<endl;
    out<<"First day of the event: "<<obj.startDate<<endl;
    out<<"Night Race: "<<obj.nightRace<<endl;
    out<<"Number of participants: "<<obj.noParticipants<<endl;
    out<<"Number of sponsors: "<<obj.noSponsors<<endl;
    out<<"Main sponsor: "<<obj.mainSponsor<<endl;



    return out;
}
///--------------------------CITIRE-RACES-------------------------------------------
istream& operator >>(istream& in, Races& obj){

    cout<<"Race track: ";
    in>>obj.raceTrack;
    cout<<"First day of the event: ";
    in>>obj.startDate;
    cout<<"Night Race: ";
    in>>obj.nightRace;
    cout<<"Number of participants: ";
    in>>obj.noParticipants;
    cout<<"Number of sponsors: ";
    in>>obj.noSponsors;
    cout<<"Main sponsor: ";
    in>>obj.mainSponsor;

    return in;

}




class Drivers{
private:

    ///Date
    static int contorId;
    const int idDriver;
    char* driverName;
    char category;
    string teamName;
    int age;
    int kartNumber;
    int noFaults;
    int* faults;
    double championshipPoints;

public:

///Getters
const int GetIdDriver()const{
    return idDriver;
}
char GetCategory()const{
    return category;
}
char* GetDriverName()const{
    return driverName;
}
int GetAge()const{
    return age;
}
int GetKartNumber()const{
    return kartNumber;
}
double GetChampionshipPoints()const{
    return championshipPoints;
}
string GetTeamName()const{
    return teamName;
}
int GetNoFaults()const{
    return noFaults;
}
int* GetFaults()const{
    return faults;
}

///setters
void SetCategory(char category){
    this->category=category;
}
void SetDriverName(char* driverName){
    if(this->driverName!=NULL)
       {
            delete[] this->driverName;
            this->driverName=NULL;
       }

    this->driverName=new char[1000];
    strcpy(this->driverName,driverName);
}
void SetAge(int age){
    this->age=age;
}
void SetKartNumber(int kartNumber){
    this->kartNumber=kartNumber;
}
void SetChampionshipPoints(double championshipPoints){
    this->championshipPoints=championshipPoints;
}
void SetTeamName(string teamName){
    this->teamName=teamName;
}
void SetNoFaults(int noFaults){
    this->noFaults=noFaults;
}
void SetFaults(int* faults){


        this->faults=NULL;

    this->faults=new int[this->noFaults];
    for(int i=0;i<noFaults;i++)
    this->faults[i]=faults[i];
}

///CONSTRUCTORI


///Fara parametri
Drivers():idDriver(contorId++){
    driverName=new char[strlen("Unknown Name")+1];
    strcpy(driverName,"Unknown Name");
    category='-';
    teamName="Unknown team";
    age=0;
    kartNumber=-1;
    noFaults=0;
    faults=NULL;
    championshipPoints=(double)0;
}
///Toti parametri
Drivers(char* driverName,char category,string teamName, int age, int kartNumber, int noFaults, int* faults, double championshipPoints):idDriver(contorId++){
    this->driverName=new char[strlen(driverName)+1];
    strcpy(this->driverName,driverName);
    this->category=category;
    this->teamName=teamName;
    this->age=age;
    this->kartNumber=kartNumber;
    this->noFaults=noFaults;
    this->faults=NULL;
    this->faults=new int[this->noFaults];
    for(int i=0;i<this->noFaults;i++)
        this->faults[i]=faults[i];
    this->championshipPoints=championshipPoints;
}
///Fara categorie(implicit fara numar si fara punctaj)
Drivers(char* driverName,string teamName, int age, int noFaults,int* faults):idDriver(contorId++){

    this->driverName=new char[strlen(driverName)+1];
    strcpy(this->driverName,driverName);
    this->category='-';
    this->teamName=teamName;
    this->age=age;
    this->kartNumber=0;
    this->noFaults=noFaults;
    this->faults=NULL;
    this->faults = new int [this->noFaults];
    for(int i=0;i<this->noFaults;i++)
        this->faults[i]=faults[i];
    this->championshipPoints=0;
}
///Fara detalii, doar date personale
Drivers(char* driverName,int age):idDriver(contorId++){
    this->driverName=new char[strlen(driverName)+1];
    strcpy(this->driverName,driverName);
    this->category='-';
    this->teamName="Unknown name: ";
    this->age=age;
    this->kartNumber=0;
    this->noFaults=0;
    this->faults=NULL;
    this->championshipPoints=0;
}

///------------------------Copiere----------------------------------
Drivers(const Drivers& obj):idDriver(obj.idDriver){
    this->driverName=new char[strlen(obj.driverName)+1];
    strcpy(this->driverName,obj.driverName);
    this->category=obj.category;
    this->teamName=obj.teamName;
    this->age=obj.age;
    this->kartNumber=obj.kartNumber;
    this->noFaults=obj.noFaults;
    for(int i=0;i<this->noFaults;i++)
        this->faults[i]=obj.faults[i];
    this->championshipPoints=obj.championshipPoints;
}

///SUPRAINCARCARE


///-------------------------------------------EGAL----------------------------------------------
Drivers& operator = (const Drivers& obj){

    if(this!=&obj)
    {
        if(this->driverName!=NULL)
        {
            delete[] this->driverName;
            this->driverName=NULL;
        }

            if(this->faults!=NULL)
        {
            delete[] this->faults;
            this->faults=NULL;
        }


    this->driverName=new char[strlen(obj.driverName)+1];
    strcpy(this->driverName,obj.driverName);
    this->category=obj.category;
    this->teamName=obj.teamName;
    this->age=obj.age;
    this->kartNumber=obj.kartNumber;
    this->noFaults=obj.noFaults;
    for(int i=0;i<this->noFaults;i++)
        this->faults[i]=obj.faults[i];
    this->championshipPoints=obj.championshipPoints;

    }
    return *this;
}
///------------------------MIC----------------------
bool operator <(const Drivers& obj){

 if(this->championshipPoints<obj.championshipPoints)
    return true;
else return false;

}
///------------------------MARE----------------------
bool operator >(const Drivers& obj){

 if(this->championshipPoints>obj.championshipPoints)
    return true;
else return false;

}
///------------------------EGAL--EGAL----------------------------
bool operator ==(const Drivers& obj){

bool valid=true;

if(valid==true){

    if(strcmp(this->driverName,obj.driverName)!=0)
        valid=false;
}

if(valid==true){

    if(this->category!=obj.category)
        valid=false;
}

if(valid==true){

    if(this->teamName!=obj.teamName)
        valid=false;
}

if(valid==true){

    if(this->age!=obj.age)
        valid=false;
}

if(valid==true){

    if(this->kartNumber!=obj.kartNumber)
        valid=false;
}

if(valid==true){

    if(this->noFaults!=obj.noFaults)
        valid=false;
}

if(valid==true){

    for(int i=0;i<noFaults;i++)
        {
            if(this->faults[i]!=obj.faults[i])
                valid=false;
        }
}

if(valid==true){

    if(this->championshipPoints!=obj.championshipPoints)
        valid=false;
}


return valid;
}
///-------------------------PLUS-CU-OBIECTE--------------------------------
Drivers operator +(Drivers obj){

    obj.championshipPoints=this->championshipPoints+obj.championshipPoints;

    return obj;
}
///------------------------PLUS-CU-CONSTANTA--------------------
Drivers operator +(float addedPoints){

    Drivers cop(*this);

    cop.championshipPoints=cop.championshipPoints+addedPoints;

    return cop;
}
///------------------------MINUS-CU-OBIECTE--------------------
Drivers operator -(Drivers obj){

    obj.championshipPoints=this->championshipPoints-obj.championshipPoints;

    return obj;
}
///------------------------MINUS-CU-CONSTANTA--------------------
Drivers operator -(float substractedPoints){

    Drivers cop(*this);

    cop.championshipPoints=cop.championshipPoints-substractedPoints;

    return cop;
}

///-------------PLUS-PLUS-CEVA-------------------------------------
Drivers& operator++(){
    this->championshipPoints++;
    return *this;
}

///-----------------CEVA-PLUS-PLUS----------------------------------
Drivers operator ++(int){


    Drivers aux(*this);
    //this->championshipPoints++;
    ++(*this);

    return aux;
}

///---------------CONSTANTA-CU-PLUS---------------------------------
friend Drivers operator+(int, Drivers obj);

///--------------INDEXARE--------------------------------------------
int operator[](int i){
    if (this->faults ==NULL)
        throw runtime_error("There are no faults!");
    else if(i<0 || i>=noFaults)
        {
            throw runtime_error("Index invalid");
        }
        else return this->faults[i];

}

///--------------CAST----------------------------------------------
operator int() const{
        return this->age;
}

///----------------SCRIERE SI CITIRE--------------------------------
friend ostream& operator <<(ostream& out, const Drivers& obj);
friend istream& operator >>(istream& in, Drivers& obj);

///------------------DESTRUCTOR--------------------------------------

~Drivers()
{

    if(this->driverName!=NULL)
    {
       delete[] this->driverName;
        this->driverName=NULL;
    }

    this->faults=NULL;


    this->category='-';
    this->teamName="";
    this->age=0;
    this->kartNumber=-1;
    this->noFaults=0;
    this->championshipPoints=0;


}

///_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_FUNCTII_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-
void afisare()
{
    cout<<"ID: "<<idDriver<<endl;
    cout<<"Driver name: "<<driverName<<endl;
    cout<<"Category: "<<category<<endl;
    cout<<"Team name: "<<teamName<<endl;
    cout<<"Age: "<<age<<endl;
    cout<<"Kart number: "<<kartNumber<<endl;
    cout<<"Number of Faults: "<<noFaults<<endl;
    cout<<"Penalty points per fault: ";
    if(noFaults==0)
        cout<<"No faults!";
    else for(int i=0;i<noFaults;i++)
        cout<<faults[i]<<" ";
    cout<<endl;
    cout<<"Championship points: "<<championshipPoints<<endl<<endl;
}


};///___________________________________________F-I-N-I-S-H----C-L-A-S-A___________________________________________________________________________________

///---------------CONSTANTA-CU-PLUS---------------------------------
Drivers operator+(int x, Drivers obj){
    return obj+x;

    //sau
/*
    Drivers aux(*this);
    aux.championshipPoints+=x;
    return aux;
*/
}
///--------------------SCRIERE-DRIVERS---------------------------------------
ostream& operator <<(ostream& out, const Drivers& obj){

    out<<"ID: "<<obj.idDriver<<endl;
    out<<"Driver name: "<<obj.driverName<<endl;
    out<<"Category: "<<obj.category<<endl;
    out<<"Team name: "<<obj.teamName<<endl;
    out<<"Age: "<<obj.age<<endl;
    out<<"Kart number: "<<obj.kartNumber<<endl;
    out<<"Number of Faults: "<<obj.noFaults<<endl;
    out<<"Penalty points per fault: ";
    if(obj.noFaults==0)
        cout<<"No faults!";
    else for(int i=0;i<obj.noFaults;i++)
        out<<obj.faults[i]<<" ";
    out<<endl;
    out<<"Championship points: "<<obj.championshipPoints<<endl<<endl;

    return out;
}
///--------------------------CITIRE-DRIVERS-------------------------------------------
istream& operator >>(istream& in, Drivers& obj){


    cout << "New Driver Name: " << endl;
    char driverName[100];
    in.get(driverName,100);
    if(obj.driverName != NULL){
        delete[] obj.driverName;
        obj.driverName = NULL;
    }
    obj.driverName = new char[strlen(driverName) + 1];
    strcpy(obj.driverName, driverName);

        obj.faults = NULL;


    cout<<"Category: ";
    in>>obj.category;
    cout<<"Team name: ";
    in>>obj.teamName;
    cout<<"Age: ";
    in>>obj.age;
    cout<<"Kart number: ";
    in>>obj.kartNumber;
    cout<<"Number of Faults: ";
    in>>obj.noFaults;
    cout<<"Penalty points per fault: ";
    obj.faults=new int[obj.noFaults];
    if(obj.noFaults==0)
        cout<<"Clean driver!"<<endl;

    else
    {
        for(int i=0;i<obj.noFaults;i++)
            in>>obj.faults[i];
    }


    cout<<"Championship points: ";
    in>>obj.championshipPoints;
    cout<<endl;

    return in;

}
///----Pana aici chestii pt Drivers--------------------------------------------------------------------------------------------



class Teams{


    ///date
    static int contorId;
    const int idTeam;
    string teamName;
    string principalName;
    float staffPerDriver;
    int noStaff;
    int noCategories;
    int noDrivers;
    int noFines;
    int* fines;


public:
    ///Getters
    const int GetIdTeam()const{
        return idTeam;
    }
    string GetTeamName()const{
        return teamName;
    }
    string GetPrincipalName()const{
        return principalName;
    }
    int GetNoStaff()const{
        return noStaff;
    }
    int GetNoCategories()const{
        return noCategories;
    }
    int GetNoDrivers()const{
        return noDrivers;
    }
    int GetNoFines()const{
        return noFines;
    }
    int* GetFines()const{
        return fines;
    }

    ///Setters--------------------------

    void SetTeamName(string teamName){
        this->teamName=teamName;
    }
    void SetPrincipalName(string principalName){
        this->principalName=principalName;
    }
    void SetNoStaff(int noStaff){
        this->noStaff=noStaff;
    }
    void SetNoCategories(int noCategories){
        this->noCategories=noCategories;
    }
    void SetNoDrivers(int noDrivers){
        this->noDrivers=noDrivers;
    }
    void SetNoFines(int noFines){
        this->noFines=noFines;
    }
    ///Constructors-----------------

    Teams():idTeam(contorId++){

        teamName="Unknown name";
        principalName="Unknown name";
        noStaff=0;
        noCategories=0;
        noDrivers=0;
        noFines=0;
        fines=new int[0];
        fines[0]=0;

    }

    Teams(string teamName,string principalName,int noStaff,int noCategories,int noDrivers):idTeam(contorId++){

        this->teamName=teamName;
        this->principalName=principalName;
        this->noStaff=noStaff;
        this->noCategories=noCategories;
        this->noDrivers=noDrivers;
        this->noFines=noFines;
        this->fines=new int[noFines+1];
        for(int i=0;i<this->noFines;i++)
            this->fines[i]=fines[i];

    }

    Teams(string teamName,string principalName):idTeam(contorId++){

        this->teamName=teamName;
        this->principalName=principalName;
        noStaff=0;
        noCategories=0;
        noDrivers=0;
        noFines=0;
        fines=new int[0];
        fines[0]=0;


    }

    Teams(string principalName,int noStaff):idTeam(contorId++){

        this->teamName="To be announced";
        this->principalName=principalName;
        this->noStaff=noStaff;
        noCategories=0;
        noDrivers=0;
        noFines=0;
        fines=new int[0];
        fines[0]=0;


    }

///------------------copiere-------------------------------
Teams(const Teams& obj):idTeam(obj.idTeam){

        this->teamName=obj.teamName;
        this->principalName=obj.principalName;
        this->noStaff=obj.noStaff;
        this->noCategories=obj.noCategories;
        this->noDrivers=obj.noDrivers;
        this->noFines=obj.noFines;
        this->fines=new int[obj.noFines+1];
        for(int i=0;i<obj.noFines;i++)
            this->fines[i]=obj.fines[i];
}

///-----------------------EGAL----------------------------------------------
Teams& operator = (const Teams& obj){


        this->teamName=obj.teamName;
        this->principalName=obj.principalName;
        this->noStaff=obj.noStaff;
        this->noCategories=obj.noCategories;
        this->noDrivers=obj.noDrivers;
        this->noFines=obj.noFines;
        this->fines=new int[obj.noFines+1];
        for(int i=0;i<obj.noFines;i++)
            this->fines[i]=obj.fines[i];

    return *this;
}

///------------------------MIC----------------------
bool operator <(const Teams& obj){

 if(this->noDrivers<obj.noDrivers)
    return true;
else return false;

}
///------------------------MARE----------------------
bool operator >(const Teams& obj){

 if(this->noDrivers>obj.noDrivers)
    return true;
else return false;

}

///------------------------EGAL-EGAL--------------------------
bool operator ==(const Teams& obj){

    bool valid=true;

    if(valid!=false)
        if(this->teamName!=obj.teamName)
            valid=false;

    if(valid!=false)
        if(this->principalName!=obj.principalName)
            valid=false;

    if(valid!=false)
        if(this->noStaff!=obj.noStaff)
            valid=false;

    if(valid!=false)
        if(this->noCategories!=obj.noCategories)
            valid=false;

    if(valid!=false)
        if(this->noDrivers!=obj.noDrivers)
            valid=false;

    if(valid!=false)
        if(this->noFines!=obj.noFines)
            valid=false;

    if(valid!=false)
       for(int i=0;i<this->noFines;i++)
            if(this->fines[i]!=obj.fines[i])
                valid=false;

    return valid;

}

///-------------------------PLUS-CU-OBIECTE--------------------------------
Teams operator +(Teams obj){

    obj.noDrivers=this->noDrivers+obj.noDrivers;
    obj.noStaff=this->noStaff+obj.noStaff;
    obj.noFines=this->noFines+obj.noFines;


    return obj;
}

///------------------------PLUS-CU-CONSTANTA--------------------

Teams operator +(int addedDrivers){

    Teams cop(*this);

    cop.noDrivers=cop.noDrivers+addedDrivers;

    return cop;
}

///------------------------MINUS-CU-OBIECTE--------------------

Teams operator -(Teams obj){

    obj.noDrivers=this->noDrivers-obj.noDrivers;

    return obj;
}

///------------------------MINUS-CU-CONSTANTA--------------------
Teams operator -(float substractedDrivers){

    Teams cop(*this);

    cop.noDrivers=cop.noDrivers-substractedDrivers;

    return cop;
}

///-------------PLUS-PLUS-CEVA-------------------------------------
Teams& operator++(){
    this->noDrivers++;
    return *this;
}

///-----------------CEVA-PLUS-PLUS----------------------------------
Teams operator ++(int){
    Teams aux(*this);
    //this->noDrivers++;
    ++(*this);

    return aux;
}

///---------------CONSTANTA-CU-PLUS---------------------------------
friend Teams operator+(int x,Teams obj);

///--------------CAST----------------------------------------------
operator int() const{
        return this->noFines;
}

///-----------------CITIRE SI SCRIERE--------------------------
friend ostream& operator <<(ostream& out, const Teams& obj);
friend istream& operator >>(istream& in, Teams& obj);

///_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_FUNCTII_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-
void afisare()
{
    cout<<"Id: "<<idTeam<<endl;
    cout<<"Team Name: "<<teamName<<endl;
    cout<<"Principal name: "<<principalName<<endl;
    cout<<"Number of staff members: "<<noStaff<<endl;
    cout<<"Number of categories: "<<noCategories<<endl;
    cout<<"Number of drivers: "<<noDrivers<<endl;
    cout<<"Number of fines: "<<noFines<<endl;
    cout<<"Fines:";
    for(int i=0;i<noFines;i++)
        cout<<fines[i]<<" ";
    cout<<endl;
}
};
///--------------------CONSTANTA-PLUS-OBIECT---------------------------------------------------------
Teams operator+(int x, Teams obj)
{
    return obj+x;

    //sau
/*
    Teams aux(*this);
    aux.noDrivers+=x;
    return aux;
*/

}
///--------------------SCRIERE-TEAMS---------------------------------------
ostream& operator <<(ostream& out, const Teams& obj){

    out<<"Id: "<<obj.idTeam<<endl;
    out<<"Team Name: "<<obj.teamName<<endl;
    out<<"Principal name: "<<obj.principalName<<endl;
    out<<"Number of staff members: "<<obj.noStaff<<endl;
    out<<"Number of categories: "<<obj.noCategories<<endl;
    out<<"Number of drivers: "<<obj.noDrivers<<endl;
    out<<"Number of fines: "<<obj.noFines<<endl;
    out<<"Fines:";
    for(int i=0;i<obj.noFines;i++)
        out<<obj.fines[i]<<" ";
    out<<endl;



    return out;
}
///--------------------------CITIRE-TEAMS-------------------------------------------
istream& operator >>(istream& in, Teams& obj){


    cout<<"Team Name: ";
    in>>obj.teamName;
    cout<<"Principal name: ";
    in>>obj.principalName;
    cout<<"Number of staff members: ";
    in>>obj.noStaff;
    cout<<"Number of categories: ";
    in>>obj.noCategories;
    cout<<"Number of drivers: ";
    in>>obj.noDrivers;
    cout<<"Number of fines: ";
    in>>obj.noFines;
    cout<<"Fines:";
    for(int i=0;i<obj.noFines;i++)
        in>>obj.fines[i];
    cout<<endl;



    return in;

}

///-----Pana aici chestii pt Teams----------------------------------------------------------------------------------------------
//Contoare
int Drivers::contorId=1;
int Racetracks::contorId=1;
int Races::contorId=1;
int Teams::contorId=1;


int main()
{
int chooseClass;
int choice;
int whichConstructor,whichGetter,whichSetter,whichFunction;
char whichOperation;
bool inClass=true,inRaces=true,inRacetracks=true,inDrivers=true,inTeams=true;
int objectNumber,objectNumber2;

int brench;
bool inBrench=true;
int chooseNoDrivers=0;
int objId,objId2,operationNumber;
string TrackName,Location;
float Length;
int NoCorners;



vector<Races>vRaces;
vector<Racetracks>vRacetracks;
vector<Drivers>vDrivers;
vector<Teams>vTeams;




///_______________________________________________________________________________

while(inBrench==true){


    cout<<"Choose what do you want from me..."<<endl;
    cout<<"1-> Create your own championship(story)"<<endl;
    cout<<"2-> Access all the functions(getters,setters,constructors,etc)"<<endl;
    cout<<"3-> Leave me alone"<<endl;
    cin>>brench;

    switch(brench)
    {
        case 1:
            {

                cout<<"Welcome to your own championship!"<<endl;
                cout<<"Let's add your first race. For now, we will create a race with all the information."<<endl;
                Races r;
                cin>>r;
                vRaces.push_back(r);
                system("CLS");
                cout<<endl<<"That's the first race:"<<endl;
                cout<<r;


                cout<<endl<<"All good, now let's add some info to you racetrack: "<<vRaces[vRaces.size()-1].GetRaceTrack()<<endl;
                Racetracks rt;
                cin>>rt;
                if(rt.GetTrackName()!=vRaces[vRaces.size()-1].GetRaceTrack())
                {
                    cout<<"You previously named it "<<vRaces[vRaces.size()-1].GetRaceTrack()<<". Do you want to keep the changes?(0/1)"<<endl;
                    cin>>choice;
                    if(choice==1)
                        {
                            vRaces[vRaces.size()-1].SetRaceTrack(rt.GetTrackName());
                        }
                    else
                        {
                            rt.SetTrackName(vRaces[vRaces.size()-1].GetRaceTrack());
                        }
                }
                vRacetracks.push_back(rt);
                cout<<"That is the racetrack!"<<endl;
                cout<<rt;

                cout<<endl<<"Now let's add a team!"<<endl;
                Teams t;
                cin>>t;
                vTeams.push_back(t);
                system("CLS");
                cout<<endl<<"That's your first team!"<<endl;;
                cout<<t;

                cout<<"Your team has "<<vTeams[vTeams.size()-1].GetNoDrivers()<<" drivers. How many of them do you want to register?"<<endl;
                cin>>chooseNoDrivers;

                while(chooseNoDrivers!=0)
                {
                                cout<<"Which constructor?"<<endl;
                                cout<<"1->No parameters 2->All parameters 3->Abort"<<endl;
                                cin>>whichConstructor;
                                switch(whichConstructor)
                                {
                                    case 1:
                                        {
                                        Drivers d;
                                        d.SetTeamName(vTeams[vTeams.size()-1].GetTeamName());
                                        vDrivers.push_back(d);
                                        cout<<vDrivers[vDrivers.size()-1];
                                        cout<<"Driver added!"<<endl<<endl;
                                        chooseNoDrivers--;
                                        break;
                                        }
                                    case 2:
                                        {
                                        Drivers d;
                                        cin>>d;
                                        vDrivers.push_back(d);
                                        cout<<"Object created!"<<endl<<endl;
                                        cout<<vDrivers[vDrivers.size()-1];
                                        chooseNoDrivers--;
                                        break;
                                        }

                                    case 3:
                                        {
                                            cout<<"Quiting constructors..."<<endl;
                                            break;
                                        }
                                    default:
                                        {
                                            cout<<"Invalid task. Please try again!"<<endl;
                                            break;
                                        }
                                }
                }

                cout<<"You are all done! Now that you have any kind of object, you are free to add more, modify, select or apply functions for them. Enjoy!"<<endl;


                break;
            }

        case 2:
            {
                ///________________________Constructors/getters/setters/operators_________________________________________
    while(inClass==true)
    {
        cout<<"In which class do you want to work?"<<endl;
        cout<<"1->Races  2->Racetracks  3->Drivers  4->Teams 5->Mix Them 6->Leave"<<endl;
        cin>>chooseClass;

        switch(chooseClass)
        {
            case 1:
                {
                    cout<<"You chose class Races"<<endl;
                    inRaces=true;

                    while(inRaces==true)
                    {
                        cout<<"Choose what to do..."<<endl;
                        cout<<"1->Constructor 2->Getter 3->Setter 4->Operation(1 Object) 5->Operation(2 Objects) 6->Function 7->Leave Class"<<endl;
                        cin>>choice;
                        switch(choice)
                        {
                            case 1: ///Constructors
                                {
                                    cout<<"Which constructor?"<<endl;
                                    cout<<"1->No parameters 2->All parameters 3->Some parameters v1 4->Some parameters v2 5->Abort"<<endl;
                                    cin>>whichConstructor;
                                    switch(whichConstructor)
                                    {
                                        case 1:
                                            {
                                            Races r;
                                            vRaces.push_back(r);
                                            cout<<"Object created!"<<endl<<endl;
                                            cout<<vRaces[vRaces.size()-1];
                                            break;
                                            }
                                        case 2:
                                            {
                                            Races r;
                                            cin>>r;
                                            vRaces.push_back(r);
                                            cout<<"Object created!"<<endl<<endl;
                                            cout<<vRaces[vRaces.size()-1];
                                            break;
                                            }
                                        case 3:
                                            {
                                                string StartDate;
                                                int NoParticipants;
                                                char* MainSponsor;
                                                MainSponsor=new char[100];
                                                cout<<"Input start date: ";
                                                cin>>StartDate;
                                                cout<<"Input number of participants: ";
                                                cin>>NoParticipants;
                                                cin.get();
                                                cout<<"Input the main sponsor: ";
                                                cin.get(MainSponsor,100);

                                                Races r(StartDate,NoParticipants,MainSponsor);

                                                vRaces.push_back(r);
                                                cout<<"Object created!"<<endl<<endl;
                                                cout<<vRaces[vRaces.size()-1];
                                                delete[] MainSponsor;
                                                MainSponsor=NULL;

                                                break;

                                            }
                                        case 4:
                                            {
                                                string TrackName;
                                                bool NightRace;
                                                int NoSponsors;
                                                cout<<"Input track name: ";
                                                cin>>TrackName;
                                                cout<<"Input night race(1/0): ";
                                                cin>>NightRace;
                                                cout<<"Input number of sponsors: ";
                                                cin>>NoSponsors;

                                                Races r(TrackName,NightRace,NoSponsors);

                                                vRaces.push_back(r);
                                                cout<<"Object created!"<<endl<<endl;
                                                cout<<vRaces[vRaces.size()-1];

                                                break;


                                            }
                                        case 5:
                                            {
                                                cout<<"Quiting constructors..."<<endl;
                                                break;
                                            }
                                        default:
                                            {
                                                cout<<"Invalid task. Please try again!"<<endl;
                                                break;
                                            }
                                    }
                                    break;
                                }

                            case 2: ///Getters
                                {
                                    cout<<"First of all, choose an object.";
                                    if(vRaces.size()>0)
                                    {
                                        cout<<"You have "<<vRaces.size()<<" objects."<<endl;
                                        cin>>objectNumber;
                                        for(int i=0;i<vRaces.size();i++)
                                            if(vRaces[i].GetIdRace()==objectNumber)
                                            {
                                                objId=i;
                                                break;
                                            }

                                    }
                                    else
                                    {
                                        cout<<endl;
                                        cout<<"You have NO OBJECTS. Please create one!"<<endl;
                                        break;
                                    }
                                    cout<<"What do you want do get?"<<endl;
                                    cout<<"1->Race Track 2->First day of the event 3->Day/Night Race 4->Number of participants 5->Number of sponsors 6->The main sponsor 7->Abort"<<endl;
                                    cin>>whichGetter;

                                    switch(whichGetter)
                                    {
                                        case 1:
                                            {
                                                cout<<vRaces[objId].GetRaceTrack()<<endl;
                                                break;
                                            }
                                        case 2:
                                            {
                                                cout<<vRaces[objId].GetStartDate()<<endl;
                                                break;
                                            }
                                        case 3:
                                            {
                                                if(vRaces[objId].GetNightRace()==false)
                                                    cout<<"Day Race"<<endl;
                                                else cout<<"Night Race"<<endl;

                                                break;
                                            }
                                        case 4:
                                            {
                                                cout<<vRaces[objId].GetNoParticipants()<<endl;
                                                break;
                                            }
                                        case 5:
                                            {
                                                cout<<vRaces[objId].GetNoSponsors()<<endl;
                                                break;
                                            }
                                        case 6:
                                            {
                                                cout<<vRaces[objId].GetMainSponsor()<<endl;
                                                break;
                                            }
                                        case 7:
                                            {
                                                cout<<"Quitting Getters..."<<endl;
                                                break;
                                            }
                                        default:
                                            {
                                                cout<<"Invalid task. Please try again!";
                                                break;
                                            }
                                    }
                                    break;
                                }

                            case 3: ///Setters
                                {
                                    cout<<"First of all, choose an object.";
                                    if(vRaces.size()>0)
                                    {
                                        cout<<"You have "<<vRaces.size()<<" objects."<<endl;
                                        cin>>objectNumber;
                                        for(int i=0;i<vRaces.size();i++)
                                            if(vRaces[i].GetIdRace()==objectNumber)
                                            {
                                                objId=i;
                                                break;
                                            }
                                    }
                                    else
                                    {
                                        cout<<endl;
                                        cout<<"You have NO OBJECTS. Please create one!"<<endl;
                                        break;
                                    }
                                    cout<<"What do you want do set?"<<endl;
                                    cout<<"1->Race Track 2->First day of the event 3->Day(0)/Night(1)Race 4->Number of participants 5->Number of sponsors 6->The main sponsor 7->Abort"<<endl;
                                    cin>>whichSetter;

                                    switch(whichSetter)
                                    {
                                        case 1:
                                            {
                                                string RaceTrack;
                                                cin>>RaceTrack;
                                                vRaces[objId].SetRaceTrack(RaceTrack);
                                                cout<<"Attribute modified successfully!"<<endl;
                                                break;
                                            }
                                        case 2:
                                            {
                                                string StartDate;
                                                cin>>StartDate;
                                                vRaces[objId].SetStartDate(StartDate);
                                                cout<<"Attribute modified successfully!"<<endl;
                                                break;
                                            }
                                        case 3:
                                            {
                                                bool NightRace;
                                                cin>>NightRace;
                                                vRaces[objId].SetNightRace(NightRace);
                                                cout<<"Attribute modified successfully!"<<endl;
                                                break;
                                            }
                                        case 4:
                                            {
                                                int NoParticipants;
                                                cin>>NoParticipants;
                                                vRaces[objId].SetNoParticipants(NoParticipants);
                                                cout<<"Attribute modified successfully!"<<endl;
                                                break;
                                            }
                                        case 5:
                                            {
                                                int NoSponsors;
                                                cin>>NoSponsors;
                                                vRaces[objId].SetNoSponsors(NoSponsors);
                                                cout<<"Attribute modified successfully!"<<endl;
                                                break;
                                            }
                                        case 6:
                                            {
                                                char* MainSponsor;
                                                MainSponsor=new char[100];
                                                cin.get();
                                                cin.get(MainSponsor,100);
                                                vRaces[objId].SetMainSponsor(MainSponsor);

                                                cout<<"Attribute modified successfully!"<<endl;
                                                break;
                                            }
                                        case 7:
                                            {
                                                cout<<"Quitting Setters..."<<endl;
                                                break;
                                            }
                                        default:
                                            {
                                                cout<<"Invalid task. Please try again!";
                                                break;
                                            }
                                    }
                                    break;
                                }

                            case 4:///Operation(1 Object)
                                {
                                    cout<<"First of all, choose an object.";
                                    if(vRaces.size()>0)
                                    {
                                        cout<<"You have "<<vRaces.size()<<" objects."<<endl;
                                        cin>>objectNumber;
                                        for(int i=0;i<vRaces.size();i++)
                                            if(vRaces[i].GetIdRace()==objectNumber)
                                            {
                                                objId=i;
                                                break;
                                            }

                                    }
                                    else
                                    {
                                        cout<<endl;
                                        cout<<"You have NO OBJECTS. Please create one!"<<endl;
                                        break;
                                    }

                                    cout<<"Now choose an operation."<<endl;
                                    cout<<"'+'  '-'  '++'->'#'"<<endl;
                                    cin>>whichOperation;

                                    switch(whichOperation)
                                    {
                                    case '+':
                                        {
                                            cout<<"How much do you want to add?"<<endl;
                                            cin>>operationNumber;
                                            vRaces[objId]=vRaces[objId]+operationNumber;
                                            cout<<vRaces[objId]<<endl;
                                            break;
                                        }
                                    case '-':
                                        {
                                            cout<<"How much do you want to substract?"<<endl;
                                            cin>>operationNumber;
                                            vRaces[objId]=vRaces[objId]-operationNumber;
                                            cout<<vRaces[objId]<<endl;
                                            break;
                                        }

                                    case '#':
                                        {
                                            cout<<++vRaces[objId];
                                            break;
                                        }
                                    }
                                    break;
                                }

                            case 5: ///Operation(2 Objects)
                                {
                                    cout<<"First of all, choose two objects.";
                                    if(vRaces.size()>=2)
                                    {
                                        cout<<"You have "<<vRaces.size()<<" objects."<<endl;
                                        cin>>objectNumber;
                                        cin>>objectNumber2;
                                        objId=-1;
                                        objId=-1;
                                        for(int i=0;i<vRaces.size();i++)
                                            if(vRaces[i].GetIdRace()==objectNumber || vRaces[i].GetIdRace()==objectNumber)
                                            {
                                                if(objId==-1)
                                                    objId=i;
                                                else
                                                    objId2=i;
                                                break;
                                            }
                                    }
                                    else
                                    {
                                        cout<<endl;
                                        cout<<"You don't have enough objects. Please create more!"<<endl;
                                        break;
                                    }
                                    cout<<"Now choose an operation."<<endl;
                                    cout<<"'+'  '-'  '='  '<'  '>'  '=='->'#'  Abort->'/'"<<endl;

                                    cin>>whichOperation;

                                    switch(whichOperation)
                                    {
                                        case '+':
                                            {
                                                cout<<(vRaces[objId]+vRaces[objId2]);
                                                break;
                                            }
                                        case '-':
                                            {
                                                cout<<(vRaces[objId]-vRaces[objId2]);
                                                break;
                                            }
                                        case '=':
                                            {
                                                vRaces[objId]=vRaces[objId2];
                                                break;
                                            }
                                        case '#':
                                            {
                                                cout<<(vRaces[objId]==vRaces[objId2])<<endl;
                                                break;
                                            }
                                        case '<':
                                            {
                                                cout<<(vRaces[objId]<vRaces[objId2]);
                                                break;
                                            }
                                        case '>':
                                            {
                                                cout<<(vRaces[objId]>vRaces[objId2]);
                                                break;
                                            }
                                        case '/':
                                            {
                                                cout<<"Quitting Operation(2 Objects)..."<<endl;
                                                break;
                                            }
                                        default:
                                            {
                                                cout<<"Invalid task. Please try again!";
                                                break;
                                            }



                                    }
                                    break;
                                }

                            case 6: ///Functions
                                {
                                 cout<<"Choose a function"<<endl;
                                 cout<<"Print an object->1  Print all objects->2"<<endl;
                                 cout<<"Index->3(not available)  Cast->4  Read an object->5"<<endl;
                                 cout<<"Delete an object->6  Abort->7"<<endl;

                                 cin>>whichFunction;
                                 switch(whichFunction)
                                 {
                                    case 1:
                                        {
                                            cout<<"First of all, choose an object.";
                                            if(vRaces.size()>0)
                                            {
                                                cout<<"You have "<<vRaces.size()<<" objects."<<endl;
                                                cin>>objectNumber;
                                                for(int i=0;i<vRaces.size();i++)
                                                    if(vRaces[i].GetIdRace()==objectNumber)
                                                    {
                                                        objId=i;
                                                        break;
                                                    }

                                            }
                                            else
                                            {
                                                cout<<endl;
                                                cout<<"You have NO OBJECTS. Please create one!"<<endl;
                                                break;
                                            }

                                            cout<<vRaces[objId];

                                            break;
                                        }


                                    case 2:
                                        {

                                            if(vRaces.size()==0)
                                                cout<<"You have no objects to print"<<endl;
                                            else
                                                for(int i=0;i<vRaces.size();i++)
                                                    cout<<vRaces[i]<<endl;

                                            break;
                                        }

                                    case 3:
                                        {
                                            cout<<"Not available for now"<<endl;
                                            break;
                                        }
                                    case 4:
                                        {
                                            cout<<"First of all, choose an object.";
                                            if(vRaces.size()>0)
                                            {
                                                cout<<"You have "<<vRaces.size()<<" objects."<<endl;
                                                cin>>objectNumber;
                                                for(int i=0;i<vRaces.size();i++)
                                                    if(vRaces[i].GetIdRace()==objectNumber)
                                                    {
                                                        objId=i;
                                                        break;
                                                    }

                                            }
                                            else
                                            {
                                                cout<<endl;
                                                cout<<"You have NO OBJECTS. Please create one!"<<endl;
                                                break;
                                            }

                                            cout<<(int)vRaces[objId]<<endl<<endl;

                                            break;
                                        }
                                    case 5:
                                        {
                                            Races x;
                                            cin>>x;
                                            vRaces.push_back(x);
                                            cout<<vRaces[vRaces.size()-1]<<endl<<endl;
                                            break;
                                        }
                                    case 6:
                                        {
                                            cout<<"First of all, choose an object.";
                                            if(vRaces.size()>0)
                                            {
                                                cout<<"You have "<<vRaces.size()<<" objects."<<endl;
                                                cin>>objectNumber;
                                                for(int i=0;i<vRaces.size();i++)
                                                    if(vRaces[i].GetIdRace()==objectNumber)
                                                    {
                                                        objId=i;
                                                        break;
                                                    }

                                            }
                                            else
                                            {
                                                cout<<endl;
                                                cout<<"You have NO OBJECTS. Please create one!"<<endl;
                                                break;
                                            }

                                            vRaces.erase(vRaces.begin()+objId);
                                            break;
                                        }
                                    case 7:
                                        {
                                            cout<<"Quitting functions..."<<endl<<endl;
                                            break;
                                        }
                                    default:
                                        {
                                            cout<<"Unknown command..."<<endl<<endl;
                                            break;
                                        }
                                 }


                                 break;
                                }

                            case 7: ///Quit
                                {
                                    cout<<"Quitting class..."<<endl<<endl;
                                    inRaces=false;
                                    break;
                                }
                            default:
                                {
                                    cout<<"Unknown command"<<endl;
                                    break;
                                }
                        }


                    }
                break;

                }
            case 2:
                {
                cout<<"You chose class Racetracks"<<endl;

                   inRacetracks=true;

                    while(inRacetracks==true)
                    {
                        cout<<"Choose what to do..."<<endl;
                        cout<<"1->Constructor 2->Getter 3->Setter 4->Operation(1 Object) 5->Operation(2 Objects) 6->Function 7->Leave Class"<<endl;
                        cin>>choice;
                        switch(choice)
                        {
                            case 1: ///Constructors
                                {
                                    cout<<"Which constructor?"<<endl;
                                    cout<<"1->No parameters 2->All parameters 3->Some parameters v1 4->Some parameters v2 5->Abort"<<endl;
                                    cin>>whichConstructor;
                                    switch(whichConstructor)
                                    {
                                        case 1:
                                            {
                                            Racetracks rt;
                                            vRacetracks.push_back(rt);
                                            cout<<"Object created!"<<endl<<endl;
                                            cout<<vRacetracks[vRacetracks.size()-1];
                                            break;
                                            }
                                        case 2:
                                            {
                                            Racetracks rt;
                                            cin>>rt;
                                            vRacetracks.push_back(rt);
                                            cout<<"Object created!"<<endl<<endl;
                                            cout<<vRacetracks[vRacetracks.size()-1];
                                            break;
                                            }
                                        case 3:
                                            {

                                                cout<<"Track name: ";
                                                cin>>TrackName;
                                                cout<<"Location: ";
                                                cin>>Location;

                                                Racetracks rt(TrackName,Location);
                                                vRacetracks.push_back(rt);
                                                cout<<"Object created!"<<endl<<endl;
                                                cout<<vRacetracks[vRacetracks.size()-1];
                                                break;

                                            }
                                        case 4:
                                            {

                                                cout<<"Track name: ";
                                                cin>>TrackName;
                                                cout<<"Location: ";
                                                cin>>Location;
                                                cout<<"Length: ";
                                                cin>>Length;
                                                cout<<"Number of corners: ";
                                                cin>>NoCorners;

                                                Racetracks rt(TrackName,Location,Length,NoCorners);

                                                vRacetracks.push_back(rt);
                                                cout<<"Object created!"<<endl<<endl;
                                                cout<<vRacetracks[vRacetracks.size()-1];

                                                break;


                                            }
                                        case 5:
                                            {
                                                cout<<"Quiting constructors..."<<endl;
                                                break;
                                            }
                                        default:
                                            {
                                                cout<<"Invalid task. Please try again!"<<endl;
                                                break;
                                            }
                                    }
                                    break;
                                }

                            case 2: ///Getters
                                {
                                    cout<<"First of all, choose an object.";
                                    if(vRacetracks.size()>0)
                                    {
                                        cout<<"You have "<<vRacetracks.size()<<" objects."<<endl;
                                        cin>>objectNumber;
                                        for(int i=0;i<vRacetracks.size();i++)
                                            if(vRacetracks[i].GetIdTrack()==objectNumber)
                                            {
                                                objId=i;
                                                break;
                                            }

                                    }
                                    else
                                    {
                                        cout<<endl;
                                        cout<<"You have NO OBJECTS. Please create one!"<<endl;
                                        break;
                                    }

                                    cout<<"What do you want do get?"<<endl;
                                    cout<<"1->Track Name 2->Location 3->Circuit Length 4->Clockwise direction? 5->Number of corners 6->Abort"<<endl;
                                    cin>>whichGetter;

                                    switch(whichGetter)
                                    {
                                        case 1:
                                            {
                                                cout<<vRacetracks[objId].GetTrackName()<<endl;
                                                break;
                                            }
                                        case 2:
                                            {
                                                cout<<vRacetracks[objId].GetLocation()<<endl;
                                                break;
                                            }
                                        case 3:
                                            {
                                                cout<<vRacetracks[objId].GetLength()<<endl;
                                                break;
                                            }
                                        case 4:
                                            {
                                                if(vRacetracks[objId].GetClockwise()==false)
                                                    cout<<"Direction anti-clockwise"<<endl;
                                                else
                                                    cout<<"Direction clockwise"<<endl;
                                                break;
                                            }
                                        case 5:
                                            {
                                                cout<<vRacetracks[objId].GetNoCorners()<<endl;
                                                break;
                                            }
                                        case 6:
                                            {
                                                cout<<"Quitting Getters..."<<endl;
                                                break;
                                            }
                                        default:
                                            {
                                                cout<<"Invalid task. Please try again!";
                                                break;
                                            }
                                    }
                                    break;
                                }

                            case 3: ///Setters
                                {
                                    cout<<"First of all, choose an object.";
                                    if(vRacetracks.size()>0)
                                    {
                                        cout<<"You have "<<vRacetracks.size()<<" objects."<<endl;
                                        cin>>objectNumber;
                                        for(int i=0;i<vRacetracks.size();i++)
                                            if(vRacetracks[i].GetIdTrack()==objectNumber)
                                            {
                                                objId=i;
                                                break;
                                            }
                                    }
                                    else
                                    {
                                        cout<<endl;
                                        cout<<"You have NO OBJECTS. Please create one!"<<endl;
                                        break;
                                    }
                                    cout<<"What do you want do set?"<<endl;
                                    cout<<"1->Track Name 2->Location 3->Circuit Length 4->Clockwise direction? 5->Number of corners 6->Abort"<<endl;
                                    cin>>whichSetter;

                                    switch(whichSetter)
                                    {
                                        case 1:
                                            {
                                                string TrackName;
                                                cin>>TrackName;
                                                vRacetracks[objId].SetTrackName(TrackName);
                                                cout<<"Attribute modified successfully!"<<endl;
                                                break;
                                            }
                                        case 2:
                                            {
                                                string Location;
                                                cin>>Location;
                                                vRacetracks[objId].SetLocation(Location);
                                                cout<<"Attribute modified successfully!"<<endl;
                                                break;
                                            }
                                        case 3:
                                            {
                                                float Length;
                                                cin>>Length;
                                                vRacetracks[objId].SetLength(Length);
                                                cout<<"Attribute modified successfully!"<<endl;
                                                break;
                                            }
                                        case 4:
                                            {

                                                bool Clockwise;
                                                cin>>Clockwise;
                                                vRacetracks[objId].SetClockwise(Clockwise);
                                                cout<<"Attribute modified successfully!"<<endl;
                                                break;
                                            }
                                        case 5:
                                            {
                                                int NoCorners;
                                                cin>>NoCorners;
                                                vRacetracks[objId].SetNoCorners(NoCorners);
                                                cout<<"Attribute modified successfully!"<<endl;
                                                break;
                                            }
                                        case 6:
                                            {
                                                cout<<"Quitting Setters..."<<endl;
                                                break;
                                            }
                                        default:
                                            {
                                                cout<<"Invalid task. Please try again!";
                                                break;
                                            }
                                    }
                                    break;
                                }

                            case 4:///Operation(1 Object)
                                {
                                    cout<<"First of all, choose an object.";
                                    if(vRacetracks.size()>0)
                                    {
                                        cout<<"You have "<<vRacetracks.size()<<" objects."<<endl;
                                        cin>>objectNumber;
                                        for(int i=0;i<vRacetracks.size();i++)
                                            if(vRacetracks[i].GetIdTrack()==objectNumber)
                                            {
                                                objId=i;
                                                break;
                                            }
                                    }
                                    else
                                    {
                                        cout<<endl;
                                        cout<<"You have NO OBJECTS. Please create one!"<<endl;
                                        break;
                                    }

                                    cout<<"Now choose an operation."<<endl;
                                    cout<<"'+'  '-'  '++'->'#'"<<endl;
                                    cin>>whichOperation;

                                    switch(whichOperation)
                                    {
                                    case '+':
                                        {
                                            cout<<"How much do you want to add?"<<endl;
                                            cin>>operationNumber;
                                            vRacetracks[objId]=vRacetracks[objId]+operationNumber;
                                            cout<<vRacetracks[objId]<<endl;
                                            break;
                                        }
                                    case '-':
                                        {
                                            cout<<"How much do you want to substract?"<<endl;
                                            cin>>operationNumber;
                                            vRacetracks[objId]=vRacetracks[objId]-operationNumber;
                                            cout<<vRacetracks[objId]<<endl;
                                            break;
                                        }

                                    case '#':
                                        {
                                            cout<<++vRacetracks[objId];
                                            break;
                                        }
                                    }
                                    break;
                                }

                            case 5: ///Operation(2 Objects)
                                {
                                    cout<<"First of all, choose two objects.";
                                    if(vRacetracks.size()>=2)
                                    {
                                        cout<<"You have "<<vRacetracks.size()<<" objects."<<endl;
                                        cin>>objectNumber;
                                        cin>>objectNumber2;
                                        objId=-1;
                                        objId=-2;
                                        for(int i=0;i<vRacetracks.size();i++)
                                            if(vRacetracks[i].GetIdTrack()==objectNumber || vRacetracks[i].GetIdTrack()==objectNumber)
                                            {
                                                if(objId==-1)
                                                    objId=i;
                                                else
                                                    objId2=i;
                                                break;
                                            }
                                    }
                                    else
                                    {
                                        cout<<endl;
                                        cout<<"You don't have enough objects. Please create more!"<<endl;
                                        break;
                                    }
                                    cout<<"Now choose an operation."<<endl;
                                    cout<<"'+'  '-'  '='  '<'  '>'  '=='->'#'  Abort->'/'"<<endl;

                                    cin>>whichOperation;

                                    switch(whichOperation)
                                    {
                                        case '+':
                                            {
                                                cout<<(vRacetracks[objId]+vRacetracks[objId2]);
                                                break;
                                            }
                                        case '-':
                                            {
                                                cout<<(vRacetracks[objId]-vRacetracks[objId2]);
                                                break;
                                            }
                                        case '=':
                                            {
                                                vRacetracks[objId]=vRacetracks[objId2];
                                                break;
                                            }
                                        case '#':
                                            {
                                                cout<<(vRacetracks[objId]==vRacetracks[objId2])<<endl;
                                                break;
                                            }
                                        case '<':
                                            {
                                                cout<<(vRacetracks[objId]<vRacetracks[objId2]);
                                                break;
                                            }
                                        case '>':
                                            {
                                                cout<<(vRacetracks[objId]>vRacetracks[objId2]);
                                                break;
                                            }
                                        case '/':
                                            {
                                                cout<<"Quitting Operation(2 Objects)..."<<endl;
                                                break;
                                            }
                                        default:
                                            {
                                                cout<<"Invalid task. Please try again!";
                                                break;
                                            }



                                    }
                                    break;
                                }

                            case 6: ///Functions
                                {
                                 cout<<"Choose a function"<<endl;
                                 cout<<"Print an object->1  Print all objects->2"<<endl;
                                 cout<<"Index->3(not available)  Cast->4  Read an object->5"<<endl;
                                 cout<<"Print direction->6"<<endl;
                                 cout<<"Delete an object->7  Abort->8"<<endl;

                                 cin>>whichFunction;
                                 switch(whichFunction)
                                 {
                                    case 1:
                                        {
                                            cout<<"First of all, choose an object.";
                                            if(vRacetracks.size()>0)
                                            {
                                                cout<<"You have "<<vRacetracks.size()<<" objects."<<endl;
                                                cin>>objectNumber;
                                                for(int i=0;i<vRacetracks.size();i++)
                                                    if(vRacetracks[i].GetIdTrack()==objectNumber)
                                                    {
                                                        objId=i;
                                                        break;
                                                    }

                                            }
                                            else
                                            {
                                                cout<<endl;
                                                cout<<"You have NO OBJECTS. Please create one!"<<endl;
                                                break;
                                            }

                                            cout<<vRacetracks[objId];

                                            break;
                                        }


                                    case 2:
                                        {

                                            if(vRacetracks.size()==0)
                                                cout<<"You have no objects to print"<<endl;
                                            else
                                                for(int i=0;i<vRacetracks.size();i++)
                                                    cout<<vRacetracks[i]<<endl;

                                            break;
                                        }

                                    case 3:
                                        {
                                            cout<<"Not available for now"<<endl;
                                            break;
                                        }
                                    case 4:
                                        {
                                            cout<<"First of all, choose an object.";
                                            if(vRacetracks.size()>0)
                                            {
                                                cout<<"You have "<<vRacetracks.size()<<" objects."<<endl;
                                                cin>>objectNumber;
                                                for(int i=0;i<vRacetracks.size();i++)
                                                    if(vRacetracks[i].GetIdTrack()==objectNumber)
                                                    {
                                                        objId=i;
                                                        break;
                                                    }

                                            }
                                            else
                                            {
                                                cout<<endl;
                                                cout<<"You have NO OBJECTS. Please create one!"<<endl;
                                                break;
                                            }

                                            cout<<(int)vRacetracks[objId]<<endl<<endl;

                                            break;
                                        }
                                    case 5:
                                        {
                                            Racetracks x;
                                            cin>>x;
                                            vRacetracks.push_back(x);
                                            cout<<vRacetracks[vRacetracks.size()-1]<<endl<<endl;
                                            break;
                                        }
                                    case 6:
                                        {
                                            cout<<"First of all, choose an object.";
                                            if(vRacetracks.size()>0)
                                            {
                                                cout<<"You have "<<vRacetracks.size()<<" objects."<<endl;
                                                cin>>objectNumber;
                                                for(int i=0;i<vRacetracks.size();i++)
                                                    if(vRacetracks[i].GetIdTrack()==objectNumber)
                                                    {
                                                        objId=i;
                                                        break;
                                                    }

                                            }
                                            else
                                            {
                                                cout<<endl;
                                                cout<<"You have NO OBJECTS. Please create one!"<<endl;
                                                break;
                                            }

                                            vRacetracks[objId].afisareClockwise();
                                            break;
                                        }
                                    case 7:
                                        {
                                            cout<<"First of all, choose an object.";
                                            if(vRacetracks.size()>0)
                                            {
                                                cout<<"You have "<<vRacetracks.size()<<" objects."<<endl;
                                                cin>>objectNumber;
                                                for(int i=0;i<vRacetracks.size();i++)
                                                    if(vRacetracks[i].GetIdTrack()==objectNumber)
                                                    {
                                                        objId=i;
                                                        break;
                                                    }

                                            }
                                            else
                                            {
                                                cout<<endl;
                                                cout<<"You have NO OBJECTS. Please create one!"<<endl;
                                                break;
                                            }

                                            vRacetracks.erase(vRacetracks.begin()+objId);
                                            break;
                                        }
                                    case 8:
                                        {
                                            cout<<"Quitting functions..."<<endl<<endl;
                                            break;
                                        }
                                    default:
                                        {
                                            cout<<"Unknown command..."<<endl<<endl;
                                            break;
                                        }
                                 }


                                 break;
                                }

                            case 7: ///Quit
                                {
                                    cout<<"Quitting class..."<<endl<<endl;
                                    inRacetracks=false;
                                    break;
                                }
                            default:
                                {
                                    cout<<"Unknown command"<<endl;
                                    break;
                                }
                        }
                    }
                break;
                }
            case 3:
                {
                cout<<"You chose class Drivers"<<endl;

                   inDrivers=true;

                    while(inDrivers==true)
                    {
                        cout<<"Choose what to do..."<<endl;
                        cout<<"1->Constructor 2->Getter 3->Setter 4->Operation(1 Object) 5->Operation(2 Objects) 6->Function 7->Leave Class"<<endl;
                        cin>>choice;
                        switch(choice)
                        {
                            case 1: ///Constructors
                                {
                                    cout<<"Which constructor?"<<endl;
                                    cout<<"1->No parameters 2->All parameters 3->Some parameters v1 4->Some parameters v2 5->Abort"<<endl;
                                    cin>>whichConstructor;
                                    switch(whichConstructor)
                                    {
                                        case 1:
                                            {
                                            Drivers d;
                                            vDrivers.push_back(d);
                                            cout<<"Object created!"<<endl<<endl;
                                            cout<<vDrivers[vDrivers.size()-1];
                                            break;
                                            }
                                        case 2:
                                            {
                                                Drivers d;
                                                cin>>d;
                                                vDrivers.push_back(d);
                                                cout<<"Object created!"<<endl<<endl;
                                                cout<<vDrivers[vDrivers.size()-1];
                                                break;
                                            }
                                        case 3:
                                            {

                                                char DriverName[100];
                                                cout<<"Driver name: ";
                                                cin.get();
                                                cin.get(DriverName,100);

                                                int Age;
                                                cout<<"Age: ";
                                                cin>>Age;

                                                Drivers d(DriverName,Age);
                                                vDrivers.push_back(d);
                                                cout<<"Object created!"<<endl<<endl;
                                                cout<<vDrivers[vDrivers.size()-1];
                                                break;

                                            }
                                        case 4:
                                            {

                                                char DriverName[100];
                                                cout<<"Driver name: ";
                                                cin.get();
                                                cin.get(DriverName,100);

                                                int Age;
                                                cout<<"Age: ";
                                                cin>>Age;

                                                string TeamName;
                                                cout<<"Team Name: ";
                                                cin>>TeamName;

                                                int NoFaults;
                                                cout<<"Number of faults: ";
                                                cin>>NoFaults;


                                                cout<<"Penalty points per fault:"<<endl;
                                                int* Faults;
                                                Faults = new int[NoFaults];

                                                    for(int i=0;i<NoFaults;i++)
                                                        cin>>Faults[i];


                                                Drivers d(DriverName,TeamName,Age,NoFaults,Faults);

                                                vDrivers.push_back(d);
                                                cout<<"Object created!"<<endl<<endl;
                                                cout<<vDrivers[vDrivers.size()-1];

                                                break;


                                            }
                                        case 5:
                                            {
                                                cout<<"Quiting constructors..."<<endl;
                                                break;
                                            }
                                        default:
                                            {
                                                cout<<"Invalid task. Please try again!"<<endl;
                                                break;
                                            }
                                    }
                                    break;
                                }

                            case 2: ///Getters
                                {
                                    cout<<"First of all, choose an object.";
                                    if(vDrivers.size()>0)
                                    {
                                        cout<<"You have "<<vDrivers.size()<<" objects."<<endl;
                                        cin>>objectNumber;
                                        for(int i=0;i<vDrivers.size();i++)
                                            if(vDrivers[i].GetIdDriver()==objectNumber)
                                            {
                                                objId=i;
                                                break;
                                            }

                                    }
                                    else
                                    {
                                        cout<<endl;
                                        cout<<"You have NO OBJECTS. Please create one!"<<endl;
                                        break;
                                    }


                                    cout<<"What do you want do get?"<<endl;
                                    cout<<"1->Driver Name 2->Category 3->Team Name 4->Age 5->Kart number 6->Number of faults 7->Faults 8->Championship points 9->Abort"<<endl;
                                    cin>>whichGetter;


                                    switch(whichGetter)
                                    {
                                        case 1:
                                            {
                                                cout<<vDrivers[objId].GetDriverName()<<endl;
                                                break;
                                            }
                                        case 2:
                                            {
                                                cout<<vDrivers[objId].GetCategory()<<endl;
                                                break;
                                            }
                                        case 3:
                                            {
                                                cout<<vDrivers[objId].GetTeamName()<<endl;
                                                break;
                                            }
                                        case 4:
                                            {
                                                cout<<vDrivers[objId].GetAge()<<endl;
                                                break;
                                            }
                                        case 5:
                                            {
                                                cout<<vDrivers[objId].GetKartNumber()<<endl;
                                                break;
                                            }
                                        case 6:
                                            {
                                                cout<<vDrivers[objId].GetNoFaults()<<endl;
                                                break;
                                            }
                                        case 7:
                                            {
                                                cout<<vDrivers[objId].GetFaults()<<endl;
                                                break;
                                            }
                                        case 8:
                                            {
                                                cout<<vDrivers[objId].GetChampionshipPoints()<<endl;
                                                break;
                                            }
                                        case 9:
                                            {
                                                cout<<"Quitting Getters..."<<endl;
                                                break;
                                            }
                                        default:
                                            {
                                                cout<<"Invalid task. Please try again!";
                                                break;
                                            }
                                    }
                                    break;
                                }

                            case 3: ///Setters
                                {
                                    cout<<"First of all, choose an object.";
                                    if(vDrivers.size()>0)
                                    {
                                        cout<<"You have "<<vDrivers.size()<<" objects."<<endl;
                                        cin>>objectNumber;
                                        for(int i=0;i<vDrivers.size();i++)
                                            if(vDrivers[i].GetIdDriver()==objectNumber)
                                            {
                                                objId=i;
                                                break;
                                            }
                                    }
                                    else
                                    {
                                        cout<<endl;
                                        cout<<"You have NO OBJECTS. Please create one!"<<endl;
                                        break;
                                    }
                                    cout<<"What do you want do set?"<<endl;
                                    cout<<"1->Driver Name 2->Category 3->Team Name 4->Age 5->Kart number 6->Number of faults 7->Faults 8->Championship Points 9->Abort"<<endl;
                                    cin>>whichSetter;

                                    switch(whichSetter)
                                    {
                                        case 1:
                                            {
                                                char DriverName[100];
                                                cin.get();
                                                cin.get(DriverName,100);

                                                vDrivers[objId].SetDriverName(DriverName);
                                                cout<<"Attribute modified successfully!"<<endl;
                                                break;
                                            }
                                        case 2:
                                            {
                                                char Category;
                                                cin>>Category;
                                                vDrivers[objId].SetCategory(Category);
                                                cout<<"Attribute modified successfully!"<<endl;
                                                break;
                                            }
                                        case 3:
                                            {
                                                string TeamName;
                                                cin>>TeamName;
                                                vDrivers[objId].SetTeamName(TeamName);
                                                cout<<"Attribute modified successfully!"<<endl;
                                                break;
                                            }
                                        case 4:
                                            {
                                                int Age;
                                                cin>>Age;
                                                vDrivers[objId].SetAge(Age);
                                                cout<<"Attribute modified successfully!"<<endl;
                                                break;
                                            }
                                        case 5:
                                            {
                                                int KartNumber;
                                                cin>>KartNumber;
                                                vDrivers[objId].SetKartNumber(KartNumber);
                                                cout<<"Attribute modified successfully!"<<endl;
                                                break;
                                            }
                                        case 6:
                                            {
                                                int NoFaults;
                                                cin>>NoFaults;
                                                vDrivers[objId].SetNoFaults(NoFaults);
                                                cout<<"Attribute modified successfully!"<<endl;
                                                break;
                                            }
                                        case 7:
                                            {
                                                int* Faults;
                                                Faults = new int[vDrivers[objId].GetNoFaults()];

                                                    for(int i=0;i<vDrivers[objId].GetNoFaults();i++)
                                                        cin>>Faults[i];

                                                vDrivers[objId].SetFaults(Faults);
                                                cout<<"Attribute modified successfully!"<<endl;

                                                delete[] Faults;
                                                Faults=NULL;


                                                break;
                                            }
                                        case 8:
                                            {
                                                double ChampionshipPoints;
                                                cin>>ChampionshipPoints;
                                                vDrivers[objId].SetChampionshipPoints(ChampionshipPoints);
                                                cout<<"Attribute modified successfully!"<<endl;
                                                break;
                                            }

                                        case 9:
                                            {
                                                cout<<"Quitting Setters..."<<endl;
                                                break;
                                            }
                                        default:
                                            {
                                                cout<<"Invalid task. Please try again!";
                                                break;
                                            }
                                    }
                                    break;
                                }

                            case 4:///Operation(1 Object)
                                {
                                    cout<<"First of all, choose an object.";
                                    if(vDrivers.size()>0)
                                    {
                                        cout<<"You have "<<vDrivers.size()<<" objects."<<endl;
                                        cin>>objectNumber;
                                        for(int i=0;i<vDrivers.size();i++)
                                            if(vDrivers[i].GetIdDriver()==objectNumber)
                                            {
                                                objId=i;
                                                break;
                                            }
                                    }
                                    else
                                    {
                                        cout<<endl;
                                        cout<<"You have NO OBJECTS. Please create one!"<<endl;
                                        break;
                                    }

                                    cout<<"Now choose an operation."<<endl;
                                    cout<<"'+'  '-'  '++'->'#'"<<endl;
                                    cin>>whichOperation;

                                    switch(whichOperation)
                                    {
                                    case '+':
                                        {
                                            cout<<"How much do you want to add?"<<endl;
                                            cin>>operationNumber;
                                            vDrivers[objId]=vDrivers[objId]+operationNumber;
                                            cout<<vDrivers[objId]<<endl;
                                            break;
                                        }
                                    case '-':
                                        {
                                            cout<<"How much do you want to substract?"<<endl;
                                            cin>>operationNumber;
                                            vDrivers[objId]=vDrivers[objId]-operationNumber;
                                            cout<<vDrivers[objId]<<endl;
                                            break;
                                        }

                                    case '#':
                                        {
                                            cout<<++vDrivers[objId];
                                            break;
                                        }
                                    }
                                    break;
                                }

                            case 5: ///Operation(2 Objects)
                                {
                                    cout<<"First of all, choose two objects.";
                                    if(vDrivers.size()>=2)
                                    {
                                        cout<<"You have "<<vDrivers.size()<<" objects."<<endl;
                                        cin>>objectNumber;
                                        cin>>objectNumber2;
                                        objId=-1;
                                        objId=-2;
                                        for(int i=0;i<vDrivers.size();i++)
                                            if(vDrivers[i].GetIdDriver()==objectNumber || vDrivers[i].GetIdDriver()==objectNumber)
                                            {
                                                if(objId==-1)
                                                    objId=i;
                                                else
                                                    objId2=i;
                                                break;
                                            }
                                    }
                                    else
                                    {
                                        cout<<endl;
                                        cout<<"You don't have enough objects. Please create more!"<<endl;
                                        break;
                                    }
                                    cout<<"Now choose an operation."<<endl;
                                    cout<<"'+'  '-'  '='  '<'  '>'  '=='->'#'  Abort->'/'"<<endl;

                                    cin>>whichOperation;

                                    switch(whichOperation)
                                    {
                                        case '+':
                                            {
                                                cout<<(vDrivers[objId]+vDrivers[objId2]);
                                                break;
                                            }
                                        case '-':
                                            {
                                                cout<<(vDrivers[objId]-vDrivers[objId2]);
                                                break;
                                            }
                                        case '=':
                                            {
                                                vDrivers[objId]=vDrivers[objId2];
                                                break;
                                            }
                                        case '#':
                                            {
                                                cout<<(vDrivers[objId]==vDrivers[objId2])<<endl;
                                                break;
                                            }
                                        case '<':
                                            {
                                                cout<<(vDrivers[objId]<vDrivers[objId2]);
                                                break;
                                            }
                                        case '>':
                                            {
                                                cout<<(vDrivers[objId]>vDrivers[objId2]);
                                                break;
                                            }
                                        case '/':
                                            {
                                                cout<<"Quitting Operation(2 Objects)..."<<endl;
                                                break;
                                            }
                                        default:
                                            {
                                                cout<<"Invalid task. Please try again!";
                                                break;
                                            }



                                    }
                                    break;
                                }

                            case 6: ///Functions
                                {
                                 cout<<"Choose a function"<<endl;
                                 cout<<"Print an object->1  Print all objects->2"<<endl;
                                 cout<<"Index->3(not available)  Cast->4  Read an object->5"<<endl;
                                 cout<<"Delete an object->6  Abort->7"<<endl;

                                 cin>>whichFunction;
                                 switch(whichFunction)
                                 {
                                    case 1:
                                        {
                                            cout<<"First of all, choose an object.";
                                            if(vDrivers.size()>0)
                                            {
                                                cout<<"You have "<<vDrivers.size()<<" objects."<<endl;
                                                cin>>objectNumber;
                                                for(int i=0;i<vDrivers.size();i++)
                                                    if(vDrivers[i].GetIdDriver()==objectNumber)
                                                    {
                                                        objId=i;
                                                        break;
                                                    }

                                            }
                                            else
                                            {
                                                cout<<endl;
                                                cout<<"You have NO OBJECTS. Please create one!"<<endl;
                                                break;
                                            }

                                            cout<<vDrivers[objId];

                                            break;
                                        }


                                    case 2:
                                        {

                                            if(vDrivers.size()==0)
                                                cout<<"You have no objects to print"<<endl;
                                            else
                                                for(int i=0;i<vDrivers.size();i++)
                                                    cout<<vDrivers[i]<<endl;

                                            break;
                                        }

                                    case 3:
                                        {
                                            cout<<"Not available for now"<<endl;
                                            break;
                                        }
                                    case 4:
                                        {
                                            cout<<"First of all, choose an object.";
                                            if(vDrivers.size()>0)
                                            {
                                                cout<<"You have "<<vDrivers.size()<<" objects."<<endl;
                                                cin>>objectNumber;
                                                for(int i=0;i<vDrivers.size();i++)
                                                    if(vDrivers[i].GetIdDriver()==objectNumber)
                                                    {
                                                        objId=i;
                                                        break;
                                                    }

                                            }
                                            else
                                            {
                                                cout<<endl;
                                                cout<<"You have NO OBJECTS. Please create one!"<<endl;
                                                break;
                                            }

                                            cout<<(int)vDrivers[objId]<<endl<<endl;

                                            break;
                                        }
                                    case 5:
                                        {
                                            Drivers d;
                                            cin>>d;
                                            vDrivers.push_back(d);
                                            cout<<vDrivers[vDrivers.size()-1]<<endl<<endl;
                                            break;
                                        }
                                    case 6:
                                        {
                                            cout<<"First of all, choose an object.";
                                            if(vDrivers.size()>0)
                                            {
                                                cout<<"You have "<<vDrivers.size()<<" objects."<<endl;
                                                cin>>objectNumber;
                                                for(int i=0;i<vDrivers.size();i++)
                                                    if(vDrivers[i].GetIdDriver()==objectNumber)
                                                    {

                                                        objId=i;
                                                        break;
                                                    }

                                            }
                                            else
                                            {
                                                cout<<endl;
                                                cout<<"You have NO OBJECTS. Please create one!"<<endl;
                                                break;
                                            }

                                            vDrivers.erase(vDrivers.begin()+objId);

                                            break;
                                        }
                                    case 7:
                                        {
                                            cout<<"Quitting functions..."<<endl<<endl;
                                            break;
                                        }
                                    default:
                                        {
                                            cout<<"Unknown command..."<<endl<<endl;
                                            break;
                                        }
                                 }


                                 break;
                                }

                            case 7: ///Quit
                                {
                                    cout<<"Quitting class..."<<endl<<endl;
                                    inDrivers=false;
                                    break;
                                }
                            default:
                                {
                                    cout<<"Unknown command"<<endl;
                                    break;
                                }
                        }
                    }
                break;
                }
            case 4:
                {
                    cout<<"You chose class Teams"<<endl;
                    inTeams=true;

                    while(inTeams==true)
                    {
                        cout<<"Choose what to do..."<<endl;
                        cout<<"1->Constructor 2->Getter 3->Setter 4->Operation(1 Object) 5->Operation(2 Objects) 6->Function 7->Leave Class"<<endl;
                        cin>>choice;
                        switch(choice)
                        {
                            case 1: ///Constructors
                                {
                                    cout<<"Which constructor?"<<endl;
                                    cout<<"1->No parameters 2->All parameters 3->Some parameters v1 4->Some parameters v2 5->Abort"<<endl;
                                    cin>>whichConstructor;
                                    switch(whichConstructor)
                                    {
                                        case 1:
                                            {
                                            Teams t;
                                            vTeams.push_back(t);
                                            cout<<"Object created!"<<endl<<endl;
                                            cout<<vTeams[vTeams.size()-1];
                                            break;
                                            }
                                        case 2:
                                            {
                                            Teams t;
                                            cin>>t;
                                            vTeams.push_back(t);
                                            cout<<"Object created!"<<endl<<endl;
                                            cout<<vTeams[vTeams.size()-1];
                                            break;
                                            }
                                        case 3:
                                            {
                                                string TeamName,PrincipalName;
                                                cout<<"Team name: ";
                                                cin>>TeamName;
                                                cout<<"Principal name: ";
                                                cin>>PrincipalName;

                                                Teams t(TeamName,PrincipalName);

                                                vTeams.push_back(t);
                                                cout<<"Object created!"<<endl<<endl;
                                                cout<<vTeams[vTeams.size()-1];

                                                break;

                                            }
                                        case 4:
                                            {
                                                string TeamName;
                                                int NoStaff;

                                                cout<<"Team name: ";
                                                cin>>TeamName;

                                                cout<<"Number of staff: ";
                                                cin>>NoStaff;

                                                Teams t(TeamName,NoStaff);

                                                vTeams.push_back(t);
                                                cout<<"Object created!"<<endl<<endl;
                                                cout<<vTeams[vTeams.size()-1];

                                                break;


                                            }
                                        case 5:
                                            {
                                                cout<<"Quiting constructors..."<<endl;
                                                break;
                                            }
                                        default:
                                            {
                                                cout<<"Invalid task. Please try again!"<<endl;
                                                break;
                                            }
                                    }
                                    break;
                                }

                            case 2: ///Getters
                                {
                                    cout<<"First of all, choose an object.";
                                    if(vTeams.size()>0)
                                    {
                                        cout<<"You have "<<vTeams.size()<<" objects."<<endl;
                                        cin>>objectNumber;
                                        for(int i=0;i<vTeams.size();i++)
                                            if(vTeams[i].GetIdTeam()==objectNumber)
                                            {
                                                objId=i;
                                                break;
                                            }

                                    }
                                    else
                                    {
                                        cout<<endl;
                                        cout<<"You have NO OBJECTS. Please create one!"<<endl;
                                        break;
                                    }
                                    cout<<"What do you want do get?"<<endl;
                                    cout<<"1->Team Name 2->Principal Name 3->Number of Staff 4->Number of categories 5->Number of drivers 6->Number of Fines 7->Fines 8->Abort"<<endl;
                                    cin>>whichGetter;

                                    switch(whichGetter)
                                    {
                                        case 1:
                                            {
                                                cout<<vTeams[objId].GetTeamName()<<endl;
                                                break;
                                            }
                                        case 2:
                                            {
                                                cout<<vTeams[objId].GetPrincipalName()<<endl;
                                                break;
                                            }
                                        case 3:
                                            {

                                                cout<<vTeams[objId].GetNoStaff()<<endl;
                                                break;
                                            }
                                        case 4:
                                            {
                                                cout<<vTeams[objId].GetNoCategories()<<endl;
                                                break;
                                            }
                                        case 5:
                                            {
                                                cout<<vTeams[objId].GetNoDrivers()<<endl;
                                                break;
                                            }
                                        case 6:
                                            {
                                                cout<<vTeams[objId].GetNoFines()<<endl;
                                                break;
                                            }
                                        case 7:
                                            {
                                                cout<<vTeams[objId].GetFines()<<endl;
                                                break;
                                            }
                                        case 8:
                                            {
                                                cout<<"Quitting Getters..."<<endl;
                                                break;
                                            }
                                        default:
                                            {
                                                cout<<"Invalid task. Please try again!";
                                                break;
                                            }
                                    }
                                    break;
                                }

                            case 3: ///Setters
                                {
                                    cout<<"First of all, choose an object.";
                                    if(vTeams.size()>0)
                                    {
                                        cout<<"You have "<<vTeams.size()<<" objects."<<endl;
                                        cin>>objectNumber;
                                        for(int i=0;i<vTeams.size();i++)
                                            if(vTeams[i].GetIdTeam()==objectNumber)
                                            {
                                                objId=i;
                                                break;
                                            }
                                    }
                                    else
                                    {
                                        cout<<endl;
                                        cout<<"You have NO OBJECTS. Please create one!"<<endl;
                                        break;
                                    }
                                    cout<<"What do you want do set?"<<endl;
                                    cout<<"1->Team Name 2->Principal Name 3->Number of Staff 4->Number of categories 5->Number of drivers 6->Number of Fines 7->Fines 8->Abort"<<endl;
                                    cin>>whichSetter;

                                    /*
                                        string teamName;
                                        string principalName;
                                        int noStaff;
                                        int noCategories;
                                        int noDrivers;
                                        int noFines;
                                        int* fines;
                                    */


                                    switch(whichSetter)
                                    {
                                        case 1:
                                            {
                                                string TeamName;
                                                cin>>TeamName;
                                                vTeams[objId].SetTeamName(TeamName);
                                                cout<<"Attribute modified successfully!"<<endl;
                                                break;
                                            }
                                        case 2:
                                            {
                                                string PrincipalName;
                                                cin>>PrincipalName;
                                                vTeams[objId].SetPrincipalName(PrincipalName);
                                                cout<<"Attribute modified successfully!"<<endl;
                                                break;
                                            }
                                        case 3:
                                            {
                                                int NoStaff;
                                                cin>>NoStaff;
                                                vTeams[objId].SetNoStaff(NoStaff);
                                                cout<<"Attribute modified successfully!"<<endl;
                                                break;
                                            }
                                        case 4:
                                            {
                                                int NoCategories;
                                                cin>>NoCategories;
                                                vTeams[objId].SetNoCategories(NoCategories);
                                                cout<<"Attribute modified successfully!"<<endl;
                                                break;
                                            }
                                        case 5:
                                            {
                                                int NoDrivers;
                                                cin>>NoDrivers;
                                                vTeams[objId].SetNoDrivers(NoDrivers);
                                                cout<<"Attribute modified successfully!"<<endl;
                                                break;
                                            }
                                        case 6:
                                            {
                                                int NoFines;
                                                cin>>NoFines;
                                                vTeams[objId].SetNoDrivers(NoFines);
                                                cout<<"Attribute modified successfully!"<<endl;
                                                break;

                                            }
                                        case 7:
                                            {
                                                int* Fines;
                                                Fines = new int[vTeams[objId].GetNoDrivers()];
                                                for(int i=0;i<vTeams[objId].GetNoDrivers();i++)
                                                    cin>>Fines[i];
                                                cout<<"Attribute modified successfully!"<<endl;
                                                break;

                                            }
                                        case 8:
                                            {
                                                cout<<"Quitting Setters..."<<endl;
                                                break;
                                            }
                                        default:
                                            {
                                                cout<<"Invalid task. Please try again!";
                                                break;
                                            }
                                    }
                                    break;
                                }

                            case 4:///Operation(1 Object)
                                {
                                    cout<<"First of all, choose an object.";
                                    if(vTeams.size()>0)
                                    {
                                        cout<<"You have "<<vTeams.size()<<" objects."<<endl;
                                        cin>>objectNumber;
                                        for(int i=0;i<vTeams.size();i++)
                                            if(vTeams[i].GetIdTeam()==objectNumber)
                                            {
                                                objId=i;
                                                break;
                                            }

                                    }
                                    else
                                    {
                                        cout<<endl;
                                        cout<<"You have NO OBJECTS. Please create one!"<<endl;
                                        break;
                                    }

                                    cout<<"Now choose an operation."<<endl;
                                    cout<<"'+'  '-'  '++'->'#'"<<endl;
                                    cin>>whichOperation;

                                    switch(whichOperation)
                                    {
                                    case '+':
                                        {
                                            cout<<"How much do you want to add?"<<endl;
                                            cin>>operationNumber;
                                            vTeams[objId]=vTeams[objId]+operationNumber;
                                            cout<<vTeams[objId]<<endl;
                                            break;
                                        }
                                    case '-':
                                        {
                                            cout<<"How much do you want to substract?"<<endl;
                                            cin>>operationNumber;
                                            vTeams[objId]=vTeams[objId]-operationNumber;
                                            cout<<vTeams[objId]<<endl;
                                            break;
                                        }

                                    case '#':
                                        {
                                            cout<<++vTeams[objId];
                                            break;
                                        }
                                    }
                                    break;
                                }

                            case 5: ///Operation(2 Objects)
                                {
                                    cout<<"First of all, choose two objects.";
                                    if(vTeams.size()>=2)
                                    {
                                        cout<<"You have "<<vTeams.size()<<" objects."<<endl;
                                        cin>>objectNumber;
                                        cin>>objectNumber2;
                                        objId=-1;
                                        objId=-1;
                                        for(int i=0;i<vTeams.size();i++)
                                            if(vTeams[i].GetIdTeam()==objectNumber || vTeams[i].GetIdTeam()==objectNumber)
                                            {
                                                if(objId==-1)
                                                    objId=i;
                                                else
                                                    objId2=i;
                                                break;
                                            }
                                    }
                                    else
                                    {
                                        cout<<endl;
                                        cout<<"You don't have enough objects. Please create more!"<<endl;
                                        break;
                                    }
                                    cout<<"Now choose an operation."<<endl;
                                    cout<<"'+'  '-'  '='  '<'  '>'  '=='->'#'  Abort->'/'"<<endl;

                                    cin>>whichOperation;

                                    switch(whichOperation)
                                    {
                                        case '+':
                                            {
                                                cout<<(vTeams[objId]+vTeams[objId2]);
                                                break;
                                            }
                                        case '-':
                                            {
                                                cout<<(vTeams[objId]-vTeams[objId2]);
                                                break;
                                            }
                                        case '=':
                                            {
                                                vTeams[objId]=vTeams[objId2];
                                                break;
                                            }
                                        case '#':
                                            {
                                                cout<<(vTeams[objId]==vTeams[objId2])<<endl;
                                                break;
                                            }
                                        case '<':
                                            {
                                                cout<<(vTeams[objId]<vTeams[objId2]);
                                                break;
                                            }
                                        case '>':
                                            {
                                                cout<<(vTeams[objId]>vTeams[objId2]);
                                                break;
                                            }
                                        case '/':
                                            {
                                                cout<<"Quitting Operation(2 Objects)..."<<endl;
                                                break;
                                            }
                                        default:
                                            {
                                                cout<<"Invalid task. Please try again!";
                                                break;
                                            }



                                    }
                                    break;
                                }

                            case 6: ///Functions
                                {
                                 cout<<"Choose a function"<<endl;
                                 cout<<"Print an object->1  Print all objects->2"<<endl;
                                 cout<<"Index->3(not available)  Cast->4  Read an object->5"<<endl;
                                 cout<<"Delete an object->6  Abort->7"<<endl;

                                 cin>>whichFunction;
                                 switch(whichFunction)
                                 {
                                    case 1:
                                        {
                                            cout<<"First of all, choose an object.";
                                            if(vTeams.size()>0)
                                            {
                                                cout<<"You have "<<vTeams.size()<<" objects."<<endl;
                                                cin>>objectNumber;
                                                for(int i=0;i<vTeams.size();i++)
                                                    if(vTeams[i].GetIdTeam()==objectNumber)
                                                    {
                                                        objId=i;
                                                        break;
                                                    }

                                            }
                                            else
                                            {
                                                cout<<endl;
                                                cout<<"You have NO OBJECTS. Please create one!"<<endl;
                                                break;
                                            }

                                            cout<<vTeams[objId];

                                            break;
                                        }


                                    case 2:
                                        {

                                            if(vTeams.size()==0)
                                                cout<<"You have no objects to print"<<endl;
                                            else
                                                for(int i=0;i<vTeams.size();i++)
                                                    cout<<vTeams[i]<<endl;

                                            break;
                                        }

                                    case 3:
                                        {
                                            cout<<"Not available for now"<<endl;
                                            break;
                                        }
                                    case 4:
                                        {
                                            cout<<"First of all, choose an object.";
                                            if(vTeams.size()>0)
                                            {
                                                cout<<"You have "<<vTeams.size()<<" objects."<<endl;
                                                cin>>objectNumber;
                                                for(int i=0;i<vTeams.size();i++)
                                                    if(vTeams[i].GetIdTeam()==objectNumber)
                                                    {
                                                        objId=i;
                                                        break;
                                                    }

                                            }
                                            else
                                            {
                                                cout<<endl;
                                                cout<<"You have NO OBJECTS. Please create one!"<<endl;
                                                break;
                                            }

                                            cout<<(int)vTeams[objId]<<endl<<endl;

                                            break;
                                        }
                                    case 5:
                                        {
                                            Teams x;
                                            cin>>x;
                                            vTeams.push_back(x);
                                            cout<<vTeams[vTeams.size()-1]<<endl<<endl;
                                            break;
                                        }
                                    case 6:
                                        {
                                            cout<<"First of all, choose an object.";
                                            if(vTeams.size()>0)
                                            {
                                                cout<<"You have "<<vTeams.size()<<" objects."<<endl;
                                                cin>>objectNumber;
                                                for(int i=0;i<vTeams.size();i++)
                                                    if(vTeams[i].GetIdTeam()==objectNumber)
                                                    {
                                                        objId=i;
                                                        break;
                                                    }

                                            }
                                            else
                                            {
                                                cout<<endl;
                                                cout<<"You have NO OBJECTS. Please create one!"<<endl;
                                                break;
                                            }

                                            vTeams.erase(vTeams.begin()+objId);
                                            break;
                                        }
                                    case 7:
                                        {
                                            cout<<"Quitting functions..."<<endl<<endl;
                                            break;
                                        }
                                    default:
                                        {
                                            cout<<"Unknown command..."<<endl<<endl;
                                            break;
                                        }
                                 }


                                 break;
                                }

                            case 7: ///Quit
                                {
                                    cout<<"Quitting class..."<<endl<<endl;
                                    inTeams=false;
                                    break;
                                }
                            default:
                                {
                                    cout<<"Unknown command"<<endl;
                                    break;
                                }
                        }


                    }
                break;

                }
            case 5:
                {
                cout<<"You chose to mix classes."<<endl;

                cout<<"First of all, choose an object from class Races";
                        if(vRaces.size()>0)
                            {
                                cout<<"You have "<<vRaces.size()<<" objects."<<endl;
                                cin>>objectNumber;
                                for(int i=0;i<vRaces.size();i++)
                                        if(vRaces[i].GetIdRace()==objectNumber)
                                        {
                                            objId=i;
                                            break;
                                        }

                            }
                            else
                            {
                                cout<<endl;
                                cout<<"You have NO OBJECTS. Please create one!"<<endl;
                                break;
                            }


                cout<<"Secondly, choose an object from class Racetracks";
                        if(vRacetracks.size()>0)
                            {
                                cout<<"You have "<<vRacetracks.size()<<" objects."<<endl;
                                cin>>objectNumber;
                                for(int i=0;i<vRacetracks.size();i++)
                                        if(vRacetracks[i].GetIdTrack()==objectNumber)
                                        {
                                            objId2=i;
                                            break;
                                        }

                            }
                            else
                            {
                                cout<<endl;
                                cout<<"You have NO OBJECTS. Please create one!"<<endl;
                                break;
                            }


                cout<<vRaces[objId]+vRacetracks[objId2]<<endl;

                break;
                }
            case 6:
                {
                inClass=false;
                cout<<"You chose to leave. Bye!"<<endl;
                break;
                }

            default:
                cout<<"I don't know this command"<<endl;
                break;
        }
    }

            }


        case 3:
            {
                cout<<"Are you sure about that? Do you want to continue?(0/1)"<<endl;
                cin>>inBrench;
                if(inBrench==true)
                    cout<<"Glad to hear that!"<<endl;
                else cout<<"U a loser..."<<endl;

                break;

            }

    }

}

    return 0;
}
