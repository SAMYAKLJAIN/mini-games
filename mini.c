#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<ctype.h>
void hangman();
void tictactoe();
void sudoku();

//hangman functions and variables
void alpha();
void set();
void logic();
void level();                                                            //common variables=i,j  
void mainmenu();
void tictactoe();
void sudoku();
int i,n,e,ctr,t,r,j,k[50],gameover=0,life=3,lvl=1,score=0,nextlevel;
char hangword[25],guessword[25],clue[25],ch,playagain;

//tictactoe functions and varaibles

int ch1,ch2;                         
static int x,y,z,m,p;                
static int lockplayer1ch[10][10],lockplayer2ch[10][10],storecompch[10];
static int userchoice;
char b[3][3]={};
char player1[10],player2[10],enter[1],press;
void selectplayer1(int ch1);
void computerch();
void selectplayer2(int ch2);
void display();
void lockplayer1choice();
void lockplayer2choice();
void lockcompchoice();
void winplayer1();
void winplayer2();
void player1win();
void player2win();
void title();

void main()
{
  system("clear");
 int choice;
 system("clear");
 printf("\n\n\t\t\t\t\t\t\tWELCOME TO MINI GAMES \n\n");
 printf("1.HANGMAN\n");
 printf("2.TIC-TAC-TOE\n");
 printf("3.SUDOKU\n");
 printf("4.EXIT\n");
 printf("Please Enter your choice for game.....");
 rechoice:scanf("%1d",&choice);
 switch(choice)
 {
  case 1:system("clear");
			hangman();
 			break;
  case 2:system("clear");
			tictactoe();
			break;
  case 3:system("clear");
			sudoku();
 		   break;
  case 4:exit(0);
  default:printf("Please enter valid option");
			 goto rechoice;		 
 } 
}

//HANGMAN Game
void hangman()
{
 mainmenu();
 set();
 while(gameover!=1) //till the game is not over
 	{
	 system("clear");  // used to clear output screen
    alpha();
  	 logic();
  	 if(nextlevel==1) //checking whether player is eligible for next level or not 
		{
		 set();
		 }	  
	 }
 system("./a.out"); 
}

void mainmenu()					//main menu of the game
{
 system("clear");
 printf("\n\n\n\t\t ");
 printf("\n\t\t888");                                            
 printf("\n\t\t888"); 
 printf("\n\t\t888");
 printf("\n\t\t88888b.  8888b. 88888b.  .d88b. 88888b.d88b.  8888b. 88888b. ");
 printf("\n\t\t888 '88b    '88b888 '88bd88P'88b888 '888 '88b    '88b888 '88b");
 printf("\n\t\t888  888.d888888888  888888  888888  888  888.d888888888  888");
 printf("\n\t\t888  888888  888888  888Y88b 888888  888  888888  888888  888  ");
 printf("\n\t\t888  888'Y888888888  888 'Y88888888  888  888'Y888888888  888 ");
 printf("\n\t\t\t\t\t     888");
 printf("\n\t\t\t\t        Y8b d88P  ");
 printf("\n\t\t\t\t  \t 'Y88P'"); 
 printf("\n\nIn this game player will be given a hangman word.Player have to guess the letter of the word to find hangman word.\n");
 printf("\nRules\n");
 printf("\n->for each turn player has to guess only one letter of the hangaman word");
 printf("\n->if player guess the word correctly he is eligible for next level and score will be incremeted by 10");
 printf("\n->for each wrong answer player will loose one life");
 printf("\n->Maximum Life=3");
 printf("\n->if life is zero game is over\n");	
 printf("\n\n\n\n\n\n\t\t\t\t\t\t\tpress any key to start...");
 scanf("%1s",&ch);
} 

void set() // sets string length and level
{
 for(i=strlen(hangword);i>0;i--)
 	{
 	 hangword[i]='\0';              
 	}
 for(i=strlen(guessword);i>0;i--)
 	{
 	 clue[i]='\0';              
 	}
 
 nextlevel=0;         
 level();                     //calling calling level function to selct level
 for(i=0;i<strlen(hangword);i++)
 	{
 	 guessword[i]='_';             //printing blanks 
 	}
 system("clear");
}

void alpha() //prints level,score,alphabets
{
 printf("\nlevel=%d\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tscore=%d \n\n",lvl,score);  //prints the current score and level	
 for(i=65;i<91;i++)         /*printing alphabets using their ASCII Values*/
	{
	 for(r=0;r<t;r++)
		{
		 ctr=0;
		 if(i==k[r])
			{
			 printf("-\t");    //printing dash(-) if that letter is used 
			 ctr=1;            //assigninig ctr(control) to 1 to skip printing that particular alphabet  
			 break;
			}
		
		}
	if(ctr==1)
		 continue;         //continue printing next alphabets
	 printf("%c\t",i);
 	}
 printf("\n\nLIFE=%d \n",life);  
 printf("\n\n\t\t\t\t\t\t\t");
 printf("clue=");                   //giving clue
 puts(clue);
 printf("\n"); 
}

void logic() //logic part
{  
 int flag=0;                 //flag decides whether entered letter is matching or not
 printf("\n\t\t\t\t\t\t\t");
 for(i=0;i<strlen(guessword);i++) //printing guessed letters
	 printf("%c ",guessword[i]);
 printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\tEnter 0 to quit game ");
 printf("\n\n\t\t\t\t\t\t\tPick a letter :"); 
 scanf("%1s",&ch);
 if(ch=='0')
 	system("./a.out"); 
 ch=toupper(ch);
 n=toascii(ch);
 k[t]=n;
 t++;
 for(i=0;i<strlen(hangword);i++)
 	{
 	 if(hangword[i]==ch) 			//checking character entered by user matching with any character of hangman word 
		{
		 guessword[i]=ch;				//initializing that character so that it'll be printed in next iteration 
		 flag=1;
		}
  	}
 if(flag==0)                   // if entered character is not matching ......
		life--;							// decrement of life
 if(life==0)							// if life is zero(game over)
 	{
    printf("\n\n\t\t\t\t\t\t\tYou lose!!\n\n\t\t\t\t\t\t\tAnswer is %s \n",hangword); // printing the answer 
    printf("\n\n\t\t\t\t\t\t\tyour final score is %d \n",score);							 //printing the final score
    gameover=1;
	 sleep(4);																							
   }
 j=strcmp(guessword,hangword);  //compares the whole string entered by user with hangman word (return 0 if its true..)
 if(j==0) 
	{
 	 sleep(1);  	
	 for(r=0;r<m;r++)	 //initialising all parameters related to printing alphabets to null values 
	 	{
		 k[r]=' ';
		}
	 r=0;
	 t=0;  
	 score+=10;			//incrementing score value by 10
	 lvl++;
	 nextlevel=1;		 // player is eligible for next level
	}	
}


void level() // this function used to select level.....which consists of hangman words and their respective clues 
{
 switch(lvl) //chosing level
 {
  case 1:strcpy(hangword,"PEA");
			strcpy(clue,"vegitable");
			break;
			break;
  case 2:strcpy(hangword,"PAJAMA");
			strcpy(clue,"dress");
		   break;
  case 3:strcpy(hangword,"CANADA");
		   strcpy(clue,"Country");
		   break;
  case 4:strcpy(hangword,"OXYGEN");
		   strcpy(clue,"Life imposible without this...");
		   break;
  case 5:strcpy(hangword,"ZOMBIE");
			strcpy(clue,"Monster..");
			break;
  case 6:strcpy(hangword,"FACTOR");
			strcpy(clue,"A dictionary word");
			break;
  case 7:strcpy(hangword,"TURKEY");
			strcpy(clue,"Animal");
			break;
  case 8:strcpy(hangword,"YACHT");
			strcpy(clue,"Home");
			break;
  case 9:strcpy(hangword,"PARROT");
			strcpy(clue,"A bird");
			break;
  case 10:strcpy(hangword,"MOOSE");
			strcpy(clue,"Animal");
			break;
  case 11:strcpy(hangword,"STATUE");
			strcpy(clue,"still model.....");
			break;
  case 12:strcpy(hangword,"WHITE");
			strcpy(clue,"Vibgyor..:)");
			break;
  case 13:strcpy(hangword,"THIGH");
			strcpy(clue,"body part..");
			break;
  case 14:strcpy(hangword,"RECITATION");
			strcpy(clue,"A dictionary word");
			break;
  case 15:strcpy(hangword,"ZIGZAG");
			strcpy(clue,"Snake...");
			break;
  case 16:strcpy(hangword,"PIXEL");
			strcpy(clue,"DPI..");
			break;
  case 17:strcpy(hangword,"RICKSHAW");
			strcpy(clue,"Vehicle");
			break;
  case 18:strcpy(hangword,"FISH");
			strcpy(clue,"><((((>");
			break;
  case 19:strcpy(hangword,"QUARTZ");
			strcpy(clue,"SiO2");
			break;
  case 20:strcpy(hangword,"ZODAIC");
			strcpy(clue,"Aries");
			break;
  case 21:strcpy(hangword,"REVOLVER");
			strcpy(clue,"tup tup");
			break;
  case 22:strcpy(hangword,"PNEUMONIA");
			 strcpy(clue,"An infection");
			 break;
  case 23:strcpy(hangword,"SWORD");
			strcpy(clue," o==[]::::::::::::::::> ");
			break;
  case 24:strcpy(hangword,"SNAKE");
			strcpy(clue,"ooooooooooo0");
			break;
  case 25:strcpy(hangword,"VICTORY");
			strcpy(clue,"KABOOM");
			break;
  case 26:strcpy(hangword,"BUTTERFLY");
			strcpy(clue,"SO");
			break;
  case 27:strcpy(hangword,"HEADPHONES");
			strcpy(clue,"d[-_-]b");
			break;
  case 28:strcpy(hangword,"FACE");
			strcpy(clue,"[-_-]");
			break;
  case 29:strcpy(hangword,"TRUMPET");
			strcpy(clue,"o--|||---<| ");
			break;
  case 30:strcpy(hangword,"HYPHEN");
			 strcpy(clue,"-----------");
			 break;	
  default:printf("\n\n\t\t\t\t\t\t\tYou Won !!!!\n\n");	
     		 printf("\n\n\t\t\t\t\t\t\tyour final score is %d \n\n",score);
	  		 sleep(4);
     		 system("./a.out");
 }
}



//End of HANGMAN


//tictactoe Game

void tictactoe()
{
 system("clear");
 printf("\t\t\t\t TIC-TAC-TOE");
 printf("\n\t\t\t\t   MENU"); 
 printf("\n\t1.SINGLE PLAYER");
 printf("\n\t2.MULTI PLAYER");
 printf("\n\tENTER YOUR CHOICE 1 OR 2\n");
 redo:scanf("%d",&userchoice);
 system("clear"); 
 if(userchoice==1)
 {
  printf("\t\tSINGLE PLAYER\n");
  printf("\n ENTER PLAYER ONE'S NAME\n");
  scanf("%s",player1);
  gets(enter);
 }
 else if(userchoice==2)
	  {
		printf("MULTI PLAYER\n");
		printf("\n ENTER PLAYER ONE'S NAME\n");
		scanf("%s",player1);
		gets(enter);
		printf("\n\n");
		printf(" ENTER PLAYER TWO'S NAME\n");
		gets(player2);
		}
 else
	  {
		printf("enter a valid choice\n");
		enter[0]=getchar();
	  }
 system("clear");
 printf("\t\t\t\t HOW TO PLAY(Instructions) \n\n1.If the player wants to play his turn at 1st position  press 1 , position 2 press 2 and  so  on  (using  number pad).\n2.The object of Tic Tac Toe is to get three in a row.\n3. You play on a three by three game board.\n4.The first player is known as X and the second is O .\n5.Players alternate placing Xs and Os on the game board until either oppent has three in a row or all nine squares are filled.\n6. X always goes first, and in the event that no one has three in a row, the stalemate is called a cat game.\n");
 sleep(2);
 printf("\n\n\n\t\t\t\t\t\t\t\tPRESS ENTER TO CONTINUE ");
 press=getchar();
 
 title();
 

switch(userchoice)
{

case 1:display(); 
	    for(m=1;m<6;m++)
		{
		 renter1:printf("\n\n\n%s's turn \n",player1);                //player1
		 scanf("%d",&ch1);
		 for(i=0;i<=2;i++)
		 for(j=0;j<=2;j++)
			{
			 if(lockplayer1ch[i][j]==ch1)
			{
			 printf("\nInvalid position\nRe-enter\n");
			 sleep(1);
			 system("clear");
			 display();
			 goto renter1;
			}		
}

for(i=0;i<=9;i++)
 if(storecompch[i]==ch1)
	{
	printf("\nInvalid position\nRe-enter\n");
	sleep(2);
	system("clear");
	display();
	goto renter1;
}



		selectplayer1(ch1);
		b[i][j]='x';
		winplayer1();
		lockplayer1choice();
                      if(m==5)
			{
			printf("\n\n DRAW !! \n GAME OVER \n\n");
sleep(2);
system("clear");
system("./a.out");
exit(0);
			}
else
{
		computerch();                                     //calling computer player 
		b[i][j]='o';
		winplayer2();
                lockcompchoice();
		system("clear");
            
		display(); 
                      
}
  }
break;                       
case 2:
	display();
	    
	for(m=1;m<6;m++)
	{

 renter2:printf("\n\n\n%s's turn \n",player1);                //player1
 scanf("%d",&ch1);
 for(i=0;i<=2;i++)
 	for(j=0;j<=2;j++)
	{
	if(lockplayer1ch[i][j]==ch1)
		{
		printf("\nInvalid position\nRe-enter\n");
		sleep(2);
		system("clear");
		display();
		goto renter2;
		}
		else if(lockplayer2ch[i][j]==ch1)
				{
				 printf("\nInvalid position\nRe-enter\n");
				 sleep(2);
				 system("clear");
				 display();
				 goto renter2;
				}
	}
 selectplayer1(ch1);
 b[i][j]='x';
 system("clear");
 display();
 winplayer1();
 lockplayer1choice();

	                     //player2
 if(m==5)
 {
  printf("\n\n DRAW !! \n GAME OVER \n\n");
  sleep(2);
  system("clear");
  system("./a.out");
  exit(0);
 }

 else
 {
	renter3:printf(" \n\n%s's turn \n\n",player2);
	scanf("%d",&ch2);
	for(i=0;i<=2;i++)
		for(j=0;j<=2;j++)
		{
		 if(lockplayer2ch[i][j]==ch2)
			{
			 printf("\nInvalid position\nRe-enter\n");
			 sleep(2);
			 system("clear");
			 display();
			 goto renter3;
			}
			else if(lockplayer1ch[i][j]==ch2)
					{
					 printf("\nInvalid position\nRe-enter\n");
					 sleep(2);
					 system("clear");
					 display();
					 goto renter3;
					}
		 }
  selectplayer2(ch2);
  b[i][j]='o';
  lockplayer2choice();
  winplayer2();	
  system("clear");
  display();
 }
}
 break;
 default : printf("enter a valid choice ");
                  exit(0);
   }

}

void selectplayer1(int ch1)                                         //player1
{
	   switch(ch1)
	  {
		case 1:i=0;j=0;
		

		x=i;y=j;
		break;
		case 2:i=0;j=1;
		

		x=i;y=j;
		break;
		case 3:i=0;j=2;
		

		x=i;y=j;
		break;
		case 4:i=1;j=0;
		

		x=i;y=j;
		break;
		case 5:i=1;j=1;
		
		x=i;y=j;
		break;
		case 6:i=1;j=2;
		
		x=i;y=j;
		break;
		case 7:i=2;j=0;
		
		x=i;y=j;
		break;
		case 8:i=2;j=1;
		

		x=i;y=j;
		break;
		case 9:i=2;j=2;
		

		x=i;y=j;
		break;
		default: printf("retry \n");
					exit(0);
		}
}
void selectplayer2(int ch2)                     // player 2
{
		switch(ch2)
		{
		case 1:i=0;j=0;
	
	
		x=i;y=j;
		break;
		case 2:i=0;j=1;
		
		x=i;y=j;
		break;
		case 3:i=0;j=2;
		

		x=i;y=j;
		break;
		case 4:i=1;j=0;
		
		x=i;y=j;
		break;
		case 5:i=1;j=1;
		
		x=i;y=j;
		break;
		case 6:i=1;j=2;
		
		x=i;y=j;
		break;
		case 7:i=2;j=0;
		
		x=i;y=j;
		break;
		case 8:i=2;j=1;
		
		x=i;y=j;break;
		case 9:i=2;j=2;
		
		x=i;y=j;
		break;
		default: printf("\n\n\nretry");
		}
}
void computerch()                          //computer player
{
 srand(time(0));
 label:z=rand()%9+1;
 for(i=0;i<=10;i++)
 	if(z==storecompch[i])
		goto label;
 for(i=0;i<=2;i++)
 	for(j=0;j<=2;j++)
		{
		 if(z==lockplayer1ch[i][j])
			goto label;
		}
 selectplayer2(z);
}

void display()
{
 for(i=0;i<=2;i++)
 {
  printf("\n");
  printf("\t\t\t\t");
 	for(j=0;j<=2;j++)
	{
	 printf("  %c|",b[i][j]);
	}
  printf("\n\t\t\t\t __________");
 }
}

void lockplayer1choice()
{
 lockplayer1ch[x][y]=ch1;
}

void lockplayer2choice()
{
 lockplayer2ch[x][y]=ch2;
}

void lockcompchoice()
{
 p++;
 storecompch[p]=z;
}

void winplayer2()
{
 if(b[0][0]=='o' && b[0][1]=='o' && b[0][2]=='o'  )
 { 
  player2win();
 }
	else if(b[0][0]=='o' && b[1][1]=='o' && b[2][2]=='o' )
			{		   
        	 player2win();
			}
			else if(b[1][0]=='o' && b[1][1]=='o' && b[1][2]=='o'  )
					{
					 player2win();
					}
					else if(b[2][0]=='o' && b[2][1]=='o' && b[2][2]=='o')
							{
							 player2win();
							}
					else if(b[0][0]=='o' && b[1][0]=='o' && b[2][0]=='o'  )
							{
					 		 player2win();
							}
							else if(b[0][1]=='o' && b[1][1]=='o' && b[2][1]=='o' )
						      	{
							 		 player2win();
									 exit(0);
									}
									else if(b[0][2]=='o' && b[1][1]=='o' && b[2][0]=='o')
											{	
											 player2win();
											}
											else if(b[0][2]=='o' && b[1][2]=='o' && b[2][2]=='o'  )
													{
													 player2win();
													}
}

void winplayer1()
{

 if(b[0][0]=='x' && b[0][1]=='x' && b[0][2]=='x')
 { 
  player1win();
 }
 else if(b[0][0]=='x' && b[1][1]=='x' && b[2][2]=='x' )
		{
		 player1win();
		}
		else if(b[1][0]=='x' && b[1][1]=='x' && b[1][2]=='x'   )
				{
				 player1win();
				}
				else if(b[2][0]=='x' && b[2][1]=='x' && b[2][2]=='x'  )
						{
						 player1win();
						}
						else if(b[0][0]=='x' && b[1][0]=='x' && b[2][0]=='x'  )
								{
								 player1win();
								}
								else if(b[0][1]=='x' && b[1][1]=='x' && b[2][1]=='x' )
										{
										 player1win();
										}	
										else if(b[0][2]=='x' && b[1][1]=='x' && b[2][0]=='x')
												{
												 player1win();
												}
												else if(b[0][2]=='x' && b[1][2]=='x' && b[2][2]=='x'   )
														{
														 player1win();
														}
}
void player1win()
{
 system("clear");
 display();
 printf("\n\n %s WINS \n",player1);
 sleep(3);
 system("clear");
 system("./a.out");
 exit(0);
}

void player2win()
{
 system("clear");display();
 if(userchoice==1)
 	printf("\n \n%s loose!!\n",player1);
 else
 	printf("\n\n %s  wins!! \n",player2 );
 sleep(2);
 system("clear");
 system("./a.out");
 exit(0);
}

void title()
{
 
 system("clear");		
 for(i=3;i>=1;i--)
 {
  printf(" GAME STARTS IN %d \n" ,i);
  sleep(1);
 if(i==3)
 {
  printf("\n\n\n\nTTTTTTTTTTTTTTTTTT   IIIIIIIIIIIIIIIIII   CCCCCCCCCCCCCCCCC\n");
  printf("TTTTTTTTTTTTTTTTTT   IIIIIIIIIIIIIIIIII   CCCCCCCCCCCCCCCCC\n");
  printf("TTTTTTTTTTTTTTTTTT   IIIIIIIIIIIIIIIIII   CCCCCCCCCCCCCCCCC\n");
  printf("     TTTTTTT              IIIIIIII        CCC              \n");  
  printf("     TTTTTTT              IIIIIIII        CCC              \n");    
  printf("     TTTTTTT              IIIIIIII        CCC              \n");    
  printf("     TTTTTTT              IIIIIIII        CCC              \n"); 
  printf("     TTTTTTT              IIIIIIII        CCC              \n");    
  printf("     TTTTTTT              IIIIIIII        CCC              \n");    
  printf("     TTTTTTT              IIIIIIII        CCC              \n");    
  printf("     TTTTTTT              IIIIIIII        CCCCCCCCCCCCCCCCC\n");   
  printf("     TTTTTTT          IIIIIIIIIIIIIIIIII  CCCCCCCCCCCCCCCCC\n");
  printf("     TTTTTTT          IIIIIIIIIIIIIIIIII  CCCCCCCCCCCCCCCCC\n"); 
  sleep(1);
  system("clear");
}

else
 
if(i==2)
{
 printf("\n\n\n\nTTTTTTTTTTTTTT      AAAAAAAAAAAAAA   CCCCCCCCCCCCCCCCC\n");
 printf("TTTTTTTTTTTTTT      AAAAAAAAAAAAAA   CCCCCCCCCCCCCCCCC\n");
 printf("TTTTTTTTTTTTTT      AAAAAAAAAAAAAA   CCCCCCCCCCCCCCCCC\n");
 printf("   TTTTTT           AAA        AAA   CCC              \n"); 
 printf("   TTTTTT           AAA        AAA   CCC              \n");
 printf("   TTTTTT           AAA        AAA   CCC              \n");
 printf("   TTTTTT           AAA        AAA   CCC              \n");
 printf("   TTTTTT           AAAAAAAAAAAAAA   CCC              \n");
 printf("   TTTTTT           AAA        AAA   CCC              \n");
 printf("   TTTTTT           AAA        AAA   CCCCCCCCCCCCCCCCC\n");
 printf("   TTTTTT           AAA        AAA   CCCCCCCCCCCCCCCCC\n");
 printf("   TTTTTT           AAA        AAA   CCCCCCCCCCCCCCCCC\n");

 sleep(1); 
 system("clear");
}
else
{
 printf("\n\n\nTTTTTTTTTTTTTTTTTTTTTT OOOOOOOOOOOOOOOOOOOOOOO EEEEEEEEEEEEEEEEEEEEEE\n");    
 printf("TTTTTTTTTTTTTTTTTTTTTT OOOOOOOOOOOOOOOOOOOOOOO EEEEEEEEEEEEEEEEEEEEEE\n");    
 printf("TTTTTTTTTTTTTTTTTTTTTT OOOOOOOOOOOOOOOOOOOOOOO EEEEEEEEEEEEEEEEEEEEEE\n");    
 printf("     TTTTTTTT          OOOOOO           OOOOOO EEEEEEE\n");   
 printf("     TTTTTTTT          OOOOOO           OOOOOO EEEEEEE\n");   
 printf("     TTTTTTTT          OOOOOO           OOOOOO EEEEEEE\n");   
 printf("     TTTTTTTT          OOOOOO           OOOOOO EEEEEEE\n");   
 printf("     TTTTTTTT          OOOOOO           OOOOOO EEEEEEEEEEEEEEEEEEEEEE\n"); 
 printf("     TTTTTTTT          OOOOOO           OOOOOO EEEEEEEEEEEEEEEEEEEEEE\n");   
 printf("     TTTTTTTT          OOOOOO           OOOOOO EEEEEEE\n");    
 printf("     TTTTTTTT          OOOOOO           OOOOOO EEEEEEE\n"); 
 printf("     TTTTTTTT          OOOOOO           OOOOOO EEEEEEE\n"); 
 printf("     TTTTTTTT          OOOOOO           OOOOOO EEEEEEE\n"); 
 printf("     TTTTTTTT          OOOOOOOOOOOOOOOOOOOOOOO EEEEEEEEEEEEEEEEEEEEEEE\n"); 
 printf("     TTTTTTTT          OOOOOOOOOOOOOOOOOOOOOOO EEEEEEEEEEEEEEEEEEEEEEE\n");
 printf("     TTTTTTTT          OOOOOOOOOOOOOOOOOOOOOOO EEEEEEEEEEEEEEEEEEEEEEE\n"); 
 sleep(1);

}

		
}
		
system("clear");

 
}





//sudoku Game

void sudoku()
{
 int sum,grid[9][9]={{0,0,0,0,0,3,2,9,0},{0,8,6,5,0,0,0,0,0},{0,2,0,0,0,1,0,0,0},{0,0,3,7,0,5,1,0,0},{9,0,0,0,0,0,0,0,8},     {0,0,2,9,0,8,3,0,0},{0,0,0,4,0,0,0,8,0},{0,4,7,1,0,0,0,0,0}};
 int i,j,k,l,sudoku[9][9];
 printf("SUDUKU ...\n\n");
 
 for(i=0;i<9;i++)            //printing question
 {
  for(j=0;j<9;j++)
  {
   printf("%d  ",grid[i][j]);
   }
   printf("\n");
 }


 for(i=0;i<9;i++)             //copying question to answer array
  {
   for(j=0;j<9;j++)
 	 {
 		sudoku[i][j]=grid[i][j];
 	 }
  }


  replay:
  printf("\n\n\n\nSolve Sudoku in Paper and Enter the solution by Rowwise \n\n\n");
  for(i=0;i<9;i++)
  {
	printf("Enter the row %d non zero elements ",i+1);
   for(j=0;j<9;j++)
    {
  	  if(sudoku[i][j]==0)   
		{
 		 scanf("%d",&sudoku[i][j]);
 		}
  	 }
  	 printf("\n");	
  }

  system("clear");
  printf("Entered solution ...\n\n"); 
  	for(i=0;i<9;i++)
 	{
  	for(j=0;j<9;j++)
  	{
    printf("%d  ",sudoku[i][j]);
   }
   printf("\n");
   }
 sleep(3);
 system("clear");
 for(i=0;i<9;i++)
  {
   for(j=0;j<9;j++)
   {
    printf("%d  ",sudoku[i][j]);
   }
   printf("\n");
  }
 
 for(i=0;i<9;i++)    //checking whether answer is correct or not
 {
  sum=0;
  for(j=0;j<9;j++)
  {
   sum=sum+sudoku[i][j];
  }
  if(sum!=45)
  	{  
	 printf("Solutuion is wrong ...\n");	
    goto main;	
	} 
 else
	 {
	  goto main; 
	 }
  }

 for(j=0;j<9;j++)
 {
  sum=0;
  for(i=0;i<9;i++)
  {
   sum=sum+sudoku[i][j];
  }
  if(sum!=45)
  	{ 
    printf("Solutuion is wrong \n");
	 goto main;
	} 
  else
	   {
	  	goto main;	
	 	}
 }
 
 for(k=0;k<3;k++)
 {
	for(l=0;l<3;l++)
 	{
 	 sum=0;
  	 for(i=k;i<i+k;i++)
	 	for(j=l;j<j+l;j++)
	 	{
  	    sum+=sudoku[i][j];
	  	}
	 if(sum!=45)
  	 { 
     printf("Solutuion is wrong ...\n ");
	  goto main;
	 } 
 	 else
		{
 		 printf("Solutuion is Correct\n");
		 main:sleep(3);
		 system("./a.out"); 	
		}
 	} 
 } 
}
	
 



 

  
