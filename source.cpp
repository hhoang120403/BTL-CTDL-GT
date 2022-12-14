#include"Vector.h"
#include"Vector.cpp"
#include"Vector_iterator.cpp"
#include"DanhSach.cpp"
#include"hoadon.cpp"
 
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
    for (DanhSach*it1=v1.begin();it1!=v1.end();it1++)
    {
        cout << *it1;
    }
    for (HoaDon*it2=v2.begin();it2!=v2.end();it2++)
    {
        cout << *it2;
    }
    h.ghi_file();

    return 0;
}
