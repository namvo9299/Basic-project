#include <iostream>
#include <set>
#include <algorithm>
using namespace std;
const int xy = 3;
set<int> q;

bool checkX(char n[xy][xy])
{
    if (n[0][0] == 'X' && n[0][0] == n[0][1] && n[0][1] == n[0][2])
        return true;
    if (n[1][0] == 'X' && n[1][0] == n[1][1] && n[1][1] == n[1][2])
        return true;
    if (n[2][0] == 'X' && n[2][0] == n[2][1] && n[2][1] == n[2][2])
        return true;
    if (n[0][0] == 'X' && n[0][0] == n[1][0] && n[1][0] == n[2][0])
        return true;
    if (n[0][1] == 'X' && n[0][1] == n[1][1] && n[1][1] == n[2][1])
        return true;
    if (n[0][2] == 'X' && n[0][2] == n[1][2] && n[1][2] == n[2][2])
        return true;
    if (n[0][0] == 'X' && n[0][0] == n[1][1] && n[1][1] == n[2][2])
        return true;
    if (n[0][2] == 'X' && n[0][2] == n[1][1] && n[1][1] == n[2][0])
        return true;
    return false;
}
bool checkO(char n[xy][xy])
{
    if (n[0][0] == 'O' && n[0][0] == n[0][1] && n[0][1] == n[0][2])
        return true;
    if (n[1][0] == 'O' && n[1][0] == n[1][1] && n[1][1] == n[1][2])
        return true;
    if (n[2][0] == 'O' && n[2][0] == n[2][1] && n[2][1] == n[2][2])
        return true;
    if (n[0][0] == 'O' && n[0][0] == n[1][0] && n[1][0] == n[2][0])
        return true;
    if (n[0][1] == 'O' && n[0][1] == n[1][1] && n[1][1] == n[2][1])
        return true;
    if (n[0][2] == 'O' && n[0][2] == n[1][2] && n[1][2] == n[2][2])
        return true;
    if (n[0][0] == 'O' && n[0][0] == n[1][1] && n[1][1] == n[2][2])
        return true;
    if (n[0][2] == 'O' && n[0][2] == n[1][1] && n[1][1] == n[2][0])
        return true;
    return false;
}
void nhap(int i, char a[xy][xy], char q)
{
    switch (i)
    {
    case 0:
        a[0][0] = q;
        break;
    case 1:
        a[0][1] = q;
        break;
    case 2:
        a[0][2] = q;
        break;
    case 3:
        a[1][0] = q;
        break;
    case 4:
        a[1][1] = q;
        break;
    case 5:
        a[1][2] = q;
        break;
    case 6:
        a[2][0] = q;
        break;
    case 7:
        a[2][1] = q;
        break;
    case 8:
        a[2][2] = q;
        break;
    }
}
int doi(int i, int j)
{
    int n;
    if (i == 0 && j == 0)
        n = 0;
    if (i == 0 && j == 1)
        n = 1;
    if (i == 0 && j == 2)
        n = 2;
    if (i == 1 && j == 0)
        n = 3;
    if (i == 1 && j == 1)
        n = 4;
    if (i == 1 && j == 2)
        n = 5;
    if (i == 2 && j == 0)
        n = 6;
    if (i == 2 && j == 1)
        n = 7;
    if (i == 2 && j == 2)
        n = 8;
    return n;
}
bool checkbotwin(char n[xy][xy])
{
    for (int i = 0; i < 3; i++)
    {
        int k = 0, h = 0;
        for (int j = 0; j < 3; j++)
        {
            if (n[i][j] == 'O')
            {
                k += 1;
                h += j;
            }
        }
        if (k == 2 && n[i][3 - h] != 'X' && n[i][3 - h] != 'O')
        {
            q.insert(doi(i, 3 - h));
            nhap(doi(i, 3 - h), n, 'O');
            return true;
        }
    }
    for (int i = 0; i < 3; i++)
    {
        int k = 0, h = 0;
        for (int j = 0; j < 3; j++)
        {
            if (n[j][i] == 'O')
            {
                k += 1;
                h += j;
            }
        }
        if (k == 2 && n[3 - h][i] != 'X' && n[3 - h][i] != 'O')
        {
            q.insert(doi(3 - h, i));
            nhap(doi(3 - h, i), n, 'O');
            return true;
        }
    }
    int k = 0, h = 0;
    for (int i = 0; i < 3; i++)
    {
        if (n[i][i] == 'O')
        {
            k += 1;
            h += i;
        }
        if (k == 2 && n[3 - h][3 - h] != 'X' && n[3 - h][3 - h] != 'O')
        {
            q.insert(doi(3 - h, 3 - h));
            nhap(doi(3 - h, 3 - h), n, 'O');
            return true;
        }
    }
    if (n[0][2] == 'O' && n[1][1] == 'O' && n[2][0] != 'X' && n[2][0] != 'O')
    {
        q.insert(doi(2, 0));
        nhap(doi(2, 0), n, 'O');
        return true;
    }
    else if (n[0][2] == 'O' && n[2][0] == 'O' && n[1][1] != 'X' && n[1][1] != 'O')
    {
        q.insert(doi(1, 1));
        nhap(doi(1, 1), n, 'O');
        return true;
    }
    else if (n[2][0] == 'O' && n[1][1] == 'O' && n[0][2] != 'X' && n[0][2] != 'O')
    {
        q.insert(doi(0, 2));
        nhap(doi(0, 2), n, 'O');
        return true;
    }
    return false;
}
bool checkbotlose(char n[xy][xy])
{
    for (int i = 0; i < 3; i++)
    {
        int k = 0, h = 0;
        for (int j = 0; j < 3; j++)
        {
            if (n[i][j] == 'X')
            {
                k += 1;
                h += j;
            }
        }
        if (k == 2 && n[i][3 - h] != 'O' && n[i][3 - h] != 'X')
        {
            q.insert(doi(i, 3 - h));
            nhap(doi(i, 3 - h), n, 'O');
            return true;
        }
    }
    for (int i = 0; i < 3; i++)
    {
        int k = 0, h = 0;
        for (int j = 0; j < 3; j++)
        {
            if (n[j][i] == 'X')
            {
                k += 1;
                h += j;
            }
        }
        if (k == 2 && n[3 - h][i] != 'O' && n[3 - h][i] != 'X')
        {
            q.insert(doi(3 - h, i));
            nhap(doi(3 - h, i), n, 'O');
            return true;
        }
    }
    int k = 0, h = 0;
    for (int i = 0; i < 3; i++)
    {
        if (n[i][i] == 'X')
        {
            k += 1;
            h += i;
        }
        if (k == 2 && n[3 - h][3 - h] != 'O' && n[3 - h][3 - h] != 'X')
        {
            q.insert(doi(3 - h, 3 - h));
            nhap(doi(3 - h, 3 - h), n, 'O');
            return true;
        }
    }
    if (n[0][2] == 'X' && n[1][1] == 'X' && n[2][0] != 'X' && n[2][0] != 'O')
    {
        q.insert(doi(2, 0));
        nhap(doi(2, 0), n, 'O');
        return true;
    }
    else if (n[0][2] == 'X' && n[2][0] == 'X' && n[1][1] != 'X' && n[1][1] != 'O')
    {
        q.insert(doi(1, 1));
        nhap(doi(1, 1), n, 'O');
        return true;
    }
    else if (n[2][0] == 'X' && n[1][1] == 'X' && n[0][2] != 'X' && n[0][2] != 'O')
    {
        q.insert(doi(0, 2));
        nhap(doi(0, 2), n, 'O');
        return true;
    }
    return false;
}
int main()
{
    char n[xy][xy];
    int te = 0;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
        {
            n[i][j] = te + 49;
            ++te;
        }
    int t;
    cout << "1. Player 1 vs Bot.\n"
         << "2. Player 1 vs Player 2\n";
    cin >> t;
    switch (t)
    {
    case 1:
    {
        int s = 2, d = 0;
        while (1)
        {
            int j;
            cout << "\tTic Tac Toe\n";
            cout << "Player 1(X) - Bot(O)\n\n";
            cout << "\t   |   |   \n";
            cout << "\t " << n[0][0] << " | " << n[0][1] << " | " << n[0][2] << endl;
            cout << "\t___|___|___\n";
            cout << "\t   |   |   \n";
            cout << "\t " << n[1][0] << " | " << n[1][1] << " | " << n[1][2] << endl;
            cout << "\t___|___|___\n";
            cout << "\t   |   |   \n";
            cout << "\t " << n[2][0] << " | " << n[2][1] << " | " << n[2][2] << endl;
            cout << "\t   |   |   \n\n";

            if (checkX(n) == true)
            {
                cout << "\nPlayer 1 win!!!";
                break;
            }
            else if (checkO(n) == true)
            {
                cout << "\nPlayer 2 win!!!";
                break;
            }
            if (d == 9)
            {
                cout << "----DRAW----\n";
                break;
            }

            if (s % 2 == 0)
            {
                cout << "Player 1, enter the number: ";
                cin >> j;

                while (1)
                {
                    if (j < 1 || j > 9)
                    {
                        cout << "\nVi tri sai, vui long nhap lai: ";
                        cin >> j;
                    }
                    else if (q.find(j - 1) == q.end())
                        break;
                    else
                    {
                        cout << "\nVi tri da duoc nhap, vui long nhap lai: ";
                        cin >> j;
                    }
                }
                q.insert(j - 1);
                nhap(j - 1, n, 'X');
                s += 1;
            }
            else
            {
                int flag = 0;
                if (checkbotwin(n) != true)
                    if (checkbotlose(n) != true)
                    {
                        while (1)
                        {
                            if (flag != 0)
                                break;
                            if (q.find(4) == q.end())
                            {
                                q.insert(4);
                                nhap(4, n, 'O');
                                break;
                            }
                            else
                            {
                                for (int i = 0; i < 9; i += 2)
                                {
                                    if (q.find(i) == q.end())
                                    {
                                        q.insert(i);
                                        nhap(i, n, 'O');
                                        flag += 1;
                                        break;
                                    }
                                }
                                if (flag == 0)
                                {
                                    for (int i = 1; i < 8; i += 2)
                                    {
                                        if (q.find(i) == q.end())
                                        {
                                            q.insert(i);
                                            nhap(i, n, 'O');
                                            flag += 1;
                                            break;
                                        }
                                    }
                                }
                            }
                        }
                    }

                s += 1;
            }
            d += 1;
            system("cls");
        }
        system("pause");
        break;
    }

    case 2:
    {
        int k = 2, h = 0;
        while (1)
        {
            int j;
            cout << "\tTic Tac Toe\n";
            cout << "Player 1(X) - Player 2(O)\n\n";
            cout << "\t   |   |   \n";
            cout << "\t " << n[0][0] << " | " << n[0][1] << " | " << n[0][2] << endl;
            cout << "\t___|___|___\n";
            cout << "\t   |   |   \n";
            cout << "\t " << n[1][0] << " | " << n[1][1] << " | " << n[1][2] << endl;
            cout << "\t___|___|___\n";
            cout << "\t   |   |   \n";
            cout << "\t " << n[2][0] << " | " << n[2][1] << " | " << n[2][2] << endl;
            cout << "\t   |   |   \n\n";

            if (checkX(n) == true)
            {
                cout << "\nPlayer 1 win!!!";
                break;
            }
            else if (checkO(n) == true)
            {
                cout << "\nPlayer 2 win!!!";
                break;
            }
            if (h == 9)
            {
                cout << "----DRAW----\n";
                break;
            }
            if (k % 2 == 0)
            {
                cout << "Player 1, enter the number: ";
                cin >> j;

                while (1)
                {
                    if (j < 1 || j > 9)
                    {
                        cout << "\nVi tri sai, vui long nhap lai: ";
                        cin >> j;
                    }
                    else if (q.find(j - 1) != q.end())
                    {
                        cout << "\nVi tri da duoc nhap, vui long nhap lai: ";
                        cin >> j;
                    }
                    else
                    {
                        break;
                    }
                }
                q.insert(j - 1);
                nhap(j - 1, n, 'X');
                k += 1;
            }
            else
            {
                cout << "Player 2, enter the number: ";
                cin >> j;
                while (1)
                {
                    if (j < 1 || j > 9)
                    {
                        cout << "\nVi tri sai, vui long nhap lai: ";
                        cin >> j;
                    }
                    else if (q.find(j - 1) == q.end())
                        break;
                    else
                    {
                        cout << "\nVi tri da duoc nhap, vui long nhap lai: ";
                        cin >> j;
                    }
                }
                q.insert(j - 1);
                nhap(j - 1, n, 'O');
                k += 1;
            }
            h += 1;
            system("cls");
        }
        system("pause");
        break;
    }

    default:
        cout << "Good bye :D";
    }
}