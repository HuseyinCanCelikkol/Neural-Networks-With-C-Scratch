#pragma once
#include <iostream>
#include <vector>
#include <random>
#include <ctime>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <numeric>
#include <cmath>


using namespace std;

class Perceptron {
public:
	
	Perceptron(int inputsize, double bias = 1.0);
	int setWeights(vector<double> weights);
	int setInputs(vector<double> inputs);
	void printWeights();
	void print();
	vector <double> inputs, weights;
	vector<vector<double>> samples;
	int inputsize;
	double coef = 3;
	double sigmoid2(double x);
	double run(vector<double> inputs);
	vector<int> classes;
	void setClasses(vector<int> classes);
	void run2(vector<vector<double>> inputs);
	double sigmoid(double net);
	double bias;
	double net(vector <double> inputs, vector <double> weights);
	double inner_product(double x, double y);
	

};

class MultilayerPerceptron {
public:
	double bias;
	double eta;
	MultilayerPerceptron(vector<int> layers, double bias = 1, double eta = 0);
	void setWeights(vector<vector<vector<double> > > mWeights);
	void printWeights();
	vector<double> run(vector<double> inputs);
	vector<vector<double>> errorrates;
	vector<vector<Perceptron>> network;
	vector<int> layers;
	vector<vector<double>> neuronoutputs;
};