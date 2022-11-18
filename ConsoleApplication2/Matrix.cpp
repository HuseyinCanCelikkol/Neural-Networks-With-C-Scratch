#include "Matrix.h"

template<class T> void Matrix<T>::createMatrix() {
	this->matrix = new T * [this->row];			//
	for (i = 0; i < this->row; i++) {			//matrisin tanýmý
		this->matrix[i] = new T[this->column];	//
	}
}

template<class T> Matrix<T>::Matrix() {			//10x10 0 dolu matris
	this->row = 10;
	this->column = 10;
	this->createMatrix();

	for (i = 0; i < this->row; i++) {
		for (j = 0; j < this->column; j++) {
			this->matrix[i][j] = 0;
		}
	}
}

template<class T> Matrix<T>::Matrix(int rows, int columns, int value) {			// row x column integer "value" dolu matris

	this->row = rows;
	this->column = columns;
	this->createMatrix();

	for (i = 0; i < this->row; i++) {
		for (j = 0; j < this->column; j++) {
			this->matrix[i][j] = value;
		}
	}
}

template<class T> Matrix<T>::Matrix(int rows, int columns, double value) {		// row x column double "value" dolu matris constructoru

	this->row = rows; this->column = columns;
	this->createMatrix();

	for (i = 0; i < this->row; i++) {
		for (j = 0; j < this->column; j++) {
			this->matrix[i][j] = value;
		}
	}
}

template<class T> Matrix<T>::Matrix(int rows, int columns, char mytype) {			// birim veya random degerli matris constructoru
	this->row = rows; this->column = columns;
	if (mytype == 'e') {
		if (this->row == this->column) {
			this->createMatrix();
			for (i = 0; i < this->row; i++) {
				for (j = 0; j < this->column; j++) {
					this->matrix[i][j] = 0;
				}
			}

			for (i = 0; i < this->row; i++) {
				this->matrix[i][i] = 1;
			}
		}
		else {
			cout << "There's no Equal Row and Columns" << endl; //row == column degilse hata mesaji (birim matriste row = column olmalý)
			cout << "Process Cancelled";
		}
	}

	if (mytype == 'r') {

		this->createMatrix();
		srand(time(NULL));
		for (i = 0; i < this->row; i++) {
			for (j = 0; j < this->column; j++) {
				this->matrix[i][j] = rand() % 256;
			}
		}
	}
}

template<class T> void Matrix<T>::print() {				//ekrana yazdir
	for (i = 0; i < this->row; i++) {
		for (j = 0; j < this->column; j++) {
			cout << this->matrix[i][j] << "\t";
			if (j == this->column - 1) cout << endl << endl;
		}
	}
}

template<class T> void Matrix<T>::print(string file) {			//dosyaya yazdir
	ofstream myfile;
	myfile.open(file.c_str());
	for (i = 0; i < this->row; i++) {
		for (j = 0; j < this->column; j++) {
			myfile << this->matrix[i][j] << "\t";
			if (j == this->column - 1) myfile << endl << endl;
		}
	}
	myfile.close();
}

template<class T> Matrix<T> Matrix<T>::resize(int rows, int columns) {			//matrisi resize et

	Matrix<T>* temp2 = new Matrix(rows, columns, 0);
	if (this->row <= rows && this->column <= columns) {							//matrisi her yonden buyutuyor isek:
		for (i = 0; i < this->row; i++) {
			for (j = 0; j < this->column; j++) {
				temp2->matrix[i][j] = this->matrix[i][j];
			}
			for (int k = this->row; k < rows; k++)
			{
				for (int l = this->column; l < columns; l++) {
					temp2->matrix[k][l] = 0;
				}
			}
		}
	}

	if (this->row <= temp2->row && this->column >= temp2->column) {			// Matrisin rowunu buyutup veya sabit birakip column unu kucultuyor isek
		for (i = 0; i < this->row; i++) {
			for (j = 0; j < temp2->column; j++) {
				temp2->matrix[i][j] = this->matrix[i][j];
			}
			for (int k = this->row; k < rows; k++)
			{
				int l = columns;
				temp2->matrix[k][l] = 0;//boþ kalan yerlere 0 yazar 

			}
		}
	}

	if (this->row >= temp2->row && this->column <= temp2->column) {			// Matrisin columnunu buyutup veya sabit birakip row unu kucultuyor isek
		for (i = 0; i < temp2->row; i++) {
			for (j = 0; j < this->column; j++) {
				temp2->matrix[i][j] = this->matrix[i][j];
			}
			for (int k = this->row; k < rows; k++)
			{
				for (int l = this->column; l < columns; l++) {
					temp2->matrix[k][l] = 0;
				}
				for (int k = this->column; k < columns; k++)
				{
					int l = rows;
					temp2->matrix[k][l] = 0;

				}
			}
		}
	}
	if (this->row >= temp2->row && this->column >= temp2->column) {			// Matrisi kucultuyor isek
		for (i = 0; i < temp2->row; i++) {
			for (j = 0; j < temp2->column; j++) {
				temp2->matrix[i][j] = this->matrix[i][j];
			}
		}
		for (int k = rows; k < this->row; k++)
		{
			for (int l = 0; l < this->column; l++) {
				this->matrix[k][l] = 0;
			}
		}
	}
	this->matrix = temp2->matrix;
	this->row = rows; this->column = columns;

	return *this;
}

template<class T> Matrix<T> Matrix<T>::operator+(Matrix<T> obj) {
	if (this->row == obj.row && this->column == obj.column) {
		Matrix<T> temp;
		for (i = 0; i < this->row; i++) {
			for (j = 0; j < this->column; j++) {
				temp.matrix[i][j] = this->matrix[i][j] + obj.matrix[i][j];
			}
		}
		temp.resize(this->row, this->column);
		return temp;
	}
	else {
		cout << "There's no equal rows or columns!" << endl;
		cout << "Process cancelled." << endl;
	}
}


template<class T> Matrix<T> Matrix<T>::operator=(Matrix<T> obj) {
	if (this->row == obj.row && this->column == obj.column) {
		Matrix<T> temp;
		for (i = 0; i < this->row; i++) {
			for (j = 0; j < this->column; j++) {
				this->matrix[i][j] = obj.matrix[i][j];
			}
		}
		temp.resize(this->row, this->column);
		return temp;
	}
	else {
		cout << "There's no equal rows or columns!" << endl;
		cout << "Process cancelled." << endl;
	}
}
template<class T> Matrix<T> Matrix<T>::operator-(Matrix<T> obj) {
	if (this->row == obj.row && this->column == obj.column) {
		Matrix<T> temp;
		for (i = 0; i < this->row; i++) {
			for (j = 0; j < this->column; j++) {
				temp.matrix[i][j] = this->matrix[i][j] - obj.matrix[i][j];
			}
		}
		temp.resize(this->row, this->column);
		return temp;
	}
	else {
		cout << "There's no equal rows or columns!" << endl;
		cout << "Process cancelled." << endl;
	}
}

template<class T> Matrix<T> Matrix<T>::operator*(Matrix<T> obj) {
	if (this->column == obj.row) {
		Matrix<T> temp;
		for (i = 0; i < this->row; i++) {
			for (j = 0; j < this->column; j++) {
				temp.matrix[i][j] = this->matrix[i][j] * obj.matrix[j][i];
			}
		}
		temp.resize(this->row, this->column);
		return temp;
	}
	else {
		cout << "There's no equal rows or columns!" << endl;
		cout << "Process cancelled." << endl;
	}
}

template<class T> Matrix<T> Matrix<T>::operator+(int value) {


	Matrix<T> temp;
	for (i = 0; i < this->row; i++) {
		for (j = 0; j < this->column; j++) {
			temp.matrix[i][j] = this->matrix[i][j] + value;
		}
	}
	temp.resize(this->row, this->column);
	return temp;

}

template<class T> Matrix<T> Matrix<T>::operator-(int value) {


	Matrix<T> temp;
	for (i = 0; i < this->row; i++) {
		for (j = 0; j < this->column; j++) {
			temp.matrix[i][j] = this->matrix[i][j] - value;
		}
	}
	temp.resize(this->row, this->column);
	return temp;

}

template<class T> Matrix<T> Matrix<T>::operator*(int value) {


	Matrix<T> temp;
	for (i = 0; i < this->row; i++) {
		for (j = 0; j < this->column; j++) {
			temp.matrix[i][j] = this->matrix[i][j] * value;
		}
	}
	temp.resize(this->row, this->column);
	return temp;

}

template<class T> Matrix<T> Matrix<T>::operator/(int value) {


	Matrix<T> temp;
	for (i = 0; i < this->row; i++) {
		for (j = 0; j < this->column; j++) {
			temp.matrix[i][j] = this->matrix[i][j] / value;
		}
	}
	temp.resize(this->row, this->column);
	return temp;

}

template<class T> Matrix<T> Matrix<T>::operator%(int value) {


	Matrix<T> temp;
	for (i = 0; i < this->row; i++) {
		for (j = 0; j < this->column; j++) {
			temp.matrix[i][j] = this->matrix[i][j] % value;
		}
	}
	temp.resize(this->row, this->column);
	return temp;

}

template<class T> Matrix<T> Matrix<T>::operator^(int value) {


	Matrix<T> temp;
	for (i = 0; i < this->row; i++) {
		for (j = 0; j < this->column; j++) {
			temp.matrix[i][j] = pow(this->matrix[i][j], value);
		}
	}
	temp.resize(this->row, this->column);
	return temp;

}

template<class T> Matrix<T> Matrix<T>::Transpose() {
	Matrix<T> temp;
	for (i = 0; i < this->row; i++) {
		for (j = 0; j < this->column; j++) {
			temp.matrix[j][i] = this->matrix[i][j];
		}
	}
	temp.resize(this->row, this->column);
	return temp;
}

template<class T> Matrix<T> Matrix<T>::emul(Matrix<T>* obj) {
	if (this->row == obj->row && this->column == obj->column) {
		Matrix<T> temp;
		for (i = 0; i < this->row; i++) {
			for (j = 0; j < this->column; j++) {
				temp.matrix[i][j] = this->matrix[i][j] * obj->matrix[i][j];
			}
		}
		temp.resize(this->row, this->column);
		return temp;
	}
	else {
		cout << "There's no equal rows or columns!" << endl;
		cout << "Process cancelled." << endl;
	}
}