#include <iostream>

using namespace std;

struct Human
{
	int Hungry; //배고픔 
	int Fatigue; //피로도

};


class YDProgrammer
{
	Human Humanstate;
	float ThinkingPower; //사고력
	float Application; //응용력
	float CodingKnowledge; //지식




public:


	void Character()
	{
		srand(time(NULL)); //랜덤 적용
		Humanstate.Hungry = 100;
		Humanstate.Fatigue = 0;
		ThinkingPower = rand() % 4 + 1; //1~4의 랜덤 스텟
		Application = rand() % 4 + 1; //1~4의 랜덤 스텟
		CodingKnowledge = rand() % 4 + 1; //1~4의 랜덤 스텟
	}

	void Sleep(int hour) // 자기
	{

		system("cls");
		Humanstate.Fatigue -= hour * 10;

		cout << hour << "시간의 수면으로 인해 피로도가 " << hour * 10 << "만큼 줄었습니다." << endl;

		if (Humanstate.Fatigue < 0)
			Humanstate.Fatigue = 0;

	}


	void Eat() // 먹기
	{
		system("cls");
		srand(time(NULL));
		int percentage = rand() % 30 + 51; // 랜덤으로 50~80만큼 배가 안고파짐
		Humanstate.Hungry += percentage;
	}

	void TakeClass() // 수업듣기
	{
		system("cls");
		const int hour = 9;
		srand(time(NULL));
		int percentage = rand() % 100 + 1;
		//50의 확률로 초 수준 30의 확률로 중수준 20의 확률로 고 수준
		if (1 <= percentage < 50)
		{
			cout << "초 수준의 수업으로 코딩지식 1이 늘었습니다" << endl;
			CodingKnowledge += 1;


		}


		else if (50 <= percentage < 80)
		{
			cout << "중 수준의 수업으로 코딩지식 2, 사고력 1, 응용력 1이 늘었습니다" << endl;
			CodingKnowledge += 2;
			ThinkingPower += 1;
			Application += 1;
		}

		else
		{
			cout << "고 수준의 수업으로 코딩지식 3, 사고력 2, 응용력 1이 늘었습니다" << endl;
			CodingKnowledge += 3;
			ThinkingPower += 2;
			Application += 1;
		}

		cout << "9시간의 수업으로 피로도 50 늘고, 배고픔 60, 이 줄었습니다." << endl;

		Humanstate.Hungry -= 60;
		Humanstate.Fatigue += 50;

		if (Humanstate.Fatigue >= 100 || Humanstate.Hungry < 0)
			cout << "Humanstate.Fatigue = " << Humanstate.Fatigue << "Humanstate.Hungry = " << Humanstate.Hungry << "으로 인해 캐릭터 사망" << endl;

	}

	void preparation(int hour) // 자습
	{
		system("cls");
		Humanstate.Fatigue += 7 * hour;
		Humanstate.Hungry -= 5 * hour;


		cout << "자습으로 인해 코딩지식 " << 0.3 * hour << " 사고력 " << 0.2 * hour << " 응용력 " << 0.2 * hour << " 만큼 상승했습니다." << endl;

		cout << hour << " 시간의 수업으로 피로도가 " << 7 * hour << " 늘고, 배고픔이 " << 5 * hour << " 줄었습니다." << endl;
		if (Humanstate.Fatigue >= 100 || Humanstate.Hungry < 0)
			cout << "Humanstate.Fatigue = " << Humanstate.Fatigue << "Humanstate.Hungry = " << Humanstate.Hungry << "으로 인해 캐릭터 사망" << endl;
	}


	void Programmers() // 프로그래머스 풀기
	{
		system("cls");

		srand(time(NULL));
		int percentage = rand() % 100 + 1;
		//확률에 따른 레벨수준과 시간
		if (1 <= percentage < 20)
		{
			cout << "LV3의 문제를 5시간 동안 풀어 사고력 3 응용력 3이 늘었습니다" << endl;
			ThinkingPower += 3;
			Application += 3;


			Humanstate.Fatigue += 7 * 5;
			Humanstate.Hungry -= 5 * 5;
			cout << "5시간의 수업으로 피로도가 " << 7 * 5 << " 늘고, 배고픔이 " << 5 * 5 << " 줄었습니다." << endl;
		}


		else if (20 <= percentage < 60)
		{
			cout << "LV2의 문제를 3시간 동안 풀어 사고력 1 응용력 1이 늘었습니다" << endl;
			ThinkingPower += 1;
			Application += 1;


			Humanstate.Fatigue += 7 * 3;
			Humanstate.Hungry -= 5 * 3;
			cout << "3시간의 수업으로 피로도가 " << 7 * 3 << " 늘고, 배고픔이 " << 5 * 3 << " 줄었습니다." << endl;
		}

		else
		{
			cout << "LV1의 문제를 1시간 동안 풀어 사고력 0.5 응용력 0.5이 늘었습니다" << endl;
			ThinkingPower += 0.5;
			Application += 0.5;


			Humanstate.Fatigue += 7 * 1;
			Humanstate.Hungry -= 5 * 1;
			cout << "1시간의 수업으로 피로도가 " << 7 * 1 << " 늘고, 배고픔이 " << 5 * 1 << " 줄었습니다." << endl;
		}


		if (Humanstate.Fatigue >= 100 || Humanstate.Hungry < 0)
			cout << "Humanstate.Fatigue = " << Humanstate.Fatigue << "Humanstate.Hungry = " << Humanstate.Hungry << "으로 인해 캐릭터 사망" << endl;

	}

	void ViewState() //상태창 보기
	{
		system("cls");
		cout << "Humanstate.Hungry = " << Humanstate.Hungry << endl;
		cout << "Humanstate.Fatigue = " << Humanstate.Fatigue << endl;
		cout << "ThinkingPower = " << ThinkingPower << endl;
		cout << "Application = " << Application << endl;
		cout << "CodingKnowledge = " << CodingKnowledge << endl;
	}



};

int main()
{

	YDProgrammer Dongchan;
	Dongchan.Character();


	Dongchan.TakeClass();
	Dongchan.Eat();
	Dongchan.preparation(3);
	Dongchan.Programmers();
	Dongchan.Sleep(6);
	Dongchan.ViewState();


}