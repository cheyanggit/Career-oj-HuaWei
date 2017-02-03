/*

�������ٳ��ж���λͬѧ��ʹ��ʣ�µ�ͬѧ�ųɺϳ�����
˵����

Nλͬѧվ��һ�ţ�������ʦҪ�����е�(N-K)λͬѧ���У�ʹ
��ʣ�µ�Kλͬѧ�ųɺϳ����Ρ�


�ϳ�������ָ������һ�ֶ��Σ���Kλͬѧ���������α��Ϊ1��2����K��
���ǵ���߷ֱ�ΪT1��T2������TK��   �����ǵ�����������i��1<=i<=K��ʹ��Ti<T2<......<Ti-1<Ti>Ti+1>......>TK��

��������ǣ���֪����Nλͬѧ����ߣ�����������Ҫ��λͬѧ���У�
����ʹ��ʣ�µ�ͬѧ�ųɺϳ����Ρ�
*/

#include <iostream>
using namespace std;




int CountChorus(int *left, int *right, int *input, int n)
{
    //  ͳ�Ƶ�������   j < i
    //  left[i] �д洢��iλ����֮ǰ���С����������
    for(int i = 0; i < n; i++)      //  ��ǰ����λ��
    {
        left[i] = 1;

        for(int j = 0; j < i; j++)  //  ��ǰ����λ��i֮ǰ
        {
            if(input[j] < input[i]      //  ��ǰѭ����λ��j�����С�ڵ�ǰ����λ��
            && left[i] < left[j] + 1)   //  j֮ǰ������ĿСʱ���ۼ�
            {
                left[i] = left[j] + 1;
            }
        }
    }

    //  ͳ�Ƶݼ�����
    //  right[i] �д洢�˺�����߱�iλ�õ��˵͵�
    for(int i = n - 1; i >= 0; i--)
    {
        right[i] = 1;

        for(int j = n - 1; j > i; j--)
        {
            if(input[j] < input[i]
            && right[i] < right[j] + 1)
            {
                right[i] = right[j] + 1;
            }
        }
    }

    //  8 186 186 150 200 160 130 197 200
    int ans  = 0;
    for(int i = 0; i < n ; i++)
    {
        //cout <<"i = " <<i <<", left = " <<left[i] <<", right = " <<right[i] <<endl;
        if(left[i] + right[i] - 1 > ans)
        {
            //cout <<i <<endl;
            ans = left[i] + right[i] - 1;
        }
    }


    return n-ans;
}

int main()
{
    int n;

    int input[500];
    int left[500],right[500];

    cin>>n;                         //  ����
    for(int i = 0; i < n; i++)
    {
        cin >>input[i];             //  ÿ���˵����
    }

    cout <<CountChorus(left, right, input, n);

    return 0;
}
