#ifndef _OBJECTBASE_H_
#define _OBJECTBASE_H_

// ������� ����� ��� ���������� � �����������
class ObjectBase  {
public:
    ObjectBase(); // �����������
    ~ObjectBase(); // ����������

protected:
    int level; // ������� �������
    bool is_Alive; // ��������� �������
    bool isAlive(); // �������� �� �������������
    int getLevel(); // ���������� ������� 
};
#endif
