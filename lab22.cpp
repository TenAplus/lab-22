#include<iostream>
#include<cmath>
using namespace std;

class ComplexNumber{				
	public:
		double real;
		double imag;
		ComplexNumber(double,double);
		ComplexNumber operator+(const ComplexNumber &);
		ComplexNumber operator-(const ComplexNumber &);
		ComplexNumber operator*(const ComplexNumber &);
		ComplexNumber operator/(const ComplexNumber &);
		bool operator==(const ComplexNumber &);
		double abs();
		double angle();
};

ComplexNumber::ComplexNumber(double x = 0,double y = 0){
	real = x; imag = y;
}

ComplexNumber ComplexNumber::operator+(const ComplexNumber &c){
	return ComplexNumber(real+c.real,imag+c.imag);
}

ComplexNumber ComplexNumber::operator-(const ComplexNumber &c){
	return ComplexNumber(real-c.real,imag-c.imag);
}

ComplexNumber ComplexNumber::operator*(const ComplexNumber &c){
    double newReal = (real * c.real) - (imag * c.imag);
    double newImag = (real * c.imag) + (imag * c.real);
    return ComplexNumber(newReal, newImag);
}

ComplexNumber ComplexNumber::operator/(const ComplexNumber &c){
    double denominator = (c.real * c.real) + (c.imag * c.imag);
    double newReal = ((real * c.real) + (imag * c.imag)) / denominator;
    double newImag = ((imag * c.real) - (real * c.imag)) / denominator;
    return ComplexNumber(newReal, newImag);
}

bool ComplexNumber::operator==(const ComplexNumber &c){
    return (real == c.real && imag == c.imag);
}

double ComplexNumber::abs(){
    return sqrt(real * real + imag * imag);
}

double ComplexNumber::angle(){
    return atan2(imag, real) * 180 / M_PI;
}

ComplexNumber operator+(double d, const ComplexNumber &c){
    return ComplexNumber(d + c.real, c.imag);
}

ComplexNumber operator-(double d, const ComplexNumber &c){
    return ComplexNumber(d - c.real, -c.imag);
}

ComplexNumber operator*(double d, const ComplexNumber &c){
    return ComplexNumber(d * c.real, d * c.imag);
}

ComplexNumber operator/(double d, const ComplexNumber &c){
    double denominator = c.real * c.real + c.imag * c.imag;
    double newReal = (d * c.real) / denominator;
    double newImag = (-d * c.imag) / denominator;
    return ComplexNumber(newReal, newImag);
}

bool operator==(double d, const ComplexNumber &c){
    return (d == c.real && c.imag == 0);
}

ostream& operator<<(ostream &os, const ComplexNumber &c){
    if (c.real == 0 && c.imag == 0) {
        os << "0";
    } else if (c.real == 0) {
        os << c.imag << "i";
    } else if (c.imag == 0) {
        os << c.real;
    } else if (c.imag > 0) {
        os << c.real << "+" << c.imag << "i";
    } else {
        os << c.real << c.imag << "i";
    }
    return os;
}
