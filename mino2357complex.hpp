#include <iostream>
#include <cmath>
#include <limits>
#include <iomanip>

namespace mino2357{

	template <typename T=double>
	class complex{
	private:
		T re;
		T im;
	public:
		complex(T x, T y) noexcept : re(x) , im(y) {}
		complex() noexcept : complex{T {}, T{}} {}
		//inline complex(T, T) noexcept;
		inline T getRealPart() const noexcept;
		inline T getImaginaryPart() const noexcept;

		inline void print() noexcept;
	
		inline complex<T>& operator=(const complex<T>&) noexcept;
		inline T norm() noexcept;
	};
/*
	template <typename T>
	inline complex<T>::complex(T a, T b) noexcept{
		re = a;
		im = b;
	}
*/
	template <typename T>
	inline void complex<T>::print() noexcept{
		std::cout << std::fixed << std::setprecision(std::numeric_limits<T>::digits10 + 1);
		std::cout << re << " " << im << std::endl;
	}

	template <typename T>
	inline T complex<T>::getRealPart() const noexcept{
		return this->re;
	}
	
	template <typename T>
	inline T complex<T>::getImaginaryPart() const noexcept{
		return this->im;
	}

	template <typename T>
	inline T complex<T>::norm() noexcept{
		return sqrt(re*re + im*im);
	}
	
	template <typename T>
	inline complex<T>& complex<T>::operator=(const complex<T>& x) noexcept{
		this->re = x.getRealPart();
		this->im = x.getImaginaryPart();
		return *this;
	}

	template <typename T>
	inline complex<T> operator+(const complex<T>& x, const complex<T>& y) noexcept{
		return complex<T>{x.getRealPart() + y.getRealPart(), x.getImaginaryPart() + y.getImaginaryPart()};
	}
	
	template <typename T>
	inline complex<T> operator-(const complex<T>& x, const complex<T>& y) noexcept{
		return complex<T>{x.getRealPart() - y.getRealPart(), x.getImaginaryPart() - y.getImaginaryPart()};
	}
	
	template <typename T>
	inline complex<T> operator*(const complex<T>& x, const complex<T>& y) noexcept{
		return complex<T>{x.getRealPart()*y.getRealPart() - x.getImaginaryPart()*y.getImaginaryPart(), x.getRealPart()*y.getImaginaryPart() + x.getImaginaryPart()*y.getRealPart()};
	}

	template <typename T>
	inline complex<T> operator/(const complex<T>& x, const complex<T>& y) noexcept{
		return complex<T>{(x.getRealPart()*y.getRealPart() + x.getImaginaryPart()*y.getImaginaryPart())/(y.getRealPart()*y.getRealPart() + y.getImaginaryPart()*y.getImaginaryPart()), (-x.getRealPart()*y.getImaginaryPart() + x.getImaginaryPart()*y.getRealPart())/(y.getRealPart()*y.getRealPart() + y.getImaginaryPart()*y.getImaginaryPart())};
	}

}
