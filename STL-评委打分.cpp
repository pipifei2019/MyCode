#include<iostream>
using namespace std;
#include<vector>
#include<string>
#include<deque>
#include<algorithm>


class Person
{
public:
	Person(string name, int score)
	{
		this->m_Name = name;
		this->m_Score = score;
	}

	string m_Name;
	int m_Score;
};

void createPerson(vector<Person>&v)
{
	string nameSeed = "ABCDE";
	for (int i = 0; i < 5; i++)
	{
		string name = "选手";
		name += nameSeed[i];
		int score = 0;
		Person p(name, score);

		v.push_back(p);
	}

}

void setScore(vector<Person>&v)
{
	deque<int>d;
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	{
		for (int i = 0; i < 10; i++)
		{
			int score = rand() % 41 + 60;
			d.push_back(score);
		}
		sort(d.begin(), d.end());
		d.pop_back();
		d.pop_front();
		int sum = 0;
		for (deque<int>::iterator dit = d.begin(); dit != d.end(); dit++)
		{
			sum += *dit;
		}
		int avg = sum / d.size();
		it->m_Score = avg;
		
	}
}

void showScore(vector<Person>& v)
{
	for (int i = 0; i < v.size(); i++)
	{
		cout  << v[i].m_Name << "  得分：" << v[i].m_Score << endl;

	}
}
int main()
{
	vector<Person>v;
	createPerson(v);
	/*for (int i = 0; i < v.size(); i++)
	{
		cout << "姓名：" << v[i].m_Name << " 分数：" << v[i].m_Score << endl;
	}*/

	setScore(v);

	showScore(v);




	return 0;
}