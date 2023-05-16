#pragma once

#include"Drawer.h"


const double pi = 4 * atan(1);


struct SinParam
{
	double A = 0;
	double f = 0;
	double y = 0;
	SinParam() {}
	SinParam(double A, double f, double y) :A(A), f(f), y(y) {}
};
class Signal
{
private:
	double fd;
	double N;
	SinParam s1;
	SinParam s2;
	SinParam s3;
	int Rank;

	vector<double>sVals;
	vector<double>sKeys;

	vector<double>rVals;
	vector<double>rKeys;

	vector<double>R;
	vector<double>U;
	vector<double>S;
	vector<double>V;

protected:
	double SignalFunc(double x);
	int svd_hestenes(int m_m, int n_n, vector<double>& a, vector<double>& u, vector<double>& v, vector<double>& sigma);
	void CreateR(vector<double>* out_val = nullptr, vector<double>* out_keys = nullptr, vector<double>* out_R = nullptr);

public:
	Signal();
	void SetSin1(double A, double f, double y);
	void SetSin2(double A, double f, double y);
	void SetSin3(double A, double f, double y);
	void SetN(int N);
	void SetFd(int fd);
	void SetRrank(int rank);


	vector<double> GetSignalVals();
	vector<double> GetSignalKeys();
	vector<double> GetUi(int id, vector<double>* keys = nullptr);
	vector<double> GetVi(int id, vector<double>* keys = nullptr);
	vector<double> GetRVals();
	vector<double> GetRKeys();
	vector<double> GetSVals();


	void DoSvd();
	void CreateSignal(vector<double>* out_val = nullptr, vector<double>* out_keys = nullptr);
};