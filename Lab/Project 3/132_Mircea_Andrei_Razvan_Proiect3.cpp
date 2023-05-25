#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <list>
#include <exception>
#include <limits>
#include <fstream>
#include<conio.h>
#include<windows.h>
using namespace std;


class Event
{
protected:
    const int idEvent;
    static int contorId;
    string numeEvent;
    string locatie;
    int nrParticipanti;
    int buget;
    int durata;


public:


///-----------CONTRUCTORS
    Event():idEvent(contorId++)
    {
        numeEvent = "Unknown_name";
        locatie = "Unknown_location";
        nrParticipanti = -1;
        buget = -1;
        durata = -1;
    }

    Event(string numeEvent,string locatie,int nrParticipanti,int buget, int durata):idEvent(contorId++)
    {
        this->numeEvent = numeEvent;
        this->locatie = locatie;
        this->nrParticipanti = nrParticipanti;
        this->buget = buget;
        this->durata = durata;
    }

    Event(const Event& obj):idEvent(obj.idEvent)
    {
        this->numeEvent = obj.numeEvent;
        this->locatie = obj.locatie;
        this->nrParticipanti = obj.nrParticipanti;
        this->buget = obj.buget;
        this->durata = obj.durata;
    }

    Event& operator = (const Event& obj)
    {
        this->numeEvent = obj.numeEvent;
        this->locatie = obj.locatie;
        this->nrParticipanti = obj.nrParticipanti;
        this->buget = obj.buget;
        this->durata = obj.durata;

        return *this;
    }


    int getBuget() const
    {
        return this->buget;
    }

    const int getID() const
    {
        return this->idEvent;
    }

    void updateBuget(int value)
    {
        this->buget+=value;
    }

    friend istream& operator>>(istream& in, Event &obj);
    friend istream& operator>>(ifstream& in, Event &obj);
    friend ostream& operator<<(ostream& out, const Event &obj);
    friend ostream& operator<<(ofstream& out, const Event &obj);

    Event& citire_fisier(string s)
    {
        ifstream inn(s);
        while(true)
        {
            try
            {
            if (!(inn >> *(this)))
                throw runtime_error("Ceva e gresit in fisier");

                break;
            }
            catch (const exception& e)
            {
                cout << "Eroare: " << e.what() << endl;
                inn.clear();
                inn.ignore(numeric_limits<streamsize>::max(), '\n');
                cout<<endl<<"Mai baga o fisa!"<<endl;
            }
        }


        return *(this);
    }

    Event& afisare_fisier(string s)
    {
        ofstream out(s);
        out<<(*this);

        return (*this);
    }

    ~Event()
        {   };
};
istream& operator>>(istream& in, Event& obj)
{
    while (true) {
        try
        {
            cout << "Nume eveniment: ";
            in >> obj.numeEvent;
            in.get();
            cout << "Nume locatie: ";
            in >> obj.locatie;
            cout << "Numar participanti: ";
            if (!(in >> obj.nrParticipanti)) {
                throw runtime_error("Vezi ca numarul asta trebuie sa fie numar(gen se numeste NUMAR participanti)");
            }
            cout << "Buget: ";
            if (!(in >> obj.buget))
                {
                throw runtime_error("Vezi ca bugetul trebuie sa fie numar");
                }
            cout << "Durata eveniment(in zile): ";
            if (!(in >> obj.durata))
                {
                throw runtime_error("Vezi ca durata trebuie sa fie numar");
                }
            break;
        } catch (const exception& e) {

        cout << "Eroare: " << e.what() << endl;
        in.clear();
        in.ignore(numeric_limits<streamsize>::max(), '\n');
        cout<<endl<<"Mai baga o fisa!"<<endl;
        }
    }

    return in;
}
istream& operator>>(ifstream& in, Event& obj)
{

        try
        {
            //cout << "Nume eveniment: ";
            in >> obj.numeEvent;
           // cout << "Nume locatie: ";
            in >> obj.locatie;
            //cout << "Numar participanti: ";
            if (!(in >> obj.nrParticipanti)) {
                throw runtime_error("Vezi ca numarul asta trebuie sa fie numar(gen se numeste NUMAR participanti)");
            }
            //cout << "Buget: ";
            if (!(in >> obj.buget))
                {
                throw runtime_error("Vezi ca bugetul trebuie sa fie numar");
                }
            //cout << "Durata eveniment(in zile): ";
            if (!(in >> obj.durata))
                {
                throw runtime_error("Vezi ca durata trebuie sa fie numar");
                }

        } catch (const exception& e) {

        cout << "Eroare: " << e.what() << endl;
        in.clear();
        in.ignore(numeric_limits<streamsize>::max(), '\n');
        //cout<<endl<<"Mai baga o fisa!"<<endl;
        }


    return in;
}
ostream& operator<<(ostream& out, const Event& obj)
{
    out<<"ID: ";
    out<<obj.idEvent<<endl;
    out<<"Nume eveniment: ";
    out<<obj.numeEvent<<endl;
    out<<"Nume locatie: ";
    out<<obj.locatie<<endl;
    out<<"Numar participanti: ";
    out<<obj.nrParticipanti<<endl;
    out<<"Buget: ";
    out<<obj.buget<<endl;
    out<<"Durata eveniment(in zile): ";
    out<<obj.durata<<endl;

    return out;
}
ostream& operator<<(ofstream& out, const Event& obj)
{
    out<<"Nume eveniment: ";
    out<<obj.numeEvent<<endl;
    out<<"Nume locatie: ";
    out<<obj.locatie<<endl;
    out<<"Numar participanti: ";
    out<<obj.nrParticipanti<<endl;
    out<<"Buget: ";
    out<<obj.buget<<endl;
    out<<"Durata eveniment(in zile): ";
    out<<obj.durata<<endl;

    return out;
}



class Concert: virtual public Event
{
protected:

    string artistName;
    bool outdoor;
    bool seats;
    int pretBilet;

public:

    Concert()
    {
        artistName="Unknown artist";
        outdoor=false;
        seats=false;
        pretBilet= -1;
    }

    Concert(string numeEvent,string locatie,int nrParticipanti,int buget, int durata,string artistName,bool outdoor,bool seats,int pretBilet):Event(numeEvent,locatie,nrParticipanti,buget,durata)
    {
        this->artistName=artistName;
        this->outdoor=outdoor;
        this->seats=seats;
        this->pretBilet=pretBilet;
    }

    Concert (const Concert& obj):Event(obj)
    {
        this->artistName=obj.artistName;
        this->outdoor=obj.outdoor;
        this->seats=obj.seats;
        this->pretBilet=obj.pretBilet;
    }

    Concert& operator=(const Concert& obj)
    {
        if(this!=&obj)
        {
            Event::operator=(obj);
            this->artistName=obj.artistName;
            this->outdoor=obj.outdoor;
            this->seats=obj.seats;
            this->pretBilet=obj.pretBilet;
        }

        return *this;
    }

    friend istream& operator>>(istream& in, Concert &obj);
    friend istream& operator>>(ifstream& in, Concert &obj);
    friend ostream& operator<<(ostream& out, const Concert &obj);
    friend ostream& operator<<(ofstream& out, const Concert &obj);


    Concert& citire_fisier(string s)
    {
        ifstream inn(s);
        while(true)
        {
            try
            {
            if (!(inn >> *(this)))
                throw runtime_error("Ceva e gresit in fisier");

                break;
            }
            catch (const exception& e)
            {
                cout << "Eroare: " << e.what() << endl;
                inn.clear();
                inn.ignore(numeric_limits<streamsize>::max(), '\n');
                cout<<endl<<"Mai baga o fisa!"<<endl;
            }
        }


        return *(this);
    }
    Concert& afisare_fisier(string s)
    {
        ofstream out(s);
        out<<(*this);

        return (*this);
    }

};
istream& operator>>(istream& in, Concert& obj)
{
    in>>(Event&)obj;
    while(true)
    {
    try
    {
        cout << "Numele artistului: ";
        in >> obj.artistName;
        cout << "Concert in aer liber (0/1): ";
        if (!(in >> obj.outdoor))
            {
            throw runtime_error("Nu scrie 0/1 degeaba, boss...");
            }
        cout << "Scaune/locuri disponibile (0/1): ";
        if (!(in >> obj.seats))
            {
            throw runtime_error("Nu scrie 0/1 degeaba, boss...");
            }
        cout << "Pretul biletului: ";
        if (!(in >> obj.pretBilet))
            {
            throw runtime_error("Pretul trebuie sa fie un numar intreg");
            }

            break;
    } catch (const exception& e) {

        cout << "Eroare: " << e.what() << endl;
        in.clear();
        in.ignore(numeric_limits<streamsize>::max(), '\n');
        cout<<endl<<"Mai baga o fisa!"<<endl;
        }
    }
    return in;
}
istream& operator>>(ifstream& in, Concert& obj)
{
    in>>(Event&)obj;

    try
    {
        //cout << "Numele artistului: ";
        in >> obj.artistName;
       // cout << "Concert in aer liber (0/1): ";
        if (!(in >> obj.outdoor))
            {
            throw runtime_error("Nu scrie 0/1 degeaba, boss...");
            }
        //cout << "Scaune/locuri disponibile (0/1): ";
        if (!(in >> obj.seats))
            {
            throw runtime_error("Nu scrie 0/1 degeaba, boss...");
            }
        //cout << "Pretul biletului: ";
        if (!(in >> obj.pretBilet))
            {
            throw runtime_error("Pretul trebuie sa fie un numar intreg");
            }


    } catch (const exception& e) {

        cout << "Eroare: " << e.what() << endl;
        in.clear();
        in.ignore(numeric_limits<streamsize>::max(), '\n');
       // cout<<endl<<"Mai baga o fisa!"<<endl;
        }

    return in;
}
ostream& operator<<(ostream& out,const Concert &obj)
{
    out<<(Event&)obj;
    out<<"Numele artistului: ";
    out<<obj.artistName<<endl;
    out<<"Concert in aer liber(0/1): ";
    out<<obj.outdoor<<endl;
    out<<"Scaune/locuri disponibile(0/1): ";
    out<<obj.seats<<endl;
    out<<"Pretul biletului: ";
    out<<obj.pretBilet<<endl;
}
ostream& operator<<(ofstream& out,const Concert &obj)
{
    out<<(Event&)obj;
    out<<"Numele artistului: ";
    out<<obj.artistName<<endl;
    out<<"Concert in aer liber(0/1): ";
    out<<obj.outdoor<<endl;
    out<<"Scaune/locuri disponibile(0/1): ";
    out<<obj.seats<<endl;
    out<<"Pretul biletului: ";
    out<<obj.pretBilet<<endl;
}


class Beerfest:virtual public Event
{
protected:

    vector<string> tipuriBere;
    int nrVanzatori;
    bool food;
    bool concurs;

public:

    Beerfest()
    {
        tipuriBere.clear();
        nrVanzatori=-1;
        food=false;
        concurs=false;
    }

    Beerfest(string numeEvent,string locatie,int nrParticipanti,int buget,int durata,vector<string> tipuriBere,int nrConcurenti,bool food):Event(numeEvent,locatie,nrParticipanti,buget,durata)
    {
        this->tipuriBere.clear();
        for(int i=0;i<tipuriBere.size();i++)
            this->tipuriBere.push_back(tipuriBere[i]);
        nrVanzatori=this->nrVanzatori;
        food=this->food;
        concurs=this->concurs;
    }

    Beerfest(const Beerfest& obj):Event(obj)
    {
        this->tipuriBere.clear();
        for(int i=0;i<obj.tipuriBere.size();i++)
            this->tipuriBere.push_back(obj.tipuriBere[i]);
        this->nrVanzatori=obj.nrVanzatori;
        this->food=obj.food;
        this->concurs=obj.concurs;
    }

    Beerfest& operator=(const Beerfest& obj)
    {
        if(this!=&obj)
        {
            Event::operator=(obj);
            this->tipuriBere.clear();
            for(int i=0;i<obj.tipuriBere.size();i++)
                this->tipuriBere.push_back(obj.tipuriBere[i]);
            this->nrVanzatori=obj.nrVanzatori;
            this->food=obj.food;
            this->concurs=obj.concurs;
        }

        return *this;
    }

    friend istream& operator>>(istream& in, Beerfest& obj);
    friend istream& operator>>(ifstream& in, Beerfest& obj);
    friend ostream& operator<<(ostream& out, const Beerfest& obj);
    friend ostream& operator<<(ofstream& out, const Beerfest& obj);

    Beerfest& citire_fisier(string s)
    {
        ifstream inn(s);
        while(true)
        {
            try
            {
            if (!(inn >> *(this)))
                throw runtime_error("Ceva e gresit in fisier");

                break;
            }
            catch (const exception& e)
            {
                cout << "Eroare: " << e.what() << endl;
                inn.clear();
                inn.ignore(numeric_limits<streamsize>::max(), '\n');
                cout<<endl<<"Mai baga o fisa!"<<endl;
            }
        }


        return *(this);
    }
    Beerfest& afisare_fisier(string s)
    {
        ofstream out(s);
        out<<(*this);

        return (*this);
    }
    ~Beerfest() {tipuriBere.clear();};
};
istream& operator>>(istream& in, Beerfest& obj)
{
    in>>(Event&)obj;
    while (true) {
        try {
            cout << "Numar vanzatori: ";
            if (!(in >> obj.nrVanzatori)) {
                throw runtime_error("Bro e numar...");
            }

            cout << "Mancare (0/1): ";
            if (!(in >> obj.food)) {
                throw runtime_error("Nu scrie (0/1) degeaba");
            }

            cout << "Exista vreun concurs? (0/1): ";
            if (!(in >> obj.concurs)) {
                throw runtime_error("Nu scrie (0/1) degeaba");
            }

            cout<<"Cate tipuri de bere avem?: ";
            int n;
            if (!(in >> n)) {
                throw runtime_error("E nevoie de un numar intreg");
            }
            if(n!=0) cout<<"Introdu tipurile de bere!"<<endl;
            for(int i=0;i<n;i++)
            {
                string s;
                in>>s;
                obj.tipuriBere.push_back(s);
            }

            break;
        } catch (const exception& e) {
            cout << "Eroare: " << e.what() << endl;
            in.clear();
            in.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << endl << "Mai baga o fisa!" << endl;
        }
    }

    return in;
}
istream& operator>>(ifstream& in, Beerfest& obj)
{
    in>>(Event&)obj;
        try {
           // cout << "Numar vanzatori: ";
            if (!(in >> obj.nrVanzatori)) {
                throw runtime_error("Bro e numar...");
            }

            //cout << "Mancare (0/1): ";
            if (!(in >> obj.food)) {
                throw runtime_error("Nu scrie (0/1) degeaba");
            }

           // cout << "Exista vreun concurs? (0/1): ";
            if (!(in >> obj.concurs)) {
                throw runtime_error("Nu scrie (0/1) degeaba");
            }

           // cout<<"Cate tipuri de bere avem?: ";
            int n;
            if (!(in >> n)) {
                throw runtime_error("E nevoie de un numar intreg");
            }
            //if(n!=0) cout<<"Introdu tipurile de bere!"<<endl;
            for(int i=0;i<n;i++)
            {
                string s;
                in>>s;
                obj.tipuriBere.push_back(s);
            }


        } catch (const exception& e) {
            cout << "Eroare: " << e.what() << endl;
            in.clear();
            in.ignore(numeric_limits<streamsize>::max(), '\n');
            //cout << endl << "Mai baga o fisa!" << endl;
        }


    return in;
}
ostream& operator<<(ostream& out,const Beerfest& obj)
{
    out<<(Event&)obj;
    out<<"Numar vanzatori: ";
    out<<obj.nrVanzatori<<endl;
    out<<"Mancare: ";
    out<<obj.food<<endl;
    out<<"Concurs: ";
    out<<obj.concurs<<endl;
    out<<"Tipuri de bere: ";
    if(obj.tipuriBere.size()==0)
        out<<"Nu-i"<<endl;
    else
        for(int i=0;i<obj.tipuriBere.size();i++)
            out<<obj.tipuriBere[i]<<" ";
}
ostream& operator<<(ofstream& out,const Beerfest& obj)
{
    out<<(Event&)obj;
    out<<"Numar vanzatori: ";
    out<<obj.nrVanzatori<<endl;
    out<<"Mancare: ";
    out<<obj.food<<endl;
    out<<"Concurs: ";
    out<<obj.concurs<<endl;
    out<<"Tipuri de bere: ";
    if(obj.tipuriBere.size()==0)
        out<<"Nu-i"<<endl;
    else
        for(int i=0;i<obj.tipuriBere.size();i++)
            out<<obj.tipuriBere[i]<<" ";

    return out;
}



class Festival: public Concert, public Beerfest
{

    map<string, vector<string>>sponsori;
    list<string> merch;

public:

    Festival():Concert(),Beerfest(),Event()
    {
        sponsori.clear();
        merch.clear();
    }

    Festival(string numeEvent,string locatie,int nrParticipanti,int buget, int durata,string artistName,bool outdoor,bool seats,int pretBilet,vector<string> tipuriBere,int nrConcurenti,bool food,  map< string,vector<string> >sponsori,list<string> merch):
                 Beerfest(numeEvent,locatie,nrParticipanti,buget,durata,tipuriBere,nrConcurenti,food),
                 Concert(numeEvent,locatie,nrParticipanti,buget, durata,artistName,outdoor,seats,pretBilet),
                  Event(numeEvent,locatie,nrParticipanti,buget,durata)
    {
        this->sponsori=sponsori;
        this->merch=merch;
    }

    Festival(const Festival& obj):Concert(obj),Beerfest(obj),Event(obj)
    {
        this->sponsori=obj.sponsori;
        this->merch=obj.merch;
    }

    Festival& operator=(Festival& obj)
    {
        if(this!=&obj)
        {
            Event::operator=(obj);
            Beerfest::operator=(obj);
            Concert::operator=(obj);
            this->sponsori=obj.sponsori;
            this->merch=obj.merch;
        }
    }

    friend istream& operator>>(istream& in, Festival& obj);
    friend istream& operator>>(ifstream& in, Festival& obj);
    friend ostream& operator<<(ostream& out, const Festival& obj);
    friend ostream& operator<<(ofstream& out, const Festival& obj);

    Festival& citire_fisier(string s)
    {
        ifstream inn(s);
        while(true)
        {
            try
            {
            if (!(inn >> *(this)))
                throw runtime_error("Ceva e gresit in fisier");

                break;
            }
            catch (const exception& e)
            {
                cout << "Eroare: " << e.what() << endl;
                inn.clear();
                inn.ignore(numeric_limits<streamsize>::max(), '\n');
                cout<<endl<<"Mai baga o fisa!"<<endl;
            }
        }


        return *(this);
    }
    Festival& afisare_fisier(string s)
    {
        ofstream out(s);
        out<<(*this);

        return (*this);
    }
    ~Festival() {sponsori.clear(),merch.clear();}

    void addSponsor()
    {
        vector<string> aux;
        string nume_aux;
        string produs_aux;
        int n_aux;
        int ok=0;


        cout<<"Numele noului sponsor: ";
        cin>>nume_aux;
        cout<<"Cu cate elemente contribuie?: ";
        cin>>n_aux;
        for(int i=0;i<n_aux;i++)
        {
            cin>>produs_aux;
            aux.push_back(produs_aux);
            if(produs_aux == "suma" || produs_aux == "bani" || produs_aux == "money")
                ok=1;
        }

        if(ok==1)
        {
            cout<<"Cu ce suma ajuta noul sponsor?: ";
            int suma_aux;
            cin>>suma_aux;
            this->updateBuget(suma_aux);
        }

        this->sponsori[nume_aux]=aux;




    }

};
istream& operator>>(istream& in, Festival& obj)
{
    in>>(Concert&)obj;
    while(true)
    {
        try
        {
            cout << "Numar vanzatori: ";
            if (!(in >> obj.nrVanzatori)) {
                throw runtime_error("Bro e numar...");
            }

            cout << "Mancare (0/1): ";
            if (!(in >> obj.food)) {
                throw runtime_error("Nu scrie (0/1) degeaba");
            }

            cout << "Exista vreun concurs? (0/1): ";
            if (!(in >> obj.concurs)) {
                throw runtime_error("Nu scrie (0/1) degeaba");
            }

            cout<<"Cate tipuri de bere avem?: ";
            int n;
            if (!(in >> n)) {
                throw runtime_error("E nevoie de un numar intreg");
            }
            cout<<"Introdu tipurile de bere!"<<endl;
            for(int i=0;i<n;i++)
            {
                string s;
                in>>s;
                obj.tipuriBere.push_back(s);
            }


            cout<<"Numar de sponsori: ";
            if (!(in >> n))
                throw runtime_error("E nevoie de un numar intreg");

            for(int i=0;i<n;i++)
            {
                cout<<"Nume sponsor: ";
                string s;
                cin>>s;

                cout<<"Cu cate lucuri sponsorieaza?"<<endl;
                int m;
                if (!(in >> m))
                    throw runtime_error("E nevoie de un numar intreg");

                cout<<"Introduceti obiectele oferite drept sponsorizare..."<<endl;
                for(int j=0;j<m;j++){
                    string t;
                    cin>>t;
                    obj.sponsori[s].push_back(t);
                }
            }

            cout<<"Numar de obiecte merch: ";
            if (!(in >> n))
                throw runtime_error("E nevoie de un numar intreg");

            cout<<"Introduceti obiectele..."<<endl;
            for(int i=0;i<n;i++)
            {
                string s;
                cin>>s;
                obj.merch.push_back(s);
            }

                            break;
        }
        catch (const exception& e)
        {
            cout << "Eroare: " << e.what() << endl;
            in.clear();
            in.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << endl << "Mai baga o fisa!" << endl;
        }


    }

    return in;
}
istream& operator>>(ifstream& in, Festival& obj)
{
    in>>(Concert&)obj;
        try
        {
            //cout << "Numar vanzatori: ";
            if (!(in >> obj.nrVanzatori)) {
                throw runtime_error("Bro e numar...");
            }

            //cout << "Mancare (0/1): ";
            if (!(in >> obj.food)) {
                throw runtime_error("Nu scrie (0/1) degeaba");
            }

            //cout << "Exista vreun concurs? (0/1): ";
            if (!(in >> obj.concurs)) {
                throw runtime_error("Nu scrie (0/1) degeaba");
            }

            //cout<<"Cate tipuri de bere avem?: ";
            int n;
            if (!(in >> n)) {
                throw runtime_error("E nevoie de un numar intreg");
            }
            //cout<<"Introdu tipurile de bere!"<<endl;
            for(int i=0;i<n;i++)
            {
                string s;
                in>>s;
                obj.tipuriBere.push_back(s);
            }

            //cout<<"Numar de sponsori: ";
            if (!(in >> n))
                throw runtime_error("E nevoie de un numar intreg n");

            for(int i=0;i<n;i++)
            {
                //cout<<"Nume sponsor: ";
                string s;
                in>>s;

                //cout<<"Cu cate lucuri sponsorieaza?"<<endl;
                int m;
                if (!(in >> m))
                    throw runtime_error("E nevoie de un numar intreg m");

                //cout<<"Introduceti obiectele oferite drept sponsorizare..."<<endl;
                for(int j=0;j<m;j++){
                    string t;
                    in>>t;
                    obj.sponsori[s].push_back(t);
                }
            }

            //cout<<"Numar de obiecte merch: ";
            if (!(in >> n))
                throw runtime_error("E nevoie de un numar intreg");

            //cout<<"Introduceti obiectele..."<<endl;
            for(int i=0;i<n;i++)
            {
                string s;
                in>>s;
                obj.merch.push_back(s);
            }


        }
        catch (const exception& e)
        {
            cout << "Eroare: " << e.what() << endl;
            in.clear();
            in.ignore(numeric_limits<streamsize>::max(), '\n');
            //cout << endl << "Mai baga o fisa!" << endl;
        }
    return in;
}
ostream& operator<<(ostream& out,const Festival& obj)
{
    out<<(Concert&)obj;
    out<<"Numar vanzatori: ";
    out<<obj.nrVanzatori<<endl;
    out<<"Mancare: ";
    out<<obj.food<<endl;
    out<<"Concurs: ";
    out<<obj.concurs<<endl;
    out<<"Tipuri de bere: ";
    if(obj.tipuriBere.size()==0)
        out<<"Nu-i"<<endl;
    else
        for(int i=0;i<obj.tipuriBere.size();i++)
            out<<obj.tipuriBere[i]<<" ";
    out<<"Sponsori:"<<endl;
    for(auto i=obj.sponsori.begin();i!=obj.sponsori.end();i++)
    {
        out<<i->first<<" ofera: ";
        for(int j=0;j<i->second.size();j++)
            out<<i->second[j]<<"/";

        out<<endl;
    }
    cout<<"Merch: ";
    for(auto i=obj.merch.begin();i!=obj.merch.end();i++)
        out<<*i<<"/";

    return out;
}
ostream& operator<<(ofstream& out,const Festival& obj)
{
    out<<(Concert&)obj;
    out<<"Numar vanzatori: ";
    out<<obj.nrVanzatori<<endl;
    out<<"Mancare: ";
    out<<obj.food<<endl;
    out<<"Concurs: ";
    out<<obj.concurs<<endl;
    out<<"Tipuri de bere: ";
    if(obj.tipuriBere.size()==0)
        out<<"Nu-i"<<endl;
    else
        for(int i=0;i<obj.tipuriBere.size();i++)
            out<<obj.tipuriBere[i]<<" ";
    out<<endl<<"Sponsori:"<<endl;
    for(auto i=obj.sponsori.begin();i!=obj.sponsori.end();i++)
    {
        out<<i->first<<" ofera: ";
        for(int j=0;j<i->second.size();j++)
            out<<i->second[j]<<"/";

        out<<endl;
    }
    out<<"Merch: ";
    for(auto i=obj.merch.begin();i!=obj.merch.end();i++)
        out<<*i<<"/";

    return out;
}


class Menu
{
    vector<Event> evenimente;
    //Event* evenimente;
    vector<Event> vipEvents;

        static Menu* instance;
    Menu() = default;
    ~Menu() = default;

    template <typename T> void read(T& obj)
    {
        cin>>obj;
    }

    template <typename T> bool money_check(int limita, T& obj)
    {
        int buget=obj.getBuget();
        if(buget<limita)
        {
            if(typeid(Festival)==typeid(T))
            {
                cout<<"You don't have enough buget. You miss "<<limita-buget<<". You can fix it by adding a sponsor! Do you want to add one?(0/1)";
                int choice;
                cin>>choice;

                if(choice==1)
                {
                    //obj.addSponsor();
                    return money_check(limita,obj);
                }
            }

            else
                return false;
        }
        else return true;

    }

    template<typename T> void toVip(int cash,T& obj)
    {
        if(money_check(cash,obj)==true)
        {
            cout<<"Event accepted!"<<endl;
            vipEvents.push_back(obj);
        }
        else cout<<"Event denied!"<<endl;
    }

    template<typename T> void printEvents(T obj)
    {
        for(auto i=obj.begin();i!=obj.end();i++)
            cout<<*i<<endl;

    }

    void meniu()
    {
        int choice1;
        bool leave = false;

        while(leave==false)
        {
            cout<<"Alege ce vrei sa faci..."<<endl;
            cout<<"1. Creare Eveniment"<<endl;
            cout<<"2. Creare Concert"<<endl;
            cout<<"3. Creare Beer Fest"<<endl;
            cout<<"4. Creare Festival"<<endl;
            cout<<"5. Afisare evenimente"<<endl;
            cout<<"6. Afisare evenimente VIP"<<endl;
            cout<<"7. Adaugare eveniment la VIP"<<endl;
            cout<<"8. Leave"<<endl;

            cin>>choice1;
            switch(choice1)
            {
            case 1:
                {
                    cout<<"1. Standard"<<endl;
                    cout<<"2. Custom"<<endl;
                    cout<<"3. Fisier"<<endl;
                    int choice2;
                    cin>>choice2;
                    switch(choice2)
                    {
                    case 1:
                        {
                            //evenimente = new Event;
                            Event e;
                            evenimente.push_back(e);
                            break;
                        }
                    case 2:
                        {
                            Event e;
                            //evenimente = new Event;
                            cin>>e;
                            evenimente.push_back(e);
                            break;
                        }
                    case 3:
                        {
                            Event e;
                            e.citire_fisier("event.in");
                            evenimente.push_back(e);
                            break;
                        }
                    }
                    break;
                }
            case 2:
                {
                    cout<<"1. Standard"<<endl;
                    cout<<"2. Custom"<<endl;
                    cout<<"3. Fisier"<<endl;
                    int choice2;
                    cin>>choice2;
                    switch(choice2)
                    {
                    case 1:
                        {

                            Concert c;
                            evenimente.push_back(c);
                            //evenimente = new Concert;
                            break;
                        }
                    case 2:
                        {
                            //evenimente = new Concert;
                            Concert c;
                            cin>>c;
                            evenimente.push_back(c);
                            break;
                        }
                    case 3:
                        {
                            //evenimente = new Concert;
                            Concert c;
                            c.citire_fisier("concert.in");
                            evenimente.push_back(c);
                            break;
                        }
                    }
                    break;
                }
            case 3:
                {
                    cout<<"1. Standard"<<endl;
                    cout<<"2. Custom"<<endl;
                    cout<<"3. Fisier"<<endl;
                    int choice2;
                    cin>>choice2;
                    switch(choice2)
                    {
                    case 1:
                        {
                            //evenimente=new Beerfest;
                            Beerfest b;
                            evenimente.push_back(b);
                            break;
                        }
                    case 2:
                        {
                            //evenimente=new Beerfest;
                            Beerfest b;
                            cin>>b;
                            evenimente.push_back(b);
                            break;
                        }
                    case 3:
                        {
                            //evenimente=new Beerfest;
                            Beerfest b;
                            b.citire_fisier("beerfest.in");
                            evenimente.push_back(b);
                            break;
                        }
                    }
                    break;
                }
            case 4:
                {
                    cout<<"1. Standard"<<endl;
                    cout<<"2. Custom"<<endl;
                    cout<<"3. Fisier"<<endl;
                    int choice2;
                    cin>>choice2;
                    switch(choice2)
                    {
                    case 1:
                        {
                            //evenimente=new Festival;
                            Festival f;
                            evenimente.push_back(f);
                            break;
                        }
                    case 2:
                        {
                            //evenimente=new Festival;
                            Festival f;
                            cin>>f;
                            evenimente.push_back(f);
                            break;
                        }
                    case 3:
                        {
                            //evenimente=new Festival;
                            Festival f;
                            f.citire_fisier("festival.in");
                            evenimente.push_back(f);
                            break;
                        }
                    }
                    break;
                }
            case 5:
                {
                    printEvents(evenimente);
                    break;
                }
            case 6:
                {
                    printEvents(vipEvents);
                    break;
                }
            case 7:
                {
                    cout<<"Alegeti ID-ul evenimentului pe care doriti sa il adaugati la VIP si bugetul minim de care are nevoie pentru a fi aprobat"<<endl;
                    printEvents(evenimente);
                    int aux_id,limit;
                    cout<<"Id-ul dorit: ";
                    cin>>aux_id;
                    try
                    {
                        cout<<"Limita minima: ";
                        if(!(cin>>limit))
                            throw invalid_argument("Functia are nevoie de un numar ca si limita");

                        if(limit<0)
                            throw logic_error("Limita minima este 0");

                        for(int i=0;i<evenimente.size();i++)
                        {
                            if(evenimente[i].getID()==aux_id)
                            {
                                toVip(limit,evenimente[i]);
                            }

                        }
                    }
                    catch (const invalid_argument& e)
                    {
                        cout<<"Invalid argument: "<<e.what()<<endl;
                        cin.clear();
                        cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
                    }
                    catch (const logic_error& g)
                    {
                        cout << "Logic error: " << g.what() << endl;
                        cin.clear();
                        cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
                    }


                    break;
                }
            default:
                {
                    leave=true;
                    break;
                }
            }
        }

    }

public:

    static Menu* getInstance() {
        if(!instance){
            instance = new Menu();
        }
        return instance;
    }

    void start()
    {
        cout<<"Apasa orice tasta pentru a incepe!";
        getch();
        system("CLS");
        meniu();
    }


};
Menu* Menu::instance = nullptr;
int Event::contorId = 1;

int main()
{
    Menu* m=Menu::getInstance();
    m->start();


    return 0;
}
