// Geometry.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>

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

public:
	Geometry();

	void Add_Point(Point &Point);

	void show_Point();

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
	index++;
	cout << "The Point you entered is located at :" << index << endl;
}

void Geometry::show_Point()
{
	cout << "The Quantity of your Points is :" << index << endl;
	for (int i = 0; i < index; i++)
	{
		point_array[i].show();
	}
}


int main()
{
	Point point;
	Geometry geo = Geometry();
	int i;
	for (;;)
	{
		cout << "1.Add point\n" << "2.Show point\n" << endl;
		cin >> i;
		switch (i)
		{
			case 1:
			{
				int x, y;
				cout << "x :";
				cin >> x;
				cout << "y :";
				cin >> y;

				point = Point(x, y);

				geo.Add_Point(point);

				break;
			}
			case 2:
			{
				geo.show_Point();
				break;
			}
		}

	}
}

