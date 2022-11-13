typedef struct no No;
typedef struct listInfo Lista;

Lista* list_create();
void list_empty(Lista* list);
void insert_beginning(Lista* list, char* name, int numero);
void insert_ending(Lista* list, char* name, int numero);
void insert_index(Lista* list, char* name, int numero, int posic);
int quantity(Lista* list);
void print_list(Lista* list);
int remove_beginning(Lista* list);
int remove_index(Lista* list, int numero, int posant);
void free_list(Lista *list);
int maior(Lista* list);
void print_index(No* nodo);
void sort_list(Lista* list);
int return_int(No* nodo);
char return_string(No* nodo);
