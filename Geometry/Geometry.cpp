// Geometry.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>
#include <cmath>

using namespace std;

class Point {
private: 
		int x, y;
public:
	Point()
	{
		x = 0;
		y = 0;
	}
	Point(int _x, int _y)
	{
		x = _x;
		y = _y;
	}

	int getx() { return x; }
	int gety() { return y; }

	void show();
	

};

void Point::show()
{
	cout << "The point x : " << x << "\ty : " << y << endl;
}

class Geometry {
private:
	int index = 0;

	Point *point_array;
	// 현재 공간에 대한 점들의 정보를 담고 있는 배열
	// 물론 배열의 크기는 생성자에서 초기화 하고 충분히
	// 크게 잡도록 합시다 (점 100 개 정도?)
public:
	Geometry();	//생성자

	Point &Get_Point(const int index) { return point_array[index]; }
	
	void Add_Point(Point &Point);

	void show_Point();

	double Distance(Point &point1, Point &point2);
	// 모든 점들 간의 거리를 출력하는 함수 입니다.
	void Print_Distance();

	void Print_Num_Meets();

};

Geometry::Geometry()
{
	point_array = new Point[100];
}

void Geometry::Add_Point(Point &point)
{
	point_array[index] = point;
	cout << "The Point you entered is located at :" << index << endl;
	index++;
}

void Geometry::show_Point()
{
	cout << "The Quantity of your Points is :" << index << endl;
	for (int i = 0; i < index; i++)
	{
		point_array[i].show();
	}
}

double Geometry::Distance(Point &point1, Point &point2)
{
	return sqrt(pow((point1.getx() - point2.getx()), 2) + pow((point1.gety() - point2.gety()), 2));
}

void Geometry::Print_Distance()		//각 점과의 거리를 표시
{
	for (int i = index; i > 0; i--)
	{
		for (int j = i; j > 0; j--)
		{
			cout << i <<":"<< j <<":"<< Distance(Get_Point(i),Get_Point(j)) << endl;
		}
	}
}

int main()
{
	Point point;
	Geometry geo = Geometry();
	char i;
	for (;;)
	{
		cout << "1.Add point\n" << "2.Show point\n" << "3.Show Distance\n" << endl;
		cin >> i;
		switch (i)
		{
			case '1':
			{
				int x, y;

				cout << "x :"; cin >> x; 
				cout << "y :"; cin >> y;

				point = Point(x, y);

				geo.Add_Point(point);

				break;
			}
			case '2':
			{
				geo.show_Point();
				break;
			}
			case '3':
			{
				geo.Print_Distance();
				break;
			}
			default:
				break;
		}
		if (i == 'q')
			break;

	}

	return 0;
}

