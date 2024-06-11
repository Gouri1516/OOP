#include<iostream>
using namespace std;
class Complex{
	private:
		int r,i;
		public:
			Complex(int real,int imaginary){
				r=real;
				i=imaginary;
			}
			Complex operator +(const Complex& other){
				return Complex(r+other.r,i+other.i);
			}
			Complex operator -(const Complex& other){
				return Complex(r-other.r,i-other.i);
			}
			void display(){
				cout<<r<<"+"<<i<<"i"<<endl;
			}
			
};
int main(){
	Complex c1(1,4);
	Complex c2(2,5);
	Complex c3=c1+c2;
	Complex c4=c1-c2;
	c1.display();
	c2.display();
	c3.display();
	c4.display();
}
