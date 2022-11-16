#include<bits/stdc++.h>
#ifndef __hoadon__cpp
#define __hoadon__cpp
using namespace std;

class HoaDon
{
private:
    string mhd, mh, lhd, day;
    int sl, price;
 
public:
    HoaDon()
    {
        ;
    };
    HoaDon(string mhd, string mh, string lhd, int sl, string day, double price);
    friend istream &operator>>(istream &is, HoaDon &p);
    friend ostream &operator<<(ostream &os, HoaDon p);
};
 
istream &operator>>(istream &is, HoaDon &p)
{
    getline(is, p.mhd);
    getline(is, p.mh);
    getline(is, p.lhd);
    is >> p.sl;
    is.ignore();
    getline(is, p.day);
    is >> p.price;
    is.ignore();
}
 
ostream &operator<<(ostream &os, HoaDon p)
{
    os << "| " << setw(12) << left << p.mhd
       << "| " << setw(10) << left << p.mh
       << "| " << setw(14) << left << p.lhd
       << "| " << setw(10) << left << p.sl
       << "| " << setw(15) << left << p.day
       << "| " << setw(13) << left << p.price
       << "| " << endl;
    return os;
}

#endif
