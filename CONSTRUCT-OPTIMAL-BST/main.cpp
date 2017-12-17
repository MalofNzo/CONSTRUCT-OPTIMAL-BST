#include <iostream>  
using namespace std;
#define n 5  
struct e_root//Ϊ��ͬʱ����e��root��������Ҫһ���ṹ��  
{
	double **e;
	int **root;
	e_root()
	{
		e = new double  *[n + 2];
		for (int i = 0; i<n + 2; i++)
		{
			e[i] = new double[n + 1];
		}
		root = new int *[n + 1];
		for (int j = 0; j<n + 1; j++)
		{
			root[j] = new int[n + 1];
		}
	};
};
struct e_root OPTIMAL_BST(double p[], double q[])
{
	struct e_root T;
	double w[n + 2][n + 1] = { 0 };
	for (int i = 1; i <= n + 1; i++)
	{
		T.e[i][i - 1] = q[i - 1];
		w[i][i - 1] = q[i - 1];
	}
	for (int l = 1; l <= n; l++)
	{
		for (int i = 1; i <= n - l + 1; i++)
		{
			int j = i + l - 1;
			T.e[i][j] = 0x7fffffff;
			w[i][j] = w[i][j - 1] + p[j] + q[j];
			for (int r = i; r <= j; r++)
			{
				double t = T.e[i][r - 1] + T.e[r + 1][j] + w[i][j];
				if (t<T.e[i][j])
				{
					T.e[i][j] = t;
					T.root[i][j] = r;
				}
			}
		}
	}
	return T;
}
void PRINT_OPTIMAL_BST(struct e_root T, int i, int j)
{
	int Root = T.root[i][j];//��ǰ�����  
	if (i == 1 && j == n)
	{
		cout << "k" << Root << "Ϊ��" << endl;
	}
	if (i == Root)
	{//�����������Ҷ��    
		cout << "d" << i - 1 << "Ϊk" << Root << "��������" << endl;
	}
	else
	{
		cout << "k" << T.root[i][Root - 1] << "Ϊk" << Root << "��������" << endl;
		PRINT_OPTIMAL_BST(T, i, Root - 1);
	}
	if (j == Root)
	{//�����������Ҷ��    
		cout << "d" << j << "Ϊk" << Root << "��������" << endl;
	}
	else
	{
		cout << "k" << T.root[Root + 1][j] << "Ϊk" << Root << "��������" << endl;
		PRINT_OPTIMAL_BST(T, Root + 1, j);
	}
}
void main()
{
	double p[n + 1] = { 0,0.15,0.10,0.05,0.10,0.20 };//ע������p�ĵ�һ��λ�ò����κ����ݡ�  
	double q[n + 2] = { 0.05,0.10,0.05,0.05,0.05,0.10 };
	//double p[n+1]={0,0.04,0.06,0.08,0.02,0.10,0.12,0.14};//15.5-2������  
	// double q[n+2]={0.06,0.06,0.06,0.06,0.05,0.05,0.05,0.05};  
	struct e_root T = OPTIMAL_BST(p, q);
	cout << "���Ŷ����������ṹ:" << endl;
	PRINT_OPTIMAL_BST(T, 1, n);
	cout << "���Ŷ�������������:" << T.e[1][n] << endl;
}