#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int LIS(vector<int>& a) {
        vector<int>tmp(a.size());
        if(a.size()==0)return 0;//空返回0；
        tmp[0]=a[0];//首先明白，tmp数组里面的数字一定是升序排列的。
        int end=0;  //end表示数组有效长度的尾部。后边你就知道end+1就是最大长度
        for(int i=1;i<a.size();i++)
        {
            if(a[i]>tmp[end])  //因为a[0]已经放进数组了，所以从1开始判断a里面的每一数
                tmp[++end]=a[i];//如果比当前数组的最尾数组还大，则直接加入进数组
            else//否则
            {
                int left=0,right=end;
           while(left<right)//使用二分来更新tmp数组里的数字(最好的理解办法带入一个用例来自己推)
                {
                    int mid=(right+left)/2;
                    if(tmp[mid]<a[i])left=mid+1;
                    else right=mid;
                }//你会发现如果第一个数超级大，那么它会被替换成较小的那个数字。
                cout << "i is " << i << endl;
				cout << "left is " << left << endl;
                tmp[left]=a[i];//这是二分的一个技巧，循环结束后的left一定是你需要的位置。	
				cout << "the array is " ;
				for (auto val : tmp) {
					cout << val << " ";
				}	
                cout << endl;
            }
        }
        return end+1;
    }
};

int main() 
{
	Solution s;
	vector<int> vec = {6,3,1,5,2,3,7};
	cout << s.LIS(vec) << endl;
}
