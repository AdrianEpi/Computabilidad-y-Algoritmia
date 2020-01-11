#include "rational.hpp"

rational::rational()
{
//	assert(d != 0);
	num_ = 0, den_ = 1;
}

rational::rational(int num, int den)
{
	assert(den != 0);
	num_ = num, den_ = den;
}

double rational::value() const
{
	return double(get_num()) / get_den();
}

rational rational::add(const rational& r)
{
	int numerador = (num_ * r.get_den()) +  (den_ * r.get_num());
	int denominador = den_ * r.get_den();
	rational sentinel(numerador, denominador);
	return sentinel;
}

rational rational::substract(const rational& r)
{
	int numerador = (num_ * r.get_den()) - (den_ * r.get_num());
	int denominador = den_ * r.get_den();
	rational sentinel(numerador, denominador);
	return sentinel;
}

rational rational::multiply(const rational& r)
{
	int numerador = (num_ * r.get_num());
	int denominador = den_ * r.get_den();
	rational sentinel(numerador, denominador);
	return sentinel;
}

rational rational::divide(const rational& r)
{
	int numerador = num_ * r.get_den();
	int denominador = den_ * r.get_num();
	rational sentinel(numerador, denominador);
	return sentinel;
}

void rational::write(ostream& os) const
{
	os << get_num() << "/" << get_den() << " = " << value() << endl;
}

void rational::read(istream& is)
{
	cout << "Numerador: ";
	is >> num_;
	cout << "Denominador: ";
	is >> den_;
	assert(den_ !=0);
}

bool rational::equal(const rational& r, const double precision) const
{

	if((get_num() * r.get_den()) == get_den() * r.get_num())
		return true;
	else
		return false;
	/*
	if (fabs(double (value() - r.value())) < precision)
		return true;
	else
		return false;
	*/
}

bool rational::greater(const rational& r, const double precision) const
{
	if((get_num() * r.get_den()) > get_den() * r.get_num())
		return true;
	else
		return false;
	/*
	if((value() - r.value()) > precision)
		return true;
	else 
		return false;
	*/
}

bool rational::less(const rational& r, const double precision) const
{
	if((get_num() * r.get_den()) < get_den() * r.get_num())
		return true;
	else
		return false;
	/*
	if ((value() - r.value()) < precision)
		return true;
	else
		return false;
	*/		
}

void rational::mcm(const rational& r)
{
	int aux, aux2, exit, a, b;
	if (get_den() < r.get_den()){
		a = get_den();
		b = r.get_den();
	}
	else{
		b = get_den();
		a = r.get_den();
	}
	aux = a;
	aux2 = b;
	while(exit != 1){
		if (a != b)	{
			if (a < b)
				a += aux;
			else 
				b += aux2;
		}
		else
			exit = 1;
	}
    set_num((b/get_den() * get_num()));
    set_den(b);
}

void rational::mcd(void)
{
	int aux, aux2, exit, a, b;
	if (get_den() < get_num()){
		a = get_den();
		b = get_num();
	}
	else if(get_den() == get_num()){
		set_num(1);
		set_den(1);
	}
	else{
		b = get_den();// aux=a;
		a = get_num(); //aux2=b;
	}
	while(exit != 1){
		if (a == 0)
			exit = 1;
		else if (b%a != 0)
			a--;
		else{
			set_num((get_num()/a));
			set_den((get_den()/a));
			exit=1;
		}
	}
}
