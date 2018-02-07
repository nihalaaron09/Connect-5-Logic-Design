// First Check if you have a chance of winning by checking for a four pattern. If found, win game. 
// Else, Check if opponent has a three pattern, and if found, block it. 
// Else, Check if you have a three patter. If found, extend to make it a four pattern
// Else select best possible node among open nodes, based on a heuristic calculation and place your move there



#include <stdio.h>
#include <stdlib.h>
#include "Student.h"

int Check_empty_board(int board[SIZE][SIZE]);

int* CheckYourFour(int board[SIZE][SIZE], int *);
int* WinYourFour(int  board[SIZE][SIZE],int, int, int, int *);

int* CheckThree(int board[SIZE][SIZE], int, int *);
int* MyMove(int board[SIZE][SIZE],int,int,int,int, int *);
int CheckThreeClosed(int board[SIZE][SIZE], int, int, int);

int * SimpleMove(int Board[SIZE][SIZE], int *);

                                                        // assume that this is player 1, X
int* getMove(int board[][SIZE], int *move)
{

if (Check_empty_board(board)==0)    // if player 1, this makes move at center
{	move[0]=SIZE/2;
	move[1]=SIZE/2;	
	return move;
}

int player=2;                   // to reuse the CheckThree fucntion for both players
move=CheckYourFour(board,move);   //if four pattern exists for player, win
if (move[0]!=-1)
	return move;
else
    { move=CheckThree(board,player,move);    // if three pattern exists for opponent, block
      if (move[0]!=-1)
	return move;
	else
	   {
	    move=CheckThree(board,player-1,move);   // if three patterne exists for player, move there
	    if (move[0]!=-1)
		return move;
	    else
		{
		move=SimpleMove(board,move);	 // make best possible move for yourself
		return move;		
		}
	   }
    }


} //getMove


// Check whether board is empty
int Check_empty_board(int board[SIZE][SIZE])  
{
int i,j;
for (i=0;i<SIZE;i++)
  {
  for (j=0;j<SIZE;j++)
    {	if (board[i][j]!=0)
		return 1;
    }
  }
return 0;
}//function




// Check for a four pattern. If detected, pass on to WinYourFour function to place move and win game
int* CheckYourFour(int board[SIZE][SIZE], int *move)
{    move[0]=-1;move[1]=-1;
int i,j,flag=13;
for (i=0;i<SIZE;i++)
{
   for (j=0;j<SIZE;j++)
     {  
     if (board[i][j]==1)
       {  
       if (board[i][j+1]==1 && i>0  && i<SIZE  && j+1>0  && j+1<SIZE)
         { 
         if (board[i][j+2]==1 && i>0  && i<SIZE  && j+2>0  && j+2<SIZE)
	   {
	   if (board[i][j+3]==1 && i>0  && i<SIZE  && j+3>0  && j+3<SIZE)
	     {
             flag=0;
		if ( !((j-1<0 && (board[i][j+4]==1 || board[i][j+4]==2)) || (j+4>SIZE && (board[i][j-1]==1 || board[i][j-1]==2)) || (board[i][j-1]==1 || board[i][i-1]==2) && (board[i][j+4]==1 || board[i][j+4]==2))  ) 
	     {move=WinYourFour(board,i,j,flag, move);
	     }
             return move;
             } //fourth if
	  }// third if
	 } //second if
	} // first if
       } //inner for  

}// outer for


for (i=0;i<SIZE;i++)
{
   for (j=0;j<SIZE;j++)
     {
     if (board[i][j]==1)
       { 
       if (board[i+1][j]==1 && i+1>0  && i+1<SIZE  && 1>0  && j<SIZE)
         { 
         if (board[i+2][j]==1 && i+2>0  && i+2<SIZE  && j>0  && j<SIZE)
	   {  
	   if (board[i+3][j]==1 && i+3>0  && i+3<SIZE  && j>0  && j<SIZE)
	     {  
	     flag=1;
		if ( !((i-1<0 && (board[i+4][j]==1 || board[i+4][j]==2)) || (i+4>SIZE && (board[i-1][i]==1 || board[i-1][j]==2)) || (board[i-1][j]==1 || board[i-1][j]==2) && (board[i+4][j]==1 || board[i+4][j]==2) ) ) 
	     {move=WinYourFour(board,i,j,flag, move);
	      }
	     return move;
	     } //fourth if 
	  }// third if
	 } //second if
	} // first of
       } // inner for
}// outer for

for (i=0;i<SIZE;i++)
{  
   for (j=0;j<SIZE;j++)
     {
     if (board[i][j]==1)
       {  
       if (board[i+1][j+1]==1 && i+1>0  && i+1<SIZE  && j+1>0  && j+1<SIZE)
         {  
         if (board[i+2][j+2]==1 && i+2>0  && i+2<SIZE  && j+2>0  && j+2<SIZE)
	   {  
	   if (board[i+3][j+3]==1 && i+3>0  && i+3<SIZE  && j+3>0  && j+3<SIZE)
	     {
	      flag=2;
	     if ( !(( (i-1<0 || j-1<0) && (board[i+4][j+4]==1 || board[i+4][j+4]==2)) || ( (i+4>SIZE || j+4>SIZE) && (board[i-1][j-1]==1 || board[i-1][j-1]==2)) || (board[i-1][j-1]==1 || board[i-1][j-1]==2) && (board[i+4][j+4]==1 || board[i+4][j+4]==2))  )
	      {move=WinYourFour(board,i,j,flag,move);
	     }
	      return move;
            } //fourth if
	  }// third if
	 } //second if
	} // first if
       } //inner for
}// outer for

for (i=0;i<SIZE;i++)
{
   for (j=0;j<SIZE;j++)
     {
     if (board[i][j]==1)
       {
       if (board[i+1][j-1]==1 && i+1>0  && i+1<SIZE  && j-1>0  && j-1<SIZE)
         { 
         if (board[i+2][j-2]==1 && i+2>0  && i+2<SIZE  && j-2>0  && j-2<SIZE)
	   {
	   if (board[i+3][j-3]==1 && i+3>0  && i+3<SIZE  && j-3>0  && j-3<SIZE)
	     {
	     flag=3;
		if ( !(( (i-1<0 || j+1<0) && (board[i+4][j-4]==1 || board[i+4][j-4]==2)) || ( (i-4>SIZE || j+4>SIZE) && (board[i-1][j+1]==1 || board	[i-1][j+1]==2)) || (board[i-1][i+1]==1 || board[i-1][i+1]==2) && (board[i+4][j-4]==1 || board[i+4][j-4]==2) ) )
	     {move=WinYourFour(board,i,j,flag,move);
	     }
	     return move;
	     } // fourth if
	  } //thrid if
	 } //second if
	} // first if
      } // inner for
}// outer for
return move;
}//function


// Once a four pattern is detected, place move at open slot
int * WinYourFour(int board[SIZE][SIZE], int a, int b, int flag, int* move)
{
switch (flag) {
	case 0:
		if (board[a][b-1]==0 && a>=0 && a<=SIZE && b-1>=0 && b-1<=SIZE)
			{move[0]=a; move[1]=b-1;}
		else if (board[a][b+4]==0 && a>=0 && a<=SIZE && b+4>=0 && b+4<=SIZE)
			{move[0]=a; move[1]=b+4;}
		break;
	case 1:
		if (board[a-1][b]==0 && a-1>=0 && a-1<=SIZE && b>=0 && b<=SIZE)
			{move[0]=a-1;move[1]=b;}
		else if (board[a+4][b]==0 && a+4>=0 && a+4<=SIZE && b>=0 && b<=SIZE)
			{move[0]=a+4; move[1]=b;}
		break;
	case 2:
		if (board[a-1][b-1]==0 && a-1>=0 && a-1<=SIZE && b-1>=0 && b-1<=SIZE )
			{move[0]=a-1;move[1]=b-1;}
		else if (board[a+4][b+4]==0 && a+4>=0 && a+4<=SIZE && b+4>=0 && b+4<=SIZE)
			{move[0]=a+4;move[1]=b+4;}
		break;
	case 3:
		if (board[a-1][b+1]==0 && a-1>=0 && a-1<=SIZE && b+1>=0 && b+1<=SIZE)
			{move[0]=a-1;move[1]=b+1;}
		else if (board[a+4][b-4]==0 && a+4>=0 && a+4<=SIZE && b-4>=0 && b-4<=SIZE)
			{move[0]=a+4;move[b]=b-4;}
		break;
}

return move;	
} //function


// Check for three pattern of either your or opponent (depending on player). Only detect, and if found, pass to MyMove
int * CheckThree(int board[SIZE][SIZE],int player, int *move)
{  int i,j; 
move[0]=-1;
move[1]=-1;
int flag=13;
for (i=0;i<SIZE;i++)
{
   for (j=0;j<SIZE;j++)
     {  
     if (board[i][j]==player)
       {  
       if (board[i][j+1]==player && i>0  && i<SIZE  && j+1>0  && j+1<SIZE)
         { 
         if (board[i][j+2]==player && i>0  && i<SIZE  && j+2>0  && j+2<SIZE)
	   {  
	     flag=0;
             move=MyMove(board, i,j,flag,player,move);
		return move;
	   }// third if
	 } //second if
	} // first if
       } //inner for  

}// outer for


for (i=0;i<SIZE;i++)
{
   for (j=0;j<SIZE;j++)
     {
     if (board[i][j]==player)
       {
       if (board[i+1][j]==player && i+1>0  && i+1<SIZE  && j>0  && j<SIZE)
         {
         if (board[i+2][j]==player && i+2>0  && i+2<SIZE  && j>0  && j<SIZE)
	   {
	   
	     flag=1;
             move=MyMove(board, i,j,flag, player,move);
	     return move;     
	  }// third if
	 } //second if
	} // first for
       } //inner for
}// outer for

for (i=0;i<SIZE;i++)
{  
   for (j=0;j<SIZE;j++)
     {
     if (board[i][j]==player)
       {  
       if (board[i+1][j+1]==player && i+1>0  && i+1<SIZE  && j+1>0  && j+1<SIZE )
         {  
         if (board[i+2][j+2]==player && i+2>0  && i+2<SIZE  && j+2>0  && j+2<SIZE )
	   { 
	     flag=2;
             move=MyMove(board, i,j,flag,player,move);
	     return move;
	  }// third if
	 } //second if
	} // first for
       } // inner for
}// outer for

for (i=0;i<SIZE;i++)
{
   for (j=0;j<SIZE;j++)
     {
     if (board[i][j]==player)
       {  
       if (board[i+1][j-1]==player && i+1>0  && i+1<SIZE  && j-1>0  && j-1<SIZE)
         { 
         if (board[i+2][j-2]==player && i+2>0  && i+2<SIZE  && j-2>0  && j-2<SIZE)
	   {  
	     flag=3; 
             move=MyMove(board, i,j,flag,player,move);
	     return move;    
	  } //third if
	 } //second if
	} // first for
      } // inner for
}// outer for
return move;
}//function


// Runs only when called from CheckThree. First checks if the three pattern is blocked on both ends or not. If it is, it checks whether it is a four patter  (for opponent) and takes action
// else, code moves on to next module. Else, it checks whether the three pattern is open at one end or closed.
// if open, it makes best possible move, closest to its own type. If closed three patter, it simply blocks it.
int* MyMove(int board[SIZE][SIZE],int a,int b,int flag,int player, int * move)
{
switch(flag){
    case 0:
	//check closed or open  
	if (CheckThreeClosed(board,a,b,flag)==1)   // function to check closed or open three
		{  //
		if ( (b-1<0 && (board[a][b+3]==1 || board[a][b+3]==2)) || (b+3>SIZE && (board[a][b-1]==1 || board[a][b-1]==2)) || (board[a][b-1]==1 || board[a][b-1]==2) && (board[a][b+3]==1 || board[a][b+3]==2)  )    // if closed at both ends, check whether one end is opponent's (for four pattern)
		 {
		   if (board[a][b+3]==2 && a>=0 && b-1>=0 && player==2 && board[a][b-1]!=1) {move[0]=a; move[1]=b-1;}
		   else if (board[a][b+3]==2 && a<=SIZE && b+3<=SIZE && player==2 && board[a][b+4]!=1) {move[0]=a;move[1]=b+4;}
			return move;		 
		 }
                 else if (board[a][b-1]!=0 || (a<0 || a>SIZE || b-1<0 || b-1>SIZE) )
			{move[0]=a; move[1]=b+3;}
		 else if (board[a][b+3]!=0 || (a<0 || a>SIZE || b+3<0 || b+3>SIZE) )
			{move[0]=a; move[1]=b-1;}

                }
        else
            { 
              int c1=0,c2=0,i,j;
	      for (i=-1;i<=1;i++)
		{  for (j=-1;j<=1;j++)
		   {  if ( (i==0 && j==0) || (i==0 && j==1))
				continue;
		      if (a+i<0 || a+i >SIZE || b+j-1 <0 || b+j-1 >SIZE)
				continue;
		       c1=c1+ board[a+i][b+j-1];
	           } //for1
		} //for2
	      for (i=-1;i<=1;i++)
		{  for (j=-1;j<=1;j++)
		   {  if ( (i==0 && j==0) || (i==0 && j==-1))
				continue;
		      if (a+i<0 || a+i >SIZE || b+j+3 <0 || b+j+3 >SIZE)
			        continue; 
			c2=c2+ board[a+i][b+j+3];
	           } 
		} 	     
             if (c1>c2)
		{move[0]=a; move[1]=b-1;}
	     else 
		{move[0]=a; move[1]=b+3;}
            }
	 break;
    case 1:
	//check closed or open
	if (CheckThreeClosed(board,a,b,flag)==1)
		{  
				if ( (a-1<0 && (board[a+3][b]==1 || board[a+3][b]==2)) || (a+3>SIZE && (board[a-1][b]==1 || board[a-1][b]==2)) || (board[a-1][b]==1 || board[a-1][b]==2) && (board[a+3][b]==1 || board[a+3][b]==2)  )   
		{	
		 if (board[a+3][b]==2 && a-1>=0 && b>=0 && player==2 && board[a-1][b]!=1) {move[0]=a-1; move[1]=b;} 
		else if (board[a+3][b]==2 && a+3<=SIZE && b<=SIZE && player==2 && board[a+4][b]!=1) {move[0]=a+4;move[1]=b;}
		return move;
		} 
                else  if ((board[a-1][b]!=0 || (a-1<0 || a-1>SIZE || b<0 || b>SIZE)) && board[a+3][b]==0 )
			{move[0]=a+3; move[1]=b;}
		 else if (board[a+3][b]!=0 || (a+3<0 && a+3>SIZE && b<0 && b>SIZE) && board[a-1][b]==0 )
			{move[0]=a-1; move[1]=b;}

                }
        else
            { 
	      int c1=0,c2=0,i,j;
	      for (i=-1;i<=1;i++)
		{  for (j=-1;j<=1;j++)
		   {  if ( (i==0 && j==0) || (i==-1 && j==0))
				continue;
		      if (a+i-1<0 || a+i-1 >SIZE || b+j <0 || b+j >SIZE)
				continue;
		       c1=c1+ board[a+i-1][b+j];
	           } //for1
		} //for2
	      for (i=-1;i<=1;i++)
		{  for (j=-1;j<=1;j++)
		   {  if ( (i==0 && j==0) || (i==-1 && j==-1))
				continue;
		      if (a+i +3<0 || a+i+3 >SIZE || b+j <0 || b+j >SIZE)
			        continue; 
			c2=c2+ board[a+i+3][b+j];
	           } //for1
		} //for2
	     if (c1>c2)
		{move[0]=a-1; move[1]=b;}
	     else 
		{move[0]=a+3; move[1]=b;}
            }
         break;

	
    case 2:
	//check closed or open
	if (CheckThreeClosed(board,a,b,flag)==1)
		{  		if ( ( (a-1<0 || b-1<0) && (board[a+3][b+3]==1 || board[a+3][b+3]==2)) || ( (b+3>SIZE || a+3>SIZE) && (board[a-1][b-1]==1 || board[a-1][b-1]==2)) || (board[a-1][b-1]==1 || board[a-1][b-1]==2) && (board[a+3][b+3]==1 || board[a+3][b+3]==2)  ) 
		{
		    if (board[a+3][b+3]==2 && a-1>=0 && b-1>=0 && player==2 && board[a-1][b-1]!=1) {move[0]=a-1;move[1]=b-1;}
		   else if (board[a+3][b+3]==2 && a+3<=SIZE && b+3<=SIZE && player==2 && board[a+4][b+4]!=1) {move[0]=a+4;move[1]=b+4;}
			return move;
			}
                   else if (board[a-1][b-1]!=0 || (a-1<0 || a-1>SIZE || b-1<0 || b-1>SIZE))
			{move[0]=a+3; move[1]=b+3;}
		   else if (board[a+3][b+3]!=0 || (a+3<0 || a+3>SIZE || b-1<0 || b-1>SIZE) )
			{move[0]=a-1; move[1]=b-1;}

                }
        else
             { 
	      int c1=0,c2=0,i,j;
	      for (i=-1;i<=1;i++)
		{  for (j=-1;j<=1;j++)
		   {  if ( (i==0 && j==0) || (i==1 && j==1))
				continue;
		      if (a+i-1<0 || a+i-1 >SIZE || b+j-1 <0 || b+j-1 >SIZE)
				continue;
		       c1=c1+ board[a+i-1][b+j-1];
	           } //for1
		} //for2
	      for (i=-1;i<=1;i++)
		{  for (j=-1;j<=1;j++)
		   {  if ( (i==0 && j==0) || (i==-1 && j==-1))
				continue;
		      if (a+i +3<0 || a+i+3 >SIZE || b+j <0 || b+j >SIZE)
			        continue; 
			c2=c2+ board[a+i+3][b+j+3];
	           } //for1
		} //for2
	     if (c1>c2)
		{move[0]=a-1; move[1]=b-1;}
	     else 
		{move[0]=a+3; move[1]=b+3;} 
            }
        break;
	
    case 3:                           
	//check closed or open
	if (CheckThreeClosed(board,a,b,flag)==1)
		{  if ( ( (a-1<0 || b+1<0) && (board[a+3][b-3]==1 || board[a+3][b-3]==2)) || ( (b-3>SIZE || a+3>SIZE) && (board[a-1][b+1]==1 || board[a-1][b+1]==2)) || (board[a-1][b+1]==1 || board[a-1][b+1]==2) && (board[a+3][b-3]==1 || board[a+3][b-3]==2)  )    
		{  
		 if (board[a+3][b-3]==2 && a-1>=0 && b+1>=0 && player==2 && board[a-1][b+1]!=1) {move[0]=a-1; move[1]=b+1;}
		else if (board[a+3][b-3]==2 && a+3<=SIZE && b-3<=SIZE && player==2 &&  board[a+4][b-4]!=1) {move[0]=a+4; move[1]=b-4;}
		return move;
		}
                 else if (board[a-1][b+1]!=0 || (a-1<0 || a-1>SIZE || b+1<0 || b+1>SIZE) )
			{move[0]=a+3; move[1]=b-3;}
		 else if (board[a+3][b-3]!=0 || (a+3<0 || a+3>SIZE || b-3<0 || b-3>SIZE))
			{move[0]=a-1; move[1]=b+1;}
                }
        else
            { 
	      int c1=0,c2=0,i,j;
	      for (i=-1;i<=1;i++)
		{  for (j=-1;j<=1;j++)
		   {  if ( (i==0 && j==0) || (i==1 && j==-1))
				continue;
		      if (a+i-1<0 || a+i-1 >SIZE || b+j+1 <0 || b+j+1 >SIZE)
				continue;
		       c1=c1+ board[a+i-1][b+j+1];
	           } //for1
		} //for2
	      for (i=-1;i<=1;i++)
		{  for (j=-1;j<=1;j++)
		   {  if ( (i==0 && j==0) || (i==-1 && j==1))
				continue;
		      if (a+i +3<0 || a+i+3 >SIZE || b+j-3<0 || b+j-3 >SIZE)
			        continue; 
			c2=c2+ board[a+i+3][b+j-3];
	           } //for1
		} //for2
	     if (c1>c2)
		{move[0]=a-1; move[1]=b+1;}
	     else 
		{move[0]=a+3; move[1]=b-3;}
            }
        break;
	}//switch
return move;

}

// Called from MyMove. Returns 1 if the three pattern detected at a,b is closed, else returns 0.
int CheckThreeClosed(int board[SIZE][SIZE],int a,int b,int flag)
{
switch (flag){
   case 0:	
        if ((board[a][b-1]!=0 || board[a][b+3]!=0) ||  b+3<0 || b+3>SIZE || b-1<0 || b-1>SIZE)
	     return 1;
        else return 0;
	break;
   case 1:	
        if ((board[a-1][b]!=0 || board[a+3][b]!=0) || a-1<0 || a-1>SIZE || a+3<0 || a+3>SIZE)
	     return 1;
        else return 0;
	break;
   case 2:	
        if ((board[a-1][b-1]!=0 || board[a+3][b+3]!=0) || a-1<0 || a-1>SIZE || a+3<0 || a+3>SIZE ||  b+3<0 || b+3>SIZE || b-1<0 || b-1>SIZE)
	     {return 1; }
        else return 0;
	break;
   case 3:	
        if ((board[a-1][b+1]!=0 || board[a+3][b-3]!=0) || a-1<0 || a-1>SIZE || a+3<0 || a+3>SIZE ||  b-3<0 || b-3>SIZE || b+1<0 || b+1>SIZE )
	     {return 1; }
	else return 0;
	break;
}//switch
}//function



// If no three patterns exist, Calculate heuristic for each open node. Heuristic is open node whose max neighbors are your type and opponents. 
// heuristic= 3*(sum of your neighbors) + opponent's--> 3 is a weight to give preference to your type over opponent's, in case of tie.
int * SimpleMove(int Board[SIZE][SIZE], int * move)
{
int max=0,i,j,i1,j1,sum1=0,sum2=0,target_a,target_b,heuristic=0;

for (i=0;i<SIZE;i++)
{   for (j=0;j<SIZE;j++)
	{  sum1=0;
	   sum2=0; 
	 for (i1=-1;i1<=1;i1++)
	   { for (j1=-1;j1<=1;j1++)
		{
		   if (Board[i+i1][j+j1]==1 && i+i1>=0 && i+i1<=SIZE && j+j1>=0 && j+j1<=SIZE && Board[i][j]==0)
			sum1=sum1 + Board[i+i1][j+j1];
		   if (Board[i+i1][j+j1]==2 && i+i1>=0 && i+i1<=SIZE && j+j1>=0 && j+j1<=SIZE && Board[i][j]==0)
			sum2=sum2 + Board[i+i1][j+j1];
		}//first for
	   }//second for
     	  heuristic=(3*sum1)+sum2;
	  if (heuristic >=max)
	    {
 		max=heuristic;
		target_a=i;
		target_b=j;
	    }	
	}//third for
}//fourth for
move[0]=target_a;
move[1]=target_b;
return move;
} // function





