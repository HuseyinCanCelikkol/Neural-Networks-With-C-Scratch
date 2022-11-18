#pragma once
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <math.h>
#include <fstream>
#include <sstream>
#include <cstdio> 
#include <stdint.h>

int i, j;


using namespace std;

template<class T>

class Matrix {

public:
	Matrix();
	Matrix(int rows, int columns, int value);
	Matrix(int rows, int columns, double value);
	Matrix(int rows, int columns, char mytype);
	void print();
	void print(string file);
	Matrix<T> resize(int rows, int columns);
	Matrix<T> operator+(Matrix<T> obj);
	Matrix<T> operator=(Matrix<T> obj);
	Matrix<T> operator-(Matrix<T> obj);
	Matrix<T> operator*(Matrix<T> obj);
	Matrix<T> operator+(int value);
	Matrix<T> operator-(int value);
	Matrix<T> operator*(int value);
	Matrix<T> operator/(int value);
	Matrix<T> operator%(int value);
	Matrix<T> operator^(int value);
	Matrix<T> Transpose();
	Matrix<T> emul(Matrix<T>* obj);
	
protected:
	unsigned int row;
	unsigned int column;
	T** matrix;
	void createMatrix();//Matrisi olustur

};