#include <stdio.h>

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Need an input and output file provided\n");
        return 1;
    }

    FILE *in, *out;
    char line[10];

    in = fopen(argv[1], "r");
    out = fopen(argv[2], "w");

    if (!in || !out){
        printf("Error opening files\n");
        return 1;
    }

    int rows, cols;

    fscanf(in, "%d %d", &rows, &cols);

    int matrix[rows][cols];
    int t_matrix[cols][rows];

    // Get values from infile
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
             fscanf(in, "%d", &matrix[i][j]);
        }
    }

    // Transpose values into new matrix
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
             t_matrix[j][i] = matrix[i][j];
        }
    }

    // Write transposed matrix to outfile
    for (int i = 0; i < cols; i++){
        for (int j = 0; j < rows; j++) {
            fprintf(out, "%d", t_matrix[i][j]);

            if (j < rows - 1) { 
                fprintf(out, " ");
            }   
        }
        if (i < cols - 1){
            fprintf(out, "\n");
        }
    }

    fclose(in);
    fclose(out);
    return 0;
}