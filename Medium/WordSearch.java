// https://leetcode.com/problems/word-search/

public class WordSearch {
    public static void main(String[] args) {
        char[][] board = {
                {'A','B','C','E'},
                {'S','F','C','S'},
                {'A','D','E','E'}
        };
        boolean ans = exist(board, "ABCCED");
        System.out.println(ans);
    }
    public static boolean exist(char[][] board, String word) {

        for(int i = 0; i < board.length; i++){
            for(int j = 0; j < board[0].length; j++){
                if(board[i][j] == word.charAt(0)){
                    char temp = board[i][j];
                    board[i][j] = '0';
                    if(isValid(board, i, j, 1, word)){
                        return true;
                    }
                    board[i][j] = temp;
                }
            }
        }

        return false;
    }
    public static boolean isValid(char[][] board, int row, int col, int index, String word){
        if(index == word.length()){
            return true;
        }
        char temp;
        if(col != 0 && board[row][col - 1] == word.charAt(index)){
            temp = board[row][col - 1];
            board[row][col - 1] = '0';
            if(isValid(board, row, col-1, index+1, word)){
                return true;
            }
            board[row][col-1] = temp;
        }
        if(col <= board[0].length-2 && board[row][col + 1] == word.charAt(index)){
            temp = board[row][col + 1];
            board[row][col + 1] = '0';
            if(isValid(board, row, col+1, index+1, word)){
                return true;
            }
            board[row][col+1] = temp;
        }
        if(row != 0 && board[row - 1][col] == word.charAt(index)){
            temp = board[row - 1][col];
            board[row - 1][col] = '0';
            if(isValid(board, row - 1, col, index+1, word)){
                return true;
            }
            board[row - 1][col] = temp;
        }
        if(row <= board.length - 2 && board[row + 1][col] == word.charAt(index)){
            temp = board[row + 1][col];
            board[row + 1][col] = '0';
            if(isValid(board, row + 1, col, index+1, word)){
                return true;
            }
            board[row + 1][col] = temp;
        }

        return false;
    }
}
