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

// унарный + для векторов
vector<double> operator+(const vector<double> & value)
{
    return value;
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

// унарный - для векторов
vector<double> operator-(const vector<double> & value)
{
    vector<double> tmp (value.size());

    for (int i = 0; i < value.size(); ++i)
    {
        tmp[i] = -value[i];
    }

    return tmp;
}

// переставляет элементы вектора в обратном порядке
vector<double> reverse(const vector<double> & a)
{
    vector<double> tmp (a.size());

    size_t last_index = a.size() - 1;

    for (ssize_t i = last_index; i >= 0; --i)
    {
        tmp[last_index - i] = a[i];
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
//double operator%(const vector<double> & a, const vector<double> & b)
//{
//
//}


// битовая | операция поэлементно
vector<int> operator|(const vector<int> & a, const vector<int> & b)
{
    vector<int> tmp (a.size());

    for (int i = 0; i < a.size(); ++i)
    {
        tmp[i] = a[i] | b[i];
    }

    return tmp;
}

// битовая & операция поэлементно
vector<int> operator&(const vector<int> & a, const vector<int> & b)
{
    vector<int> tmp (a.size());

    for (int i = 0; i < a.size(); ++i)
    {
        tmp[i] = a[i] & b[i];
    }

    return tmp;
}

// потоковый ввод
std::istream & operator>>(std::istream & is, vector<double> & value )
{
    int n;
    is >> n;

    value.resize(n);

    for (int i = 0; i < n; ++i)
    {
        is >> value[i];
    }

    return is;
}

// потоковый вывод
std::ostream & operator<<(std::ostream & os, vector<double> const & value )
{
    for (double val: value)
        os << val << ' ';

    os << '\n';

    return os;
}

}
