#include <iostream>
#include <cmath>
using namespace std;


bool is__int(const char* S) { /*������� �������� ���Ĩ���� ������ �� �������� ��������*/
    const char* temp = "0123456789";
    unsigned point_count = 0;
    //������������� ��� ��� �����
    for (int i = 0; i < strlen(S); i++)
    {				//strlen() ���������� ����� ������, �������������� ������� ��������, �� ������� ��������� str
        if ((i > 0) && (S[i] == '+' || S[i] == '-'))
            return false;
        if (S[i] == '.')
        {
            point_count++;
            if (point_count > 1) return false;
        }
        if (!strchr(temp, S[i])) return false;// ���������� ���������
        //����� �������, �� ����� ����� ���� ������ ��� ��������� ��������� �� ����� ������.
    }
    return true;

}