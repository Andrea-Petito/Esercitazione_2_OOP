#include <iostream>

template<typename T>
class complex_number {
	T real;
	T imag;

public:
    complex_number() : real(0), imag(0) {};
	complex_number(T r, T i) : real(r), imag(i) {};
	
	T getReal() const {
		return real;
	}
	
	T getImag() const {
		return imag;
	}
	
	complex_number<T> conjugate() const {
		return complex_number<T>(real, -imag);
	}
	
	complex_number<T> operator+(const complex_number<T>& other) const {
		return complex_number<T>(real + other.real, imag + other.imag);
	}
	
	complex_number<T>& operator+=(const complex_number<T>& other) {
		real += other.real;
		imag += other.imag;
		return *this;
	}
	
	complex_number<T> operator*(const complex_number<T>& other) const{
		T newReal = real * other.real - imag * other.imag;
		T newImag = real * other.imag + imag * other.real;
		return complex_number<T>(newReal, newImag);
	}
	
	complex_number<T>& operator*=(const complex_number<T>& other) {
		T newReal = real * other.real - imag * other.imag;
		T newImag = real * other.imag + imag * other.real;
		real = newReal;
		imag = newImag;
		return *this;
	}
	std::ostream& print(std::ostream& os) const {
        os << real;
        if (imag >= 0) {
            os << "+" << imag << "i";
        } else {
            os << imag << "i";
        }
        return os;
    }
};

template<typename T>
std::ostream& operator<<(std::ostream& os, const complex_number<T>& c) {
    return c.print(os);
}

int main() {
	complex_number<float> z1(3.5f, 2.0f);
	complex_number<float> z2(1.5f, -4.5f);
	
	std::cout << "Numero complesso 1: " << z1 << std::endl;
	std::cout << "Numero complesso 2: " << z2 << std::endl;
	
	complex_number<float> conj = z1.conjugate();
	std::cout << "Il coniugato di z1 e': " << conj << std::endl;
	
	complex_number<float> sum = z1 + z2;
	std::cout << "La somma di z1 e z2 e': " << sum << std::endl;
	
	z1 += z2;
	std::cout << "z1 dopo z1 += z2: " << z1 << std::endl;
	
	complex_number<float> product = z1 * z2;
	std::cout << "Il prodotto di z1 e z2 e': " << product << std::endl;
	
	z1 *= z2;
    std::cout << "z1 dopo z1 *= z2 e': " << z1 << std::endl;

	return 0;
}