#include <bits/stdc++.h>
#include <windows.h> //������ʹ��<windows.h> ͷ�ļ��� system() ��������Ҫ��linux�±��뱾���룡
#include <conio.h>
#include <unistd.h>
#include <fstream>

using namespace std;

const int C4 = 262;
const int D4 = 294;
const int E4 = 330;
const int F4 = 349;
const int G4 = 392;
const int A4 = 440;
const int B4 = 494;
const int duration = 500;
bool out = false;
int hour, minute, second;
string a;
struct err_hs
{
    int new_h, new_m, new_s;
};

err_hs hs(int h, int m, int s)
{
    err_hs tmp;
    int x = h, y = m, z = s;
    if(z >= 60)
    {
        y += z / 60;
        int t = z;
        z = t % 60;
    }
    if(y >= 60)
    {
        x += y / 60;
        int t = y;
        y = t % 60;
    }
    tmp.new_h = x;
    tmp.new_m = y;
    tmp.new_s = z;
    return tmp;
}

void sound()
{
    string path;
    ifstream infile("timer.psdt");
    if(infile.is_open())
    {
        getline(infile, path);

        infile.close(); // �ر��ļ�
    }
    else
    {
        cout << "�����޷��򿪻�û��Ȩ�޴���Ҫ�����ļ� timer.psdt" << endl;
        system("pause");
        exit(0);
    }

    if(path != "0")
    {
        string str = "start ";
        str += path;
        const char *cmd = str.c_str();
        system(cmd);
    }
    return;
}

void lesstime(int a, int b, int hour, int minute, int second)
{
    if(hour == 0 && minute == 0 && second == 0)
    {
        out = true;
        system("cls");
        cout << "ʱ�䵽��" << endl;
        sound();
        system("pause");
        return;
    }
    if(a * 4 < b)
    {
        if(hour < 10)
        {
            printf("\033[31m0\033[0m");
            printf("\033[31m%d\033[0m", hour);
            printf("\033[31m:\033[0m");
        }
        else
        {
            printf("\033[31m%d\033[0m", hour);
            printf("\033[31m:\033[0m");
        }
        if(minute < 10)
        {
            printf("\033[31m0\033[0m");
            printf("\033[31m%d\033[0m", minute);
            printf("\033[31m:\033[0m");
        }
        else
        {
            printf("\033[31m%d\033[0m", minute);
            printf("\033[31m:\033[0m");
        }
        if(second < 10)
        {
            printf("\033[31m0\033[0m");
            printf("\033[31m%d\033[0m", second);
        }
        else
        {
            printf("\033[31m%d\033[0m", second);
        }
    }
    else
    {
        if(hour < 10)
        {
            cout << "0" << hour << ":";
        }
        else
        {
            cout << hour << ":";
        }
        if(minute < 10)
        {
            cout << "0" << minute << ":";
        }
        else
        {
            cout << minute << ":";
        }
        if(second < 10)
        {
            cout << "0" << second;
        }
        else
        {
            cout << second;
        }
    }
}

int main()
{
    while(a != "Y")
    {
        if(access("timer.psdt", F_OK))
        {
            ofstream outfile("timer.psdt");
            if(outfile.is_open()) outfile << "clock.mp3";
        }
        if(access("timer.psdt", R_OK) || access("timer.psdt", W_OK))
        {
            cout << "����û��Ȩ�޶���д��Ҫ�����ļ� timer.psdt" << endl;
            system("pause");
            return 0;
        }
        cout << "Leo Timer 1" << endl;

        cout << "˵��������ʱ�а������������ֹͣ��" << endl;
        cout << "ѡ����(����ʱ 1������ʱ 2���˳� 3������ 4������ 5)��";

        string choose_mode;
        cin >> choose_mode;
        if(choose_mode == "1")
        {
            system("cls");
            cout << "������Сʱ����";
            cin >> hour;
            cout << "�������������";
            cin >> minute;
            cout << "������������";
            cin >> second;

            if(minute >= 60 || second >= 60)
            {
                err_hs x = hs(hour, minute, second);
                hour = x.new_h;
                minute = x.new_m;
                second = x.new_s;
            }

            int t = hour * 3600 + minute * 60 + second;

            cout << endl;
            system("cls");
            cout << "׼����ʼ......" << endl;
            Sleep(3000);
            system("cls");

            while(true)
            {
                int ans = hour * 3600 + minute * 60 + second;
                lesstime(ans, t, hour, minute, second);

                if(out)
                {
                    system("cls");
                    break;
                }

                Sleep(1000);
                system("cls");
                if(second == 0 && minute == 0 && hour != 0)
                {
                    second = 59, minute = 59;
                    hour--;
                    continue;
                }
                else if(second == 0)
                {
                    if(minute == 0)
                    {
                        if(hour == 0)
                        {
                            break;
                        }
                        else
                        {
                            minute = 59;
                            hour--;
                        }
                    }
                    else
                    {
                        second = 59;
                        minute--;
                    }
                }
                else
                {
                    second--;
                }
            }
        }

        else if(choose_mode == "2")
        {
            system("cls");
            cout << "������ʼ......" << endl;
            Sleep(3000);
            system("cls");

            while(!kbhit())
            {

                if(hour < 10)
                {
                    cout << "0" << hour << ":";
                }
                else
                {
                    cout << hour << ":";
                }
                if(minute < 10)
                {
                    cout << "0" << minute << ":";
                }
                else
                {
                    cout << minute << ":";
                }
                if(second < 10)
                {
                    cout << "0" << second;
                }
                else
                {
                    cout << second;
                }
                Sleep(1000);
                system("cls");
                if(second == 59 && minute == 59)
                {
                    second = 0, minute = 0;
                    hour++;
                }
                else if(second == 59)
                {
                    second = 0;
                    minute++;
                }
                else
                {
                    second++;
                }
            }

            system("cls");
            cout << "����ʱ��ֹ��" << endl;
            system("pause");
            system("cls");
        }

        else if(choose_mode == "3")
        {
            system("cls");
            cout << "��ȷ��Ҫ�˳��˳���(Y/N)" << endl;
            cin >> a;
            if(a == "Y" || a == "y")
            {
                return 0;
            }
            else
            {
                system("cls");
                continue;
            }
        }
        else if(choose_mode == "4")
        {
            system("cls");
            cout << "About ���ڴ����" << endl;
            cout << "Leo Timer Version 1" << endl;
            cout << "Build Date: 2025.2.11" << endl;
            cout << "Author: wrixeo(Leo Zhu)" << endl;
            cout << "If you have any question, please send an email to wrixeo382874@outlook.com. I will reply as soon as possible." << endl;
            cout << "������Э��" << endl;
            system("pause");
            system("cls");
            continue;
        }

        else if(choose_mode == "5")
        {
            system("cls");
            cout << "���� Settings" << endl;
            cout << "˵������Ҫɾ��timer.psdt(Personal Data File)��������ᶪʧ�������ݡ�" << endl;
            cout << "�����ֶ�����timer.psdt����ʹ�ü��±��򿪡�" << endl << endl;
            cout << "��������" << endl;

            ofstream outfile("timer.psdt");
            if(outfile.is_open())
            {
                cout << "����·��" << endl;
                cout << "������·��" << endl;
                cout << "���磺D:\\a.mp3��" << endl;
                cout << ">>>";
                string path;
                getline(cin, path);
                if(path == "x") path = "0";
                outfile << path << endl;
                outfile.close();
            }
            else
            {
                cout << "�޷����ļ� timer.psdt" << endl;
            }

            system("cls");
            cout << "������ɣ�" << endl;
            Sleep(1800);
            system("cls");
            continue;
        }

        else
        {
            system("cls");
            cout << "�������" << endl;
            Sleep(3000);
            system("cls");
            continue;
        }
    }

    return 0;
}
