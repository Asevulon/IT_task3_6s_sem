#include"pch.h"
#include"Signal.h"


Signal::Signal()
{

}


void Signal::SetSin1(double A, double f, double y)
{
	s1 = SinParam(A, f, y);
}
void Signal::SetSin2(double A, double f, double y)
{
	s2 = SinParam(A, f, y);
}
void Signal::SetSin3(double A, double f, double y)
{
	s3 = SinParam(A, f, y);
}


void Signal::SetN(int n)
{
	N = n;
}
void Signal::SetFd(int Fd)
{
	fd = Fd;
}
void Signal::SetRrank(int rank)
{
	Rank = rank;
}


vector<double> Signal::GetSignalVals()
{
	return sVals;
}
vector<double> Signal::GetSignalKeys()
{
	return sKeys;
}
vector<double> Signal::GetUi(int id, vector<double>* keys)
{
	if (Rank * id >= U.size())return vector<double>();

	vector<double>res, k;
	for (int i = 0; i < Rank; i++)
	{
		res.push_back(U[Rank * i + id]);
		k.push_back(i + 1);
	}
	if (keys != nullptr)*keys = k;
	return res;
}
vector<double> Signal::GetVi(int id, vector<double>* keys)
{
	if (Rank * id >= V.size())return vector<double>();

	vector<double>res, k;
	for (int i = 0; i < Rank; i++)
	{
		res.push_back(V[Rank * i + id]);
		k.push_back(i + 1);
	}
	if (keys != nullptr)*keys = k;
	return res;
}
vector<double> Signal::GetRVals()
{
	return rVals;
}
vector<double> Signal::GetRKeys()
{
	return rKeys;
}
vector<double> Signal::GetSVals()
{
	return S;
}


void Signal::CreateSignal(vector<double>* out_val, vector<double>* out_keys)
{
	vector<double> vals;
	vector<double> keys;

	for (int i = 0; i < N; i++)
	{
		vals.push_back(SignalFunc(i));
		keys.push_back(i / fd);
	}

	sVals = vals;
	sKeys = keys;

	if (out_val != nullptr)*out_val = vals;
	if (out_keys != nullptr)*out_keys = keys;
}
double Signal::SignalFunc(double x)
{
	double res = s1.A * sin(2 * pi * s1.f * x / fd + s1.y);
	res += s2.A * sin(2 * pi * s2.f * x / fd + s2.y);
	res += s3.A * sin(2 * pi * s3.f * x / fd + s3.y);
	return res;
}


void Signal::CreateR(vector<double>* out_val, vector<double>* out_keys, vector<double>* out_R)
{
	if (sVals.empty())return;


	vector<double>r;
	vector<double>keys;


	for (int i = 0; i < Rank; i++)
	{
		double val = 0;
		for (int k = 0; k < N - i; k++)
		{
			val += sVals[k] * sVals[k + i];
		}
		val /= N - i;
		r.push_back(val);
		keys.push_back(i);
	}

	
	vector<double>RR;
	for (int i = 0; i < Rank; i++)
	{
		for (int j = 0; j < Rank; j++)
		{
			RR.push_back(r[abs(i - j)]);
		}
	}


	rKeys = keys;
	rVals = r;
	R = RR;
	if (out_val != nullptr)*out_val = rVals;
	if (out_keys != nullptr)*out_keys = rKeys;
	if (out_R != nullptr)*out_R = R;
}


void Signal::DoSvd()
{
	CreateR();
	vector<double>u(Rank*Rank, 0), v(Rank * Rank, 0), s(Rank, 0);
	svd_hestenes(Rank, Rank, R, u, v, s);
	U = u;
	S = s;
	V = v;
}


int Signal::svd_hestenes(int m_m, int n_n, vector<double>& a, vector<double>& u, vector<double>& v, vector<double>& sigma)
{
	float thr = 0.000001f;
	int n, m, i, j, l, k, lort, iter, in, ll, kk;
	float alfa, betta, hamma, eta, t, cos0, sin0, buf, s, r;
	n = n_n;
	m = m_m;
	for (i = 0; i < n; i++)
	{
		in = i * n;
		for (j = 0; j < n; j++)
			if (i == j) v[in + j] = 1.;
			else v[in + j] = 0.;
	}
	for (i = 0; i < m; i++)
	{
		in = i * n;
		for (j = 0; j < n; j++)
		{
			u[in + j] = a[in + j];
		}
	}

	iter = 0;
	while (1)
	{
		lort = 0;
		iter++;
		for (l = 0; l < n - 1; l++)
			for (k = l + 1; k < n; k++)
			{
				alfa = 0.; betta = 0.; hamma = 0.;
				for (i = 0; i < m; i++)
				{
					in = i * n;
					ll = in + l;
					kk = in + k;
					alfa += u[ll] * u[ll];
					betta += u[kk] * u[kk];
					hamma += u[ll] * u[kk];
				}

				if (sqrt(alfa * betta) < 1.e-10)	continue;
				if (fabs(hamma) / sqrt(alfa * betta) < thr)
					continue;

				lort = 1;
				eta = (betta - alfa) / (2.f * hamma);
				t = (eta / fabs(eta)) /
					(fabs(eta) + (float)sqrt(1.f + eta * eta));
				cos0 = 1.f / (float)sqrt(1.f + t * t);
				sin0 = t * cos0;

				for (i = 0; i < m; i++)
				{
					in = i * n;
					buf = u[in + l] * cos0 - u[in + k] * sin0;
					u[in + k] = u[in + l] * sin0 + u[in + k] * cos0;
					u[in + l] = buf;

					if (i >= n) continue;
					buf = v[in + l] * cos0 - v[in + k] * sin0;
					v[in + k] = v[in + l] * sin0 + v[in + k] * cos0;
					v[in + l] = buf;
				}
			}

		if (!lort) break;
	}

	for (i = 0; i < n; i++)
	{
		s = 0.;
		for (j = 0; j < m; j++)	s += u[j * n + i] * u[j * n + i];
		s = (float)sqrt(s);
		sigma[i] = s;
		if (s < 1.e-10)	continue;
		for (j = 0; j < m; j++)	u[j * n + i] = u[j * n + i] / s;
	}
	for (i = 0; i < n - 1; i++)
		for (j = i; j < n; j++)
			if (sigma[i] < sigma[j])
			{
				r = sigma[i]; sigma[i] = sigma[j]; sigma[j] = r;
				for (k = 0; k < m; k++)
				{
					r = u[i + k * n]; u[i + k * n] = u[j + k * n]; u[j + k * n] = r;
				}
				for (k = 0; k < n; k++)
				{
					r = v[i + k * n]; v[i + k * n] = v[j + k * n]; v[j + k * n] = r;
				}
			}

	return iter;
}