typedef struct{
    char fiscalCode[17];
    int day, month, year;
    float amount;

} clientsInfo;


typedef struct clientsList {
    clientsInfo information;
    struct clientsList *next;
    
} clientsList;


void dataFetcher(char *filename);