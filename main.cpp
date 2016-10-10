#include <cmath>
#include <iostream>
#include <complex>
#include <boost/multiprecision/cpp_dec_float.hpp>
#include <Eigen/Sparse>
#include <Eigen/Dense>

#include "mino2357complex.hpp"

namespace mp = boost::multiprecision;
using f1000 = mp::number<mp::cpp_dec_float<50>>;

int main(){
	mino2357::complex<f1000> a(f1000("1.0"), f1000("2.0"));
	mino2357::complex<f1000> b(f1000("3.0"), f1000("4.0"));
	mino2357::complex<f1000> c(f1000("5.0"), f1000("6.0"));
	mino2357::complex<f1000> d(f1000("7.0"), f1000("8.0"));
	mino2357::complex<f1000> e(f1000("7.0"), f1000("8.0"));

	a.print();
	b.print();

	(a + b).print();
	(a - b).print();
	(a * b).print();
	(a / b).print();
	
	(a * b).print();
	(c * d).print();
	(a * b + c * d).print();
}





