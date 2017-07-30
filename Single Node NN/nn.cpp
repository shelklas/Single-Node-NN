#include <iostream>
#include <algorithm>
#include <vector>
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
double calcDivWeight(double& x, double& y, double& weight,double & bias)
{
	return ((sigmoid(weight * x + bias) - y)*sigmoid(weight*x + bias)*(1 - sigmoid(weight * x + bias))) * x;
}
double calcDivBias(double& x, double& y, double& weight,double& bias)
{
	return ((sigmoid(weight * x + bias) - y)*sigmoid(weight*x + bias)*(1 - sigmoid(weight * x + bias)));
}
void printOut(double& weight, double& theta, double& error, double& divWeight,double & divBias)
{
	cout << std::fixed;
	cout << "Weight = " << setprecision(10) << weight << endl;
	cout << "Theta = " << setprecision(10) << theta << endl;
	cout << "Error = " << setprecision(10) << error << endl;
	cout << "Dirivative Weight = " << setprecision(10) << divWeight << endl;
	cout << "Dirivative Bias = " << setprecision(10) << divBias << endl;
}
int main()
{
	double x = 2;
	double y = 0.4;
	double weight = 1;
	double bias = 0;
	double stepSize = 0.0001;
	vector<pair<double, double>> points;

	points.push_back(make_pair(2, .67));
	points.push_back(make_pair(4, .15));

	double error;
	double divWeight;
	double divBias;
	double theta;
	int iterations = 0;
	
	theta = forwardFeed(x, weight, bias);
	error = calcError(theta, y);
	divWeight = calcDivWeight(x, y, weight, bias);
	divBias = calcDivBias(x, y, weight, bias);
	
	while ((divWeight >= 0.001 || divWeight <= -0.001) && (divBias >= 0.001 || divBias <= -0.001))
	{
		theta = forwardFeed(x, weight,bias);
		error = calcError(theta, y);
		divWeight = calcDivWeight(x, y, weight,bias);
		divBias = calcDivBias(x, y, weight, bias);

		if (divWeight > 0)
			weight -= stepSize;
		else if (divWeight < 0)
			weight += stepSize;

		if (divBias > 0)
			bias -= stepSize;
		else if (divBias < 0)
			bias += stepSize;

		cout << "Iteration " << iterations++ << endl;
		if (iterations % 100 == 0 || iterations ==1)
			printOut(weight,theta,error, divWeight,divBias);
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

}