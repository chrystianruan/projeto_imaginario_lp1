#include "complexo.h"

Complexo::~Complexo(){
	//Se usou alocação dinâmica, desalocar aqui.
}

//Não mudar
Complexo::Complexo(){
	a = 0.;
	b = 0.;
}

//Não mudar
void Complexo::imprimir(){
	//Imprime na tela "a+bi" (sem aspas) e sem espaços.
	cout << a<<"+"<<b<<"i";
}

//Para Fazer
Complexo::Complexo(Complexo const &i_){
	a = i_.a;
	b = i_.b;
}

//Para Fazer
Complexo::Complexo(float a_, float b_){
	a = a_;
	b = b_;
}

//Para Fazer
//Método de Potência de um número imaginário elevado a um número inteiro "i_"
Complexo Complexo::pow(int i_){
	// string i;

	// if (i_ % 4 == 0) {
	// 	i = "1";
	// } else if (i_ % 4 == 1) {
	// 	i = "i";
	// } else if (i_ % 4 == 2) {
	// 	i = "-1";
	// } else {
	// 	i = "-i";
	// }

	// int b2 = 2;

	// int result;

	// if (i == "i" || i == "-i") {
	// 	if (i == "-i") {
	// 		result = -1;
	// 	} else {
	// 		result = 1;
	// 	}
	// } else {
	// 	result = stoi(i) * b2;
	// }

	


	return Complexo();
}

//Para Fazer
Complexo Complexo::operator+(Complexo &i_){
	float resultA = getA() + i_.getA();
	float resultB = getB() + i_.getB();

	return Complexo(resultA, resultB);
}

//Para Fazer
Complexo Complexo::operator-(Complexo &i_){
	float resultA = getA() - i_.getA();
	float resultB = getB() - i_.getB();
	
	return Complexo(resultA, resultB);
}

//Para Fazer
Complexo Complexo::operator*(Complexo &i_){
	float resultA = getAMultiplicacao(*this, i_);
	float resultB = getBMultiplicacao(*this, i_);

	return Complexo(resultA, resultB);
}

//Para Fazer
Complexo Complexo::operator/(Complexo &i_){
	Complexo conjugado = getConjugado(i_);
	float parteSuperiorA = getAMultiplicacao(*this, conjugado);
	float parteSuperiorB = getBMultiplicacao(*this, conjugado);
	float parteInferiorA = getAMultiplicacao(i_, conjugado);
	
	return Complexo(parteSuperiorA/parteInferiorA, parteSuperiorB/parteInferiorA);
}

//Para Fazer
Complexo& Complexo::operator=(Complexo const &i_){
	return *this;
}

//Para Fazer
bool Complexo::operator==(Complexo const &i_){
	if (getA() != i_.a && getB() != i_.b) {
		return false;
	}

	return true;
}

//Para Fazer
bool Complexo::operator!=(Complexo const &i_){
	if (getA() != i_.a && getB() != i_.b) {
		return true;
	}

	return false;
}

float Complexo::getA() {
	return a;
}

float Complexo::getB() {
	return b;
}

void Complexo::setA(float a_) {
	a = a_;
}

void Complexo::setB(float b_) {
	b = b_;
} 

float Complexo::getAMultiplicacao(Complexo &i1, Complexo &i2) {
	float result = i1.getA() * i2.getA() - i1.getB() * i2.getB();

	return result;
}

float Complexo::getBMultiplicacao(Complexo &i1, Complexo &i2) {
	float result = i1.getA() * i2.getB() + i1.getB() * i2.getA();

	return result;
}

Complexo Complexo::getConjugado(Complexo &i_) {
	if (i_.getB() < 0 ) {
		return Complexo(i_.getA(), i_.getB());
	}

	return Complexo(i_.getA(), -i_.getB());
}

