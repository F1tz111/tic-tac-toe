#include <stdbool.h>
#include <stdio.h>

void draw_board(char board[]) {
    
    printf("# 1 2 3\n");
    for(int i=0,n=0 ;i<3;i++){

    	printf("%d",i+1);

    	for(int j = 0;j<3;j++){
    	printf(" %c",board[n]);
    	n++;
    	
    }
    	printf("\n");
    	
    }

}

void init_board(char board[]){
   for(int i = 0;i<9;i++){
       board[i] = '-';
   }
}

bool put_char(char board[],char symbol){

	char sym_pos[2];
    
    printf("current character: %c\n",symbol);
	printf("Enter position in xy-cordinate to place character: ");
	scanf("%s",sym_pos);

    
    if(sym_pos[0]<='3' && sym_pos[1]<='3' ){
	int row = (sym_pos[0]-'0') - 1;
	int col = (sym_pos[1]-'0') - 1;

	int pos = row + col * 3;

	if(pos >= 0 && pos < 9){
          if(board[pos] == 'x' || board[pos] == 'o')
            return false;       

          board[pos] = symbol;
          return true;
	
	}
}

return false;

}

bool check_winner(char board[],char symbol){
    
    if(board[0] == symbol && board[1] == symbol && board[2] == symbol)
    	return true;
    if(board[3] == symbol && board[4] == symbol && board[5] == symbol)
    	return true;
    if(board[6] == symbol && board[7] == symbol && board[8] == symbol)
    	return true;

    if(board[0] == symbol && board[3] == symbol && board[6] == symbol)
    	return true;
    if(board[1] == symbol && board[4] == symbol && board[7] == symbol)
    	return true;
    if(board[2] == symbol && board[5] == symbol && board[8] == symbol)
    	return true;

    if(board[0] == symbol && board[4] == symbol && board[8] == symbol)
    	return true;
    if(board[2] == symbol && board[4] == symbol && board[6] == symbol)
    	return true;
    
    
   
   return false;


}


int main(){
    
    char board[9];
    char symbol = 'x';
    init_board(board);
    
    while(true){
    draw_board(board);

    
    if(put_char(board,symbol)){

          if(check_winner(board,symbol))
          	break;

          if(symbol == 'x'){
          	symbol = 'o'; 
          }
          else
            symbol = 'x';
        
        }
    }

    draw_board(board);
  }   
