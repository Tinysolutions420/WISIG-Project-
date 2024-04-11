#include <stdio.h>

// Structure to store the data
struct PHY_data {
    int Sfn;
    int Slot;
    int PRACH;
    int PUSCH;
    int PUCCH;
    int US_HARQ;
    int SSB;
    int PDSCH;
    int PDCCH;
};

// Function to print the data in tabular format
void print_data_table(struct PHY_data data[], int size) {
    // Print the table header
    printf("| %-5s | %-5s | %-6s | %-6s | %-6s | %-12s | %-5s | %-6s | %-6s |\n",
           "Sfn", "Slot", "PRACH", "PUSCH", "PUCCH", "US_HARQ", "SSB", "PDSCH", "PDCCH");
    printf("|-------|-------|--------|--------|--------|--------------|-------|--------|--------|\n");

    // Print each row of data
    for (int i = 0; i < size; i++) {
        printf("| %-5d | %-5d | %-6d | %-6d | %-6d | %-12d | %-5d | %-6d | %-6d |\n",
               data[i].Sfn, data[i].Slot, data[i].PRACH, data[i].PUSCH, data[i].PUCCH,
               data[i].US_HARQ, data[i].SSB, data[i].PDSCH, data[i].PDCCH);
    }
}

int main() {
    FILE *file = fopen("data.txt", "r"); // Open the file in read mode
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    // Read data from the file
    struct PHY_data data[100]; // Assuming a maximum of 100 entries
    int size = 0;
    while (fscanf(file, "Sfn: %d, Slot: %d, PRACH: %d, PUSCH: %d, PUCCH %d, US_HARQ %d, SSB: %d, PDSCH: %d, PDCCH: %d",
                  &data[size].Sfn, &data[size].Slot, &data[size].PRACH,
                  &data[size].PUSCH, &data[size].PUCCH, &data[size].US_HARQ,
                  &data[size].SSB, &data[size].PDSCH, &data[size].PDCCH) == 9) {
        size++;
    }

    fclose(file); // Close the file

    // Print the data in table format
    print_data_table(data, size);

    return 0;
}

