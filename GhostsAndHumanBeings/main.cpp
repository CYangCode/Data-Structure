#include <iostream>
#include <vector>

using namespace std;

struct State
{
    int ln, lm, is_boat_left;
    State * next;
    State(int n, int m, int isb):ln(n), lm(m), is_boat_left(isb) {}
    int operator==(const State & state)
    {
        return this->lm == state.lm && this->ln == state.ln && this->is_boat_left == state.is_boat_left;
    }
    void print()
    {
        cout << "(" << ln << ", " << lm << ") " << (is_boat_left? "������":"�����Ұ�") << endl;
    }
};

class Vector: public vector<State>
{
public:
    bool find(State & state)
    {
        for (State s: *this)
        {
            if (s == state) return true;
        }
        return false;
    }

};
/** \brief �˹�Ӻ���ߵ����ұߵ�����
 *
 * \param ln ������˵�����
 * \param lm ����߹������
 * \param rn ���ұ��˵�����
 * \param rm ���ұ߹������
 * \param is_boat_left ���Ƿ��ںӵ����
 * \return void
 *
 */
int methods[5][2] = {{0, 1}, {1, 0}, {1, 1}, {2, 0}, {0, 2}};
Vector vec;
void * CrossRiver(int ln, int lm, int rn, int rm, int is_boat_left)
{
    if (ln < 0 || lm < 0 || rn < 0 || rm < 0) return nullptr;
    if (ln == 0 && lm == 0)
    {
        vec.push_back(State(ln, lm, is_boat_left));
        return new State(0, 0, is_boat_left);
    }
    if ((ln != 0 && lm > ln) || (rn != 0 && rm > rn)) return nullptr;
    State state(ln, lm, is_boat_left);
    if (vec.find(state)) return nullptr;
    vec.push_back(state);
    for (int i = 0; i < 5; ++i)
    {
        if (is_boat_left)
            CrossRiver(ln - methods[i][0], lm - methods[i][1], rn + methods[i][0], rm + methods[i][1], 0);
        else
            CrossRiver(ln + methods[i][0], lm + methods[i][1], rn - methods[i][0], rm - methods[i][1], 1);
    }
   // vec.pop_back();
}

void travel(int is_left, int pos)
{
    if (vec[pos].ln == 0 && vec[pos].lm == 0)
    {
        vec[pos].print();
        return;
    }
    int i;
    for (i = pos; vec[i].is_boat_left == is_left; ++i);
    vec[i - 1].print();
    travel(!is_left, i);
}

int main()
{
    CrossRiver(3, 3, 0, 0, 1);
    travel(1, 0);
}
