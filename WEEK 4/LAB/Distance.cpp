#include <iostream>
#include <cmath>
using namespace std;

#include "Distance.h"

Distance::Distance(){
    _inches = 0;
    _feet = 0.0;
    init();
}

Distance::Distance(unsigned ft, double in){
    _feet = ft;
    _inches = in;
    init();
}

Distance::Distance(double in){
    _feet = 0;
    _inches = in;
    init();
}

unsigned Distance::getFeet() const {
    cout << _feet << endl;
    return _feet;
}

double Distance::getInches() const {
    cout << _inches << endl;
    return _inches;
}

double Distance::distanceInInches() const {
    return ((_feet*12)+_inches);
}

double Distance::distanceInFeet() const {
    return ((_feet)+(_inches/12));
}

double Distance::distanceInMeters() const{
    double meters = distanceInInches()*0.0254;
    return(meters);
}

Distance Distance::operator+(const Distance& rhs) const {
    Distance sum;
    sum._feet = _feet + rhs._feet;
    sum._inches = _inches + rhs._inches;
    sum.init();
    return sum;
}

Distance Distance::operator-(const Distance& rhs) const {
    Distance diff;

    if(_feet == 0 && rhs._feet == 0){
        if(_inches < rhs._inches){
            diff._feet = 0;
            diff._inches = rhs._inches - _inches;
        }
        else{
            diff._feet = 0;
            diff._inches = _inches - rhs._inches;
        }
    }

    else if(_feet < rhs._feet){
        if(rhs._inches < _inches){
            diff._feet = rhs._feet - 1 - _feet;
            diff._inches = rhs._inches + 12 - _inches;
        }
        else{
            diff._feet = rhs._feet - _feet;
            diff._inches = rhs._inches - _inches;
        }
    }
    else{
        if(_inches < rhs._inches){
            diff._feet = _feet - 1 - rhs._feet;
            diff._inches = _inches + 12 - rhs._inches;
        }
        else{
            diff._feet = _feet - rhs._feet;
            diff._inches = _inches - rhs._inches;
        }
    }
    diff.init();
    return diff;
}

ostream &operator<<(ostream &out, const Distance &rhs) {
    out << rhs._feet << "' " << rhs._inches << "\"";
    return out;
}

void Distance::init(){
    if(_inches < 0){
        _inches = -(_inches);
    }
    if(_inches >= 12){
        _feet += _inches/12;
        _inches = fmod(_inches,12);
    }
}
