#include <stdio.h>

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Need an input and output file provided\n");
        return 1;
    }

    FILE *in, *out;

    in = fopen(argv[1], "r");
    out = fopen(argv[2], "w");

    if (!in || !out){
        printf("Error opening files\n");
        return 1;
    }

    int rows, cols;

    fscanf(in, "%d %d", &rows, &cols);

    int matrix[rows][cols];
    int t_matrix[cols+1][rows];

    t_matrix[0][0] = cols;
    t_matrix[0][1] = rows;

    // Get values from infile
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
             fscanf(in, "%d", &matrix[i][j]);
        }
    }

    // Transpose values into new matrix
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
             t_matrix[j+1][i] = matrix[i][j];
        }
    }

    fprintf(out, "%d %d\n", t_matrix[0][0], t_matrix[0][1]);

    // Write transposed matrix to outfile
    for (int i = 1; i < cols+1; i++){
        for (int j = 0; j < rows; j++) {
            fprintf(out, "%d", t_matrix[i][j]);

            if (j < rows - 1) { 
                fprintf(out, " ");
            }   
        }
        if (i < cols){
            fprintf(out, "\n");
        }
    }

    fclose(in);
    fclose(out);
    return 0;
}