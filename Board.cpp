#include "Board.h"
#include<iostream>
#include <cstdlib>

void Board::init()
{
    bool flag=true;
    while(flag)
    {
        int i = rand()%4;
        int j = rand()%4;
        int z = rand()%10;
        if(board[i][j]==0)
        {
            if( z>=8 ) board[i][j] = 4;
            else board[i][j] = 2;
            flag=false;
        }
    }
}

bool Board::checkUp()
{
    for(int i = 0; i < 4; i++)
    {
        //if (board[0][i] == 0 && board[1][i] == 0 && board[2][i] == 0 && board[3][i] == 0) continue;
        for(int j = 3; j > 0 ; j--)
        {
            for(int z = j-1; z >= 0; z--)
            {
                if( board[j][i] == board[z][i] && board[j][i] != 0 && board[z][i] != 0  ) return true;
                if( board[j][i] != board[z][i] && board[z][i] == 0 ) return true;
                if ( board [j][i] != board[z][i] && board[z][i] != 0 ) break;
            }
        }
    }
    return false;
}

bool Board::checkDown()
{
    for(int i = 0; i < 4; i++)
    {
        //if (board[0][i] == 0 && board[1][i] == 0 && board[2][i] == 0 && board[3][i] == 0) continue;
        for(int j = 0; j < 3 ; j++)
        {
            for(int z = j+1; z < 4; z++)
            {
                if( board[j][i] == board[z][i] && board[j][i] != 0 && board[z][i] != 0    ) return true;
                if( board[j][i] != board[z][i] && board[z][i] == 0 ) return true;
                if ( board [j][i] != board[z][i] && board[z][i] != 0 ) break;
            }
        }
    }
    return false;
}

bool Board::checkRight()
{
    for(int i = 0; i < 4; i++)
    {
        //if (board[i][0] == 0 && board[i][1] == 0 && board[i][2] == 0 && board[i][3] == 0) continue;
        for(int j = 0; j < 3; j++)
        {
            for(int z = j+1; z < 4; z++)
            {
                if( board[i][j] == board[i][z] && board[i][j] != 0 && board[i][z] != 0 ) return true;
                if( board[i][j] != board[i][z] && board[i][z] == 0 ) return true;
                if ( board [i][j] != board[i][z] && board[i][z] != 0 ) break;
            }
        }
    }
    return false;
}

bool Board::checkLeft()
{
    for(int i = 0; i < 4; i++)
    {
        //if (board[i][0] == 0 && board[i][1] == 0 && board[i][2] == 0 && board[i][3] == 0) continue;
        for(int j = 3; j > 0 ; j--)
        {
            for(int z = j-1; z >= 0; z--)
            {
                if( board[i][j] == board[i][z] && board[i][j] != 0 && board[i][z] != 0 ) return true;
                if( board[i][j] != board[i][z] && board[i][z] == 0 ) return true;
                if ( board [i][j] != board[i][z] && board[i][z] != 0 ) break;
            }
        }
    }
    return false;
}

void Board::Up()
{
    for(int i = 0; i < 4; i++)
    {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[2][i] == board[3][i] && board[0][i] != 0)
        {
            board[0][i] = board[0][i] * 2;
            board[1][i] = board[1][i] *2;
            board[2][i] = 0;
            board[3][i] =0;
            continue;
        }
        for(int j = 0; j < 3; j++)
        {
            if( board[j][i] == 0 )
            {
                for (int k = j+1; k < 4; k++)
                {
                    if( board[k][i] != 0)
                    {
                        board[j][i] = board[k][i];
                        board[k][i] = 0 ;
                        break;
                    }
                }
            }
        }
        for(int j = 0; j < 2;j++)
        {
            if(board[j][i] == board[j+1][i])
            {
                board[j][i] += board[j+1][i];
                board[j+1][i] = board[j+2][i];
                if(j == 0)
                {
                    board[j+2][i] = board[j+3][i];
                    board[j+3][i] = 0 ;
                }
                else board[j+2][i] = 0;
            }
        }
        if(board[2][i] == board[3][i])
        {
            board[2][i] = board[2][i]*2;
            board[3][i] = 0;
        }
    }

}

void Board::Down()
{
    for(int i = 0; i < 4; i++)
    {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[2][i] == board[3][i] && board[0][i] != 0)
        {
            board[3][i] = board[0][i] * 2;
            board[2][i] = board[1][i] *2;
            board[1][i] = 0;
            board[0][i] =0;
            continue;
        }
        for(int j = 3; j > 0; j--)
        {
            if( board[j][i] == 0 )
            {
                for (int k = j-1; k >= 0; k--)
                {
                    if( board[k][i] != 0)
                    {
                        board[j][i] = board[k][i];
                        board[k][i] = 0 ;
                        break;
                    }
                }
            }
        }
        for(int j = 3; j > 1;j--)
        {
            if(board[j][i] == board[j-1][i])
            {
                board[j][i] += board[j-1][i];
                board[j-1][i] = board[j-2][i];
                if(j == 3)
                {
                    board[j-2][i] = board[j-3][i];
                    board[j-3][i] = 0;
                }
                else board[j-2][i] = 0;
            }
        }
        if(board[0][i] == board[1][i])
        {
            board[1][i] = board[1][i]*2;
            board[0][i] = 0;
        }
    }
}

void Board::Right()
{
    for(int i = 0; i < 4; i++)
    {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][2] == board[i][3] && board[i][1] != 0)
        {
            board[i][3] = board[i][0] * 2;
            board[i][2] = board[i][1] *2;
            board[i][1] = 0;
            board[i][0] =0;
            continue;
        }
        for(int j = 3; j > 0; j--)
        {
            if( board[i][j] == 0 )
            {
                for (int k = j-1; k >= 0; k--)
                {
                    if( board[i][k] != 0)
                    {
                        board[i][j] = board[i][k];
                        board[i][k] = 0 ;
                        break;
                    }
                }
            }
        }
        for(int j = 3; j > 1;j--)
        if(board[i][j] == board[i][j-1])
        {
            board[i][j] += board[i][j-1];
            board[i][j-1] = board[i][j-2];
            if( j == 3 )
            {
                board[i][j-2] = board[i][j-3];
                board[i][j-3] = 0;
            }
            else board[i][j-2] = 0;

        }
        if(board[i][0] == board[i][1])
        {
            board[i][1] = board[i][1]*2;
            board[i][0] = 0;
        }
    }
}

void Board::Left()
{
    for(int i = 0; i < 4; i++)
    {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][2] == board[i][3] && board[i][1] != 0)
        {
            board[i][0] = board[i][0] * 2;
            board[i][1] = board[i][1] *2;
            board[i][2] = 0;
            board[i][3] =0;
            continue;
        }
        for(int j = 0; j < 3; j++)
        {
            if( board[i][j] == 0 )
            {
                for (int k = j+1; k < 4; k++)
                {
                    if( board[i][k] != 0)
                    {
                        board[i][j] = board[i][k];
                        board[i][k] = 0 ;
                        break;
                    }
                }
            }
        }
        for(int j = 0; j < 2;j++)
        if(board[i][j] == board[i][j+1])
        {
            board[i][j] += board[i][j+1];
            board[i][j+1] = board[i][j+2];
            if(j == 0)
            {
                board[i][j+2] = board[i][j+3];
                board[i][j+3] = 0;
            }
            else board[i][j+2] = 0;
        }
        if(board[i][2] == board[i][3])
        {
            board[i][2] = board[i][2]*2;
            board[i][3] = 0;
        }

    }
}

