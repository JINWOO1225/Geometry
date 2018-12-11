// Geometry.cpp
// https://modoocode.com/173

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
	int index;

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

	int isitOneLine(Point &point1, Point &point2, Point &targetPoint);
};

Geometry::Geometry()
{
	index = 0;
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
	for (int i = index - 1; i >= 0; i--)
	{
		for (int j = i-1; j >= 0; j--)
		{
			cout << i <<":"<< j <<":"<< Distance(Get_Point(i),Get_Point(j)) << endl;
		}
	}
}
// 모든 점들을 잇는 직선들 간의 교점의 수를 출력해주는 함수 입니다.
// 참고적으로 임의의 두 점을 잇는 직선의 방정식을 f(x,y) = ax+by+c = 0 이라고 할 때 임의의 다른 두 점 (x1, y1) 과 (x2, y2) 가 f(x,y)=0 을 기준으로 서로 다른 부분에 있을 조건은 f(x1, y1) * f(x2, y2) <= 0 이면 됩니다.
// 
void Geometry::Print_Num_Meets() 
{
	int count = 0;
	int *nodeArray = new int[index];
	for(int i = index; i >= 0; i--)
	{
		for(int j = i - 1; j >= 0; j--)
		{
			for(int k = 0; k < index; k++)
			{
				cout << i << j << k;
				isitOneLine(point_array[i],point_array[j],point_array[k]);
			}
		}
	}
}

int Geometry::isitOneLine(Point &point1, Point &point2, Point &targetPoint)
{

	cout << "result is : "<< (((double)point1.gety() - (double)point2.gety())*((double)targetPoint.getx()-(double)point1.getx())/((double)targetPoint.gety()-(double)point1.gety())) << endl;


}

int main()
{
	Point point;
	Geometry geo = Geometry();
	char i;
	for (;;)
	{
		cout << "1.Add point\n" << "2.Show point\n" << "3.Show Distance\n"<< "4.Show Meeting Points\n" << endl;
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

			case '4':
			{
				geo.Print_Num_Meets();
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

