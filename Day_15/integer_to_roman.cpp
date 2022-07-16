#include<map>
string IntToroman(int num) {
    // Write your code here
    string roman = "";
    map<int,string>mpp;
    mpp[1] = "I";
    mpp[4] = "IV";
    mpp[5] = "V";
    mpp[9] = "IX";
    mpp[10] = "X";
    mpp[40] = "XL";
    mpp[50] = "L";
    mpp[90] = "XC";
    mpp[100] = "C";
    mpp[400] = "CD";
    mpp[500] = "D";
    mpp[900] = "CM";
    mpp[1000] = "M";
    while(num)
    {
        int x = 0;
        for(auto it:mpp)
        {
            if(num/it.first!=0) x = it.first;
            else break;
        }
        for(int i=0;i<num/x;i++)
            roman += mpp[x];
        num %= x;
    }
    return roman;
}