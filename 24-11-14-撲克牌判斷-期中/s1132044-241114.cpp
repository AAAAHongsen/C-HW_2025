/**
* @author       洪萱穎  < s1132044@mail.yzu.edu.tw >
* @version      1.0
* @since        1.0
*/
#include <iostream>
#include <string>
#include<sstream>
#include <vector>
using namespace std;

void sequencePoke(vector<string>& S, int n) //排序pokeS (pokeS , pokeS長度)
{
    //依花色排序
    for (int i = 0; i < n; i++) //重複n回
    {
        for (int j = 0; j < n; j++) //比較n次資料
        {
            string t;
            if (S[i][0] > S[j][0])
            {
                t = S[i]; S[i] = S[j]; S[j] = t;
            }
        }
    }
    //同花色排序
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if (S[i][0] == S[j][0])
            {
                string t;
                string strA = S[i].substr(1, 2), strB = S[j].substr(1, 2);  //(string.substr(i, n) 忽略字串前i個字符，輸入後n個字符)
                istringstream cutstrA(strA);
                istringstream cutstrB(strB);
                int a = 0, b = 0;
                cutstrA >> a; cutstrB >> b;  //將剪下的數字字串存成實數int，方便比較大小。
                if (a < b) 
                { 
                    t = S[i]; S[i] = S[j]; S[j] = t; 
                }
            }
        }
    }
}
int main()
{
    int n = 0;  //資料筆數
    cin >> n;

    cin.ignore(100, '\n');  //忽略空格
    for (int i = 0; i < n; i++)
    {
        string poke, onePoke;    //poke:一疊牌內容    //onePoke:切割下的單張牌
        getline(cin, poke);    //輸入一疊牌內容 (getline可接受空格的字串)

        istringstream cutPoke(poke);    //(istringstream可分割字串)
        vector<string>pokeS;    //pokeS:已切割完的一疊牌內容 (使用vector因不確定牌張數)

        while (getline(cutPoke, onePoke, ' '))  //分割poke (getline(可分割的字串, 切割的结果"逐個"放入字串, 分隔字符))
        {
            pokeS.push_back(onePoke);    //新增切割下的單張牌(onePoke)到 pokeS 字串尾端
        }

        sequencePoke(pokeS, pokeS.size());

        for (int i = 0; i < pokeS.size(); i++)
        {
            if (i == (pokeS.size() - 1)) cout << pokeS[i] << endl;
            else cout << pokeS[i] << " ";
        }
    }
}