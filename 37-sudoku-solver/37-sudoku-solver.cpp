class Solution {
public:
    bool solved = false;
        
    int n = 3;
    int nine = n * n;

    vector<vector<char>> board2;
    vector<vector<bool>> rows = vector<vector<bool>>(9, vector<bool>(10, false));
    vector<vector<bool>> cols = vector<vector<bool>>(9, vector<bool>(10, false));
    vector<vector<bool>> boxes = vector<vector<bool>>(9, vector<bool>(10, false));

    bool canPlace(int num, int row, int col) {
        bool rowCheck = (rows[row][num] == false);
        bool colCheck = (cols[col][num] == false);

        int boxIdx = (row / 3) * 3 + col / 3;
        bool boxCheck = (boxes[boxIdx][num] == false);

        return rowCheck && colCheck && boxCheck;
    }
        
    void placeNumber(int num, int row, int col) {
        rows[row][num] = true;
        cols[col][num] = true;

        int boxIdx = (row / 3) * 3 + col / 3;
        boxes[boxIdx][num] = true;

        board2[row][col] = num + '0';
    }

    void removeNumber(int num, int row, int col) {
        rows[row][num] = false;
        cols[col][num] = false;

        int boxIdx = (row / 3) * 3 + col / 3;
        boxes[boxIdx][num] = false;

        board2[row][col] = '.'; 
    }

    void placeNextNumber(int row, int col) {
        if ((row == nine - 1) && (col == nine - 1)) {
            solved = true;
        } else {
            if (col == nine - 1)
                backtrack(row + 1, 0);
            else backtrack(row, col + 1);
        }    
    }

    void backtrack(int row, int col) {
        if (board2[row][col] == '.') {
            for (int d = 1; d < 10; d++) {
                if (canPlace(d,row,col)) {
                    placeNumber(d,row,col);
                    placeNextNumber(row,col);

                    if (!solved)
                        removeNumber(d,row,col);  
                }
            }
        }
        else placeNextNumber(row,col);
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        this->board2 = board;
        
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char num = board[i][j];
                if (num != '.') {
                    placeNumber((int)(num - '0'),i,j);
                }
            }
        }
        backtrack(0,0);
        board = this->board2;
    }
    
};