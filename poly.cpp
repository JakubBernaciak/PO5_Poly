#include <cstdlib>
#include "poly.h"
#include<cmath>
poly::poly(double x){
    tab=new double[1];
    size=1;
    *tab=x;
}
poly::~poly(){
    delete[] tab;
}
void poly::realloc(const unsigned int s) {
    double *ptab;
    ptab=new double[s+1];
    for(unsigned int i=0;i<s+1;i++)//zapelnianie zerami nowej tablicy
        ptab[i]=0;
    for(unsigned int i=0;i<this->size;i++)//przepisywanie wartosci
        ptab[i]=this->tab[i];
    this->size=s+1;
    delete[] this->tab;
    this->tab=ptab;
}
double &poly::operator[](unsigned int pos) {
    if(pos>=size)//jezeli indeks jest wiekszy lub rowny wielkosci allokujemy nowa tablice
        realloc(pos);
    return tab[pos];
}
poly::poly(const poly &s) {
    tab=new double[s.size];
    size=s.size;
    for(unsigned int i=0;i<size;i++)
        tab[i]=s.tab[i];
}
poly &poly::operator=(const poly &s){
    if(this==&s)
        return *this;
    delete[] tab;
    tab=new double[s.size];
    size=s.size;
    for(unsigned int i = 0;i<size;i++)
        tab[i]=s.tab[i];
    return *this;
}
ostream &operator<<(ostream &s, const poly &c){
    if(c.size==1){
        s<<c.tab[0];
        return s;
    }
    for(int i=(int)c.size-1;i>=0;i--){
        if(c.tab[i]==0) continue; //pomijanie zer
        if(i!=c.size-1){
            if(c.tab[i]>0)
                s<<" + ";
            else
                s<<" - ";
        }
        if(i==0)
            s << abs(c.tab[i]);
        else if(i==1)
            s << abs(c.tab[i])<<"x";
        else
        if(c.tab[i]!=1)
            s << abs(c.tab[i]) << "x^"<<i;
        else
            s << "x^"<<i;
    }
    return s;
}
poly poly::operator+(const poly&s)const{
    poly p3;
    if(this->size>s.size)
        p3.realloc(this->size-1);
    else
        p3.realloc(s.size-1);
    for(unsigned int i=0;i<this->size;i++)
        p3.tab[i]+=this->tab[i];
    for(unsigned int i=0;i<s.size;i++)
        p3.tab[i]+=s.tab[i];
    return p3;
}
poly operator*(const poly &a,const poly &b){
    poly c;
    c.realloc(a.size+b.size-2);
    for(int i=0;i<a.size;i++)
        for(int j=0;j<b.size;j++)
            c.tab[i+j]+=b.tab[j]*a.tab[i];
    return c;
}
double poly::operator()(double x) {
    double value=0;
    for(unsigned int i=0;i<size;i++)
        value+=tab[i]*pow(x,i);
    return value;
}
