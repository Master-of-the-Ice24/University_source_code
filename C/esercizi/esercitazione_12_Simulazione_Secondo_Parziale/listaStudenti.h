typedef struct {
    int studentID; 
    char exam[40];
    int day, month, year, grade;
    
} studentInfo;

typedef struct list {
    studentInfo data;
    struct list *next;

} list;


void createNode(list *lastNode, int studentID, int value);

void updateNode(list *node, int value, int index);