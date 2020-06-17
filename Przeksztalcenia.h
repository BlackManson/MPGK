#include "Macierz.h"
using namespace std;

template <int size>
class Przeksztalcenia
{
private:
	static Macierz<size> privateMacierz;

public:
    static Macierz<size> skalowanie3D(float _wartosc);
	static Macierz<size> skalowanie3D(float wartoscX, float wartoscY);
	static Macierz<size> skalowanie3D(float * _wartoscs);

	static Macierz<size> translacja3D(float _wartosc);
	static Macierz<size> translacja3D(float wartoscX, float wartoscY);
	static Macierz<size> translacja3D(float * _wartoscs);

	static Macierz<size> obrot3D(float kat);
	static Macierz<size> skalowanie4D(float _wartosc);
	static Macierz<size> skalowanie4D(float wartoscX, float wartoscY, float wartoscZ);
	static Macierz<size> skalowanie4D(float * _wartoscs);

	static Macierz<size> obrotX(float kat);
	static Macierz<size> obrotY(float kat);
	static Macierz<size> obrotZ(float kat);
	static Macierz<size> obrot_macierz4x4(float kat, Wektor<size> wektorOs);

	static Macierz<size> translacja4D(float _wartosc);
	static Macierz<size> translacja4D(float wartoscX, float wartoscY, float wartoscZ);
	static Macierz<size> translacja4D(float * _wartoscs);

	static Macierz<4> lookAt(Wektor<3> p_camera, Wektor<3> p_center, Wektor<3> p_up);
	static Macierz<size> macierzPerspektyw(const float katStopnie, const float wysokoscOkna, const float szerokoscOkna, const float bliskieZ, const float dalekieZ);

	static float naStopnie(float rad);
	static float naRadiany(float stopnie);

};


template<int size>
Macierz<size> Przeksztalcenia<size>::skalowanie3D(float wartosc)
{
	Macierz<size> nowaMacierz;
	nowaMacierz.jednostkowa();
	nowaMacierz.setElement(0, 0, wartosc);
	nowaMacierz.setElement(1, 1, wartosc);
	return nowaMacierz;
}

template<int size>
Macierz<size> Przeksztalcenia<size>::skalowanie3D(float wartoscX, float wartoscY)
{
	Macierz<size> nowaMacierz;
	nowaMacierz.jednostkowa();
	nowaMacierz.setElement(0, 0, wartoscX);
	nowaMacierz.setElement(1, 1, wartoscY);
	return nowaMacierz;
}

template<int size>
Macierz<size> Przeksztalcenia<size>::skalowanie3D(float* wartoscs)
{
	Macierz<size> nowaMacierz;
	nowaMacierz.jednostkowa();
	for (int i = 0; i < 2; i++)
	{
		nowaMacierz.setElement(i, i, wartoscs[i]);
	}
	return nowaMacierz;
}

template<int size>
Macierz<size> Przeksztalcenia<size>::obrot3D(float kat)
{
	Macierz<size> nowaMacierz;
	nowaMacierz.jednostkowa();
	float katRadiany = naRadiany(kat);

	nowaMacierz.setElement(0, 0, cos(katRadiany));
	nowaMacierz.setElement(0, 1, -sin(katRadiany));

	nowaMacierz.setElement(1, 0, sin(katRadiany));
	nowaMacierz.setElement(1, 1, cos(katRadiany));

	return nowaMacierz;
}


template<int size>
Macierz<size> Przeksztalcenia<size>::translacja3D(float wartosc)
{
	Macierz<size> nowaMacierz;
	nowaMacierz.jednostkowa();
	nowaMacierz.setElement(0, 2, wartosc);
	nowaMacierz.setElement(1, 2, wartosc);
	return nowaMacierz;
}

template<int size>
Macierz<size> Przeksztalcenia<size>::translacja3D(float wartoscX, float wartoscY)
{
	Macierz<size> nowaMacierz;
	nowaMacierz.jednostkowa();
	nowaMacierz.setElement(0, 2, wartoscX);
	nowaMacierz.setElement(1, 2, wartoscY);
	return nowaMacierz;
}

template<int size>
Macierz<size> Przeksztalcenia<size>::translacja3D(float* tab_2x2)
{
	Macierz<size> nowaMacierz;
	nowaMacierz.jednostkowa();
	nowaMacierz.setElement(0, 2, tab_2x2[0]);
	nowaMacierz.setElement(1, 2, tab_2x2[1]);
	return nowaMacierz;
}


template<int size>
Macierz<size> Przeksztalcenia<size>::skalowanie4D(float wartosc)
{
	Macierz<size> nowaMacierz;
	nowaMacierz.jednostkowa();
	nowaMacierz.setElement(0, 0, wartosc);
	nowaMacierz.setElement(1, 1, wartosc);
	nowaMacierz.setElement(2, 2, wartosc);
	nowaMacierz.setElement(3, 3, nowaMacierz.getElement(3, 3));
	return nowaMacierz;
}

template<int size>
Macierz<size> Przeksztalcenia<size>::skalowanie4D(float wartoscX, float wartoscY, float p_zValue)
{
	Macierz<size> nowaMacierz;
	nowaMacierz.jednostkowa();
	nowaMacierz.setElement(0, 0, wartoscX);
	nowaMacierz.setElement(1, 1, wartoscY);
	nowaMacierz.setElement(2, 2, p_zValue);
	nowaMacierz.setElement(3, 3, nowaMacierz.getElement(3, 3));
	return nowaMacierz;
}

template<int size>
Macierz<size> Przeksztalcenia<size>::skalowanie4D(float* wartoscs)
{
	Macierz<size> nowaMacierz;
	nowaMacierz.jednostkowa();
	for (int i = 0; i < 3; i++)
	{
		nowaMacierz.setElement(i, i, wartoscs[i]);
	}
	nowaMacierz.setElement(3, 3, nowaMacierz.getElement(3, 3));
	return nowaMacierz;
}


template<int size>
Macierz<size> Przeksztalcenia<size>::obrotX(float kat)
{
	Macierz<size> nowaMacierz;
	nowaMacierz.jednostkowa();
	float katRadiany = naRadiany(kat);
	nowaMacierz.setElement(1, 1, cos(katRadiany));
	nowaMacierz.setElement(1, 2, -sin(katRadiany));
	nowaMacierz.setElement(2, 1, sin(katRadiany));
	nowaMacierz.setElement(2, 2, cos(katRadiany));
	return nowaMacierz;
}

template<int size>
Macierz<size> Przeksztalcenia<size>::obrotY(float kat)
{
	Macierz<size> nowaMacierz;
	nowaMacierz.jednostkowa();
	float katRadiany = naRadiany(kat);
	nowaMacierz.setElement(0, 0, cos(katRadiany));
	nowaMacierz.setElement(0, 2, sin(katRadiany));
	nowaMacierz.setElement(2, 0, -sin(katRadiany));
	nowaMacierz.setElement(2, 2, cos(katRadiany));
	return nowaMacierz;
}

template<int size>
Macierz<size> Przeksztalcenia<size>::obrotZ(float kat)
{
	Macierz<size> nowaMacierz;
	nowaMacierz.jednostkowa();
	float katRadiany = naRadiany(kat);
	nowaMacierz.setElement(0, 0, cos(katRadiany));
	nowaMacierz.setElement(0, 1, -sin(katRadiany));
	nowaMacierz.setElement(1, 0, sin(katRadiany));
	nowaMacierz.setElement(1, 1, cos(katRadiany));
	return nowaMacierz;
}

template <int size>
Macierz<size> Przeksztalcenia<size>::obrot_macierz4x4(float kat, Wektor<size> wektorOs) {
    Wektor<size> osX, osY, osZ;
    osX = {1, 0, 0}; // o? X
    osY = {0, 1, 0}; // o? Y
    osZ = {0, 0, 1}; // o? Z

    if (wektorOs == osX) {
        Macierz<size> wzgledemX(4);
        wzgledemX.setElement(0, 0, 1);
        wzgledemX.setElement(1, 1, cos(naRadiany(kat)));
        wzgledemX.setElement(1, 2, -sin(naRadiany(kat)));
        wzgledemX.setElement(2, 1, sin(naRadiany(kat)));
        wzgledemX.setElement(2, 2, cos(naRadiany(kat)));
        wzgledemX.setElement(3, 3, 1);
        privateMacierz = wzgledemX;
    } else if (wektorOs == osY) {
        Macierz<size> wzgledemY(4);
        wzgledemY.setElement(0, 0, cos(naRadiany(kat)));
        wzgledemY.setElement(0, 2, sin(naRadiany(kat)));
        wzgledemY.setElement(1, 1, 1);
        wzgledemY.setElement(2, 0, -sin(naRadiany(kat)));
        wzgledemY.setElement(2, 2, cos(naRadiany(kat)));
        wzgledemY.setElement(3, 3, 1);
        privateMacierz = wzgledemY;
    } else if (wektorOs == osZ) {
        Macierz<size> wzgledemZ(4);
        wzgledemZ.setElement(0, 0, cos(naRadiany(kat)));
        wzgledemZ.setElement(0, 1, -sin(naRadiany(kat)));
        wzgledemZ.setElement(1, 0, sin(naRadiany(kat)));
        wzgledemZ.setElement(1, 1, cos(naRadiany(kat)));
        wzgledemZ.setElement(2, 2, 1);
        wzgledemZ.setElement(3, 3, 1);
        privateMacierz = wzgledemZ;
    }
}

template<int size>
Macierz<size> Przeksztalcenia<size>::translacja4D(float wartosc)
{
	Macierz<size> nowaMacierz;
	nowaMacierz.jednostkowa();
	nowaMacierz.setElement(0, 3, wartosc);
	nowaMacierz.setElement(1, 3, wartosc);
	nowaMacierz.setElement(2, 3, wartosc);

	return nowaMacierz;
}

template<int size>
Macierz<size> Przeksztalcenia<size>::translacja4D(float wartoscX, float wartoscY, float wartoscZ)
{
	Macierz<size> nowaMacierz;
	nowaMacierz.jednostkowa();
	nowaMacierz.setElement(0, 3, wartoscX);
	nowaMacierz.setElement(1, 3, wartoscY);
	nowaMacierz.setElement(2, 3, wartoscZ);

	return nowaMacierz;
}

template<int size>
Macierz<size> Przeksztalcenia<size>::translacja4D(float* tab_3x3)
{
	Macierz<size> nowaMacierz;
	nowaMacierz.jednostkowa();
	nowaMacierz.setElement(0, 3, tab_3x3[0]);
	nowaMacierz.setElement(1, 3, tab_3x3[1]);
	nowaMacierz.setElement(2, 3, tab_3x3[2]);

	return nowaMacierz;
}


template<> Macierz<4> Przeksztalcenia<4>::lookAt(Wektor<3> pozycjaKamery, Wektor<3> pozycjaCelu, Wektor<3> gornyWektor)
{
	Macierz<4> nowaMacierz;
	nowaMacierz.jednostkowa();

	Wektor<3> l_direction = pozycjaKamery - pozycjaCelu;
	l_direction.normalizacja();

	Wektor<3> l_right = l_direction.IloczynWektorowy(gornyWektor);

	l_right.normalizacja();

	gornyWektor = l_right.IloczynWektorowy(l_direction);

	gornyWektor.normalizacja();

	for (int i = 0; i < 3; i++)
	{
		nowaMacierz.setElement(0, i, l_right[i]);
		nowaMacierz.setElement(1, i, gornyWektor[i]);
		nowaMacierz.setElement(2, i, -l_direction[i]);
	}

	nowaMacierz.setElement(0, 3, l_right.iloczynSkalarny(pozycjaKamery));
	nowaMacierz.setElement(1, 3, gornyWektor.iloczynSkalarny(pozycjaKamery));
	nowaMacierz.setElement(2, 3, -l_direction.iloczynSkalarny(pozycjaKamery));

	nowaMacierz.setElement(3, 3, 1.0f);

	return nowaMacierz;
}

template<int size>
Macierz<size> Przeksztalcenia<size>::macierzPerspektyw(const float katStopnie, const float wysokoscOkna, const float szerokoscOkna, const float bliskieZ, const float dalekieZ)
{
	float radio = (float)szerokoscOkna / (float)wysokoscOkna;

	float katRadiany = naRadiany(katStopnie);
	katRadiany = tan(katRadiany * 0.5);

	Macierz<4> nowaMacierz;
	nowaMacierz.jednostkowa();

	nowaMacierz.setElement(0, 0, 1/(radio * katRadiany));
	nowaMacierz.setElement(1, 1, 1/katRadiany);
	nowaMacierz.setElement(2, 2, -(dalekieZ + bliskieZ)/(dalekieZ - bliskieZ));
	nowaMacierz.setElement(3, 2, -1.0f);
	nowaMacierz.setElement(2, 3, -(2 * dalekieZ * bliskieZ) / (dalekieZ - bliskieZ));

	return nowaMacierz;
}


template<int size>
float Przeksztalcenia<size>::naStopnie(float rad)
{

	return rad * 180.0 / M_PI;
}

template<int size>
float Przeksztalcenia<size>::naRadiany(float stopnie)
{

	return stopnie * M_PI / 180.0;
}

