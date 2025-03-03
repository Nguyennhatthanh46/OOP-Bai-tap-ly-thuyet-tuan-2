#include <iostream>

using namespace std;
class SoPhuc {
private:
    double phanThuc;
    double phanAo;
public:
    friend istream& operator >> (istream&,SoPhuc&);
    friend ostream& operator << (ostream&,SoPhuc);
    friend SoPhuc operator + (SoPhuc a,SoPhuc b);
    friend SoPhuc operator - (SoPhuc a,SoPhuc b);
    friend SoPhuc operator * (SoPhuc a,SoPhuc b);
    friend SoPhuc operator / (SoPhuc a,SoPhuc b);
    double getPhanThuc(){
        return phanThuc;
        }
    double getPhanAo(){
        return phanAo;
        }
};

istream& operator >>(istream& nhap, SoPhuc &a){
nhap>>a.phanThuc>>a.phanAo;
return nhap;
}

SoPhuc operator + (SoPhuc a,SoPhuc b){
SoPhuc temp;
temp.phanThuc = a.phanThuc + b.phanThuc;
temp.phanAo = a.phanAo + b.phanAo;
return temp;
}

SoPhuc operator - (SoPhuc a,SoPhuc b){
SoPhuc temp;
temp.phanThuc = a.phanThuc - b.phanThuc;
temp.phanAo = a.phanAo - b.phanAo;
return temp;
}

SoPhuc operator * (SoPhuc a,SoPhuc b){
SoPhuc temp;
temp.phanThuc = a.phanThuc*b.phanThuc - a.phanAo*b.phanAo;
temp.phanAo = a.phanThuc*b.phanAo + a.phanAo*b.phanThuc;
return temp;
}

SoPhuc operator / (SoPhuc a,SoPhuc b){
SoPhuc temp;
temp.phanThuc = (a.phanThuc*b.phanThuc + a.phanAo*b.phanAo)/(b.phanThuc*b.phanThuc + b.phanAo*b.phanAo);
temp.phanAo = (a.phanAo*b.phanThuc - a.phanThuc*b.phanAo)/(b.phanThuc*b.phanThuc + b.phanAo*b.phanAo) ;
return temp;
}

ostream& operator << (ostream& xuat,SoPhuc a){
if(a.phanThuc!=0){
if(a.phanAo > 0) {
        xuat <<a.phanThuc<<"+"<<a.phanAo<<"i";
}
else if(a.phanAo<0) {
        xuat <<a.phanThuc<<a.phanAo<<"i ";
}
else {
        xuat <<a.phanThuc;
        }
}else{
if (a.phanAo != 0) {xuat << a.phanAo << "i";
}
    else {xuat << "0";}
}
return xuat;
}

int main(){
SoPhuc sp1, sp2;
cout<<"Nhap lan luot hai So Phuc: "<<endl;
cin>>sp1>>sp2;
while(sp2.getPhanThuc()==0&&sp2.getPhanAo()==0){
    cout<<"Vui long nhap lai: "<<endl;
    cin>>sp1>>sp2;
}
cout<<"Ket qua phep cong hai So Phuc: "<<sp1+sp2<<endl;
cout<<"Ket qua phep tru hai So Phuc: "<<sp1-sp2<<endl;
cout<<"Ket qua phep nhan hai So Phuc: "<<sp1*sp2<<endl;
cout<<"Ket qua phep chia hai So Phuc: "<<sp1/sp2<<endl;
}
