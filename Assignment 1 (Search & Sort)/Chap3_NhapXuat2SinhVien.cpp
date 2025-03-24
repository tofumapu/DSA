/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/
#include <iostream>
#include <string>
#include <stdio.h>
#include <iomanip>
#include <limits>

int main() {
	std::string HoTen;
	char GioiTinh;
	int NamSinh;
	char TenLop[100];
	float DiemToan, DiemTin, DTB;

//###INSERT CODE HERE -
    freopen("test.inp","r",stdin);
    freopen("test.out","w",stdout);
    std::string GT, GT2;
    std::string HoTen2;
    int NamSinh2;
    char TenLop2[100];

    getline(std::cin, HoTen);
    getline(std::cin, GT);
    std::cin >> NamSinh;
    std::cin.ignore(256, '\n');
    std::cin.getline(TenLop, 100);
    std::cin >> DiemToan;
    std::cin >> DiemTin;
    DTB = (DiemToan + DiemTin) / 2;

    std::cout << HoTen << '\n';
    std::cout << GT[0] << '\n';
    std::cout << NamSinh << '\n';
    std::cout << TenLop << '\n';
    std::cout << DiemToan << '\n';
    std::cout << DiemTin << '\n';
    std::cout << DTB;
    std::cin.ignore(256, '\n');


    getline(std::cin >> std::ws, HoTen2);
    getline(std::cin >> std::ws, GT2);
    std::cin >> std::ws >> NamSinh2;
    std::cin.ignore(256, '\n');
    std::cin.getline(TenLop2, 100);
    std::cin >> DiemToan >> DiemTin;
    DTB = 0.5 * (DiemToan + DiemTin);
    std::cout << '\n' << HoTen2 << '\n';
    std::cout << GT2[0] << '\n';
    std::cout << NamSinh2 << '\n';
    std::cout << TenLop2 << '\n';
    std::cout << DiemToan << '\n';
    std::cout << DiemTin << '\n';
    std::cout << DTB;
    return 0;
}

