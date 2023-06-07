#include <iostream>
#include <vector>

struct Timestamp{
    unsigned hrs;
    unsigned mins;
};

class EventBase{
protected:
    Timestamp Anfang;
    Timestamp Ende;
public:
    //clone function
    virtual EventBase* clone() const =0;
    //constructor
    EventBase();
    //virtual destructor
    virtual ~EventBase() = default;
};

class SimpleEvent: public EventBase{
public:
    SimpleEvent(Timestamp start, Timestamp finish){
        Anfang=start;
        Ende=finish;
    }
    EventBase* clone() const{
        return new SimpleEvent(*this);
    }
};

class EventWithFixedIntermission: public EventBase{
protected:
    Timestamp max_dauerheit;
    Timestamp Antrakt_dauerhaft;

public:
    EventWithFixedIntermission(Timestamp start, Timestamp finish){
        Anfang=start;
        Ende=finish;
        max_dauerheit.hrs=0;
        max_dauerheit.mins=20;

        if(Ende.hrs*60+Ende.mins-(Anfang.hrs*60+Anfang.mins)>240)
            throw std::exception();
    }

    EventBase* clone() const{
        return new EventWithFixedIntermission(*this);
    }

};

class EventWithIntermission: public EventBase{
protected:
    Timestamp Antrakt_anfang;
    Timestamp Antrakt_ende;

    bool check_AntraktZeit() const{
        return (Antrakt_ende.hrs*60+Antrakt_ende.mins-(Antrakt_anfang.hrs*60+Antrakt_anfang.mins))>=30 &&
        (Antrakt_ende.hrs*60+Antrakt_ende.mins-(Antrakt_anfang.hrs*60+Antrakt_anfang.mins))<=60;
    }

public:
    EventWithIntermission(Timestamp start, Timestamp finish, Timestamp Antrakt_anfang, Timestamp Antrakt_ende){
        Anfang=start;
        Ende=finish;
        this->Antrakt_anfang=Antrakt_anfang;
        this->Antrakt_ende=Antrakt_ende;

        if(!check_AntraktZeit() && Ende.hrs*60+Ende.mins-(Anfang.hrs*60+Anfang.mins)>360)
            throw std::exception();

    }

    EventBase* clone() const{
        return new EventWithIntermission(*this);
    }
};

class EventCollection: public EventBase{
private:
    std::vector<EventBase*> data;
public:
    void addEvent();
};

int main(){
}
