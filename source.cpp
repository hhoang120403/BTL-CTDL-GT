#include"Vector.h"
#include"Vector.cpp"
#include"Vector_iterator.cpp"

int cnt = 0;
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
 
Vector<DanhSach> v1;
Vector<HoaDon> v2;
 
class Hang
{
public:
    void doc_file();
    void ghi_file();
    void so_luong_mat_hang();
    friend ostream &operator<<(ostream &os, Hang p);
};
 
void Hang::doc_file()
{
    ifstream filein;
    filein.open("test.txt", ios_base::in);
    int n;
    filein >> n;
    filein.ignore();
    DanhSach x;
    for (int i = 1; i <= n; i++)
    {
        filein >> x;
        v1.push_back(x);
    }
    int m;
    filein >> m;
    filein.ignore();
    HoaDon k;
    for (int i = 1; i <= m; i++)
    {
        filein >> k;
        v2.push_back(k);
    }
}
 
void Hang::ghi_file()
{
    fstream f;
    f.open("output.txt", ios::out);
    f << "***********************************************************************************************\n"
      << setw(35) << right << "DANH SACH MAT HANG" << endl;
    f << "---------------------------------------------------------\n";
    f << "| " << setw(10) << left << "Ma hang"
      << "| " << setw(20) << left << "Ten hang"
      << "| " << setw(20) << left << "Nha san xuat"
      << "|" << endl;
    f << "---------------------------------------------------------\n";
 
    for (auto &it : v1)
    {
        f << it;
    }
    f << "---------------------------------------------------------\n\n";
    f << setw(50) << right << "HOA DON MUA BAN HANG" << endl;
    f << "---------------------------------------------------------------------------------------\n";
    f << "| " << setw(12) << left << "Ma hoa don"
      << "| " << setw(10) << left << "Ma hang"
      << "| " << setw(14) << left << "Loai hoa don"
      << "| " << setw(10) << left << "So luong"
      << "| " << setw(15) << left << "Ngay mua ban"
      << "| " << setw(13) << left << "Gia mua ban"
      << "| " << endl;
    f << "---------------------------------------------------------------------------------------\n";
 
    for (auto &it : v2)
    {
        f << it;
    }
    f << "---------------------------------------------------------------------------------------\n\n";
}
 
void Hang::so_luong_mat_hang()
{
}
 
int main()
{
    Hang h;
    h.doc_file();
    for (auto &it : v1)
    {
        cout << it;
    }
    for (auto &it : v2)
    {
        cout << it;
    }
    h.ghi_file();

    return 0;
}
