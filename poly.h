#ifndef POLYV2_POLY_H
#define POLYV2_POLY_H
#include<iostream>
using namespace std;
class poly {
private:
    double*tab;
    unsigned int size;
public:
    poly(double x=0);//konstruktor
    ~poly();//dekonstruktor
    double& operator[](unsigned int pos);//operator indekosowania
    void realloc(unsigned int size);//reallokacja pamieci
    poly(const poly &s);//konstruktor kopiujacy
    poly &operator=(const poly &s);//operator przypisania
    friend ostream & operator<<(ostream & s,const poly &c);//operator wypisywania
    poly operator+(const poly &s) const;//operator dodwania
    friend poly operator*(const poly&,const poly&);//operator novena
    double operator()(double x);//obliczanie wartosci w danym punkcie
};


#endif //POLYV2_POLY_H
