typedef struct {
    int studentID; 
    char exam[40];
    int day, month, year, grade;
    
} studentInfo;

typedef struct {
    int studentID, examsNumber, summedUpGrades;

} basicInfo;

typedef struct list {
    basicInfo data;
    struct list *next;

} list;


void createNode(list *lastNode, int studentID, int value);
void updateNode(list *node, int value, int index);
void searchForDuplicate(list *node, studentInfo *ID, int *index, bool *flag);
void printNodes(list *node);