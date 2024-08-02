#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct Player
{
	char playerName[20]; // it shows name charecter size
	int numberMatches;
	int numberRuns;
	int numberWickets;
	int jersyNumber;
} Player;
void add(struct Player *, int *);
void display(struct Player *, int);
int search(struct Player *, int);
void manu();
	int size = 6;
void main()
{

	int exit = 1;
	void display();

//		struct Player player[size]; // this array shows how many player you have to
	int numberPlayers = 5; // player incrementation

	Player *player = (Player *)calloc(size, sizeof(Player));
	hard_code(player);
	do
	{
		int choice;
		manu();
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			add(player, &numberPlayers);
			break;
		case 2:
			display(player, numberPlayers);
			break;
		case 3:
			search(player, numberPlayers);
			break;
		case 4:
			sort(player, numberPlayers);
			break;
		case 5:
			update(player, numberPlayers);
			break;
		case 6:
			removePlayer(player, &numberPlayers);
			break;
		case 7:
			printf("successfully Exit");
			exit = 7;
			break;
		default:
			printf("\n");
			printf("*******Invalid Input*******\n");
			printf("\n");
		}
	} while (exit != 7);
}
void manu()
{
	printf("\n1: Add player = ");
	printf("\n2: display = ");
	printf("\n3: search = ");
	printf("\n4: sort = ");
	printf("\n5: update = ");
	printf("\n6: remove = ");
	printf("\n7: Exit");

	printf("\nEnter a choice : ");
}

void add(struct Player *player, int *numberPlayers)
{
	if (*numberPlayers > size)
	{
//		printf("\nIndex out off Bond\n");
		fflush(stdin);
		size++;
		Player *player = (Player *)realloc(player, sizeof(player) * size);
	}
	printf("\nEnter a player name = ");
	fflush(stdin);
	gets(player[*numberPlayers].playerName);
	printf("Enter a NumberMatches = ");
	scanf("%d", &player[*numberPlayers].numberMatches); // struct vaariable name and postion of index and mener of structure
	printf("Enter a Runs = ");
	scanf("%d", &player[*numberPlayers].numberRuns);
	printf("Enter a number of wickets = ");
	scanf("%d", &player[*numberPlayers].numberWickets);
	printf("Enter a player jersey number = ");
	scanf("%d", &player[*numberPlayers].jersyNumber);
	*numberPlayers = *numberPlayers + 1;
	printf("\n***Player Successfully Added***\n");

}
void display(struct Player *player, int numberPlayers)
{
	if (numberPlayers == 0)
	{
		printf("\n***Do Not have a player to show***\n");
	}
	else
	{
		printf("\n+-----------------+-------------------+-------------------+----------------+-------------------+");
		printf("\n|   Player Name   |   Jersey Number   |   Total Matches   |   Total Runs   |   Total Wickets   |");
		printf("\n+-----------------+-------------------+-------------------+----------------+-------------------+");
		for (int i = 0; i < numberPlayers; i++)
		{
			printf("\n|   %-9s     | %9d         | %9d         | %6d         | %9d         |", player[i].playerName, player[i].jersyNumber, player[i].numberMatches, player[i].numberRuns, player[i].numberWickets);
		}
		printf("\n+-----------------+-------------------+-------------------+----------------+-------------------+\n");
	}
}

int search(struct Player *player, int numberPlayers)
{
	int flag = 0;
	int number;
	printf("\n1 for search by name \n2 for search by jersey number = ");
	scanf("%d", &number);
	if (number == 1)
	{
		if (numberPlayers == 0)
		{
			printf("\n***do not have to Player Show***\n");
		}
		else
		{
			char search[100];
			printf("\nEnter a player name = ");
			fflush(stdin);
			gets(search);
			for (int i = 0; i < numberPlayers; i++)
			{
				if (strcasecmp(player[i].playerName, search) == 0)
				{
					flag = 1;
					printf("\n+-----------------+-------------------+-------------------+----------------+-------------------+");
					printf("\n|   Player Name   |   Jersey Number   |   Total Matches   |   Total Runs   |   Total Wickets   |");
					printf("\n+-----------------+-------------------+-------------------+----------------+-------------------+");
					printf("\n|   %-9s     | %9d         | %9d         | %6d         | %9d         |", player[i].playerName, player[i].jersyNumber, player[i].numberMatches, player[i].numberRuns, player[i].numberWickets);

					printf("\n+-----------------+-------------------+-------------------+----------------+-------------------+\n");
					return i;
				}
			}
			if (flag == 0)
			{
				printf("\n***Name does not Found!!***\n");
			}
		}
	}
	else if (number == 2)
	{
		if (numberPlayers == 0)
		{
			printf("\n***Do not have a Player to Show***\n");
		}
		else
		{
			printf("\nEnter a player jersey number = ");
			int gercy;
			scanf("%d", &gercy);
			int i;
			for (i = 0; i < numberPlayers; i++)
			{
				if (player[i].jersyNumber == gercy)
				{
					flag =1;
					printf("\n+-----------------+-------------------+-------------------+----------------+-------------------+");
					printf("\n|   Player Name   |   Jersey Number   |   Total Matches   |   Total Runs   |   Total Wickets   |");
					printf("\n+-----------------+-------------------+-------------------+----------------+-------------------+");
					printf("\n|   %-9s     | %9d         | %9d         | %6d         | %9d         |", player[i].playerName, player[i].jersyNumber, player[i].numberMatches, player[i].numberRuns, player[i].numberWickets);

					printf("\n+-----------------+-------------------+-------------------+----------------+-------------------+\n");
					return i;
				}
			}
			// if (i == numberPlayers)
			if(flag == 0)
			{
				printf("\n***The number does not Found***\n");
			}
		}
	}
	else
	{
		printf("\n***Invalid Inpiut!!***\n");
	}
	return -1;
}
void sort(struct Player *player, int numberPlayers)
{
	if (numberPlayers == 0)
	{
		printf("\n***Do not have a player to sort***\n");
	}
	else
	{

		int flag = 0;
		int check = 0;
		int choice;
		int number;
		printf("\n 1 for sort by runs : \n 2 for sort by Matches  : \n 3 for sort by wickets : \n 4 for sort by jursey number : \n");
		printf("\nEnter a choice = \n");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:

			for (int i = 0; i < numberPlayers; i++)
			{
				for (int j = i + 1; j < numberPlayers; j++)
				{
					if (player[i].numberRuns < player[j].numberRuns)
					{
						struct Player temp = player[i];
						player[i] = player[j];
						player[j] = temp;
					}
				}
			}
			printf("How many players you have to sort = ");
			scanf("%d", &number);
			display(player, number);
			break;
		case 2:
			for (int i = 0; i < numberPlayers; i++)
			{
				for (int j = i + 1; j < numberPlayers; j++)
				{
					if (player[i].numberMatches < player[j].numberMatches)
					{
						struct Player temp = player[i];
						player[i] = player[j];
						player[j] = temp;
					}
				}
			}
			printf("How many players you have to sort = ");
			scanf("%d", &number);
			display(player, number);
			break;
		case 3:
			for (int i = 0; i < numberPlayers; i++)
			{
				for (int j = i + 1; j < numberPlayers; j++)
				{
					if (player[i].numberWickets < player[j].numberWickets)
					{
						struct Player temp = player[i];
						player[i] = player[j];
						player[j] = temp;
					}
				}
			}

			printf("How many players you have to sort = ");
			scanf("%d", &number);
			display(player, number);
			break;
		case 4:
			for (int i = 0; i < numberPlayers; i++)
			{
				for (int j = i + 1; j < numberPlayers; j++)
				{
					if (player[i].jersyNumber < player[j].jersyNumber)
					{
						struct Player temp = player[i];
						player[i] = player[j];
						player[j] = temp;
					}
				}
			}
			printf("How many players you have to sort = ");
			scanf("%d", &number);
			display(player, number);
			break;

		default:
			printf("\n***Please Inter Valid Input!!***\n");
			flag = 1;
			break;
		}
	}
}
void update(struct Player *player, int numberPlayers)
{
	int choice;
	printf("\n***Update a player Information***\n ");
	printf("***The Old Information****");
	int res = search(player, numberPlayers);
	if (numberPlayers != 0)
	{
		if (res != -1)
		{
			printf("\n***Enter a new Information about Player***\n");
			printf("\n 1 for update jersey number : \n 2 for update name :\n 3 for update Runs :\n 4 for Update Number of Matches :\n 5 for update Wickets\n ");

			printf("\nEnter a your choice to update palyer information : ");
			scanf("%d", &choice);
			if (choice == 1)
			{
				printf("Enter a New jersey number : ");
				scanf("%d", &player[res].jersyNumber);
			}
			else if (choice == 2)
			{
				printf("Enter a new name : ");
				fflush(stdin);
				gets(player[res].playerName);
			}
			else if (choice == 3)
			{
				printf("Enter a new runs : ");
				scanf("%d", &player[res].numberRuns);
			}
			else if (choice == 4)
			{
				printf("Enter a number of matches : ");
				scanf("%d", &player[res].numberMatches);
			}
			else if (choice == 5)
			{
				printf("Enter number of wickets : ");
				scanf("%d", &player[res].numberWickets);
			}
			else
			{
				printf("\n***Enter a valid Input!!***\n");
			}

			printf("\n***Successfully Updated new Information***\n");
		}
	}
	else
	{
		printf("\n***Player does not match***\n");
	}
}
void removePlayer(struct Player *player, int *numberPlayers)
{
	printf("\n****Current Information****\n");
	int index = search(player, *numberPlayers);
	if (index != -1)
	{
		for (int i = index; i < *numberPlayers; i++)
		{
			player[i] = player[i + 1];
		}
		*numberPlayers = *numberPlayers - 1;
		printf("\n****The player remove Successfully***\n");
	}
}

void hard_code(struct Player *player)
{
	player[0].jersyNumber = 77;
	player[0].numberMatches = 10;
	player[0].numberWickets = 55;
	player[0].numberRuns = 22;
	strcpy(player[0].playerName, "Asjad");

	player[1].jersyNumber = 88;
	player[1].numberMatches = 11;
	player[1].numberWickets = 44;
	player[1].numberRuns = 30;
	strcpy(player[1].playerName, "Raza");

	player[2].jersyNumber = 22;
	player[2].numberMatches = 17;
	player[2].numberWickets = 12;
	player[2].numberRuns = 20;
	strcpy(player[2].playerName, "Ansari");

	player[3].jersyNumber = 11;
	player[3].numberMatches = 3;
	player[3].numberWickets = 2;
	player[3].numberRuns = 4;
	strcpy(player[3].playerName, "Rohit");

	player[4].jersyNumber = 66;
	player[4].numberMatches = 2;
	player[4].numberWickets = 7;
	player[4].numberRuns = 3;
	strcpy(player[4].playerName, "Shubam");
}
