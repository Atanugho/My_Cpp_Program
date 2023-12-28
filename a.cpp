
#include <iostream>
#include<limits>
using namespace std;

class Complex {
    int real; 
    int imag;

public:
    Complex(int r = 0, int i = 0) {
        real = r;
        imag = i;
    }

    Complex operator+( Complex &c)  {
        Complex result;
        result.real = real+c.real;
        result.imag = imag+c.imag;
        return result;
    }

    Complex operator*( Complex &c)  {
        Complex result;
        result.real = (real*c.real)-(imag*c.imag);
        result.imag = (real * c.imag) + (imag * c.real);
        return result;
    }

    friend istream &operator>>(istream &input, Complex &c) {
        input >> c.real>> c.imag;
        return input;
    }

    friend ostream &operator<<(ostream &output,  Complex &c) {
        output << c.real;
        if (c.imag >= 0) {
            output << "+" << c.imag << "i";
        } else {
            output << c.imag << "i";
        }
        return output;
    }
};

int main() {
    Complex c1, c2, c3, c4;
    cout << "Enter the first complex number: ";
    cin >> c1;

    //cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Enter the second complex number:";
    cin>>c2;
    c3 = c1+c2;
    c4 = c1*c2;
    cout<<"the sum of the two complex number :"<<c3<<endl;
    cout<<"product of the two complex number :"<<c4<<endl;
    return 0;
}    
