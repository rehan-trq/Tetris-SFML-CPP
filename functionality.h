/* PROGRAMMING FUNDAMENTAL'S PROJECT FOR FALL 2022 BS(CS)
 * You need to define the required function in the part instructed here below.
 * Avoid making any unnecessary changes, particularly the ones you don't understand.
 * The different pieces should be defined using an array - uncomment the following code once you are done creating the array.
 * TIP: Understand thoroughly before getting started with coding.
 * */
 
 // Muhammad Rehan Tariq
 // 22i-0965
 // CS-A
 
//---Piece Starts to Fall When Game Starts---//
void fallingPiece(float& timer, float& delay, int& colorNum){
    if (timer>delay){
        for (int i=0;i<4;i++){
            point_2[i][0]=point_1[i][0];
            point_2[i][1]=point_1[i][1];
            point_1[i][1]+=1;                   //How much units downward	
            
        }
        if (!anamoly()){
        	for(int i=0; i<4; i++)
        	{
        		gameGrid[point_2[i][1]][point_2[i][0]]=colorNum;
        	}
            colorNum=1+rand()%7;
            int n=rand()%7;
            //--- Un-Comment this Part When You Make BLOCKS array---//
            
                for (int i=0;i<4;i++){
                    point_1[i][0] = BLOCKS[n][i] % 2;
                    point_1[i][1] = BLOCKS[n][i] / 2;
                }
            
        }
        timer=0;
    }
}

/////////////////////////////////////////////
///*** START CODING YOUR FUNTIONS HERE ***///

void right(int& delta_x)		// for moving right
{
	
	for(int i=0; i<4; i++)
	{
		point_2[i][0]=point_1[i][0];
		point_1[i][0]+=delta_x;		//for moving one unit right
	}
	if(!anamoly())			//to check if the block is inside the grid and is not coinciding with other block
	{
		for(int i=0; i<4; i++)
		{
			point_1[i][0]=point_2[i][0];
		}
	}
	
	
	
	
}

void left(int& delta_x)		// for moving left
{
	
	for(int i=0; i<4; i++)
	{
		point_2[i][0]=point_1[i][0];
		point_1[i][0]+=delta_x;		//for moving one unit left
	}
	if(!anamoly())		//to check if the block is inside the grid and is notcoinciding with other block
	{
		for(int i=0; i<4; i++)
		{
			point_1[i][0]=point_2[i][0];
		}
	}
	
}

void rotation()		// function for rotation
{
	
	for(int r=0; r<4; r++)		//this loop is used to change the coordinates using the centre of rotation of the block
	{
		
		int x = point_1[r][1] - point_1[1][1];
		int y = point_1[r][0] - point_1[1][0];
		point_1[r][0] = point_1[1][0] + x;
		point_1[r][1] = point_1[1][1] - y;
	}
	if(!anamoly())		// it will prevent the rotation of block if it is going outside the grid or is coinciding with block
	{
		for(int r=0; r<4; r++)
		{
			
			point_1[r][0]=point_2[r][0];	 
			point_1[r][1]=point_2[r][1];
		}
	}
	
}
void rowdestroy()		//for destroying the completed rows
{
	
	int r=M-1;
	for(int i=r; i>0; i--)	//for checking all the rows  
	{
		int cnt=0;		//counter for checking if all the column in a row are full or not.
		
		for(int j=0; j<N; j++)	//for checking grids in rows i.e columns
		{
			if(gameGrid[i][j])	//to check if the row is completed i.e if it is 1 then that grid is filled and cnt will be incremented by 1
			{
				cnt++;		//if a particular column is filled it will be incremented by 1 and in the we will check if it is equal to number of column
			}
			gameGrid[r][j]=gameGrid[i][j];	//if row is destroyed the upper row will come down
			
		}
		if(cnt<N)		//if row is not completed then r will be decremented so that when the next row is destroyed the upper row will come down.
		{
			r--;
		}
	}
	
}
void instant_fall()
{
	while(anamoly())		//anamoly will check if the block is inside the grid and is not coinciding the other block
	{
		for(int i=0; i<4; i++)		//this loop will simply make the block to fall without delay i.e instant fall with same logic as used in falling piece function
		{
			
             point_2[i][0]=point_1[i][0];		
             point_2[i][1]=point_1[i][1];
             point_1[i][1]+=1; 
		}
	}
	
	for(int i=0; i<4; i++)		//this loop will keep the block inside the grid and will prevent its coincedence with other block as by the above loop 
	{
			point_1[i][1]-=1;		
	}
	
	
}

bool game_end()			// for ending the game when any space in top row is filled
{
	 
	for(int r=0; r<N; r++)		//loop will check all the spaces of the top row if either of them are  filled 
	{
		if(gameGrid[1][r])		//it will return true if any coloumn of the top row is filled 
		{
			return true;
		}
		
		
	}
		
	return false;	
}



///*** YOUR FUNCTIONS END HERE ***///
/////////////////////////////////////
