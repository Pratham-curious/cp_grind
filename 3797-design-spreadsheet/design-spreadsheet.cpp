class Spreadsheet {
private:
    vector<vector<int>> mat;

public:
    Spreadsheet(int rows) { mat.resize(rows+1, vector<int>(26, 0)); }

    void setCell(string cell, int value) {
        int row = 0, col = 0;
        col = cell[0] - 'A';
        row = stoi(cell.substr(1));
        mat[row][col] = value;
    }

    void resetCell(string cell) {
        int row = 0, col = 0;
        col = cell[0] - 'A';
        row = stoi(cell.substr(1));
        mat[row][col] = 0;
    }

    int getValue(string formula) {
        int idx = formula.find('+');
        string x = formula.substr(1, idx - 1);
        string y = formula.substr(idx + 1);
        int a = 0,b = 0;
        if (x[0] >= 'A' && x[0] <= 'Z') {
            int row = 0, col = 0;
            col = x[0] - 'A';
            row = stoi(x.substr(1));
            a = mat[row][col];
        }
        else{
            a = stoi(x);
        }
        if (y[0] >= 'A' && y[0] <= 'Z') {
            int row = 0, col = 0;
            col = y[0] - 'A';
            row = stoi(y.substr(1));
            b = mat[row][col];
        }
        else{
            b = stoi(y);
        }
        return a+b;

    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */