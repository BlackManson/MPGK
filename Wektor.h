#pragma once
#include <iostream>
#include <math.h>
#include <type_traits>


using namespace std;
template <int size>
class Wektor
{
protected:
    float vectorElement[size];

public:
    Wektor();
    Wektor(float wartosc);
    Wektor(float wartoscX, float wartoscY, float wartoscZ);
    Wektor(float wartoscX, float wartoscY, float wartoscZ, float wartoscW);
    Wektor(float* przekazanaTablica);
    Wektor& operator=(const Wektor& _wektor);
    Wektor operator+(Wektor& _wektor);
    Wektor& operator+=(Wektor& _wektor);
    Wektor operator-(Wektor& _wektor);
    Wektor& operator-=(Wektor& _wektor);
    Wektor operator*(int scalar);
    Wektor& operator*=(int scalar);
    friend ostream& operator<<(ostream& _output, const Wektor& _wektor);

    float getX()const;
    float getY()const;
    float getZ()const;
    float getW()const;
    void setX(float wartoscX);
    void setY(float wartoscY);
    void setZ(float wartoscZ);
    void setW(float wartoscW);

    void normalizacja();
    float iloczynSkalarny(Wektor& _wektor);
    Wektor IloczynWektorowy(Wektor& _wektor);

    float dlugoscWektora();
    float& operator[](int index); //wykorzystywane w funkcji lookat

};

template<int size>
Wektor<size>::Wektor()
{
    for (int i = 0; i < size; i++)
    {
        vectorElement[i] = 0;
    }
}

template<int size>
Wektor<size>::Wektor(float wartosc)
{
    for (int i = 0; i < size; i++)
    {
        vectorElement[i] = wartosc;
    }
}

template<int size>
Wektor<size>::Wektor(float wartoscX, float wartoscY, float wartoscZ)
{
    vectorElement[0] = wartoscX;
    vectorElement[1] = wartoscY;
    vectorElement[2] = wartoscZ;
}

template<int size>
Wektor<size>::Wektor(float wartoscX, float wartoscY, float wartoscZ, float wartoscW)
{
    vectorElement[0] = wartoscX;
    vectorElement[1] = wartoscY;
    vectorElement[2] = wartoscZ;
    vectorElement[3] = wartoscW;
}

template<int size>
Wektor<size>::Wektor(float* _tablica)
{
    for (int i = 0; i < size; i++)
    {
        vectorElement[i] = _tablica[i];
    }
}


template<int size>
Wektor<size>& Wektor<size>::operator=(const Wektor<size>& _wektor)
{
    for (int i = 0; i < size; i++)
    {
        vectorElement[i] = _wektor.vectorElement[i];
    }
    return *this;
}

template<int size>
Wektor<size> Wektor<size>::operator+(Wektor<size>& _wektor)
{
    Wektor<size> l_vec;
    for (int i = 0; i < size; i++)
    {
        l_vec.vectorElement[i] = vectorElement[i] + _wektor[i];
    }
    return l_vec;
}

template<int size>
Wektor<size>& Wektor<size>::operator+=(Wektor<size>& _wektor)
{
    for (int i = 0; i < size; i++)
    {
        vectorElement[i] += _wektor[i];
    }
    return *this;
}

template<int size>
Wektor<size> Wektor<size>::operator-(Wektor<size>& _wektor)
{
    Wektor<size> l_vec;
    for (int i = 0; i < size; i++)
    {
        l_vec.vectorElement[i] = vectorElement[i] - _wektor[i];
    }
    return l_vec;
}

template<int size>
Wektor<size>& Wektor<size>::operator-=(Wektor<size>& _wektor)
{
    for (int i = 0; i < size; i++)
    {
        vectorElement[i] -= _wektor[i];
    }
    return *this;
}

template<int size>
Wektor<size> Wektor<size>::operator*(int scalar)
{
    Wektor<size> l_vec;
    for (int i = 0; i < size; i++)
    {
        l_vec.vectorElement[i] = this->vectorElement[i] * scalar;
    }
    return l_vec;
}

template<int size>
Wektor<size>& Wektor<size>::operator*=(int scalar)
{
    for (int i = 0; i < size; i++)
    {
        vectorElement[i] *= scalar;
    }
    return *this;
}

template<int size>
ostream& operator<<(ostream& _output, const Wektor<size>& _wektor)
{
    _output << "( ";
    for (int i = 0; i < size; i++)
    {
        if (i == 3)
            _output << _wektor.vectorElement[i];
        else
            _output << _wektor.vectorElement[i] << ", ";
    }
    _output << " )";
    return _output;
}

template<int size>
float Wektor<size>::getX()const
{
    return vectorElement[0];
}

template<int size>
float Wektor<size>::getY()const
{
    return vectorElement[1];
}

template<int size>
float Wektor<size>::getZ()const
{
    return vectorElement[2];
}

template<int size>
float Wektor<size>::getW()const
{
    return vectorElement[3];
}

template<int size>
void Wektor<size>::setX(float wartoscX)
{
    vectorElement[0] = wartoscX;
}

template<int size>
void Wektor<size>::setY(float wartoscY)
{
    vectorElement[1] = wartoscY;
}

template<int size>
void Wektor<size>::setZ(float wartoscZ)
{
    vectorElement[2] = wartoscZ;
}

template<int size>
void Wektor<size>::setW(float wartoscW)
{
    vectorElement[3] = wartoscW;
}

template<int size>
void Wektor<size>::normalizacja()
{
    float _wektorDlugosc = dlugoscWektora();

    if (_wektorDlugosc == 0)
    {
        cerr << "Nie mozna normalizowac wektora o dlugosci 0" << endl;
        return;
    }
    for (int i = 0; i < size; i++)
    {
        vectorElement[i] /= _wektorDlugosc;
    }
}

template<int size>
float Wektor<size>::iloczynSkalarny(Wektor<size>& _wektor)
{
    float skalar = 0;
    for (int i = 0; i < size; i++)
    {
        skalar += (vectorElement[i] * _wektor.vectorElement[i]);
    }
    return skalar;
}


template<int size>
Wektor<size> Wektor<size>::IloczynWektorowy(Wektor& _wektor)
{
    float x = (vectorElement[1] * _wektor.vectorElement[2] - vectorElement[2] * _wektor.vectorElement[1]);
    float y = -(vectorElement[0] * _wektor.vectorElement[2] - vectorElement[2] * _wektor.vectorElement[0]);
    float z = (vectorElement[0] * _wektor.vectorElement[1] - vectorElement[1] * _wektor.vectorElement[0]);
    float w = vectorElement[3];

    if (size == 4)
    {
        return Wektor(x,y,z,w);
    }

    if (size == 3)
    {
        return Wektor(x, y, z);
    }

}


template<int size>
float& Wektor<size>::operator[](int index)
{
    return vectorElement[index];
}

template<int size>
float Wektor<size>::dlugoscWektora()
{
    float result = 0.0f;

    for (int i = 0; i < size; i++)
    {
        result += (vectorElement[i] * vectorElement[i]);
    }

    return sqrt(result);
}
