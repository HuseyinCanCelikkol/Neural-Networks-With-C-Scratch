#include "ANN.h"
mt19937 mt(time(NULL));
Perceptron::Perceptron(int inputsize, double bias) {

	this->weights.resize(inputsize + 1);
	this->bias = bias;
	for (int i = 0; i < this->weights.size(); i++) {
		this->weights[i] = (2.0 * (double)mt() / RAND_MAX) - 1.0;
	}
}

void Perceptron::print() {
	for (int i = 0; i < this->inputs.size(); i++) {
		cout << i << ". input value =" << this->inputs[i] << endl;
		cout << i << ". weight value =" << this->weights[i] << endl << endl;
	}
}

int Perceptron::setInputs(vector<double> inputs) {
	this->inputs = inputs;
	return 1;
}

void Perceptron::setClasses(vector<int> classes) {
	this->classes = classes;
}
int Perceptron::setWeights(vector<double> weights) {	
		this->weights = weights;
		return 1;	
}
double Perceptron::sigmoid(double x) {
	return 1.0 / (1.0 + exp(-x));
}

double Perceptron::sigmoid2(double x) {
	if (x > 0) { return 1; }
	else { return 0; }
}

double Perceptron::run(vector<double> inputs) {
	inputs.push_back(bias);
	double nett = (double)net(inputs, this->weights);
	
	return sigmoid(nett);
	
}

void Perceptron::run2(vector<vector<double>> inputs) {
	for (int i = 0; i < inputs.size(); i++) {
		inputs[i].push_back(bias);
	}


	bool isntSolved = true;

	while (isntSolved) {
		isntSolved = false;
		printWeights();
		
		double epsylon = 0.02;
		for (int i = 0; i < inputs.size(); i++) {
			double output = (double)sigmoid2(net(inputs[i],this->weights));
			if (classes[i] - output != 0) {
				isntSolved = true;
				
				float value = this->coef * (classes[i] - output);
				for (int j = 0; j < weights.size(); j++) {
				
						weights[j] += value*inputs[i][j];

				}
				
			}
		}
	}
	cout << endl << endl;
	cout << "last weights: ";
	for (int i = 0; i < weights.size(); i++) {
		cout << weights[i] << "\t";
	}
	cout << endl << endl;
	cout << "input control: " << endl;
	
}
void Perceptron::printWeights() {
	cout << "Weights :" << "\t";
	for (int i = 0; i < this->weights.size(); i++) {
		cout << weights[i] << "\t";
 	}
	cout << endl;
}
double Perceptron::inner_product(double x, double y) {
	return x * y;
}
double Perceptron::net(vector<double> inputs, vector<double> weights) {

double net = 0;
	for (int i = 0; i < inputs.size(); i++) {
		net += (double)inner_product(inputs[i], weights[i]);
	}
	return (double)net;
}

MultilayerPerceptron::MultilayerPerceptron(vector<int> layers, double bias, double eta) {
	this->layers = layers;
	this->bias = bias;
	this->eta = eta;

	for (int i = 0; i < this->layers.size(); i++) {
		this->neuronoutputs.push_back(vector<double>(layers[i], 0.0));
		this->errorrates.push_back(vector<double>(layers[i], 0.0));
		this->network.push_back(vector<Perceptron>());
		if (i > 0) {
			for (int j = 0; j < layers[i]; j++) {
				this->network[i].push_back(Perceptron(layers[i - 1], bias));
			}
		}
	}
}

void MultilayerPerceptron::setWeights(vector<vector<vector<double>>> mWeights) {
	for (int i = 0; i < mWeights.size(); i++) {
		for (int j = 0; j < mWeights[i].size(); j++) {
			network[i+1][j].setWeights(mWeights[i][j]);
		}
	}
}

vector<double> MultilayerPerceptron::run(vector<double> inputs) {
	neuronoutputs[0] = inputs; // neuronoutputs 0 is input layer. so all the inputs are on 0th index
	for (int i = 1; i < network.size(); i++) {
		for (int j = 0; j < network[i].size(); j++) {
			neuronoutputs[i][j] = network[i][j].run(neuronoutputs[i - 1]);
		}
	}
	return neuronoutputs.back();
}

void MultilayerPerceptron::printWeights() {
	cout << endl;
	for (int i = 1; i < network.size(); i++) {
		for (int j = 0; j < layers[i]; j++) {
			cout << "Layer " << i + 1 << " Neuron " << j << ": ";
			for (auto& it : network[i][j].weights)
				cout << it << "   ";
			cout << endl;
		}
	}
	cout << endl;
}