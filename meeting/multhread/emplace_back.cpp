#include <vector>
#include <map>
#include <string>
#include <iostream>
using namespace std;


struct President  
{  
    std::string name;  
    std::string country;  
    int year;  

    President(std::string p_name, std::string p_country, int p_year)  
        : name(std::move(p_name)), country(std::move(p_country)), year(p_year)  
    {  
        cout << "    Construction\n";  
    }
    President(const President& other)
        : name(std::move(other.name)), country(std::move(other.country)), year(other.year)
    {
        cout << "    Copy Construction\n";
    }
    President(President&& other)  
        : name(std::move(other.name)), country(std::move(other.country)), year(other.year)  
    {  
        cout << "    Move Construction\n";  
    }
};  

int main()  
{
    cout << "emplace_back to vector:\n"; 
    vector<President> v1;
    President p("hello", "world", 15);
    v1.emplace_back(std::move(p)); 
    
    cout << "\npush_back to vector (way-1 - right value reference as parameter):\n";
    vector<President> v2;
    v2.push_back(President("Nelson Mandela", "South Africa", 1994));
    
    cout << "\npush_back to vector (way-2 - left value as parameter):\n";
    vector<President> v3;
    President p1("Nelson Mandela", "South Africa", 1994);
    v3.push_back(p1);
    
    cout << "\ninsert into map: \n";
    map<int, President> m1;
    m1.insert(make_pair<int, President>(10, President("Nelson Mandela", "South Africa", 1994)));
    
    cout << "\nemplace into map: \n";
    map<int, President> m2;
    m2.emplace(10, President("Nelson Mandela", "South Africa", 1994));
    
    return 0;
}


