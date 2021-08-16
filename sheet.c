#include <stdio.h>
#include <string.h>
#include <stdbool.h>

char d (int argc, char *argv[], char delim, char line []);
void chek_delim(int argc, char *argv[], char delim, char line[]);
int arow ( char line[], char delim, int arow_bool);
int irow ( char line[], char delim,int counter_line, char irow_buffer[], int irow_row);
int drow ( int counter_line, int row, int drow_bool);
void icol ( char line[], char delim, int column, int bool1_1);
void acol ( char line[], char delim);
void dcol ( char line[], char delim, int column, int cset_bool, int bool_1);
void cset ( char *argv[], char line[], char delim, int j, int column, int buffer_switch, char bufer_1[], char bufer_2[]);
void toupper ( char line[], char delim, int column);
void tolower ( char line[], char delim, int column);
void round_ (int argc, char *argv[], char line[], char delim, int column);
void integer (int argc, char *argv[], char line[], char delim, int column);
void copy ( char *argv[], char line[], char delim, int j, int copy_line1, int copy_line2, int buffer_switch);
void swap ( char *argv[], char line[], char delim, int j, int copy_line1, int copy_line2, int buffer_switch);
void move ( char *argv[], char line[], char delim, int j, int copy_line1, int copy_line2, int buffer_switch);
int contains (int argc, char *argv[], char delim, char line[], int column, int j, int counter_line, int rows_bool);
int main(int argc, char *argv[]) {
    char tab = getc (stdin);
    char line[10240];
    char delim = " ";
   
    int counter_line=0;
    int row;                             // row - line number entered by the user
    int j = 0;
    char irow_buffer[100];
    int irow_row = -1;
    int buffer_switch = 0;                // changing the buffer for cset
    bool drow_bool = false;
    bool cset_bool = false;
    bool arow_bool = false;
    bool arow_bool1= false;
    bool arow_bool2= false;
    bool rows_bool = false;
    bool argv_bool1 =  true;
    bool argv_bool2 = true;

    while(tab!=EOF || arow_bool == 1 && arow_bool1 == 0){
        if(tab == EOF)
            arow_bool1 = 1;
        ungetc(tab, stdin);
        if (irow_row != counter_line)
            scanf ("%[^\n]%*c", &line);
        else{ 
            for (int i = 0; irow_buffer[i] != NULL; i++)
                line[i] = irow_buffer[i];
        }
        counter_line++;
        
        delim = d (argc, argv, delim, line);
        chek_delim(argc, argv, delim, line);

        for(j = 0; j < argc; j++){
            if(strcmp(argv[j], "arow") == 0){
                arow (line, delim, arow_bool);
                arow_bool2 = 1;
            }
            if(strcmp(argv[j], "irow") == 0){
                irow_row = atoi(argv[j+1]);
                irow ( line, delim, counter_line, irow_buffer, irow_row);
                // arow_bool2 = 1;
            }
            if(strcmp(argv[j], "rows") == 0){
                int rows_N = 0;
                int rows_M = 0;
                    rows_N = atoi(argv[j+1]);
                    rows_M = atoi(argv[j+2]);
                while (rows_N <= rows_M){
                    if(rows_N != counter_line)
                        rows_bool = 1;
                    rows_N ++;
                }
            }
            if(strcmp(argv[j], "contains") == 0){
                int column = 0;
                    column = atoi(argv[j+1]);
                contains (argc, argv, delim, line, column, j, counter_line, rows_bool);
                rows_bool = contains (argc, argv, delim, line, column, j, counter_line, rows_bool);
            }
            if(rows_bool == 0){

                if(strcmp(argv[j], "drow") == 0){
                    if (argv_bool1 = 1)
                        row = atoi(argv[j+1]);
                    drow (counter_line, row, drow_bool);
                    drow_bool = drow (counter_line, row, drow_bool);
                }
                if(strcmp(argv[j], "drows") == 0){
                    int row2 = 0;
                        row = atoi(argv[j+1]);
                        row2 = atoi(argv[j+2]);
                    for (;row <= row2; row++){
                        drow (counter_line, row, drow_bool);
                        drow_bool = drow (counter_line, row, drow_bool);                    
                    }
                }    
                if(strcmp(argv[j], "icol") == 0){
                    int bool1_1 = 0;
                    if (strcmp (argv[j+1],"1") == 0)
                        bool1_1 = 1;
                    int column = atoi (argv[j+1]);
                    icol ( line, delim, column, bool1_1);
                }
                if(strcmp(argv[j], "acol") == 0){
                    acol (line, delim);
                }

                if(strcmp(argv[j], "dcol") == 0){
                    int bool_1 = 0;
                    if (strcmp (argv[j+1],"1") == 0)
                        bool_1 = 1;
                    int column = atoi (argv[j+1]);
                    dcol (line, delim, column, cset_bool, bool_1);
                }
                if(strcmp(argv[j], "dcols") == 0){
                    int bool_1 = 0;
                    if (strcmp (argv[j+1],"1") == 0)
                        bool_1 = 1;
                    int column = atoi (argv[j+2]);
                    int column2 = atoi (argv[j+1]);
                    for(;column >= column2; column--)
                    dcol (line, delim, column, cset_bool, bool_1);
                }
                if(strcmp(argv[j], "cset") == 0){
                    int bool_1 = 0;
                    if (strcmp (argv[j+1],"1") == 0)
                        bool_1 = 1;                
                    int column = atoi (argv[j+1]);
                    cset_bool = 1;
                    char bufer_1[100];
                    char bufer_2[100];
                    dcol (line, delim, column, cset_bool, bool_1);
                    cset (argv, line, delim, j, column, buffer_switch, bufer_1, bufer_2);
                }
                if(strcmp(argv[j], "toupper") == 0){
                    int column = atoi (argv[j+1]);
                    column -= 1;
                    toupper (line, delim, column);
                }
                if(strcmp(argv[j], "tolower") == 0){
                    int column = atoi (argv[j+1]);
                    column -= 1;
                    tolower (line, delim, column);
                }
                if(strcmp(argv[j], "round") == 0){
                    int column = atoi (argv[j+1]);
                    round_ (argc, argv, line, delim, column);
                }
                if(strcmp(argv[j], "int") == 0){
                    int column = atoi (argv[j+1]);
                    integer (argc, argv, line, delim, column);                    
                }
                if(strcmp(argv[j], "copy") == 0){
                    int copy_line1 = atoi (argv[j+2]);
                    int copy_line2 = atoi (argv[j+1]);
                    copy ( argv, line, delim, j, copy_line2, copy_line1, buffer_switch);
                }
                if(strcmp(argv[j], "swap") == 0){
                    int copy_line1 = atoi (argv[j+2]);
                    int copy_line2 = atoi (argv[j+1]);
                    swap ( argv, line, delim, j, copy_line2, copy_line1, buffer_switch);
                }
                if(strcmp(argv[j], "move") == 0){
                    int copy_line1 = atoi (argv[j+2]);
                    int copy_line2 = atoi (argv[j+1]);
                    move ( argv, line, delim, j, copy_line2, copy_line1, buffer_switch);
                }
            }
        }
        rows_bool = 0;
        tab=getc(stdin);
        if (arow_bool2 == 1){
            if (arow_bool == 0){
                    if(tab == EOF)
                        arow_bool = 1;
            }
        }

        if (drow_bool == 0)
            printf("%s\n", line);
        drow_bool = 0;
    }
}   
char d (int argc, char *argv[], char delim, char line[]){
    // DELIM
    for(int j=0; j<argc; j++){
        if(strcmp(argv[j], "-d") == 0){
            delim = argv[j+1][0];
            }
        }
    return delim;
}
void chek_delim(int argc, char *argv[], char delim, char line[]){
// check divisorsfor delim
    for(int j=0; j<argc; j++){
        if(strcmp(argv[j], "-d") == 0){
            delim = argv[j+1][0];
            for(int i = 0; argv[j+1][i] != NULL; i++){
                for(int k = 0; line[k] != NULL; k++){
                    if(line[k] == argv[j+1][i])
                        line[k] = delim;
                    }
                }
        }
    }
    return;
}
int contains (int argc, char *argv[], char delim, char line[], int column, int j, int counter_line, int rows_bool){
    char bufer[100];
    char bufer_argv[100];
    int qt_delim = 0;
    int symbol = 0;
    memset(bufer, 0, 100);
    memset(bufer_argv, 0, 100);
    rows_bool = 1;

    for(int i = 0; argv[j+2][i] != NULL; i++){
        bufer_argv[i] = argv[j+2][i];

    }   
    for(int i = 0; qt_delim != column-1; i++){
        symbol++;
        if (line[i] == delim) qt_delim++;
    }
    for(int i = 0; line[symbol] != delim; i++, symbol++){
        bufer[i] = line[symbol];
    }
    int l = 0;
    int k = 0;
    for(int i = 0; bufer[i] != NULL; i++)
        l++;

    for (int i = 0; bufer_argv[i] != NULL; i++) {
        if(bufer[i] == bufer_argv[i])
            k++;
    }
    if(k == l)
        rows_bool = 0;
    else
        rows_bool = 1;
    return rows_bool;
}        
int arow ( char line[], char delim, int arow_bool){
    int qt_delim = 0;
    for(int i = 0; line[i] != NULL; i++){
        if(line[i] == delim)
            qt_delim++;
    }
    if (arow_bool == 1){
        for(int i = 0; i <= qt_delim; i++)
            line[i] = delim;
    line[qt_delim] = '\0';
    }
       
    return 0;
}
int irow ( char line[], char delim,int counter_line, char irow_buffer[], int irow_row){
    int qt_delim = 0;
    for(int i = 0; line[i] != NULL; i++){
        if(line[i] == delim)
            qt_delim++;
    }
    if (irow_row == counter_line){
        for (int i = 0; line[i] != NULL; i++)
            irow_buffer[i] = line[i];
        for(int i = 0; i <= qt_delim; i++){
            line[i] = delim;
        }
        line[qt_delim] = '\0';
    }
return irow_row;
}
int drow ( int counter_line, int row, int drow_bool){
    if(row==counter_line) {
        drow_bool = 1;
    }
    return drow_bool;
}
void icol ( char line[], char delim, int column, int bool1_1){
    int qtdel = 0;
    int qtstr = 0;
    int q = 0;
    column -= 1;
    // creating the first cell
    if (bool1_1 == 1){
        for (int i = 10240; i > -1; i--){
            line[i+1] = line[i];
        }
        line[0] = delim;
    }
    else{
    // find where the first "delim" of the cell 
        for (int i = 0; i < 10240; i++){
            if (line[i] == delim) qtdel++;
            if (qtdel == column) break;
            qtstr++;
        }
    // extend the line by copying the dilim
        for (int i = 10240; i > qtstr-1; i--){
            line[i+1] = line[i];
        }
    }
    return;
}
void acol (char line[], char delim){
    int counter = 0;
    for (int i = 0; line[i] != NULL; i++) counter++;
        line [counter] = delim;
        line [counter+1] = '\0';
        
}
void dcol ( char line[], char delim, int column, int cset_bool, int bool_1){
    int qt_dcol_1 = 0;
    int qt_dcol_2 = 0;
    int qt_symbol_1 = 0;
    int qt_symbol_2 = 0;
    int bool_2 = 0;
    column = column-1;
    // if the user entered 1 cell, then this process is executed
    if (bool_1 == 1){
        int j = 0;
        for(;line[j] != delim; j++){}
        for (int i = 0; line[i]!=NULL ; i++){
            if(cset_bool == 0)
                line[i] = line[i+j+1];
            if(cset_bool == 1)
                line[i] = line[i+j];
        }
    }
    else{
        // find where the first "delim" of the cell 
        for(int i = 0; i < 10240; i++){
            if (line[i] == delim) qt_dcol_1++;
            if (column == qt_dcol_1) bool_1 = 1;
            if (bool_1 == 0) qt_symbol_1++;
        // find where the last "delim" of the cell 
            if (line[i] == delim || line[i] == NULL) qt_dcol_2++;
            if (column+1 == qt_dcol_2) bool_2 = 1;
            if (bool_2 == 0) qt_symbol_2++;
        }
// process of rewriting an array with overlaying information on a user-selected cell
        // without first "delim"
        if(cset_bool == 1){
            for (int i = 0; line[i]!=NULL ; i++){
                line[i+qt_symbol_1+1] = line[i+qt_symbol_2];
            }
        }
        // with all "delim"
        if(cset_bool == 0){
            for (int i = 0; line[i]!=NULL ; i++){
                line[i+qt_symbol_1] = line[i+qt_symbol_2];
            }
        }
    }
    return;  
}
void toupper ( char line[], char delim, int column){
    int diff = 'a'-'A';
    int qt_del = 0;
    int bool_f = 0;
    int qt_symbol = 0;
    for(int i = 0; i < 10240; i++){
        if (line[i] == delim) qt_del++;
        if (column == qt_del) bool_f = 1;
        if (bool_f == 0) qt_symbol++;
    }
    qt_symbol += 1; 
    for(; line[qt_symbol] != delim; qt_symbol++){
        if (line[qt_symbol]>= 'a' && line[qt_symbol]<= 'z')
            line[qt_symbol] -= diff;
    }
}
void tolower ( char line[], char delim, int column){
    int diff = 'a'-'A';
    int qt_del = 0;
    int bool_f = 0;
    int qt_symbol = 0;
    for(int i = 0; i < 10240; i++){
        if (line[i] == delim) qt_del++;
        if (column == qt_del) bool_f = 1;
        if (bool_f == 0) qt_symbol++;
    }
    qt_symbol += 1; 
    for(; line[qt_symbol] != delim; qt_symbol++){
        if (line[qt_symbol]>= 'A' && line[qt_symbol]<= 'Z')
            line[qt_symbol] += diff;
    }
}
void round_ (int argc, char *argv[], char line[], char delim, int column){
    char bufer[100];
    int qt_delim = 0;
    int symbol = 0;
    for(int i = 0; qt_delim != column-1; i++){
        symbol++;
        if (line[i] == delim) qt_delim++;
    }
    // printf("%i\n",symbol);
    for (int i = 0;line[symbol] != delim; symbol++){
        if((line[symbol] >= 48) && (line[symbol] <= 57) || (line[symbol] == 46)){
            bufer[i] = line[symbol];
            i++;
        }
    }
    char bufer_1[100];
    sprintf(bufer_1,"%f", bufer);
    // memset(bufer_1,0,100);
    char bufer_2[100];
    int cset_bool = 1;
    int buffer_switch = 1;
    int bool_1 = 0;
    int j;
    if (column == 1)
        bool_1 = 1;
    dcol (line, delim, column, cset_bool, bool_1);
    cset (argv, line, delim, j, column, buffer_switch, bufer_1, bufer_2);
}
void integer (int argc, char *argv[], char line[], char delim, int column){
    char bufer[100];
    int qt_delim = 0;
    int symbol = 0;
    int symbol2 = 0;
    int symbol3 = 0;
    // find where the first "delim" of the cell 
    for(int i = 0; qt_delim != column-1; i++){
        symbol++;
        symbol2++;
        if (line[i] == delim) qt_delim++;
    }
    // check for numbers
    for (int i = 0;line[symbol] != delim; symbol++){
        if((line[symbol] >= 48) && (line[symbol] <= 57) || (line[symbol] == 46)){
            if(line[symbol] == 46)
                break;
            bufer[i] = line[symbol];
            symbol3++;
            i++;
        }
        else        // if the cells contain characters other than numbers, the buffer is cleared
            memset(bufer, 0, 100);
    }
    bufer[symbol3+1] = '\0';
    symbol3 = 0; 
    char bufer_1[100];
    if(bufer[0] != NULL)
    for(int i = 0; bufer[i] != NULL; i++){
        bufer_1[i] = bufer[i];
        symbol3++;
    }
    else
    {
       for(int i = 0; line[symbol2] != delim; symbol2++, i++){
            bufer_1[i] = line[symbol2];
            symbol3++;
       }
    }
    bufer_1[symbol3] = '\0';
    memset(bufer, 0, 100);
    
    char bufer_2[100];
    int cset_bool = 1;
    int buffer_switch = 1;
    int bool_1 = 0;
    int j;
    if (column == 1)
        bool_1 = 1;
    dcol (line, delim, column, cset_bool, bool_1);
    cset (argv, line, delim, j, column, buffer_switch, bufer_1, bufer_2);
}
 void cset (char *argv[], char line[], char delim, int j, int column, int buffer_switch, char bufer_1[], char bufer_2[]){
    char bufer[10240];
    int delim_num = 0;          //counter delim
    int symbol_num = 0;         //counter symbol
    int symbol_num2 = 0;
    int counter = 0;
    int couner2 = 0;
    int counter3 = 0;
    // find where the first "delim" of the cell 
    for (int i = 0; delim_num != column-1; i++){
        symbol_num++;
        symbol_num2++;
        if(line[i] == delim || NULL){
            delim_num++;
            counter++;
        }
    }
    // saves the cell selected by the user to the clipboard
    for (int i = 0; line[symbol_num] != NULL; symbol_num++, i++){
        bufer[i] = line[symbol_num];
        couner2++;
    }
    bufer[couner2] = '\0';
    if(buffer_switch == 0){
    // adds information entered by the user to the line
        for (int i = 0 ;argv[j+2][i] != NULL; i++, symbol_num2++){
            line[symbol_num2] = argv[j+2][i];
            counter3++;
        }
    }
    //  adds buffer_1 or buffer_2 to the line
    if(buffer_switch == 1){
        for (int i = 0 ;bufer_1[i] != NULL; i++, symbol_num2++){
            line[symbol_num2] = bufer_1[i];
            counter3++;
        }
    }
    if(buffer_switch == 2){
        for (int i = 0 ;bufer_2[i] != NULL; i++, symbol_num2++){
            if(bufer_2[0] == NULL) break;
            line[symbol_num2] = bufer_2[i];
            counter3++;
        }
    }
    // adds a clipboard to the line
    for (int i = 0; i <= counter+couner2+counter3+1; i++, symbol_num2++){
        line[symbol_num2] = bufer[i];
    } 
 }
void copy (char *argv[], char line[], char delim, int j, int copy_line1, int copy_line2, int buffer_switch){
    char bufer_1[100];
    char bufer_2[100];
    int qt_delim1 = 0;          //counter delim
    int qt_symbol1 = 0;
    memset(bufer_1,0,100);
    memset(bufer_2,0,100);
    // find where the first delim of the cell 
    for (int i = 0; qt_delim1 != copy_line1-1; i++){
        qt_symbol1++;
        if(line[i] == delim) qt_delim1++;
        if(line[i] == NULL) qt_delim1++;
    }
    // saves the cell selected by the user to the clipboard
    for(int i = 0;line[qt_symbol1] != delim; qt_symbol1++, i++){
        if(line[qt_symbol1] == NULL) break;
        bufer_1[i] = line[qt_symbol1];
    }
    // another way of processing for the first cell
    int bool_1 = 0;
    if(copy_line2 == 1){
        bool_1 = 1;
    }
    int column = copy_line2;
    // during normal work "dcol" removes cell along with one "delim", but no need to remove "delim" for "cset"
    int cset_bool = 1;
    dcol (line, delim, column, cset_bool, bool_1);
    // activation of the operating mode with buffer_1
    buffer_switch = 1;
    cset (argv, line, delim, j, column, buffer_switch, bufer_1, bufer_2);
    bool_1 = 0;
}
void swap ( char *argv[], char line[], char delim, int j, int copy_line1, int copy_line2, int buffer_switch){
    char bufer_1[100];
    char bufer_2[100];
    int qt_delim1 = 0;
    int qt_symbol1 = 0;
    int qt_delim2 = 0;
    int qt_symbol2 = 0;
    int symbol_bf1 = 1;
    memset(bufer_1,0,100);
    memset(bufer_2,0,100);
    // find where the first delim of the cell 
    for (int i = 0; qt_delim1 != copy_line1-1; i++){
        qt_symbol1++;
        if(line[i] == delim ) qt_delim1++;
        if(line[i] == NULL ) qt_delim1++;
    }
    // saves the cell selected by the user to the buffer_1
    for(int i = 0;line[qt_symbol1] != delim; qt_symbol1++, i++){
        bufer_1[i] = line[qt_symbol1];
        if(line[qt_symbol1] == NULL) break;
    }
    // find where the first delim of the cell 
    for (int i = 0; qt_delim2 != copy_line2-1; i++){
        qt_symbol2++;
        if(line[i] == delim) qt_delim2++;
        if(line[i] == NULL ) qt_delim1++;
    }
    // saves the cell selected by the user to the buffer_2
    for(int i = 0;line[qt_symbol2] != delim; qt_symbol2++, i++){
        bufer_2[i] = line[qt_symbol2];
        if(line[qt_symbol2] == NULL) break;
    }
    int column = copy_line2 ;
    int cset_bool = 1;

    int bool_1 = 0;
    if(copy_line2 == 1){
        bool_1 = 1;
    }
    // activation of the operating mode with buffer_1
    buffer_switch = 1;
    dcol (line, delim, column, cset_bool, bool_1);
    cset (argv, line, delim, j, column, buffer_switch, bufer_1, bufer_2);

    bool_1 = 0;
    if(copy_line1 == 1){
        bool_1 = 1;
    }
    // activation of the operating mode with buffer_2
    column = copy_line1;
    buffer_switch = 2;
    dcol (line, delim, column, cset_bool, bool_1);
    cset (argv, line, delim, j, column, buffer_switch, bufer_1, bufer_2);
    bool_1 = 0;
}
void move ( char *argv[], char line[], char delim, int j, int copy_line1, int copy_line2, int buffer_switch){
    char bufer_1[100];
    char bufer_2[100];
    int qt_delim1 = 0;
    int qt_symbol1 = 0;
    memset(bufer_1,0,100);
    memset(bufer_2,0,100);
    // find where the first delim of the cell 
    for (int i = 0; qt_delim1 != copy_line1-1; i++){
        qt_symbol1++;
        if(line[i] == delim || NULL) qt_delim1++;
    }
    for(int i = 0;line[qt_symbol1] != delim; qt_symbol1++, i++){
        bufer_1[i] = line[qt_symbol1];
    }
// create a new cell to move the cell that the user has selected
    int column = copy_line2;
    int bool1_1 = 0;
    if (copy_line2 == 1)
        bool1_1 = 1;
    column = copy_line2;
    icol ( line, delim, column, bool1_1);
    bool1_1 = 0;

    int bool_1 = 0;
    if(copy_line2 == 1){
        bool_1 = 1;
    }
// use "cset" to insert an old cell into a new one
    column = copy_line2;
    int cset_bool = 1;
    buffer_switch = 1;
    dcol (line, delim, column, cset_bool, bool_1);
    cset (argv, line, delim, j, column, buffer_switch, bufer_1, bufer_2);
// delete old cell
    bool_1 = 0;
    if(copy_line1 == 1){
        bool_1 = 1;
    }
    column = copy_line1 + 1;
    cset_bool = 0;
    dcol (line, delim, column, cset_bool, bool_1);
    bool_1 = 0;
}