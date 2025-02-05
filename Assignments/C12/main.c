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

    printf("Rows: %d, Cols: %d\n", rows, cols);

    int t_matrix[cols][rows];

    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
             fscanf(in, "%d", &t_matrix[j][i]);
        }
    }

        for (int i = 0; i < rows; i++){
            for (int j = 0; j < cols; j++){
             printf("%d",t_matrix[j][i]);
        }
        printf("\n");
    }
    fclose(in);
    fclose(out);
    return 0;
}