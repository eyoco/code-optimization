#include <stdio.h>
#include "life.h"

// You are only allowed to change the contents of this file with respect 
// to improving the performance of this program



// If you need to initialize some data structures for your implementation
// of life then make changes to the following function, otherwise 
// do not change this function.

void initLife() {
}



// When completed this file will contain several versions of the life() function and 
// conditional compilation will be used to determine which version runs.  Each 
// version will be surrounded with  an ifdef, undef, and endif as illustrated 
// immediately below this comment block. To select the version of the life function 
// to use, put the #define USE USE immediately infront of the version of the life() 
// to compile.  Your version of life() must produce a correct result. 

// You are required to document the changes you make in the README.txt file. For each entry
// in the README.txt file there is to be a version of the matching  life() function here such
// that the markers can see, and run if needed,  the actual code that you used 
// to produce your results for the logged change to the life function.  


#ifdef USE
int life(long oldWorld[N][N], long newWorld[N][N]) {
  return 0;
}
#undef USE
#endif



#define USE


// For each version of life you are testing duplicate the code between the 
// ifdef and endif and make your changes. To use the new version, move the the #define 
// just about this comment to be just in front of the ifdef for the new version.

#ifdef USE

int life(long oldWorld[N][N], long newWorld[N][N]) {

  register int i, j, k, l;
  
  //clear the new world
  /*for (i = 0; i < N; i++)
    for (j = 0; j < N; j++) {
      newWorld[j][i] =  0;
    }	*/

  //int col, row;
  //int q = -1;

  register int alive = 0;
  
  //register int row_top, row_bot, col_left, col_right;
  //register int col_topleft, col_immabove, col_topright, col_immleft, col_immright, col_botleft, col_immbelow, col_botright;
  //register int row_topleft, row_immabove, row_topright, row_immleft, row_immright, row_botleft, row_immbelow, row_botright;
  //register int tmp;
  
 // for(i = 0; i < N; i++){
	//  for(j = 0; j < N; j++){
  for(j = 0; j < N; j++){
	  for(i = 0; i < N; i++){
	  	  alive += checkHealth(oldWorld[(j - 1 + N ) % N][(i -1 + N) % N] + oldWorld[(j - 1 + N ) % N][i] + 
		  		oldWorld[(j - 1 + N ) % N][(i + 1 + N) % N] + oldWorld[j][(i -1 + N) % N] + 
		  		oldWorld[j][(i + 1 + N) % N] + oldWorld[(j + 1 + N ) % N][(i -1 + N) % N] + 
		  		oldWorld[(j + 1 + N ) % N][i] + oldWorld[(j + 1 + N ) % N][(i + 1 + N) % N], oldWorld[j][i]);
	  }
  }
  return alive;
}
#undef USE
#endif


#ifdef USE

int life1(long oldWorld[N][N], long newWorld[N][N]) {	//original version

  register int i, j, k, l;
  
  //clear the new world
  /*for (i = 0; i < N; i++)
    for (j = 0; j < N; j++) {
      newWorld[j][i] =  0;
    }	*/

  //int col, row;
  register int q = -1;

  register int alive = 0;
  
  register int row_top, row_bot, col_left, col_right;
  //register int col_topleft, col_immabove, col_topright, col_immleft, col_immright, col_botleft, col_immbelow, col_botright;
  //register int row_topleft, row_immabove, row_topright, row_immleft, row_immright, row_botleft, row_immbelow, row_botright;
  register int tmp;
  
  for(i = 0; i < N; i++){
  	  col_left = (i -1 + N) % N;
  	  col_right = (i + 1 + N) % N;
	  /*col_topleft = (i -1 + N) % N;
	  col_topright = (i + 1 + N) % N;
	  col_immleft = (i -1 + N) % N;
	  col_immright = (i + 1 + N) % N;
	  col_botleft = (i - 1 + N) % N;
	  col_botright = (i + 1 + N) % N;	*/
	  for(j = 0; j < N; j++){
	  	  //newWorld[j][i] = 0;
	  	  row_top = (j - 1 + N ) % N;
		  //row_topleft = (j - 1 + N ) % N;
		  //newWorld[j][i] += oldWorld[row_topleft][col_topleft];
		  //row_immabove = (j - 1 + N ) % N;
		  //newWorld[j][i] += oldWorld[row_immabove][i];
		  //row_topright = (j - 1  + N ) % N;
		  //newWorld[j][i] += oldWorld[row_topright][col_topright];
		  //newWorld[j][i] += oldWorld[j][col_immleft];
		  //newWorld[j][i] += oldWorld[j][col_immright];
		  row_bot = (j + 1 + N ) % N;
		  //row_botleft = (j + 1 + N ) % N;
		  //newWorld[j][i] += oldWorld[row_botleft][col_botleft];
		  //row_immbelow = (j + 1  + N ) % N;
		  //newWorld[j][i] += oldWorld[row_immbelow][i];
		  //row_botright = (j + 1  + N ) % N;
		  //newWorld[j][i] += oldWorld[row_botright][col_botright];
		  tmp = oldWorld[row_top][col_left] + oldWorld[row_top][i] + oldWorld[row_top][col_right] + oldWorld[j][col_left] + oldWorld[j][col_right] + oldWorld[row_bot][col_left] + oldWorld[row_bot][i] + oldWorld[row_bot][col_right];
		  //tmp = oldWorld[row_topleft][col_topleft] + oldWorld[row_immabove][i] + oldWorld[row_topright][col_topright] + oldWorld[j][col_immleft] + oldWorld[j][col_immright] + oldWorld[row_botleft][col_botleft] + oldWorld[row_immbelow][i] + oldWorld[row_botright][col_botright];
		  //newWorld[j][i] = checkHealth(newWorld[j][i] + tmp, oldWorld[j][i]) ;
		  newWorld[j][i] = checkHealth(tmp, oldWorld[j][i]) ;
		  alive += newWorld[j][i] ? 1:0;
	  }
  }
  return alive;
}
#undef USE
#endif

#ifdef USE

int life0(long oldWorld[N][N], long newWorld[N][N]) {

  int i, j, k, l;
  
  //clear the new world
  for (i = 0; i < N; i++)
    for (j = 0; j < N; j++) {
      newWorld[j][i] =  0;
    }

  int col, row;
  int q = -1;


  // Count the cells to the top left
  for (i = 0; i < N; i++) {
    col = (i -1 + N) % N;
    for (j = 0; j < N; j++) {
      row = (j - 1 + N ) % N;
      newWorld[j][i] += oldWorld[row][col];
    }
  }
  
  // Count the cells immediately above
  for (i = 0; i < N; i++) {
    for (j = 0; j < N; j++) {
      row = (j - 1 + N ) % N;
      newWorld[j][i] += oldWorld[row][i];
    }
  }

  // Count the cells to the top right
  for (i = 0; i < N; i++) {
    col = (i + 1 + N) % N;
    for (j = 0; j < N; j++) {
      row = (j - 1  + N ) % N;
      newWorld[j][i] += oldWorld[row][col];
    }
  }

 // Count the cells to the immediate left
  for (i = 0; i < N; i++) {
    col = (i -1 + N) % N;
    for (j = 0; j < N; j++) {
       newWorld[j][i] += oldWorld[j][col];
    }
  }
  
  // Count the cells to the immediate right
  for (i = 0; i < N; i++) {
    col = (i + 1 + N) % N;
    for (j = 0; j < N; j++) {
      newWorld[j][i] += oldWorld[j][col];
    }
  }

// Count the cells to the bottom left
  for (i = 0; i < N; i++) {
    col = (i - 1 + N) % N;
    for (j = 0; j < N; j++) {
      row = (j + 1 + N ) % N;
      newWorld[j][i] += oldWorld[row][col];
    }
  }

  // Count the cells immediately below
  for (i = 0; i < N; i++) {
    for (j = 0; j < N; j++) {
      row = (j + 1  + N ) % N;
      newWorld[j][i] += oldWorld[row][i];
    }
  }

  // Count the cells to the bottom right
  for (i = 0; i < N; i++) {
    col = (i + 1 + N) % N;
    for (j = 0; j < N; j++) {
      row = (j + 1  + N ) % N;
      newWorld[j][i] += oldWorld[row][col];
    }
  }

  // Check each cell to see if it should come to life, continue to live, or die
  int alive = 0;
  
  for (i = 0; i < N; i++)
    for (j = 0; j < N; j++) {
      newWorld[j][i] = checkHealth(newWorld[j][i], oldWorld[j][i]);
      alive += newWorld[j][i] ? 1:0;
    }

  return alive;
}
#undef USE
#endif

#ifdef USE

int life2(long oldWorld[N][N], long newWorld[N][N]) {

  register int i, j, k, l;
  
  //clear the new world
  /*for (i = 0; i < N; i++)
    for (j = 0; j < N; j++) {
      newWorld[j][i] =  0;
    }	*/

  //int col, row;
  int q = -1;

  register int alive = 0;
  
  register int row_top, row_bot, col_left, col_right;
  //register int col_topleft, col_immabove, col_topright, col_immleft, col_immright, col_botleft, col_immbelow, col_botright;
  //register int row_topleft, row_immabove, row_topright, row_immleft, row_immright, row_botleft, row_immbelow, row_botright;
  register int tmp;
  
  for(i = 0; i < N; i++){
  	  col_left = (i -1 + N) % N;
  	  col_right = (i + 1 + N) % N;
	  /*col_topleft = (i -1 + N) % N;
	  col_topright = (i + 1 + N) % N;
	  col_immleft = (i -1 + N) % N;
	  col_immright = (i + 1 + N) % N;
	  col_botleft = (i - 1 + N) % N;
	  col_botright = (i + 1 + N) % N;	*/
	  for(j = 0; j < N; j++){
	  	  //newWorld[j][i] = 0;
	  	  row_top = (j - 1 + N ) % N;
		  //row_topleft = (j - 1 + N ) % N;
		  //newWorld[j][i] += oldWorld[row_topleft][col_topleft];
		  //row_immabove = (j - 1 + N ) % N;
		  //newWorld[j][i] += oldWorld[row_immabove][i];
		  //row_topright = (j - 1  + N ) % N;
		  //newWorld[j][i] += oldWorld[row_topright][col_topright];
		  //newWorld[j][i] += oldWorld[j][col_immleft];
		  //newWorld[j][i] += oldWorld[j][col_immright];
		  row_bot = (j + 1 + N ) % N;
		  //row_botleft = (j + 1 + N ) % N;
		  //newWorld[j][i] += oldWorld[row_botleft][col_botleft];
		  //row_immbelow = (j + 1  + N ) % N;
		  //newWorld[j][i] += oldWorld[row_immbelow][i];
		  //row_botright = (j + 1  + N ) % N;
		  //newWorld[j][i] += oldWorld[row_botright][col_botright];
		  tmp = oldWorld[row_top][col_left] + oldWorld[row_top][i] + 
		  		oldWorld[row_top][col_right] + oldWorld[j][col_left] + 
		  		oldWorld[j][col_right] + oldWorld[row_bot][col_left] + 
		  		oldWorld[row_bot][i] + oldWorld[row_bot][col_right];
		  //tmp = oldWorld[row_topleft][col_topleft] + oldWorld[row_immabove][i] + oldWorld[row_topright][col_topright] + oldWorld[j][col_immleft] + oldWorld[j][col_immright] + oldWorld[row_botleft][col_botleft] + oldWorld[row_immbelow][i] + oldWorld[row_botright][col_botright];
		  //newWorld[j][i] = checkHealth(newWorld[j][i] + tmp, oldWorld[j][i]) ;
		  newWorld[j][i] = checkHealth(tmp, oldWorld[j][i]) ;
		  alive += newWorld[j][i] ? 1:0;
	  }
  }
  return alive;
}
#undef USE
#endif


#ifdef USE

int life4(long oldWorld[N][N], long newWorld[N][N]) {

  register int i, j, k, l;
  
  //clear the new world
  /*for (i = 0; i < N; i++)
    for (j = 0; j < N; j++) {
      newWorld[j][i] =  0;
    }	*/

  //int col, row;
  //int q = -1;

  register int alive = 0;
  
  //register int row_top, row_bot, col_left, col_right;
  //register int col_topleft, col_immabove, col_topright, col_immleft, col_immright, col_botleft, col_immbelow, col_botright;
  //register int row_topleft, row_immabove, row_topright, row_immleft, row_immright, row_botleft, row_immbelow, row_botright;
  //register int tmp;
  
  for(i = 0; i < N; i++){
	  for(j = 0; j < N; j++){
	  	  alive += checkHealth(oldWorld[(j - 1 + N ) % N][(i -1 + N) % N] + oldWorld[(j - 1 + N ) % N][i] + 
		  		oldWorld[(j - 1 + N ) % N][(i + 1 + N) % N] + oldWorld[j][(i -1 + N) % N] + 
		  		oldWorld[j][(i + 1 + N) % N] + oldWorld[(j + 1 + N ) % N][(i -1 + N) % N] + 
		  		oldWorld[(j + 1 + N ) % N][i] + oldWorld[(j + 1 + N ) % N][(i + 1 + N) % N], oldWorld[j][i]);
	  }
  }
  return alive;
}
#undef USE
#endif


#ifdef USE

int life3(long oldWorld[N][N], long newWorld[N][N]) {

  register int i, j, k, l;
  
  //clear the new world
  /*for (i = 0; i < N; i++)
    for (j = 0; j < N; j++) {
      newWorld[j][i] =  0;
    }	*/

  //int col, row;
  //int q = -1;

  register int alive = 0;
  
  //register int row_top, row_bot, col_left, col_right;
  //register int col_topleft, col_immabove, col_topright, col_immleft, col_immright, col_botleft, col_immbelow, col_botright;
  //register int row_topleft, row_immabove, row_topright, row_immleft, row_immright, row_botleft, row_immbelow, row_botright;
  //register int tmp;
  
  for(i = 0; i < N; i++){
  	  //col_left = (i -1 + N) % N;
  	  //col_right = (i + 1 + N) % N;
	  /*col_topleft = (i -1 + N) % N;
	  col_topright = (i + 1 + N) % N;
	  col_immleft = (i -1 + N) % N;
	  col_immright = (i + 1 + N) % N;
	  col_botleft = (i - 1 + N) % N;
	  col_botright = (i + 1 + N) % N;	*/
	  for(j = 0; j < N; j++){
	  	  //newWorld[j][i] = 0;
	  	  //row_top = (j - 1 + N ) % N;
		  //row_topleft = (j - 1 + N ) % N;
		  //newWorld[j][i] += oldWorld[row_topleft][col_topleft];
		  //row_immabove = (j - 1 + N ) % N;
		  //newWorld[j][i] += oldWorld[row_immabove][i];
		  //row_topright = (j - 1  + N ) % N;
		  //newWorld[j][i] += oldWorld[row_topright][col_topright];
		  //newWorld[j][i] += oldWorld[j][col_immleft];
		  //newWorld[j][i] += oldWorld[j][col_immright];
		  //row_bot = (j + 1 + N ) % N;
		  //row_botleft = (j + 1 + N ) % N;
		  //newWorld[j][i] += oldWorld[row_botleft][col_botleft];
		  //row_immbelow = (j + 1  + N ) % N;
		  //newWorld[j][i] += oldWorld[row_immbelow][i];
		  //row_botright = (j + 1  + N ) % N;
		  //newWorld[j][i] += oldWorld[row_botright][col_botright];
		  /*tmp = oldWorld[(j - 1 + N ) % N][(i -1 + N) % N] + oldWorld[(j - 1 + N ) % N][i] + 
		  		oldWorld[(j - 1 + N ) % N][(i + 1 + N) % N] + oldWorld[j][(i -1 + N) % N] + 
		  		oldWorld[j][(i + 1 + N) % N] + oldWorld[(j + 1 + N ) % N][(i -1 + N) % N] + 
		  		oldWorld[(j + 1 + N ) % N][i] + oldWorld[(j + 1 + N ) % N][(i + 1 + N) % N];	*/
		  /*	tmp = oldWorld[row_top][col_left] + oldWorld[row_top][i] + 
		  		oldWorld[row_top][col_right] + oldWorld[j][col_left] + 
		  		oldWorld[j][col_right] + oldWorld[row_bot][col_left] + 
		  		oldWorld[row_bot][i] + oldWorld[row_bot][col_right];	*/
		  //tmp = oldWorld[row_topleft][col_topleft] + oldWorld[row_immabove][i] + oldWorld[row_topright][col_topright] + oldWorld[j][col_immleft] + oldWorld[j][col_immright] + oldWorld[row_botleft][col_botleft] + oldWorld[row_immbelow][i] + oldWorld[row_botright][col_botright];
		  //newWorld[j][i] = checkHealth(newWorld[j][i] + tmp, oldWorld[j][i]) ;
		  //newWorld[j][i] = checkHealth(tmp, oldWorld[j][i]) ;
		  //alive += checkHealth(tmp, oldWorld[j][i])  ? 1:0;
		  /*alive += checkHealth(oldWorld[(j - 1 + N ) % N][(i -1 + N) % N] + oldWorld[(j - 1 + N ) % N][i] + 
		  		oldWorld[(j - 1 + N ) % N][(i + 1 + N) % N] + oldWorld[j][(i -1 + N) % N] + 
		  		oldWorld[j][(i + 1 + N) % N] + oldWorld[(j + 1 + N ) % N][(i -1 + N) % N] + 
		  		oldWorld[(j + 1 + N ) % N][i] + oldWorld[(j + 1 + N ) % N][(i + 1 + N) % N], oldWorld[j][i])  ? 1:0;	*/
	  	 if(j == 0 && i != 0 && i != N-1){
	  	 	alive += checkHealth(oldWorld[j][(i -1 + N) % N] + oldWorld[(j + 1 + N ) % N][(i - 1 + N) % N] + 
		  		oldWorld[(j + 1  + N ) % N][i] + oldWorld[(j + 1  + N ) % N][(i + 1 + N) % N] + 
		  		oldWorld[j][(i + 1 + N) % N] , oldWorld[j][i]);
	  	 } else if(j == N-1 && i != 0 && i != N-1){
	  	  alive += checkHealth(oldWorld[j][(i -1 + N) % N] + oldWorld[(j - 1 + N ) % N][(i -1 + N) % N] + 
		  		oldWorld[(j - 1 + N ) % N][i] + oldWorld[(j - 1  + N ) % N][(i + 1 + N) % N] + 
		  		oldWorld[j][(i + 1 + N) % N], oldWorld[j][i]);
	  	 } else {
	  	 	alive += checkHealth(oldWorld[(j - 1 + N ) % N][(i -1 + N) % N] + oldWorld[(j - 1 + N ) % N][i] + 
		  		oldWorld[(j - 1 + N ) % N][(i + 1 + N) % N] + oldWorld[j][(i -1 + N) % N] + 
		  		oldWorld[j][(i + 1 + N) % N] + oldWorld[(j + 1 + N ) % N][(i -1 + N) % N] + 
		  		oldWorld[(j + 1 + N ) % N][i] + oldWorld[(j + 1 + N ) % N][(i + 1 + N) % N], oldWorld[j][i]);
	  	 }
	  }
  }
  return alive;
}
#undef USE
#endif


#ifdef USE

int life5(long oldWorld[N][N], long newWorld[N][N]) {

  register int i, j, k, l;
  
  //clear the new world
  /*for (i = 0; i < N; i++)
    for (j = 0; j < N; j++) {
      newWorld[j][i] =  0;
    }	*/

  //int col, row;
  //int q = -1;

  register int alive = 0;
  
  //register int row_top, row_bot, col_left, col_right;
  //register int col_topleft, col_immabove, col_topright, col_immleft, col_immright, col_botleft, col_immbelow, col_botright;
  //register int row_topleft, row_immabove, row_topright, row_immleft, row_immright, row_botleft, row_immbelow, row_botright;
  //register int tmp;
  
  for(i = 0; i < N; i++){
  	  //col_left = (i -1 + N) % N;
  	  //col_right = (i + 1 + N) % N;
	  /*col_topleft = (i -1 + N) % N;
	  col_topright = (i + 1 + N) % N;
	  col_immleft = (i -1 + N) % N;
	  col_immright = (i + 1 + N) % N;
	  col_botleft = (i - 1 + N) % N;
	  col_botright = (i + 1 + N) % N;	*/
	  for(j = 0; j < N; j++){
	  	  //newWorld[j][i] = 0;
	  	  //row_top = (j - 1 + N ) % N;
		  //row_topleft = (j - 1 + N ) % N;
		  //newWorld[j][i] += oldWorld[row_topleft][col_topleft];
		  //row_immabove = (j - 1 + N ) % N;
		  //newWorld[j][i] += oldWorld[row_immabove][i];
		  //row_topright = (j - 1  + N ) % N;
		  //newWorld[j][i] += oldWorld[row_topright][col_topright];
		  //newWorld[j][i] += oldWorld[j][col_immleft];
		  //newWorld[j][i] += oldWorld[j][col_immright];
		  //row_bot = (j + 1 + N ) % N;
		  //row_botleft = (j + 1 + N ) % N;
		  //newWorld[j][i] += oldWorld[row_botleft][col_botleft];
		  //row_immbelow = (j + 1  + N ) % N;
		  //newWorld[j][i] += oldWorld[row_immbelow][i];
		  //row_botright = (j + 1  + N ) % N;
		  //newWorld[j][i] += oldWorld[row_botright][col_botright];
		  /*tmp = oldWorld[(j - 1 + N ) % N][(i -1 + N) % N] + oldWorld[(j - 1 + N ) % N][i] + 
		  		oldWorld[(j - 1 + N ) % N][(i + 1 + N) % N] + oldWorld[j][(i -1 + N) % N] + 
		  		oldWorld[j][(i + 1 + N) % N] + oldWorld[(j + 1 + N ) % N][(i -1 + N) % N] + 
		  		oldWorld[(j + 1 + N ) % N][i] + oldWorld[(j + 1 + N ) % N][(i + 1 + N) % N];	*/
		  /*	tmp = oldWorld[row_top][col_left] + oldWorld[row_top][i] + 
		  		oldWorld[row_top][col_right] + oldWorld[j][col_left] + 
		  		oldWorld[j][col_right] + oldWorld[row_bot][col_left] + 
		  		oldWorld[row_bot][i] + oldWorld[row_bot][col_right];	*/
		  //tmp = oldWorld[row_topleft][col_topleft] + oldWorld[row_immabove][i] + oldWorld[row_topright][col_topright] + oldWorld[j][col_immleft] + oldWorld[j][col_immright] + oldWorld[row_botleft][col_botleft] + oldWorld[row_immbelow][i] + oldWorld[row_botright][col_botright];
		  //newWorld[j][i] = checkHealth(newWorld[j][i] + tmp, oldWorld[j][i]) ;
		  //newWorld[j][i] = checkHealth(tmp, oldWorld[j][i]) ;
		  //alive += checkHealth(tmp, oldWorld[j][i])  ? 1:0;
		  /*alive += checkHealth(oldWorld[(j - 1 + N ) % N][(i -1 + N) % N] + oldWorld[(j - 1 + N ) % N][i] + 
		  		oldWorld[(j - 1 + N ) % N][(i + 1 + N) % N] + oldWorld[j][(i -1 + N) % N] + 
		  		oldWorld[j][(i + 1 + N) % N] + oldWorld[(j + 1 + N ) % N][(i -1 + N) % N] + 
		  		oldWorld[(j + 1 + N ) % N][i] + oldWorld[(j + 1 + N ) % N][(i + 1 + N) % N], oldWorld[j][i])  ? 1:0;	*/
	  	 if(j == 0 && i != 0 && i != N-1){
	  	 	alive += checkHealth(oldWorld[j][(i -1 + N) % N] + oldWorld[(j + 1 + N ) % N][(i - 1 + N) % N] + 
		  		oldWorld[(j + 1  + N ) % N][i] + oldWorld[(j + 1  + N ) % N][(i + 1 + N) % N] + 
		  		oldWorld[j][(i + 1 + N) % N] , oldWorld[j][i]);
	  	 } else if(j == N-1 && i != 0 && i != N-1){
	  	  alive += checkHealth(oldWorld[j][(i -1 + N) % N] + oldWorld[(j - 1 + N ) % N][(i -1 + N) % N] + 
		  		oldWorld[(j - 1 + N ) % N][i] + oldWorld[(j - 1  + N ) % N][(i + 1 + N) % N] + 
		  		oldWorld[j][(i + 1 + N) % N], oldWorld[j][i]);
	  	 } else if(i == 0 && j != 0 && j != N-1){
			 alive += checkHealth(oldWorld[(j - 1 + N ) % N][i] + oldWorld[(j - 1  + N ) % N][(i -1 + N) % N] + 
		  		oldWorld[j][(i -1 + N) % N] + oldWorld[(j + 1 + N ) % N][(i + 1 + N) % N] + 
		  		oldWorld[(j + 1  + N ) % N][i], oldWorld[j][i]);
		 } else if(i == N-1 && j != 0 && j != N-1){
			 alive += checkHealth(oldWorld[(j - 1 + N ) % N][i] + oldWorld[(j - 1 + N ) % N][(i + 1 + N) % N] + 
		  		oldWorld[j][(i + 1 + N) % N] + oldWorld[(j + 1  + N ) % N][(i - 1 + N) % N] + 
		  		oldWorld[(j + 1  + N ) % N][i], oldWorld[j][i]);
		 } else 
			{
	  	 	alive += checkHealth(oldWorld[(j - 1 + N ) % N][(i -1 + N) % N] + oldWorld[(j - 1 + N ) % N][i] + 
		  		oldWorld[(j - 1 + N ) % N][(i + 1 + N) % N] + oldWorld[j][(i -1 + N) % N] + 
		  		oldWorld[j][(i + 1 + N) % N] + oldWorld[(j + 1 + N ) % N][(i -1 + N) % N] + 
		  		oldWorld[(j + 1 + N ) % N][i] + oldWorld[(j + 1 + N ) % N][(i + 1 + N) % N], oldWorld[j][i]);
	  	 }
	  }
  }
  return alive;
}
#undef USE
#endif


#ifdef USE

int life6(long oldWorld[N][N], long newWorld[N][N]) {

  register int i, j, k, l;
  
  //clear the new world
  /*for (i = 0; i < N; i++)
    for (j = 0; j < N; j++) {
      newWorld[j][i] =  0;
    }	*/

  //int col, row;
  //int q = -1;

  register int alive = 0;
  
  //register int row_top, row_bot, col_left, col_right;
  //register int col_topleft, col_immabove, col_topright, col_immleft, col_immright, col_botleft, col_immbelow, col_botright;
  //register int row_topleft, row_immabove, row_topright, row_immleft, row_immright, row_botleft, row_immbelow, row_botright;
  //register int tmp;
  
  for(i = 0; i < N; i++){
	  for(j = 0; j < N; j++){
	  	  alive += checkHealth(oldWorld[(j - 1 + N ) % N][(i -1 + N) % N] + oldWorld[(j - 1 + N ) % N][i] + 
		  		oldWorld[(j - 1 + N ) % N][(i + 1 + N) % N] + oldWorld[j][(i -1 + N) % N] + 
		  		oldWorld[j][(i + 1 + N) % N] + oldWorld[(j + 1 + N ) % N][(i -1 + N) % N] + 
		  		oldWorld[(j + 1 + N ) % N][i] + oldWorld[(j + 1 + N ) % N][(i + 1 + N) % N], oldWorld[j][i]);
	  }
  }
  return alive;
}
#undef USE
#endif