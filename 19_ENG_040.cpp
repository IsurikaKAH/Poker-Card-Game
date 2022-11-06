/*--------------------------------------
Name: Isurika K.A.H.
Index No.: 19/ENG/040
Assignment No.: 04
-------------------------------------*/


#include<iostream>
#include<vector>
#include<string>
#include<ctime> 	
#include<cstdlib>   
#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;

//-----There are only three players---------

//defining variables for noumber of rounds for one game, nomber of cards in the deck, points for each player
int NoOfRounds=5;
const int deckcards = 52;
static int m1=0,m2=0,m3=0;

//Defining functions
void StoreData();
void givepoints(int r1, int r2, int r3);
int sortcards(vector<int>v, vector<string>s);
void checkwinner(int n1, int n2, int n3);


/*---------------------------------------------------
Function : convert
Description : convert card face to an integer
input parameters : 
		s - card face

output : card number as an integer
--------------------------------------------------*/

int convert(char s)
{
	switch(s)
	{
		case 'A':{return 1;
			break;
		}
		case '2':{return 2;
			break;
		}
		case '3':{return 3;
			break;
		}
		case '4':{return 4;
			break;
		}
		case '5':{return 5;
			break;
		}
		case '6':{return 6;
			break;
		}
		case '7':{return 7;
			break;
		}
		case '8':{return 8;
			break;
		}
		case '9':{return 9;
			break;
		}
		case 'T':{return 10;
			break;
		}
		case 'J':{return 11;
			break;
		}
		case 'Q':{return 12;
			break;
		}
		case 'K':{return 13;
			break;
		}
	}
}

//create class Card
class Card{
	public:
		Card(char cardFace, string cardSuit);
		void print();
		Card();
		char face;
		string suit;
};

//constructor
Card::Card(){}

/*---------------------------------------------------
Function : Card
Description : assign card face and suit to variables
input parameters : 
		cardFace - card face
		cardSuit - suit of the card

--------------------------------------------------*/
Card::Card(char cardFace, string cardSuit)
{
	face = cardFace;
	suit = cardSuit;
}


/*---------------------------------------------------
Function : print
Description : print the cards
input parameters : none
output : none
--------------------------------------------------*/
void Card::print()
{
	cout<<face<<" of "<<suit;
}
 
 
//create class Deck
class Deck: public Card{
 	public:
 		Deck();
 		void shuffle();
 		void printDeck();
 		void distribute(vector<int>P1_no,vector<int>P2_no,vector<int>P3_no,vector<int>D_no,vector<string>P1_suit,vector<string>P2_suit,vector<string>P3_suit,vector<string>D_suit);
 	
 	private:
 		Card *deck;
		 
};
 
/*---------------------------------------------------
Function : printDeck
Description : print the deck of cards
input parameters : none
output : none
--------------------------------------------------*/
void Deck::printDeck()
{
	for(int i=0; i<deckcards; i++)
	{
		deck[i].print();
		cout<<endl;
	}
}


/*---------------------------------------------------
Function : Deck
Description : create a new deck of cards
input parameters : none
--------------------------------------------------*/
Deck::Deck()
{
	char faces[] ={'A','2','3','4','5','6','7','8','9','T','J','Q','K'};
	string suits[] = {"Hearts","Diamonds","Clubs","Spades"};
	deck = new Card[deckcards];
	for(int count=0; count<deckcards; count++)
	{
		deck[count] = Card(faces[count%13], suits[count/13]);
	}
}


/*---------------------------------------------------
Function : shuffle
Description : shuffle card deck
input parameters : none
output : none
--------------------------------------------------*/
void Deck::shuffle()
{
	for(int x =0; x<deckcards; x++)
	{
		int y = (rand() + time(0))%deckcards;
		Card temp;
		
		//swap cards
		temp = deck[x];
		deck[x] = deck[y];
		deck[y] = temp;
	}
}


/*---------------------------------------------------
Function : withdraw
Description : Ask user whether user want to withdraw or not
input parameters : none
output : true if user do not want to withdraw, false fi user want to withdraw
--------------------------------------------------*/
bool withdraw()
{
	int input;
	cout<<"Do you want to withdraw (1-yes, 0-no): ";
	cin>>input;
	
	if(input==1)
	{
		return false;
	}
	else if(input==0)
	{
		return true;
	}
	else
	{
		cout<<"wrong input!!!\n";
		withdraw();
	}
}


/*---------------------------------------------------
Function : distribute
Description : Distribute cards
input parameters : 
	P1_no - integer vector of player 01 card faces
	P2_no - integer vector of player 02 card faces
	P3_no - integer vector of player 03 card faces
	D_no - integer vector of Dealer card faces
	P1_suit - string vector of player 01 card suits
	P2_suit - string vector of player 02 card suits
	P3_suit - string vector of player 03 card suits
	D_suit - string vector of Dealer card suits
output : none
--------------------------------------------------*/
void Deck::distribute(vector<int>P1_no,vector<int>P2_no,vector<int>P3_no,vector<int>D_no,vector<string>P1_suit,vector<string>P2_suit,vector<string>P3_suit,vector<string>D_suit)
{
	int r1,r2,r3,r4;
	cout<<"\nPlayer 1 cards: \n";
	for(int i=2; i<7; i++)		//distribute player 01 cards and store it in vector
	{
		int num = convert(deck[i].face);
		P1_no.push_back(num);
		P1_suit.push_back(deck[i].suit);
		deck[i].print();
		cout<<endl;
	}
	if(withdraw())	//ckeck if player want to withdraw
	{
		r1 = sortcards(P1_no,P1_suit);
	}
	
	
	cout<<"\nPlayer 2 cards: \n";	//distribute player 02 cards and store it in vector
	for(int i=7; i<12; i++)
	{
		int num = convert(deck[i].face);
		P2_no.push_back(num);
		P2_suit.push_back(deck[i].suit);
		deck[i].print();
		cout<<endl;
	}
	if(withdraw())
	{
		r2 =sortcards(P2_no,P2_suit);
	}
	
	
	cout<<"\nPlayer 3 cards: \n";		//distribute player 03 cards and store it in vector
	for(int i=12; i<17; i++)
	{
		int num = convert(deck[i].face);
		P3_no.push_back(num);
		P3_suit.push_back(deck[i].suit);
		deck[i].print();
		cout<<endl;
	}
	if(withdraw())
	{
		r3 =sortcards(P3_no,P3_suit);
	}
	
	
	cout<<"\nDealer cards: \n";		//distribute dealer cards and store it in vector
	for(int i=17; i<22; i++)
	{
		int num = convert(deck[i].face);
		D_no.push_back(num);
		D_suit.push_back(deck[i].suit);
		deck[i].print();
		cout<<endl;
	}
	r4 =sortcards(D_no,D_suit);
	
	givepoints(r1, r2, r3);			//give points to players
	checkwinner(m1,m2,m3);			//check for the winner in each round	
}


/*---------------------------------------------------
Function : checkhighcard
Description : check if player has a highcard
input parameters : 
	v - card faces player has
	s - card suits player has
output : none
--------------------------------------------------*/
void checkhighcard(vector<int>v, vector<string>s)
{
	cout<<"High card!!!"<<endl;
}

/*---------------------------------------------------
Function : checkOnepair
Description : check if player has a pair
input parameters : 
	v - card faces player has
output : true if player has one pair
--------------------------------------------------*/
bool checkOnepair(vector<int>v)
{
	if((v[0]==v[1]) || (v[1]==v[2]) || (v[2]==v[3]) || (v[3]==v[4]))
	{
		
		return true;
	}	
	else
	{
		return false;
	}
}


/*---------------------------------------------------
Function : checkTwopairs
Description : check if player has two pairs
input parameters : 
	v - card faces player has
output : true if player has two pairs
--------------------------------------------------*/
bool checkTwopairs(vector<int>v)
{
	if((v[0]==v[1]) && (v[2]==v[3]))
	{
		return true;
	}
	
	else if((v[0]==v[1]) && (v[3]==v[4]))
	{
		return true;
	}
	
	else if((v[1]==v[2]) && (v[3]==v[4]))
	{
		return true;
	}
	else
	{
		return false;
	}
}


/*---------------------------------------------------
Function : checkThreeofakind
Description : check if player has three of a kind
input parameters : 
	v - card faces player has
output : true if player has three of a kind
--------------------------------------------------*/
bool checkThreeofakind(vector<int>v)
{
	if((v[0]==v[1]) && v[1]==v[2])
	{
		return true;
	}
	
	else if((v[1]==v[2]) && v[2]==v[3])
	{
		return true;
	}
	
	else if((v[2]==v[3]) && v[3]==v[4])
	{
		return true;
	}
	else
	{
		return false;
	}
}


/*---------------------------------------------------
Function : checkstriaght
Description : check if player has a straight
input parameters : 
	v - card faces player has
output : true if player has a straight
--------------------------------------------------*/
bool checkstriaght(vector<int>v)
{
	for(int i=0; i<5; i++)
	{
		if((v[i])==v[i+1]-1)
		{
			return true;
		}

		else if((v[0]==10) && (v[1]==11) && (v[2]==12) && (v[3]==13) && (v[4]==1))
		{
			return true;
		}
		
		else
		{
			return false;
		}
	}
}


/*---------------------------------------------------
Function : checkFlush
Description : check if player has a flush
input parameters : 
	v - card suits player has
output : true if player has a flush
--------------------------------------------------*/
bool checkFlush(vector<string>v)
{
	int count1 =0;
	int count2 =0;
	for(int i=0; i<5; i++)
	{
		if(v[i] == "Hearts" || v[i] == "Diamonds")
		{
			count1++;
		}
	}
	
	for(int i=0; i<5; i++)
	{
		if(v[i] == "Clubs" || v[i] == "Spades")
		{
			count2++;
		}
	}
	
	
	if((count1==5) || (count2==5))
	{
		return true;
	}
	else
	{
		return false;
	}
}


/*---------------------------------------------------
Function : checkFullHouse
Description : check if player has a full house
input parameters : 
	v - card faces player has
output : true if player has a full house
--------------------------------------------------*/
bool checkFullHouse(vector<int>v)
{
	if((checkThreeofakind(v)) && (checkOnepair(v)))
	{
		return true;
	}
	else
	{
		return false;
	}
}


/*---------------------------------------------------
Function : checkFourofakind
Description : check if player has four of a kind
input parameters : 
	v - card faces player has
output : true if player has four of a kind
--------------------------------------------------*/
bool checkFourofakind(vector<int>v)
{
	if((v[0]==v[1]) && (v[1]==v[2]) && (v[2]==v[3]))
	{
		return true;
	}
	
	else if((v[1]==v[2]) && (v[2]==v[3]) && (v[3]==v[4]))
	{
		return true;
	}
	else
	{
		return false;
	}
}


/*---------------------------------------------------
Function : checkstraightFlush
Description : check if player has straight flush
input parameters : 
	v - card faces player has
	s - card suits player has
output : true if player has straight flush
--------------------------------------------------*/
bool checkstraightFlush(vector<int>v1,vector<string>v2)
{
	if((v2[0]==v2[1]) && (v2[1]==v2[2]) &&  (v2[2]==v2[3]) && (v2[3]==v2[4]))
	{
		if(checkstriaght(v1))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}


/*---------------------------------------------------
Function : checkCards
Description : check what is player's combination
input parameters : 
	v - card faces player has
	s - card suits player has
output : rank according to combination
--------------------------------------------------*/
int checkCards(vector<int>v,vector<string>s)
{
	int rank;
	if(checkstraightFlush(v,s)==false)
	{
		if(checkFourofakind(v)==false)
		{
			if(checkFullHouse(v)==false)
			{
				if(checkFlush(s)==false)
				{
					if(checkstriaght(v)==false)
					{
						if(checkThreeofakind(v)==false)
						{
							if(checkTwopairs(v)==false)
							{
								if(checkOnepair(v)==false)
								{
									checkhighcard(v,s);
									rank = 1;	
								}
								else
								{
									rank = 2;
									cout<<"One pair!!!\n";
								}
							}
							else
							{
								rank = 3;
								cout<<"Two pairs!!!\n";
							}
						}
						else
						{
							rank = 4;
							cout<<"Three of a kind!!!\n";
						}
					}
					else
					{
						rank = 5;
						cout<<"Straight!!!\n";
					}
				}
				else
				{
					rank = 6;
					cout<<"Flush!!!\n";
				}
			}
			else
			{
				rank = 7;
				cout<<"Full House!!!\n";
			}
		}
		else
		{
			rank = 8;
			cout<<"Four of a kind!!!\n";
		}
	}
	else
	{
		rank = 9;
		cout<<"Straight flush!!!\n";
	}
	
	return rank;
}

/*---------------------------------------------------
Function : sortcards
Description : sort vector in descending order
input parameters : 
	v - card faces player has
output : rank according to combination
--------------------------------------------------*/
int sortcards(vector<int>v,vector<string>s)
{
	sort(v.begin(), v.end(), greater<int>());
		
	int num = checkCards(v,s);
	return num;
}


/*---------------------------------------------------
Function : givepoints
Description : give player points
input parameters : 
	r1 - player 01's rank
	r2 - player 02's rank
	r3 - player 03's rank
output : none
--------------------------------------------------*/
void givepoints(int r1, int r2, int r3)
{
	//store ranks in a vector and sort in descending order
	vector<int>v;
	v.push_back(r1);
	v.push_back(r2);
	v.push_back(r3);
	sort(v.begin(), v.end(), greater<int>());
	
	//if highest rank is r1, then give 10 points to player 01 and deduct 1 point from other players
	if(v[0] == r1)
	{
		m1 = m1+10;
		m2 = m2-1;
		m3 = m3-1;
	}
	//if highest rank is r2, then give 10 points to player 02 and deduct 1 point from other players
	else if(v[0] == r2)
	{
		m2 = m2+10;
		m1 = m1-1;
		m3 = m3-1;
	}
	//if highest rank is r3, then give 10 points to player 03 and deduct 1 point from other players
	else if(v[0] == r3)
	{
		m3= m3+10;
		m2 = m2-1;
		m1 = m1-1;
	}
	
	//print the score board
	cout<<"\n-----------------Score board----------------\n";
	cout<<"Player 01 : "<<m1;
	cout<<"\nPlayer 02 : "<<m2;
	cout<<"\nPlayer 03 : "<<m3;
	cout<<"\n--------------------------------------------\n";
	StoreData();
}


/*---------------------------------------------------
Function : checkwinner
Description : check who is the winner
input parameters : 
	n1 - player 01's points
	n2 - player 02's points
	n3 - player 03's points
output : none
--------------------------------------------------*/
void checkwinner(int n1, int n2, int n3)
{
	//store points in a vector and sort in descending order
	vector<int>v;
	v.push_back(n1);
	v.push_back(n2);
	v.push_back(n3);
	sort(v.begin(), v.end(), greater<int>());
	
	//if the highest points are equal to player 01's points he wins
	if(v[0] == n1)
	{
		cout<<"\nPlayer 01 wins!!!\n";
	}
	//if the highest points are equal to player 02's points he wins
	else if(v[0] == n2)
	{
		cout<<"\nPlayer 02 wins!!!\n";
	}
	//if the highest points are equal to player 03's points he wins
	else if(v[0] == n3)
	{
		cout<<"\nPlayer 03 wins!!!\n";
	}	
}


/*---------------------------------------------------
Function : StoreData
Description : store data in a text file
input parameters : none
output : none
--------------------------------------------------*/
void StoreData()
{
	ofstream file("File.txt", ios::out | ios::app);
	file<<"\n-----------------Score board(Round)----------------";
	file<<"\nPlayer 01 : "<<m1;
	file<<"\nPlayer 02 : "<<m2;
	file<<"\nPlayer 03 : "<<m3;
	file<<"\n--------------------------------------------\n";
	file.close();
}



int main()
{
	int rounds = 1;	//variable for number of rounds
	do
	{
		cout<<"\nRound "<<rounds<<endl;
		//define vectors for store card faces and suits ofeach player
		vector<int>P1_no,P2_no,P3_no,D_no;
		vector<string>P1_suit,P2_suit,P3_suit,D_suit;	
		vector<int>v;
	
		Deck deck;	//create an object of class Deck
		deck.shuffle(); //shuffle deck
		cout<<endl;
	
		deck.distribute(P1_no,P2_no,P3_no,D_no,P1_suit,P2_suit,P3_suit,D_suit);	//distribute cards
		NoOfRounds--;
		rounds++;
	}while(NoOfRounds>0);
	
	
	//check for final winner after 5 rounds
	cout<<"\nWinner of the game: ";
	checkwinner(m1,m2,m3);
	
	return 0;
}
