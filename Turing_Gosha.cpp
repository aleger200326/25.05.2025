// MT.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <map>

int main()
{
    try 
    {
        const char* mtfilename = "MT.txt";
        const char* cmdfilename = "input.txt";
        const char* outfilename = "output.txt";
        std::map <std::string, std::string> mp;
        std::map <std::string, bool> mpb;
        int pos = 1000000;
        std::ifstream readmt(mtfilename);
        std::ofstream printout(outfilename);
        if (!readmt)
        {
            throw "Can't open the file";
        }
        std::ifstream readcmd(cmdfilename);
        if (!readcmd)
        {
            throw "Can't open the file";
        }
        std::string ss,s;
        readmt >> ss;
        for (int i = 0; i < 1000000; ++i)
        {
            s += '0';
        }
        s += ss;
        for (int i = 2000000 - s.length(); i < 2000000; ++i)
        {
            s += '0';
        }
        ss = "";
        while (readcmd.peek() != EOF)
        {
            std::string s1, s2, s3, s4, s5, s6;
            readcmd >> s1 >> s2 >> s3 >> s4 >> s5 >> s6;
            mpb[s1 + s2] = true;
            mp[s1 + s2] = s4 + s5 + s6;
            if(ss=="") ss = s1;
        }
        std::string sn = "";
        sn += s[pos];
        while (mpb[ss+sn])
        {
            s[pos] = mp[ss + sn][0];
            std::string tmp = mp[ss + sn];
            if (tmp[1] == 'L')
            {
                --pos;
                if (pos == 0) throw "out of memory";
            }
            if (tmp[1] == 'R')
            {
                ++pos;
                if (pos == 1999999) throw "out of memory";
            }
            sn = s[pos];
            tmp.erase(tmp.begin(), tmp.begin() + 2);
            ss = tmp;
        }
        int l = -1, r = -1;
        int length = s.length();
        l = s.find_first_of('1');
        r = s.find_last_of('1');
        for (int i = std::min(l, pos); i <= std::max(pos, r); ++i)
            printout << s[i];
        printout << std::endl;
        if (l < pos)
        {
            for (int i = 0; i < pos - l; ++i)
                printout << " ";
        }
        printout << "^" << std::endl;
        readmt.close();
        readcmd.close();
        printout.close();
    }
    catch (const char* str)
    {
        std::cout << "Error! " << str << std::endl;
    }
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
