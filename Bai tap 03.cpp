#include <iostream>
#include <iomanip>
using namespace std;
class Candidate{
    friend class TestCandidate;
private:
    string ma,ten, ngaysinh;
    double Toan,Van,Anh;
public:
    friend istream& operator >> (istream&,Candidate&);
    friend ostream& operator << (ostream&,Candidate);

};

istream& operator >>(istream& nhap, Candidate &a){
nhap>>a.ma;
nhap.ignore();
getline(nhap,a.ten);
nhap>>a.ngaysinh;
nhap>>a.Toan>>a.Van>>a.Anh;
return nhap;
}

ostream& operator << (ostream& xuat,Candidate a){
xuat<<a.ma<<endl;
xuat<<a.ten<<endl;
xuat<<a.ngaysinh<<endl;
xuat<<fixed<<setprecision(2)<<a.Toan<<" "<<a.Van<<" "<<a.Anh<<endl;
return xuat;
}

class TestCandidate{
private:    
    int n;
    Candidate *a;
public:
    void Nhap();
    void Xuat();
    bool KiemTra();
    ~TestCandidate();
};

void TestCandidate::Nhap(){
cout<<"Nhap So Luong Thi Sinh: ";
cin>>n;
a = new Candidate[n];
for(int i = 0;i<n;i++){
    cout<<"Thi Sinh thu: "<<i+1<<endl;
    cin>>a[i];
}
}

void TestCandidate::Xuat(){
cout<<endl;
cout<<"Danh Sach Thi Sinh: "<<endl;
double tongDiem;
for(int i = 0; i<n;i++){
    tongDiem = a[i].Toan + a[i].Van + a[i].Anh;
    if(tongDiem>15){
        cout<<a[i]<<endl;
    }
}
}

TestCandidate::~TestCandidate() {
    delete[] a;
}

int main(){
 TestCandidate SinhVien;
 SinhVien.Nhap();
 SinhVien.Xuat();
}
