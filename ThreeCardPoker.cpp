//**************************************
// Name: Basic C++ Poker Programming Assignment
// Description:This will deal two five card poker hand and then determine the winner from among the hands or if there is a tie.
// By: Winston Alexander Hope, Jr.
//**************************************

//Winston Hope, Jr.
//Programming II, Program # 5
//This will deal two five card poker hand
//and then determine the winner from amongst handss

// Three Card Poker is played as heads-up between the player's hand and the dealer's hand. 
// After all ante wagers are placed, three cards are dealt to each player and the dealer. 
// Players have a choice to either fold or continue in the game by placing a "play" wager equal to their ante. 
// Hands are then exposed and wagers resolved.
// The dealer's hand must be Queen high or better for the dealer hand to play. 
// If the dealer does not play, then there is no action on play wagers and ante wagers are paid 1 to 1. 
// If the dealer does play, the dealer and player hands are compared. 
// If the player hand loses, both the ante and play wagers are lost. 
// If the player hand wins both the ante and play wagers are paid 1 to 1. 
// If the hands are tied, then there is no action on either wager.
// Winning hands in order of precedence: Straight Flush, Three of a Kind, Straight, Flush, Pair and High Card.


#include <iostream>
#include <iomanip>
// #include <stdlib>
#include <ctime>
// #include<conio>//single character imput... 
				//...without the use of carriage return
using namespace std;				
				
void shuffle(int[][13]);
void deal(int[], int[], int[], int[]);
void print(int[], int[]);
void clear_deck(int[], int[], int[], int[]);
int dealerCanPlay(int[]);

int Ppair(int[],int[]);
int threeofkind(int[],int[]);
int flush(int[],int[]);
int straight(int[],int[]);
int straightflush(int[],int[]);
int Tie_Check(int[],int[],int);
int deck[ 4 ][ 13 ] = { 0 };
int playerBank = 20;
int amtBet = 0;
int canPlay = 0;
int choice;

const char *suit[4] = {"Hearts", "Diamonds", "Clubs", "Spades"};
const char *face[13] = {"Deuce", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King", "Ace"};
const char *type[6]= {"none", "pair", "flush", "straight", "threeofkind", "straight flush"};

char A = 3, B = 4, C = 5, D = 6;
char answer;
char again;

int main()
{
//
  int t = 5;
  int hand1[3], hand2[3], hand3[3], hand4[3]; 
  int handtype1, handtype2;
//
  srand(time(NULL));
//
do
  {
  //
  cout << "Enter 1 to play or 2 to exit\n";
  cout << "Enter your choice: ";
  cin >> choice;
  while (choice < 1 || choice > 2)
  {
    cout << "Please choose 1 or 2:";
    cin >> choice;
  }
  // Exit program
  if (choice == 2)
  {
  return 0;
  }

//
  canPlay = 0;
  while (canPlay == 0)
  {
  	shuffle(deck);
    deal(hand1, hand2, hand3, hand4);
    canPlay = dealerCanPlay(hand4);
    cout << canPlay << "\n";
    if (canPlay == 0)
    {
      clear_deck(hand1, hand2, hand3, hand4);
	}
  }
//
// Check if dealer has queen or higher
// 
  cout << face[hand4[0]] << " ";
  cout << face[hand4[1]] << " ";
  cout << face[hand4[2]] << " ";
  cout << "\n";
  playerBank = playerBank - 1;
  cout << "Player you have placed a dollar in the ante:\n";
  cout << "Your balance is " << playerBank << "\n";
//
  print(hand1, hand2); //Print the first hand
  cout << endl;
//	
  handtype1 = Ppair(hand2, hand1); //Begin hand classificatiosn process	
  cout << endl;
//
  cout << "Player may bet from 1 to " << playerBank << "\n";
  cout << "What is your bet?:\n";
  cin >> amtBet;
  cout << "Dealer:\n\n";
//
  print(hand3, hand4); //Print the second hand
  cout << endl;
  cout << endl;	
//
  handtype2 = Ppair(hand4, hand3); 
// 
  cout<<"Player Hand:	Dealer Hand:"
	<< "\n" << type[handtype1]
	<<"		"<< type[handtype2] << endl;
//
  if(handtype1 > handtype2)
    cout<<"\nPlayer Wins!\n\n";
    playerBank = playerBank + amtBet;
//
  if(handtype1<handtype2)
    cout<<"\nDealer Wins!\n\n";
    playerBank = playerBank - amtBet;
//
  if(handtype1 == handtype2)
	Tie_Check(hand2, hand4, handtype1);

//
  clear_deck(hand1, hand2, hand3, hand4);
//
  cout << endl;

} while (choice != 2);

  return 0;
}
// 

  int dealerCanPlay(int dhand[3])
  {
   	int cp = 0;
    if (face[dhand[0]] == "Queen")
      cp = 1;
    if (face[dhand[0]] == "King")
      cp = 1;  
    if (face[dhand[0]] == "Ace")
      cp = 1;
    if (face[dhand[1]] == "Queen")
      cp = 1;
    if (face[dhand[1]] == "King")
      cp = 1;  
    if (face[dhand[1]] == "Ace")
      cp = 1;  
    if (face[dhand[2]] == "Queen")
      cp = 1;
    if (face[dhand[2]] == "King")
      cp = 1;  
    if (face[dhand[2]] == "Ace")
      cp = 1;     
    if (cp == 1)
      return 1;
    else
      return 0;
  } 

// Shuffle
  void shuffle(int wDeck[][13])
  {
    int row, column;
    for ( int card = 1; card <= 52; card++ ) 
	{
      do
	  {
        row = rand() % 4;
        column = rand() % 13;
      }
	  while( wDeck[ row ][ column ] != 0 );
        wDeck[ row ][ column ] = card;
    }
  }
  
// Deal
void deal(int ahand[3], int bhand[3], int chand[3], int dhand[3])
  {
    int x = 0, y = 0; //counter for each hand
	for (int card = 1; card <= 6; card++)
      for (int row = 0; row <= 3; row++)
        for (int column = 0; column <= 12; column++)
		//this will deal the hands one by one
		if (deck[row][column] == card)
		{
		  if(card %2 == 1)
		  {
            ahand[x] = row;
            bhand[x] = column;
            x++; 
	      }
          else
		  {
	        chand[y] = row;
            dhand[y] = column;
            y++;
          }
        }
    }
    
//
  void print(int hand1[3], int hand2[3])
  {
    for (int num = 0; num < 3; num++)
    {  
      cout << setw(5) << setiosflags(ios::right)
        << face[hand2[num]] << " of "
        << setw(8) << setiosflags(ios::left)
        << suit[hand1[num]];			
	  cout << endl;			
	} 
  }
  
//
  int Ppair(int phand[3],int qhand[3])
  {
    int frequency[13] = {0}, keep = 0;
    int track;
    // first arrange the array in ascending osrder
    for(int b = 0; b < 2; b++)
      for(int c = 0; c < 2; c++)
      if(phand[c] < phand[c + 1])
      {
        track = phand[c + 1];
        phand[c + 1] = phand[c];
        phand[c] = track;
      }
      //this is to find out how many of each faces there is 
      for(int p = 0; p < 3; p++)
        ++frequency[phand[p]];
        for(int p2 = 0; p2 <= 12; p2++)
        {
	    //using frequency to check for a pair
          if(frequency[p2] == 2)
          {
            keep = 2; 
          }
        }
        if(keep == 2) //if there is a pair
        {
          cout<<"Player has a pair!\n\n";
          return 1;
        }
	  //if there is no pair check for flush
      else
        return flush(phand, qhand);
  }
//
  int flush(int phand[3], int qhand[3])
  {
    int frequency[13] = {0}, keep=0;
    for(int p = 0; p < 3; p++) //using the suit in this case to determine if hand is a flush
      ++frequency[qhand[p]];
      for(int p2 = 0; p2 <= 12; p2++)
      {
        keep = frequency[p2];
        if(keep == 3)
        {
          break; 
        }
      } 
      if(keep==3) //if there is a flush
      {
        cout<<"Player has a flush!\a\a\n\n";
        return 2;
      }
      else //if there is no flush check for a straight
        return straight(phand, qhand);
  }
//
  int straight(int phand[3], int qhand[3])
  {
    int frequency[3] = {0}, keep = 0, x, y, z = 0;
	 /*a straight is determined by checking:
	 if the next value is one more than the 
	 previous value.....*/
    for(int p=0; p+1 < 3; p++)
    { 
      x=phand[p]; y=phand[p+1];
		/*...if the next value is not one less than
		the previous value, 'z' will be assingned 
		the value '1' to indocate that there is no 'straight'*/
      if(x+1!=y||frequency[p]==3)
      {
        z = 1;
        break; 
      } 
    } 
    if(z == 0)
    {
      cout<<"Player has a straight!\a\a\n\n";
      return 3;
    }
    else
    {
      return threeofkind(phand, qhand);
    }
  }

//
  int threeofkind(int phand[3], int qhand[3])
  {
    int frequency[13] = {0}, keep = 0;
    for(int p = 0; p < 3; p++)
      ++frequency[phand[p]]; 
      for(int p2 = 0; p2 <= 12; p2++)
      {
        if(frequency[p2] == 3)
        {
          keep+=3; 
        }
      }
      if(keep==3)//if there is three of a kind
      {
        cout << "Player has three of a kind!\a\a\n\n";
        return 4;
      }
      else //if there is no three of a kind check for straightflush
        return straightflush(phand, qhand);
  }

//
int straightflush(int phand[3],int qhand[3])
{
// int frequency[3] = {0}, keep = 0, x, y, z;
// 
//	 //checking to make sure that hand is not a flush
// for(int suit_count=0;suit_count<5;suit_count++)
// ++frequency[qhand[suit_count]];
// 
//	 /*a straight is determined by checking:
//	 if the next value is one more than the 
//	 previous value.....*/
// for(int p=0; p+1 < 3; p++)
// { 
//		x=phand[p]; y=phand[p+1];
//		/*...if the next value is not one less than
//		the previous value, 'z' will be assingned 
//		the value '1' to indocate that there is no 'straight'*/
//if(x+1!=y||frequency[p]==3)
//{
// z=1;
// break; 
//}
// } 
// if(z==1)//if there is no 'straight' return zero to indicate that there was no match for any hand type
// {
// return 0;
// }
// else//if there is a a 'straight'...
//		 //...return '3' to indicate so
// {
//cout<<"Player has a straight flush!\a\a\n\n";
return 0;
//}
}

// clearing the deck and hands
  void clear_deck(int Hand1[3], int Hand2[3], int Hand3[3], int Hand4[3])
  {
    for(int a = 0; a <= 3; a++)
      for(int b = 0; b <= 12; b++)
        deck[a][b] = 0;
        for(int c = 0; c < 3; c++)
		{       
          Hand1[c] = 0; Hand2[c] = 0;
          Hand3[c] = 0; Hand4[c] = 0;
		}
  }
 
//
  int Tie_Check(int hand2[3], int hand4[3], int ht) 
  {
    //local functions
    void pair_arrange(int[], int);
    int tie_breaker(int[], int[], int);
    int sum = 0, sum2 = 0;
	 
    /*if the hands have no match or the hands are both 'straights',
	invoke the tie breaker function without the need to arrainge the
	hands in pairs as there should be no pairs in both hands*/
	
    if(ht == 0 || ht == 4)
	  tie_breaker(hand2, hand4, ht);
    else
    {
      pair_arrange(hand2, ht);
      pair_arrange(hand4, ht);
      
   /* the pair arrange function will multiply the first two pairs and 
      assign it to the first element in the array.
	  So the following first pair to determine a winner */
	  
      if(hand2[0] > hand4[0])
	    cout << "Player One Wins!";
      if(hand2[0] < hand4[0])
	    cout << "Player Two Wins!";
      if(hand2[0] == hand4[0])
	    tie_breaker(hand2, hand4, ht);
    } 
    return 0; 
  }
  
//
  void pair_arrange(int h2[],int tp)
  {
	int ar[3]={0},ar2[3]={0},count=2;
	//
	int frequency[13] = {0}, a, aa, keep=0;
	//
	for(int q = 0; q < 3; q++)
		{
		++frequency[h2[q]];
		}
		if(tp==1) // if the hand is a pair the code will group it accoidingly
		{
		  for(a=0;a<13;a++)
		  {
		    if(frequency[a]==2)
		    {
		      ar[0]=a*2; // take the pair, multiply it by two and assign it to the first element in the array... 
		      break;
		    }
		  }
		  //...then take the rest and assign them to each folowing element
		  int y = 1;
		  for(int b = 0; b < a ; b++)
		  {
		    if(frequency[b] == 1)
		    {
		      ar[y] = b;
		      y++;
		    }
		  }
        }
	    else
          if(tp == 2 || tp == 3)//if the hand is a 'two pair' or 'three of a kind' the subscript will be multiplied by three
          {
	        if(tp == 3) 
		      count = 3;
	        for(aa = 0; aa < 13; aa++)
		    {
		      if(frequency[aa] == count)
		      {
			    ar2[0]=aa*count;
			    break;
		      }
		    }
	//////////////////////////////
	//this is not necessary if 
	//the hand is a three-of-kind hand
 if(tp != 3)
	{
	  int yy = 1;
	  for(int bb = aa+1 ; yy <= 1; bb++)
		{
          if(frequency[bb] == 2)
		  {
		    ar[1]=bb*2;//this is for the two pair hand
		    break;
		  }
		}
	 }
	//////////////////////////////
	int con=2;
	if(tp==3)
			con=1;
	for(int bb = 0; bb < 13; bb++)
		{ 
		 if(tp == 3 && con == 3)//if hand is a 'three-of-kind'
							//the the loop needs to break
							//at two
		 break; 
		 if(frequency[bb]==1)
		 {
		 ar[con]=bb;
		 if(tp==3)con++;
		 }
		} 
}
		cout<<endl;
	///////////////////////////////
	//copying the values back to argument 'h2'...
	//the array containing a hand-no suits, only faces
	 for(int copy = 0; copy < 3; copy++)
		{
		 h2[copy]=ar[copy];
		}		
}

// this function determines the winner if the pairs are tied
  int tie_breaker(int h2[], int h4[], int ty)
  {
    int b, add, wild=1;
    if (ty == 1)
	  add = 4;
	if (ty == 2)
	  add = 3;
    if (ty == 3)
	  add = 3;
	if(ty == 4)
	  add = 2;
    if (ty == 0 || ty == 6)
	{
	  wild = 0;
	  add = 5;
	}
 
   //comparing each value elememt by element
   //if the element in one hand is equal to the corresponding
   //element in the other hand, the iteration will
   //continue until there is one that is greater than 
   //or less than to determine the winner.
   //if the iteration terminates and no winner is found,
   //the game is a tie.
    for ( b = wild; b < add; b++)
    {
      if(h2[b] > h4[b])
      {
        cout << "\nPlayer One Wins!\n";
        return 0;
      }
      if (h2[b] < h4[b])
      {
        cout << "\nPlayer Two Wins!\n";
        return 0;
      }       
    }
    if(b == add)
    {
      cout << "\nTie Game! Both Players have the same hand\n";
    }
  return 0; 
  }
