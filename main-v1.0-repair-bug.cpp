#include <bits/stdc++.h>
#include <windows.h> //本程序使用<windows.h> 头文件和 system() 函数，不要在linux下编译本代码！
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

        infile.close(); // 关闭文件
    }
    else
    {
        cout << "错误：无法打开或没有权限打开重要配置文件 timer.psdt" << endl;
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
        cout << "时间到！" << endl;
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
            cout << "错误：没有权限读或写重要配置文件 timer.psdt" << endl;
            system("pause");
            return 0;
        }
        cout << "Leo Timer 1" << endl;

        cout << "说明：正计时中按下任意键将会停止。" << endl;
        cout << "选择功能(倒计时 1，正计时 2，退出 3，关于 4，设置 5)：";

        string choose_mode;
        cin >> choose_mode;
        if(choose_mode == "1")
        {
            system("cls");
            cout << "请输入小时数：";
            cin >> hour;
            cout << "请输入分钟数：";
            cin >> minute;
            cout << "请输入秒数：";
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
            cout << "准备开始......" << endl;
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
            cout << "即将开始......" << endl;
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
            cout << "正计时终止。" << endl;
            system("pause");
            system("cls");
        }

        else if(choose_mode == "3")
        {
            system("cls");
            cout << "您确定要退出此程序？(Y/N)" << endl;
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
            cout << "About 关于此软件" << endl;
            cout << "Leo Timer Version 1" << endl;
            cout << "Build Date: 2025.2.11" << endl;
            cout << "Author: wrixeo(Leo Zhu)" << endl;
            cout << "If you have any question, please send an email to wrixeo382874@outlook.com. I will reply as soon as possible." << endl;
            cout << "永不妥协！" << endl;
            system("pause");
            system("cls");
            continue;
        }

        else if(choose_mode == "5")
        {
            system("cls");
            cout << "设置 Settings" << endl;
            cout << "说明：不要删除timer.psdt(Personal Data File)，否则你会丢失所有数据。" << endl;
            cout << "若想手动更改timer.psdt，请使用记事本打开。" << endl << endl;
            cout << "闹铃设置" << endl;

            ofstream outfile("timer.psdt");
            if(outfile.is_open())
            {
                cout << "闹铃路径" << endl;
                cout << "请输入路径" << endl;
                cout << "（如：D:\\a.mp3）" << endl;
                cout << ">>>";
                string path;
                getline(cin, path);
                if(path == "x") path = "0";
                outfile << path << endl;
                outfile.close();
            }
            else
            {
                cout << "无法打开文件 timer.psdt" << endl;
            }

            system("cls");
            cout << "设置完成！" << endl;
            Sleep(1800);
            system("cls");
            continue;
        }

        else
        {
            system("cls");
            cout << "输入错误！" << endl;
            Sleep(3000);
            system("cls");
            continue;
        }
    }

    return 0;
}
