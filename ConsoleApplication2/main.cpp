#include <iostream>
#include "ANN.h"

int main()
{
    Perceptron x(2);
    x.coef = 1;
    x.setWeights({ 26,44,13});

    x.setClasses({ 1,1,1,0 });

    x.run2({ { 1,1 }, { 0,1 }, { 1,0 }, { 0,0 } });

    cout << x.run({ 1,1 }) << endl;
    cout << x.run({ 0,1 }) << endl;
    cout << x.run({ 1,0 }) << endl;
    cout << x.run({ 0,0 }) << endl;
    
    cout << "\n\n--------Hardcoded XOR Example----------------\n\n";
    MultilayerPerceptron mlp = MultilayerPerceptron({ 2,3,1 });  //mlp
    mlp.setWeights({ {{-10,-10,15},{15,15,-10},{15,15,-10}}, {{10,10,-15}} });
    cout << "Hard-coded weights:\n";
    mlp.printWeights();

    cout << "XOR:" << endl;
    cout << "0 0 = " << mlp.run({ 0,0 })[0] << endl;
    cout << "0 1 = " << mlp.run({ 0,1 })[0] << endl;
    cout << "1 0 = " << mlp.run({ 1,0 })[0] << endl;
    cout << "1 1 = " << mlp.run({ 1,1 })[0] << endl;

}

//{10,10,-15} #AND
  //{15,15,-10}  #OR
  //{-15,-15,10}  #NOR
  //{-10,-10,15} #NAND