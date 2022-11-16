#include<bits/stdc++.h>
#ifndef __danhsach__cpp__
#define __danhsach__cpp__

using namespace std;

class DanhSach
{
private:
    string mh, th, nsx;
 
public:
    DanhSach()
    {
        ;
    };
    DanhSach(string mh, string th, string nsx);
    friend istream &operator>>(istream &is, DanhSach &p);
    friend ostream &operator<<(ostream &os, DanhSach p);
    friend void display();
};
 
istream &operator>>(istream &is, DanhSach &p)
{
    getline(is, p.mh);
    getline(is, p.th);
    getline(is, p.nsx);
}
 
ostream &operator<<(ostream &os, DanhSach p)
{
    os << "| " << setw(10) << left << p.mh
       << "| " << setw(20) << left << p.th
       << "| " << setw(20) << left << p.nsx
       << "|" << endl;
    return os;
}

#endif

