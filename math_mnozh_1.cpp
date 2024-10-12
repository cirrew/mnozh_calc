#include <iostream>
#include <vector>
#include <string>
#include <time.h>
using namespace std;

int dLower = -100; //нижняя базовая граница
int dHigher = 100; //верхняя базовая граница
vector<int> emptyMn; //пустое множество
vector<int> universum; //универсум
vector<vector<int>> mnozh; //вектор векторов (множеств)
vector<string> tasks; //действия
vector<vector<int>> taskRez; //результаты действий

void universum_refill() //заполнение универсума
{
    universum.clear();
    for (int i = -100; i < 100; i++)
    {
        universum.push_back(i);
    }
}

void strFormula(string s)
{
    vector<string> p;
    vector<string> p1;
    vector<int> ind;
    string tempstr = "";
    int curi = 0;
    int counter = -1;
    int c = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
            c++;
    }
    for (int i = 0; i < s.size(); i++)
    {
        tempstr = "";
        if (s[i] == '(')
        {
            ind.push_back(i);
            curi = i;
        }
        if (s[i] == ')')
        {
            for (int j = curi; j <= i; j++)
            {
                tempstr = tempstr + s[j];
            }
            p.push_back(tempstr);
            p1.push_back(tempstr);
            ind.pop_back();
            if (ind.size() > 0)
            {
                curi = ind[ind.size() - 1];
            }
        }
    }
    for (int i = 0; i < p.size()-1; i++)
    {
        counter++;
        int j = i + 1;
        while (p[j].find(p[i]) == -1)
        {
            j++;
        }
        p1[j].replace(p1[j].find(p[i]), p[i].size(), to_string(counter) + '`');
    }
    if (p1.size() == 1)
    {
        tasks.push_back(p1[0]);
    }
    for (int i = 0; i < p1.size(); i++)
    {
        tasks.push_back(p1[i]);
    }
}

int ifIsInt(string a) //проверка, является ли введённая строка числом
{
    bool fl = false;
    if (a[0] == '-' && a.size()>1)
    {
        fl = true;
        for (int i = 1; i < a.size(); i++)
        {
            if ((a[i] != '0') && (a[i] != '1') && (a[i] != '2') && (a[i] != '3') && (a[i] != '4') && (a[i] != '5') && (a[i] != '6') && (a[i] != '7') && (a[i] != '8') && (a[i] != '9'))
            {
                fl = false;
            }
        }
    }
    else
    {
        fl = true;
        for (int i = 0; i < a.size(); i++)
        {
            if ((a[i] != '0') && (a[i] != '1') && (a[i] != '2') && (a[i] != '3') && (a[i] != '4') && (a[i] != '5') && (a[i] != '6') && (a[i] != '7') && (a[i] != '8') && (a[i] != '9'))
            {
                fl = false;
            }
        }
    }
    if (fl)
        return 1;
    else
        return 0;
}

void pri(vector<int> v) //вывод элементво множества
{
    if (v.size() == 0)
    {
        cout << "Пустое множество";
    }
    else
    {
        cout << v[0];
        for (int i = 1; i < v.size(); i++)
        {
            cout << " " << v[i];
        }
    }
    cout << endl;
}
void pri(vector<string> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << endl;
    }
}

vector<int> gen1() //первый способ создания
{
    int n = 10000; //размер множества
    int num; //для вводимых чисел
    int q = 0; //счётчик текущих чисел в множестве
    string tmp;
    bool fl = true;
    vector<int> v;
    tmp = "a";
    cout << "Количество вводимых чисел?\n";
    while (n > dHigher - dLower + 1)
    {
        cin >> tmp;
        if (ifIsInt(tmp) == 1)
        {
            n = stoi(tmp);
            if (n > dHigher - dLower + 1)
            {
                cout << "Количество превышает диапазон" << endl;
            }
        }
        else
        {
            cout << "Не число" << endl;
        }
    }
    cout << "\nВвод чисел (диапазон от -100 до 100 включительно)" << endl;
    tmp = "a";
    while (q < n)
    {
        cin >> tmp;
        if (ifIsInt(tmp) == 1)
        {
            num = stoi(tmp);
            if ((num <= dHigher) && (num >= dLower))
            {
                bool f = true;
                for (int i = 0; i < v.size(); i++)
                {
                    if (v[i] == num)
                        f = false;
                }
                if (f)
                {
                    q++;
                    v.push_back(num);
                }
                else
                {
                    cout << "Указанное число уже есть в множестве" << endl;
                }
            }
            else
            {
                cout << "Указанное число не входит в диапазон" << endl;
            }
        }
        else
        {
            cout << "Не число" << endl;
        }
    }
    return v;
}

vector<int> gen2() //второй
{
    vector<int> v;
    int n = 10000;
    int num;
    string tmp;
    bool fl;
    int q = 0;
    tmp = "a";
    cout << "Количество вводимых чисел?\n";
    while (n > dHigher - dLower + 1)
    {
        cin >> tmp;
        if (ifIsInt(tmp) == 1)
        {
            n = stoi(tmp);
            if (n > dHigher - dLower + 1)
            {
                cout << "Количество превышает диапазон" << endl;
            }
        }
        else
        {
            cout << "Не число" << endl;
        }
    }
    while (q < n)
    {
        num = rand()%200 - 100;
        if ((num <= dHigher) && (num >= dLower))
        {
            bool f = true;
            for (int i = 0; i < v.size(); i++)
            {
                if (v[i] == num)
                    f = false;
            }
            if (f)
            {
                q++;
                v.push_back(num);
            }
        }
    }
    return v;
}

vector<int> gen3() //третий
{
    int newup = dHigher; //дествительная кастомная граница для генерации
    int newdown = dLower; //то же, но нижняя
    int delim = 1;
    vector<int> v; //множество
    int num; //вводимые числа
    string tmp; //для проверки
    bool fl;
    int q = -1; //для определения действия
    while (q != 3)
    {
        tmp = "a";
        cout << "\n1. Изменить диапазон\n2. Изменить делимость чисел\n3. Создать множество\n";
        cin >> tmp;
        if (ifIsInt(tmp) == 1)
        {
            q = stoi(tmp);
        }
        else
        {
            q = 4;
        }
        switch (q)
        {
        case 1:
        {
            int tmpUp, tmpDown; //новый временный диапазон
            cout << "Новая нижняя граница (базовая: -100): ";
            tmp = "a";
            while (ifIsInt(tmp) != 1)
            {
                cin >> tmp;
            }
            tmpDown = stoi(tmp);
            cout << "Новая верхяя граница (базовая: 100): ";
            tmp = "a";
            while (ifIsInt(tmp) != 1)
            {
                cin >> tmp;
            }
            tmpUp = stoi(tmp);
            if (tmpDown < dLower || tmpUp > dHigher)
            {
                cout << "Превышение исходных границ" << endl;
            }
            if (tmpDown > tmpUp)
            {
                cout << "Невозможные границы: нижняя больше верхней" << endl;
            }
            else
            {
                newup = tmpUp;
                newdown = tmpDown;
            }
            break;
        }
        case 2:
        {
            delim = -1;
            while (delim <= 0)
            {
                cout << "Новая делимость чисел? 1 для всех чисел диапазона\n";
                tmp = "a";
                while (ifIsInt(tmp) != 1)
                {
                    cin >> tmp;
                }
                delim = stoi(tmp);
                if (delim <= 0)
                {
                    cout << "Не делитель" << endl;
                }
            }
            break;
        }
        case 3:
        {
            for (int i = newdown; i <= newup; i++)
            {
                if (i % delim == 0)
                    v.push_back(i);
            }
            break;
        }
        case 4:
        {
            cout << "Не число" << endl;
            break;
        }
        default:
        {
            cout << "Не то число" << endl;
            break;
        }
        }
    }
    return v;
}

vector<int> crossing(vector<int> a, vector<int> b) //пересечение
{
    vector<int> rez;
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = 0; j < b.size(); j++)
        {
            if (a[i] == b[j])
            {
                rez.push_back(a[i]);
            }
        }
    }
    return rez;
}

vector<int> unifying(vector<int> a, vector<int> b) //объединение
{
    vector<int> rez;
    for (int i = 0; i < a.size(); i++)
    {
        rez.push_back(a[i]);
    }
    for (int i = 0; i < b.size(); i++)
    {
        for (int j = 0; j < a.size(); j++)
        {
            if (a[j] != b[i])
            {
                bool f = true;
                for (int k = 0; k < rez.size(); k++)
                {
                    if (b[i] == rez[k])
                        f = false;
                }
                if (f)
                    rez.push_back(b[i]);
            }
        }
    }
    return rez;
}

vector<int> substract(vector<int> a, vector<int> b) //разность
{
    bool f;
    vector<int> rez;
    if (a.size() != 0 && b.size() == 0)
        return a;
    for (int i = 0; i < a.size(); i++)
    {
        f = true;
        for (int j = 0; j < b.size(); j++)
        {
            if (a[i] == b[j])
                f = false;
        }
        if (f)
        {
            rez.push_back(a[i]);
        }
    }
    return rez;
}

vector<int> symmetr_substract(vector<int> a, vector<int> b) //симметрическая разность
{
    bool f;
    vector<int> rez;
    for (int i = 0; i < a.size(); i++)
    {
        f = true;
        for (int j = 0; j < b.size(); j++)
        {
            if (a[i] == b[j])
                f = false;
        }
        if (f)
            rez.push_back(a[i]);
    }
    for (int i = 0; i < b.size(); i++)
    {
        f = true;
        for (int j = 0; j < a.size(); j++)
        {
            if (b[i] == a[j])
                f = false;
        }
        if (f)
            rez.push_back(b[i]);
    }
    return rez;
}

vector<int> addition(vector<int> a) //дополнение
{
    universum_refill();
    return substract(universum, a);
}

bool simple_function_read(string s) //действия из введённого текста
{
    bool ifAdd = false; //определяет, если нужно дополнение
    bool ifRez = false; //определяет, если из вектора с результатами
    vector<int> a;
    vector<int> b;
    vector<int> rez;
    string a1 = "";
    string b1 = "";
    string s1 = ""; //s но без скобок
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] != '(' && s[i] != ')')
        {
            s1 += s[i];
        }
    }
    if (s1.size() <= 1)
    {
        cout << "Не формула" << endl;
        return false;
    }
    int i;
    i = max((int)s1.find('+'), (int)s1.find('@'));
    i = max(i, (int)s1.find('#'));
    i = max(i, (int)s1.find('^'));
    if (s1[0] == '-' && i==-1) //если есть только дополнение
    {
        a1 = s1.substr(1);
        if (a1[a1.size() - 1] == '`')
        {
            if (stoi(a1) <= taskRez.size())
            {
                a = addition(taskRez[stoi(a1)]);
            }
            else
            {
                cout << "unknown error" << endl;
                return false;
            }
        }
        else
        {
            if (ifIsInt(a1) == 1)
            {
                if (stoi(a1) <= mnozh.size())
                {
                    a = addition(mnozh[stoi(a1)]);
                }
                else
                {
                    cout << "Нет такого множества" << endl;
                    return false;
                }
            }
        }
    }
    else
    {
        if (i == -1)
        {
            cout << "err" << endl;
            return false;
        }
        else
        {
            for (int j = i - 1; j >= 0; j--)
            {
                a1 = s1[j] + a1;
            }
            for (int j = i + 1; j < s1.size(); j++)
            {
                b1 += s1[j];
            }
            ifAdd = false;
            ifRez = false;
            if (a1[0] == '-')
            {
                ifAdd = true;
                a1 = a1.substr(1);
            }
            if (a1[a1.size() - 1] == '`')
            {
                ifRez = true;
            }
            if (ifRez) //если из результатов
            {
                a = taskRez[stoi(a1)];
            }
            else //если из обычных
            {
                if (ifIsInt(a1) == 1)
                {
                    if (stoi(a1) >= mnozh.size())
                    {
                        cout << "Нет такого множества" << endl;
                        return false;
                    }
                    else
                    {
                        a = mnozh[stoi(a1)];
                    }
                }
                else
                {
                    cout <<"Не число1" << endl;
                    return false;
                }
            }
            if (ifAdd)
            {
                a = addition(a);
            }


            ifAdd = false;
            ifRez = false;
            if (b1[0] == '-')
            {
                ifAdd = true;
                b1 = b1.substr(1);
            }
            if (b1[b1.size() - 1] == '`')
            {
                ifRez = true;
            }
            if (ifRez) //если из результатов
            {
                b = taskRez[stoi(b1)];
            }
            else //если из обычных
            {
                if (ifIsInt(b1) == 1)
                {
                    if (stoi(b1) >= mnozh.size())
                    {
                        cout << "Нет такого множества" << endl;
                        return false;
                    }
                    else
                    {
                        b = mnozh[stoi(b1)];
                    }
                }
                else
                {
                    cout << "Не число2" << endl;
                    return false;
                }
            }
            if (ifAdd)
            {
                b = addition(b);
            }

            switch (s1[i])
            {
            case '+':
            {
                rez = unifying(a, b);
                break;
            }
            case '#':
            {
                rez = substract(a, b);
                break;
            }
            case '@':
            {
                rez = crossing(a, b);
                break;
            }
            case '^':
            {
                rez = symmetr_substract(a, b);
                break;
            }
            default:
            {
                cout << "Что-то пошло не так" << endl;
                return false;
            }
            }
            taskRez.push_back(rez);
            return true;
        }
    }
}

void f_read(string s)
{
    taskRez.clear();
    tasks.clear();
    if (s.find('-') == -1 && s.find('@') == -1 && s.find('+') == -1 && s.find('^') == -1 && s.find('#') == -1)
    {
        cout << "Не формула" << endl;
        return;
    }
    strFormula(s);
    int i = 0;
    bool f = true;
    while ((i < tasks.size()) && (f))
    {
        f = simple_function_read(tasks[i]);
        i++;
    }
    if (f)
    {
        pri(taskRez[taskRez.size() - 1]);
        char ch;
        cout << "Добавить к остальным множествам? (1 для добавления) ";
        cin >> ch;
        if (ch == '1')
            mnozh.push_back(taskRez[taskRez.size() - 1]);
    }
}

int main()
{
    int a;
    srand(time(0));
    system("chcp 1251 > null");
    a = -1;
    while (a != 0)
    {
        cout << "1. Создать множество\n2. Вычислить действие\n3. Вывести множества\n0. Выход\n";
        cin >> a;
        switch (a)
        {
        case 1:
        {
            vector<int> a;
            cout << "Способы - 1, 2, 3\n";
            int sposob = -1;
            cin >> sposob;
            switch (sposob)
            {
            case 1:
            {
                a = gen1();
                mnozh.push_back(a);
                break;
            }
            case 2:
            {
                a = gen2();
                mnozh.push_back(a);
                break;
            }
            case 3:
            {
                a = gen3();
                mnozh.push_back(a);
                break;
            }
            default:
            {
                cout << "not a way" << endl;
                break;
            }
            }
            break;
        }
        case 2:
        {
            string str;
            cout << "Формула?\nДополнение: -\nПересечение: @\nОбъединение: +\nСимметрическая разность: ^\nРазность: #\n";
            cout << "Доступные множества:";
            for (int i = 0; i < mnozh.size(); i++)
            {
                cout << i << ' ';
            }
            cout << endl;
            cin >> str;
            f_read(str);
            break;
        }
        case 3:
        {
            for (int i = 0; i < mnozh.size(); i++)
            {
                cout << i << ' ';
            }
            cout << endl << "which? ";
            int ij;
            cin >> ij;
            if (ij > -1 && ij < mnozh.size())
                pri(mnozh[ij]);
            else
                cout << "err" << endl;
            break;
        }
        case 0:
        {
            break;
        }
        default:
        {
            cout << "err" << endl;
            break;
        }
        }
    }
    return 0;
}