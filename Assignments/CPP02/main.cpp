#include <fstream>
#include "stats.h"

using namespace std;

int main(int argc, char *argv[]) {
    double min = 0, max = 0, avg = 0, std_dev = 0, line;

    // Open the output file
    string file_name(argv[argc-1]);
    ofstream output(file_name);
    
    // Loop through the input files
    for (int i = 1; i < argc - 1; i++){
        //Initialize values for the next input file
        min = 0, max = 0, avg = 0, std_dev = 0;
        vector<double> values;
        string file_name(argv[i]);
        ifstream file(file_name);

        if (file.is_open()) {
            while(file >> line){
                values.push_back(line);
            }
        }
        //Sort the values from the file and calculate the stats with the formatted vector
        sort(values);
        stats(values,min,max,avg,std_dev);

        // Write to the output file and close the current input file
        output << min << ',' << max << ',' << avg << ',' << std_dev << '\n';
        file.close();
    }
    output.close();
    return 0;
}
