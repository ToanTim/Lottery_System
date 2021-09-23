#include<iostream>
#include<string>
#include<ctime>


using namespace std;
/* ==========                  note                   ===============*/

// name_number : 7 numbers
// name_number2: 3 bonus numbers

			   /* ==========                  note                   ===============*/


int random_number()
{
	return rand() % 39 + 1;
}
void order_max_to_min(int order_1[], int order_2[])
{
	int integer;

	//7 numbers order_max_to_min
	for (int i = 0; i < 6; i++)
	{
		for (int j = i + 1; j < 7; j++)
		{
			if (order_1[i] < order_1[j])
			{
				integer = order_1[i];
				order_1[i] = order_1[j];
				order_1[j] = integer;
			}
		}
	}

	int integer2;

	//3 bonus numbers order_max_to_min
	for (int i = 0; i < 2; i++)
	{
		for (int j = i + 1; j < 3; j++)
		{
			if (order_2[i] < order_2[j])
			{
				integer2 = order_2[i];
				order_2[i] = order_2[j];
				order_2[j] = integer2;
			}
		}
	}


}
bool check_function(int arrayNumber[], int findNumber)
{
	for (int i = 0; i < 6; i++)
	{
		if (arrayNumber[i] == findNumber)
		{
			return true;
		}
	}
	return false;
}
void draw_numbers(int array_number[], int array_bonus_number[])
{
	//7 numbers
	int i = 0;
	while (i < 7)
	{
		int randomNumber = random_number();
		if (check_function(array_number, randomNumber) == false)
		{
			array_number[i] = randomNumber;
			i = i + 1;
		}
	}

	//3 bonus numbers
	i = 0;
	while (i < 3) {
		int randomNumber = random_number();
		if (check_function(array_bonus_number, randomNumber) == false) {
			array_bonus_number[i] = randomNumber;
			i = i + 1;
		}
	}
}
void cout_bonus_number(int bonus_number[])
{

	for (int a = 0; a < 3; a++)
	{
		cout << bonus_number[a] << " ";
	}
	cout << endl;
}
void cout_number(int number[])
{

	for (int a = 0; a < 7; a++)
	{
		cout << number[a] << " ";
	}
	cout << endl;
}
struct user_infor
{
	string sex, name, address, bank, card_number;
};
user_infor create_user()
{
	user_infor information;
	cout << "How can we call you (Mr , Mrs ,Madam ,Sir) : ";
	getline(cin, information.sex);
	cout << "Pls enter your name : ";
	getline(cin, information.name);
	cout << "pls enter your bank account : ";
	getline(cin, information.card_number);
	cout << "Pls enter your bank's name : ";
	getline(cin, information.bank);

	return information;
}
void check_prize()
{
	srand(static_cast<unsigned int>(time(NULL)));
	user_infor information;
	information = create_user();

	const int array_size1 = 7;
	const int array_size2 = 3;
	int you_number[array_size1];
	int you_number2[array_size2];

	const int lottery_number_size = 7;
	const int lottery_bonus_number_size = 3;
	int lottery_number[lottery_number_size];
	int lottery_number2[lottery_bonus_number_size];

	draw_numbers(you_number, you_number2);
	draw_numbers(lottery_number, lottery_number2);

	order_max_to_min(you_number, you_number2);
	order_max_to_min(lottery_number, lottery_number2);




	cout << "your seven number are           : ";
	cout_number(you_number);



	cout << "your three bonus numbers are    : ";
	cout_bonus_number(you_number2);



	cout << "Lottery seven number are        : ";
	cout_number(lottery_number);



	cout << "Lottery three bonus numbers are : ";
	cout_bonus_number(lottery_number2);


	int a = 0, b = 0, c = 0, d = 0;
	int compare = 0, compare2 = 0;

	for (a = 0; a < 6; a++)
	{
		for (b = 0; b < 6; b++)
		{
			if (you_number[a] == lottery_number[b])
			{
				++compare;
			}
		}

	}

	for (c = 0; c < 3; c++)
	{
		for (d = 0; d < 3; d++)
		{
			if (you_number2[c] == lottery_number2[d])
			{
				++compare2;
			}
		}

	}

	cout << "you got : " << compare << " + " << compare2 << endl;

	if (compare == 7)
	{
		cout << "CONGRATULATIONS " << information.sex << " " << information.name << " ========>>you have won     JACKPOT prize    <<=========" << endl;
		cout << "5 000 000 000 euro will be sent to your bank account which is : " << information.card_number << " before 23.59 today" << endl;
		cout << " ========>>  thank you for using TOAN TRAN's lottery system   <<=========" << endl;
		cout << "    ========>>       your smile is our success       <<=========" << endl;
	}
	else if (compare == 6)
	{
		cout << "CONGRATULATIONS " << information.sex << " " << information.name << " ========>>you have won     2rd prize    <<=========" << endl;
		cout << "1 000 000 000 euro will be sent to your bank account which is : " << information.card_number << " before 23.59 today" << endl;
		cout << "thank you for using TOAN TRAN's lottery system" << endl;
		cout << "your smile is our success" << endl;
	}
	else if (compare == 5 && compare2 == 2)
	{
		cout << "CONGRATULATIONS " << information.sex << " " << information.name << " ========>>you have won     3th prize    <<=========" << endl;
		cout << "500 000 euro will be sent to your bank account which is : " << information.card_number << " before 23.59  today" << endl;
		cout << " ========>>  thank you for using TOAN TRAN's lottery system   <<=========" << endl;
		cout << "    ========>>       your smile is our success       <<=========" << endl;
	}
	else if (compare == 5 && compare2 == 2)
	{
		cout << "CONGRATULATIONS " << information.sex << " " << information.name << " ========>>you have won     3th prize    <<=========" << endl;
		cout << "100 000 euro will be sent to your bank account which is : " << information.card_number << " before 23.59  today" << endl;
		cout << " ========>>  thank you for using TOAN TRAN's lottery system   <<=========" << endl;
		cout << "    ========>>       your smile is our success       <<=========" << endl;
	}
	else if (compare == 5)
	{
		cout << "CONGRATULATIONS " << information.sex << " " << information.name << " ========>>you have won     3th prize    <<=========" << endl;
		cout << "10 000 euro will be sent to your bank account which is : " << information.card_number << " before 23.59  today" << endl;
		cout << " ========>>  thank you for using TOAN TRAN's lottery system   <<=========" << endl;
		cout << "    ========>>       your smile is our success       <<=========" << endl;
	}
	else if (compare == 4 && compare2 == 1)
	{
		cout << "CONGRATULATIONS " << information.sex << " " << information.name << " ========>>you have won     4th prize    <<=========" << endl;
		cout << "1 000 euro will be sent to your bank account which is : " << information.card_number << " before 23.59 today" << endl;
		cout << " ========>>  thank you for using TOAN TRAN's lottery system   <<=========" << endl;
		cout << "    ========>>       your smile is our success       <<=========" << endl;
	}
	else if (compare == 3 && compare2 == 2)
	{
		cout << "CONGRATULATIONS " << information.sex << " " << information.name << " ========>>you have won     5th prize    <<=========" << endl;
		cout << "100 euro will be sent to your bank account which is : " << information.card_number << " before 23.59 today" << endl;
		cout << " ========>>  thank you for using TOAN TRAN's lottery system   <<=========" << endl;
		cout << "    ========>>       your smile is our success       <<=========" << endl;
	}
	else if (compare == 3 && compare2 == 1)
	{
		cout << "CONGRATULATIONS " << information.sex << " " << information.name << " ========>>you have won     6th prize    <<=========" << endl;
		cout << "50 euro will be sent to your bank account which is : " << information.card_number << " before 23.59 today" << endl;
		cout << " ========>>  thank you for using TOAN TRAN's lottery system   <<=========" << endl;
		cout << "    ========>>       your smile is our success       <<=========" << endl;
	}
	else if (compare == 2 && compare2 == 2)
	{
		cout << "CONGRATULATIONS " << information.sex << " " << information.name << " ========>>you have won     7th prize    <<=========" << endl;
		cout << "10 euro will be sent to your bank account which is : " << information.card_number << " before 23.59 today" << endl;
		cout << " ========>>  thank you for using TOAN TRAN's lottery system   <<=========" << endl;
		cout << "    ========>>       your smile is our success       <<=========" << endl;
	}
	else if (compare == 2 && compare2 == 0)
	{
		cout << "CONGRATULATIONS " << information.sex << " " << information.name << " ========>>you have won     8th prize    <<=========" << endl;
		cout << "5 euro will be sent to your bank account which is : " << information.card_number << " before 23.59 today" << endl;
		cout << " ========>>  thank you for using TOAN TRAN's lottery system   <<=========" << endl;
		cout << "    ========>>       your smile is our success       <<=========" << endl;
	}
	else if (compare == 1 && compare2 == 1)
	{
		cout << "CONGRATULATIONS " << information.sex << " " << information.name << " ========>>you have won     9th prize    <<=========" << endl;
		cout << "3 euro will be sent to your bank account which is : " << information.card_number << " before 23.59 today" << endl;
		cout << " ========>>  thank you for using TOAN TRAN's lottery system   <<=========" << endl;
		cout << "    ========>>       your smile is our success       <<=========" << endl;
	}
	else if (compare == 1 && compare2 == 0)
	{
		cout << "CONGRATULATIONS " << information.sex << " " << information.name << " ========>>you have won     10th prize    <<=========" << endl;
		cout << "2 euro will be sent to your bank account which is : " << information.card_number << " before 23.59 today" << endl;
		cout << " ========>>  thank you for using TOAN TRAN's lottery system   <<=========" << endl;
		cout << "    ========>>       your smile is our success       <<=========" << endl;
	}
	else
	{
		cout << "=========>>   unfortunately this time is not your lucky time <<========" << endl;
		cout << "But don't feel sad =(((. you still have a lot of chances in the future" << endl;
		cout << " ========>>  thank you for using TOAN TRAN's lottery system   <<=========" << endl;
		cout << "    ========>>       your smile is our success       <<=========" << endl;
	}

}
