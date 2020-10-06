#pragma once
#include <vector>
#include <iostream>

using std::vector;

namespace task
{
// бинарный + для векторов
vector<double> operator+(const vector<double> & a, const vector<double> & b)
{
    vector<double> tmp (a.size());

    for (int i = 0; i < a.size(); ++i)
    {
        tmp[i] = a[i] + b[i];
    }

    return tmp;
}

// бинарный - для векторов
vector<double> operator-(const vector<double> & a, const vector<double> & b)
{
    vector<double> tmp (a.size());

    for (int i = 0; i < a.size(); ++i)
    {
        tmp[i] = a[i] - b[i];
    }

    return tmp;
}

// переставляет элементы вектора в обратном порядке
vector<double> reverse(const vector<double> & a)
{
    vector<double> tmp (a.size());

    for (unsigned i = (a.size() - 1); i >= 0; --i)
    {
        tmp[i] = a[i];
    }

    return tmp;
}

// скалярное произведение
double operator*(const vector<double> & a, const vector<double> & b)
{
    double scalar_product = 0;

    for (int i = 0; i < a.size(); ++i)
    {
        scalar_product+= (a[i] * b[i]);
    }

    return scalar_product;
}

// векторное произведение
double operator%(const vector<double> & a, const vector<double> & b)
{

}

//vector<double> & operator+(const vector<double> & value)
//{
//    return const_cast<vector<double> &>(value);
//}
//
//vector<double> & operator-(vector<double> & value )
//{
//
//}



//    R operator %(K a, S b);
//    bool operator ||(K a, S b);
//    bool operator &&(K a, S b);
//    R operator <<(K a, S b);
//    R operator >>(K a, S b);

}
