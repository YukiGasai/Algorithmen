#include <iostream>
#include <algorithm>
#include <vector>



struct Point {
	float x;
	float y;
	Point(float _x, float _y) {
		x = _x;
		y = _y;
	}
};

float fa0(Point p) {
	return p.x * p.x + p.y * p.y;
}


Point operator+(const Point& a, const Point& b) {
	return Point(a.x+b.x, a.y+b.y);
}

Point operator-(const Point& a, const Point& b) {
	return Point(a.x - b.x, a.y - b.y);
}


Point operator*(float a, const Point& p) {
	return Point((float)a*p.x, (float)a*p.y);
}

bool operator<(const Point& a, const Point& b) {
	return fa0(a) < fa0(b);
}

bool operator<=(const Point& a, const Point& b) {
	return fa0(a) <= fa0(b);
}

bool operator>(const Point& a, const Point& b) {
	return fa0(a) > fa0(b);
}

bool operator>=(const Point& a, const Point& b) {
	return fa0(a) >= fa0(b);
}

float fa0(float x, float y) {
	return x * x + y * y;
}

float fa1x(float x, float y) {
	return -2 * x;
}

float fa1y(float x, float y) {
	return -2 * y;
}



void Armijo(float x, float y, float s) {
	
	while (true) {
		float oldX = x;
		x = x + s * fa1x(x, y);
		y = y + s * fa1y(x, y);

		
		if (abs(x - oldX) < 0.001) {
			break;
		}

	}

	std::cout << "Min bei " << x << " :  " << y << std::endl;

}


void DownhillSimplex() {


	std::vector<Point> points = { {1,1}, {1,2}, {3,1} };
	


	while (true) {

		std::sort(points.begin(), points.end());
		std::cout << "---------- SORTED --------------" << std::endl;
		for (int i = 0; i < 3; i++) {
			std::cout << points[i].x << "\t" << points[i].y << "\t\t" << fa0(points[i]) << std::endl;
		}

		Point z = 0.5 * (points[0] + points[1]);
	
		Point r = z + 1 * (z - points[2]);




		if (points[0] <= r && r <= points[1]) {
			points[2] = r;
		}
		else if (r <= points[0]) {
			Point e = z + 2 * (z - points[2]);
			if (e < r) {
				points[2] = e;
			}
			else {
				points[2] = r;
			}
		}
		else if (r > points[1]) {
			Point k(0,0);
			if (r > points[2]) {
				k = z + 0.5 * (points[2] - z);
			}
			else {
				k = z + 0.5 * (z - points[2]);
			}

			if (k < points[2]) {
				points[2] = k;
			}
			else {
				for (int i = 0; i < 3; i++) {
					points[i] = 0.5 * (points[i] + points[0]);
				}
			}

		}

		std::cout << "---------- NEW --------------" << std::endl;
		for (int i = 0; i < 3; i++) {
			std::cout << points[i].x << "\t" << points[i].y << "\t\t" << fa0(points[i]) << std::endl;
		}
	
	}
}

int main() {
	//Armijo(1, 1, 0.3);
	DownhillSimplex();
}