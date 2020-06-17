#include "Wektor.h"

using namespace std;

template <int size>
class Macierz
{
protected:
    float macierzTabela[size][size];

public:
    Macierz();
    Macierz(float wartosc);
    Macierz(float _macierz[size][size]);
    Macierz(const Macierz& _macierz);

    Macierz operator=(const Macierz& _macierz);
    Macierz operator+(Macierz& _macierz);
    Macierz& operator+=(Macierz& _macierz);
    Macierz operator-(Macierz& _macierz);
    Macierz& operator-=(Macierz& _macierz);
    Macierz operator*(int wartosc);
    Macierz& operator*=(int wartosc);
    Macierz operator*(Macierz& _macierz);
    Macierz& operator*=(Macierz& _macierz);
    Wektor<size> operator*(Wektor<size>& p_vector);
    friend ostream& operator << (ostream& p_out, const Macierz& _macierz);
    friend ostream& operator<<(ostream& p_out, const Macierz<size>& _macierz)
    {
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                p_out << _macierz.macierzTabela[i][j] << ",		";
            }
            p_out << endl;
        }
        return p_out;
    }

    float getElement(int p_row, int p_column)const;
    void setElement(int p_row, int p_column, float wartosc);
    float* getRow(int p_row);
    void jednostkowa();
    void transponuj();
    void odwrocMacierz();

    float wyznacznikMacierzy();
    float obliczWyznacznik(float matrix[size][size], int rozmiarM);

    Macierz macierzDopelnienAlgebraicznych();
    Macierz dopelnienieAlgebraiczne3D();
    Macierz dopelnienieAlgebraiczne4D();

    Macierz laczTransformacje(initializer_list<Macierz> list);
};


template<int size>
Macierz<size>::Macierz()
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            macierzTabela[i][j] = 0;
        }
    }
}

template<int size>
Macierz<size>::Macierz(float wartosc)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
            macierzTabela[i][j] = wartosc;
    }
}

template<int size>
Macierz<size>::Macierz(float _macierz[size][size])
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
            macierzTabela[i][j] = _macierz[i][j];
    }
}

template<int size>
Macierz<size>::Macierz(const Macierz& _macierz)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            macierzTabela[i][j] = _macierz.macierzTabela[i][j];
        }
    }
}

template<int size>
Macierz<size> Macierz<size>::operator=(const Macierz& p_matrix)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            macierzTabela[i][j] = p_matrix.macierzTabela[i][j];
        }
    }
    return *this;
}
template<int size>
Macierz<size> Macierz<size>::operator+(Macierz& p_matrix)
{
    Macierz<size> l_matrix;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            l_matrix.macierzTabela[i][j] = macierzTabela[i][j] + p_matrix.macierzTabela[i][j];
        }
    }
    return l_matrix;
}
template<int size>
Macierz<size>& Macierz<size>::operator+=(Macierz& p_matrix)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            macierzTabela[i][j] += p_matrix.macierzTabela[i][j];
        }
    }
    return *this;
}
template<int size>
Macierz<size> Macierz<size>::operator-(Macierz& p_matrix)
{
    Macierz<size> l_matrix;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            l_matrix.macierzTabela[i][j] = macierzTabela[i][j] - p_matrix.macierzTabela[i][j];
        }
    }
    return l_matrix;
}
template<int size>
Macierz<size>& Macierz<size>::operator-=(Macierz& p_matrix)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            macierzTabela[i][j] -= p_matrix.macierzTabela[i][j];
        }
    }
    return *this;
}
template<int size>
Macierz<size> Macierz<size>::operator*(int wartosc)
{
    Macierz<size> l_matrix;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            l_matrix.macierzTabela[i][j] = macierzTabela[i][j] * wartosc;
        }
    }
    return l_matrix;
}
template<int size>
Macierz<size>& Macierz<size>::operator*=(int wartosc)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            macierzTabela[i][j] *= wartosc;
        }
    }
    return *this;
}
template<int size>
Macierz<size> Macierz<size>::operator*(Macierz& p_matrix)
{
    Macierz<size> l_matrix;
    for (int i = 0; i < size; i++)
    {
        for (int k = 0; k < size; k++)
        {
            float l_value = 0.0f;
            for (int j = 0; j < size; j++)
            {
                l_value += (macierzTabela[i][j] * p_matrix.macierzTabela[j][k]);
            }
            l_matrix.macierzTabela[i][k] = l_value;
        }

    }
    return l_matrix;
}
template<int size>
Macierz<size>& Macierz<size>::operator*=(Macierz& p_matrix)
{
    Macierz<size> l_matrix = *this;
    for (int i = 0; i < size; i++)
    {
        for (int k = 0; k < size; k++)
        {
            float l_value = 0.0f;
            for (int j = 0; j < size; j++)
            {
                l_value += (l_matrix.macierzTabela[i][j] * p_matrix.macierzTabela[j][k]);
            }
            macierzTabela[i][k] = l_value;
        }
    }
    return *this;
}
template<int size>
Wektor<size> Macierz<size>::operator*(Wektor<size>& p_vector)
{
    Wektor<size> l_vector;
    for (int i = 0; i < size; i++)
    {
        float l_value = 0.0f;
        for (int j = 0; j < size; j++)
        {
            l_value += p_vector[j] * macierzTabela[j][i];
        }
        l_vector[i] = l_value;
    }
    return l_vector;
}

template<int size>
float Macierz<size>::getElement(int wiersz, int kolumna)const
{
    return macierzTabela[kolumna][wiersz];
}

template<int size>
void Macierz<size>::setElement(int wiersz, int kolumna, float wartosc)
{
    macierzTabela[wiersz][kolumna] = wartosc;
}

template<int size>
float* Macierz<size>::getRow(int wiersz)
{
    return macierzTabela[wiersz];
}

template<int size>
void Macierz<size>::jednostkowa()
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (i == j)
                macierzTabela[i][j] = 1.0f;
            else
                macierzTabela[i][j] = 0.0f;
        }
    }
}
template<int size>
void Macierz<size>::transponuj()
{
    Macierz<size> macierz(macierzTabela);
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            macierzTabela[j][i] = macierz.macierzTabela[i][j];
        }
    }
}
template<int size>
void Macierz<size>::odwrocMacierz()
{
    Macierz<size> nowaMacierz = *this;
    float wyznacznik = nowaMacierz.wyznacznikMacierzy();
    float odwroconyWyznacznik = 1.0f / wyznacznik;

    if (wyznacznik == 0)
    {
        cerr << "Nie mo¿na odwróciæ macierzy, ktorej wyznacznik wynosi 0" << endl;
        return;
    }

    if (size == 3)
    {
        *this = nowaMacierz.dopelnienieAlgebraiczne3D();
    }

    if (size == 4)
    {
        *this = nowaMacierz.dopelnienieAlgebraiczne4D();
    }
    *this *= odwroconyWyznacznik;
}

template<int size>
Macierz<size> Macierz<size>::laczTransformacje(initializer_list<Macierz> list)
{
    Macierz<size> nowaMacierz;

    int i = 0;
    for (Macierz<size> elem : list)
    {
        if (i == 0)
        {
            nowaMacierz = elem;
            i++;
        }
        else
        {
            nowaMacierz *= elem;
        }
    }

    return nowaMacierz;
}


template<int size>
float Macierz<size>::wyznacznikMacierzy()
{
    return obliczWyznacznik(macierzTabela, size);

}


template<int size>
float Macierz<size>::obliczWyznacznik(float matrix[size][size], int rozmiarM)
{
    int wyznacznik = 0;
    float submatrix[size][size];

    if (rozmiarM == 2)
        return ((matrix[0][0] * matrix[1][1]) - (matrix[1][0] * matrix[0][1]));
    else {
        for (int x = 0; x < rozmiarM; x++) {

            int subi = 0;
            for (int i = 1; i < rozmiarM; i++) {
                int subj = 0;

                for (int j = 0; j < rozmiarM; j++) {

                    if (j == x)
                        continue;
                    submatrix[subi][subj] = matrix[i][j];
                    subj++;
                }
                subi++;

            }
            wyznacznik = wyznacznik + (pow(-1, x) * matrix[0][x] * obliczWyznacznik(submatrix, rozmiarM - 1));
        }
    }
    return wyznacznik;
}

template<int size>
Macierz<size> Macierz<size>::macierzDopelnienAlgebraicznych()
{
    if (size == 3)
    {
        return dopelnienieAlgebraiczne3D;
    }

    if (size == 4)
    {
        return dopelnienieAlgebraiczne4D;
    }
}


template<int size>
Macierz<size> Macierz<size>::dopelnienieAlgebraiczne3D()
{
    Macierz<size> macierzWynikowa;
    float l_values[4];
    int l_elements = 0;

    for (int wiersz = 0; wiersz < size; wiersz++)
    {
        for (int kolumna = 0; kolumna < size; kolumna++)
        {
            for (int i = 0; i < size; i++)
            {
                for (int j = 0; j < size; j++)
                {
                    if (i != wiersz && j != kolumna)
                    {
                        l_values[l_elements++] = macierzTabela[i][j];
                    }
                }
            }
            l_elements = 0;
            float element = (l_values[0] * l_values[3]) - (l_values[1] * l_values[2]);
            if ((wiersz + kolumna) % 2 == 0)
                macierzWynikowa.setElement(wiersz, kolumna, element);
            else
                macierzWynikowa.setElement(wiersz, kolumna, -element);
        }
    }
    macierzWynikowa.transponuj();
    return macierzWynikowa;
}

template<int size>
Macierz<size> Macierz<size>::dopelnienieAlgebraiczne4D()
{
    Macierz<size> macierzWynikowa;
    float macierzWynikowaT[3][3];
    int wierszMacierzy = 0;
    int kolumnaMacierzy = 0;

    for (int row = 0; row < size; row++)
    {
        for (int column = 0; column < size; column++)
        {
            for (int i = 0; i < size; i++)
            {
                for (int j = 0; j < size; j++)
                {
                    if (i != row && j != column)
                    {
                        macierzWynikowaT[wierszMacierzy][kolumnaMacierzy++] = macierzTabela[i][j];
                    }
                }
                if (kolumnaMacierzy >= 3)
                {
                    kolumnaMacierzy = 0;
                    wierszMacierzy++;
                }
            }
            Macierz<size> l_tempMatrix(macierzWynikowaT);
            wierszMacierzy = 0;
            kolumnaMacierzy = 0;
            float element = l_tempMatrix.wyznacznikMacierzy();
            if ((row + column) % 2 == 0)
                macierzWynikowa.setElement(row, column, element);
            else
                macierzWynikowa.setElement(row, column, -element);
        }
    }
    macierzWynikowa.transponuj();
    return macierzWynikowa;
}
