#include <conio.h>
#include <iostream>
#include <math.h>

using namespace std;

class Complex
{
private:
  double Real, Imag;
public:
    Complex ():Real (0), Imag (0)
  {
  };

  Complex (double co)
  {
    Real = co;
    Imag = 0;
  };

  Complex (double Real, double Imag) // ten konstruktor zastepuje 2 powyzsze,czyli rzutuje,inicjuje domniemanie
  {
    this->Real = Real;// jakby byla inna nazwa w przekazaniu parametrow to nie musialo by byc this chybaaa
    this->Imag = Imag;
  };

  Complex & operator= (const Complex & s)// referencja - bo zwracamy wskaznik do this do utworzonego obiektu
  {
    Real = s.Real;
    Imag = s.Imag;
    return *this;
  };
  
   Complex & operator= (double co)
  {
    Real = co;
    Imag = 0;
    return *this;
  };

  Complex operator- () const
  {
    return Complex(-Real,-Imag);
  };

  /*Complex operator+ (const Complex& co) const //
  {
    Complex n;
    n.Real = this->Real + co.Real;
    n.Imag = this->Imag + co.Imag;
    return n;
  };*/
  
  Complex operator*=(Complex s1)
  {
    double temp=Real;
           Real = (Real*s1.Real - Imag*s1.Imag);   
           Imag = (temp*s1.Imag + Imag*s1.Real);//podstawiamy stare s1.real
    return *this; 
  } 

  Complex operator/=(Complex s1)
  {
    double temp=Real; //real jest czesc rzecz istniejacego obiektu,dajemy do go tempa poniewaz w ponizszej linii juz ulega zmianie jego wartosc a w drugiej linii potrzebujemy uzyc wartosci oryginalnej
           Real = ((Real*s1.Real + Imag*s1.Imag))/((s1.Real)*(s1.Real))+((s1.Imag)*(s1.Imag));   
           Imag = (Imag*s1.Real - temp*s1.Imag)/((s1.Real)*(s1.Real))+((s1.Imag)*(s1.Imag)); 
    return *this;            
  }

  Complex & operator+= (Complex co)
  {
    Real += co.Real;
    Imag += co.Imag;
    return *this;
  };
  
  Complex & operator-= (Complex co)
  {
    Real -= co.Real;
    Imag -= co.Imag;
    return *this;
  };

  friend double abs (Complex co);
  friend Complex conj (Complex co);
  friend double phase (Complex co);
  friend Complex operator/ (Complex s1,Complex s2);
  friend Complex operator* (Complex s1,Complex s2);
  friend Complex operator+ (Complex s1,Complex s2);
  friend Complex operator- (Complex s1,Complex s2);
  
  friend ostream & operator << (ostream & s, const Complex & c)
  {
    s << "(" << c.Real << "," << c.Imag << "i" << ")";
    return s;
  };
};

  //poza klasa!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

  double abs (Complex co)
  {
    double n;
    n = sqrt(pow(co.Real,2)+pow(co.Imag,2));
    return n;
  }
  
  Complex conj (Complex co)
  {
   co.Imag = -co.Imag;
   return co;
  }
  
  double phase (Complex co)
  {
   double arg;
   if(co.Real>=0) arg = atan2(co.Imag,co.Real);
    else
        if(co.Real<0 and co.Imag>=0)
                     arg=atan2(co.Imag,co.Real)+M_PI;
        else 
             if(co.Real<0 and co.Imag<0)
                          arg=atan2(co.Imag,co.Real)-M_PI;
   return arg;
  }
  
  Complex operator/(Complex s1, Complex s2)
  {
    Complex quotient;
    quotient.Real = ((s1.Real*s2.Real + s1.Imag*s2.Imag))/((s2.Real)*(s2.Real))+((s2.Imag)*(s2.Imag));   
    quotient.Imag = (s1.Real*s2.Imag - s1.Imag*s2.Real)/((s2.Real)*(s2.Real))+((s2.Imag)*(s2.Imag)); 
    return quotient;
  } 
        
  Complex operator* (Complex s1,Complex s2) 
  {
    Complex product;
    product.Real = (s1.Real*s2.Real) + (-(s1.Imag*s2.Imag));
    product.Imag = (s1.Real*s2.Imag) + (s1.Imag*s2.Real);
    return product;
  }
  
   Complex operator+ (Complex s1,Complex s2)
  {
    Complex sum;
    sum.Real = s1.Real + s2.Real;
    sum.Imag = s1.Imag + s2.Imag;
    return sum;
  };
  
  Complex operator- (Complex s1,Complex s2)
  {
    Complex result;
    result.Real = s1.Real - s2.Real;
    result.Imag = s1.Imag - s2.Imag;
    return result;
  };
  
 /* inline Complex operator - (Complex s1, Complex s2) //po co jest inline?
{
  Complex n (s1);
  return n -= s2;
};*/




int main()
{
  Complex a(0.0,15),b(0,13),c,d,e(3,4);
  Complex sprzez;
  sprzez = conj(e);
  cout << sprzez <<endl;
  double wynik;
  wynik = abs(a);
  cout << wynik <<endl;
  d = a*b;
  cout << d <<endl;
  c = 10;
  cout << c <<endl;
  c = -a;
  cout << c <<endl;  
  c = a+b;
  cout << c <<endl;
  //c = c - Complex(10);
  //cout << c <<endl;  
  c = 10 - a;
  //(c +=b) +=10;
  cout << c <<endl;
  
  getchar();
}
