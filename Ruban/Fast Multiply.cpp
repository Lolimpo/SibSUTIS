#include<bits/stdc++.h> 
using namespace std; 
#define max(a,b) ((a) > (b) ? (a) : (b))
int O = 0;

string add(string lhs, string rhs) 
{
    int length = max(lhs.size(), rhs.size());
    int carry = 0;
    int sum_col;
    string result;
    while (lhs.size() < length) 
      lhs.insert(0,"0");
            
    while (rhs.size() < length) 
      rhs.insert(0,"0");

    for (int i = length - 1; i >= 0; i--) 
    {
        O++;
        sum_col = (lhs[i]-'0') + (rhs[i]-'0') + carry;
        carry = sum_col/10;
        result.insert(0,to_string(sum_col % 10));
    }
    
    if (carry)
        result.insert(0,to_string(carry));
    
    return result.erase(0, min(result.find_first_not_of('0'), result.size()-1));
}

string subtract(string lhs, string rhs) 
{
    int length = max(lhs.size(), rhs.size());
    int diff;
    string result;

    while (lhs.size() < length) 
      lhs.insert(0,"0");
            
    while (rhs.size() < length) 
      rhs.insert(0,"0");

    for (int i = length-1; i >= 0; i--) 
    {
        diff = (lhs[i]-'0') - (rhs[i]-'0');
        if (diff >= 0)
            result.insert(0, to_string(diff));
        else 
        {
            int j = i - 1;
            while (j >= 0) 
            {
                lhs[j] = ((lhs[j]-'0') - 1) % 10 + '0';
                O--;
                if (lhs[j] != '9') 
                    break;
                else 
                    j--;
            }
            result.insert(0, to_string(diff+10));
        }
      
    }
    return result.erase(0, min(result.find_first_not_of('0'), result.size()-1));
}

string multiply1(string lhs, string rhs) 
{
    int length = max(lhs.size(), rhs.size());
    while (lhs.size() < length) 
      lhs.insert(0,"0");

    while (rhs.size() < length) 
      rhs.insert(0,"0");

    if (length == 1)
        return to_string((lhs[0]-'0')*(rhs[0]-'0'));

    string lhs0 = lhs.substr(0,length/2);
    string lhs1 = lhs.substr(length/2,length-length/2);
    string rhs0 = rhs.substr(0,length/2);
    string rhs1 = rhs.substr(length/2,length-length/2);
    
    string p0 = multiply1(lhs0,rhs0);
    string p1 = multiply1(lhs1,rhs1);
    string p2 = multiply1(add(lhs0,lhs1),add(rhs0,rhs1));
    string p3 = subtract(p2,add(p0,p1));

    for (int i = 0; i < 2*(length-length/2); i++)
        p0.append("0");
    for (int i = 0; i < length-length/2; i++)
        p3.append("0");
        
    string result = add(add(p0,p1),p3);
    O++;

    return result.erase(0, min(result.find_first_not_of('0'), result.size()-1));
}

string multiply(string num1, string num2) 
{ 
    int len1 = num1.size(); 
    int len2 = num2.size(); 
    if (len1 == 0 || len2 == 0) 
    return "0"; 

    vector<int> result(len1 + len2, 0); 

    int i_n1 = 0;  
    int i_n2 = 0;  

    for (int i=len1-1; i>=0; i--) 
    { 
        int carry = 0; 
        int n1 = num1[i] - '0'; 
        i_n2 = 0;       
        for (int j=len2-1; j>=0; j--) 
        { 
            int n2 = num2[j] - '0'; 
            int sum = n1*n2 + result[i_n1 + i_n2] + carry; 
            carry = sum/10; 
            O += 2;
            result[i_n1 + i_n2] = sum % 10; 
  
            i_n2++; 
        } 
  
        if (carry > 0) 
        {
            result[i_n1 + i_n2] += carry; 
            O++;
        }
            

        i_n1++; 
    } 
  
    int i = result.size() - 1; 
    while (i>=0 && result[i] == 0) 
        i--; 

    if (i == -1) 
        return "0"; 

    string s = ""; 
      
    while (i >= 0) 
        s += std::to_string(result[i--]); 
  
    return s; 
} 

int diff(string str1, string str2)
{
    int temp1 = 0, temp2 = 0;
    for(int i = 0; i < str1.size(); i++)
        if(str1[i] != '0')
            temp1++;
    for(int i = 0; i < str2.size(); i++)
        if(str2[i] != '0')
            temp2++;
    return (temp1 * temp2) + temp2 - 1;
}

int main() 
{ 
    string str1, str2;
    //string str1 = "1235421415454545454545454544"; 
    //string str2 = "1714546546546545454544548544544545"; 
    cout << "Enter num1: "; cin >> str1;
    cout << "Enter num2: "; cin >> str2;
    if((str1.at(0) == '-' || str2.at(0) == '-') &&  
        (str1.at(0) != '-' || str2.at(0) != '-' )) 
        cout<<"-"; 
  
  
    if(str1.at(0) == '-' && str2.at(0)!='-') 
    { 
        str1 = str1.substr(1); 
    } 
    else if(str1.at(0) != '-' && str2.at(0) == '-') 
    { 
        str2 = str2.substr(1); 
    } 
    else if(str1.at(0) == '-' && str2.at(0) == '-') 
    { 
        str1 = str1.substr(1); 
        str2 = str2.substr(1); 
    } 

    cout << "Column multiply result: " << multiply(str1, str2) << endl; 
    cout << "Difficulty: " << diff(str1, str2) << endl; O = 0;
    cout << "Fast multiply result: " << multiply1(str1, str2) << endl;
    cout << "Difficulty: " << ceil(pow(str1.size(), log2(3))) << endl;
    return 0; 
} 