#pragma once
//credit to 3 blue 1 brown and ben eater for their interactive quaternion series
#include <math.h>
class Quat
{
protected:
	double r, i, j, k;

public:

	Quat(double rl, double ii, double ji, double ki) : r(rl), i(ii), j(ji), k(ki) {}

	double X() { return i; }
	double Y() { return j; }
	double Z() { return k; }

	//theta - amount to rotate by, unit  - axis to rotate around, point - point being rotated
	static Quat rot(double theta, Quat unit, Quat point) 
	{
		double s1 = sin( theta);
		double s2 = sin(-theta);
		Quat q1(cos( theta), s1 * unit.i, s1 * unit.j, s1 * unit.k);
		Quat q2(cos(-theta), s2 * unit.i, s2 * unit.j, s2 * unit.k);
		return q1 * point * q2;
	}

	Quat operator*(Quat in) 
	{
		return Quat(this->r * in.r - this->i * in.i - this->j * in.j - this->k * in.k, 
					this->r * in.i + this->i * in.r + this->j * in.k - this->k * in.j,
					this->r * in.j + this->j * in.r + this->k * in.i - this->i * in.k,
					this->r * in.k + this->k * in.r + this->i * in.j - this->j * in.i);
	}

};

