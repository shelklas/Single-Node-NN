#include <iostream>
#include <functional>
#include <algorithm>
#include <string>
#include <fstream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

double sigmoid(double x)
{
	return (1 / (1 + pow(2.718, -x)));
}
double forwardFeed(double& x, double& weight,double& bias)
{
	return(sigmoid(x*weight + bias));
}
double calcError(double& theta, double& y)
{
	return (0.5*(pow((theta - y), 2)));
}
double calcDivWeight(double& x, double& y, double& x1, double& y1, vector<pair<double,double>>& points, double& weight,double & bias)
{
	return ((sigmoid(weight * x + bias) - y)*sigmoid(weight*x + bias)*(1 - sigmoid(weight * x + bias)) * x) - ((sigmoid(weight * x1 + bias) - y1)*sigmoid(weight*x1 + bias)*(1 - sigmoid(weight * x1 + bias)) * x1);
	//return ((sigmoid(weight * x + bias) - y)*sigmoid(weight*x + bias)*(1 - sigmoid(weight * x + bias))) * x;
	//double output = ((sigmoid(weight * points.begin()->first) + bias) - points.begin()->second)*sigmoid(weight*points.begin()->first + bias)*(1 - sigmoid(weight * points.begin()->first + bias)) * points.begin()->first;
	//for (vector<pair<double, double>>::iterator it = points.begin() + 1; it != points.end(); it++)
	//	output -= ((sigmoid(weight * it->first + bias) - it->second)*sigmoid(weight*it->first + bias)*(1 - sigmoid(weight * it->first + bias))) * it->first;
	//return output;
}
double calcDivBias(double& x, double& y,double& x1,double&y1, vector<pair<double, double>>& points, double& weight,double& bias)
{
	return ((sigmoid(weight * x + bias) - y)*sigmoid(weight*x + bias)*(1 - sigmoid(weight * x + bias))- (sigmoid(weight * x1 + bias) - y1)*sigmoid(weight*x1 + bias)*(1 - sigmoid(weight * x1 + bias)));
	//return ((sigmoid(weight * x + bias) - y)*sigmoid(weight*x + bias)*(1 - sigmoid(weight * x + bias)));
	//double output = ((sigmoid((weight * points.begin()->first) + bias) - points.begin()->second)*sigmoid(weight*points.begin()->first + bias)*(1 - sigmoid(weight * points.begin()->first + bias)));
	//for (vector<pair<double, double>>::iterator it = points.begin() + 1; it != points.end(); it++)
	//	output -= ((sigmoid(weight * it->first + bias) - it->second)*sigmoid(weight*it->first + bias)*(1 - sigmoid(weight * it->first + bias)));
	//return output;
}
void printOut(double& weight,double& bias, double& theta, double& error, double& divWeight,double & divBias,int& iteration)
{
	cout << std::fixed;
	cout << endl;
	cout << setw(20) << "-------------------ITERATION :" << iteration << " ----------------------" << endl;
	cout << endl;
	cout << "Weight = " << setprecision(10) << weight << endl;
	cout << "Bias = " << setprecision(10) << bias << endl;
	cout << "Theta = " << setprecision(10) << theta << endl;
	cout << "Error = " << setprecision(10) << error << endl;
	cout << "Dirivative Weight = " << setprecision(10) << divWeight << endl;
	cout << "Dirivative Bias = " << setprecision(10) << divBias << endl;
	cout << endl;
	cout << setw(20) << "---------------------------------------------------------" << endl;
	cout << endl;
}
int main()
{
	double x = 2;
	double y = 0.4;

	double x1 = 5;
	double y1 = .9;

	double weight = 1;
	double bias=0;
	double stepSize = 0.001;
	double precision = 0.001;
	vector<pair<double, double>> points;

	points.push_back(make_pair(2, .25));
	points.push_back(make_pair(5, .97));

	double e rror;
	double divWeight;
	double divBias;
	double theta;
	int iterations = 0;
	
	theta = forwardFeed(x, weight, bias);
	error = calcError(theta, y);
	divWeight = calcDivWeight(x, y, x1, y1, points, weight, bias);
	divBias = calcDivBias(x, y,x1,y1,points, weight, bias);
	
	while ((divWeight >= precision || divWeight <= -(precision)) && (divBias >= precision || divBias <= -(precision)))
	{
		theta = forwardFeed(x, weight,bias);
		error = calcError(theta, y);
		divWeight = calcDivWeight(x, y, x1, y1, points, weight, bias);
		divBias = calcDivBias(x, y,x1,y1, points, weight, bias);

		if (divWeight >= 0)
			weight += stepSize;
		else if (divWeight < 0)
			weight -= stepSize;

		if (divBias >= 0)
			bias += stepSize;
		else if (divBias < 0)
			bias -= stepSize;

		cout << "Iteration " << iterations++ << endl;
		if (iterations % 100 == 0 || iterations ==1)
			printOut(weight,bias,theta,error, divWeight,divBias,iterations);
	}
	cout << endl;
	cout << setw(20)<<"----------------------------------------------------" << endl;
	cout << endl;
	cout << std::fixed;
	cout << "Weight = " << setprecision(10)<< weight << endl;
	cout << "Bias = " << setprecision(10) << bias << endl;
	cout << "Theta = " << setprecision(10) << theta << endl;
	cout << "Error = " << setprecision(10) << error << endl;
	cout << "Dirivative Weight = " << setprecision(10) << divWeight << endl;
	cout << "Dirivative Bias = " << setprecision(10) << divBias << endl;
	cout << endl;
	double output = (sigmoid((weight * x) + bias));
	cout << "X = " << output << endl;

}