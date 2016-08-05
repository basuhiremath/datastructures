#Singly Linked List

singly_list_node_t *create_singly_list( int value );

int destroy_singly_list( singly_list_node_t **node_head );

int prepend_singly_node( singly_list_node_t **node_head, int value );

int append_singly_node( singly_list_node_t *node_head, int value );

int count_singly_nodes( singly_list_node_t *node_head );

void print_singly_list( singly_list_node_t *node_head );

int find_singly_node( singly_list_node_t *node_head, const int value );

int remove_singly_head_node( singly_list_node_t **node_head );

int remove_singly_tail_node( singly_list_node_t **node_head );

int remove_singly_node( singly_list_node_t **node_head, int position );

int insert_singly_node(singly_list_node_t **node_head, int insert_position, int value);

int swap_singly_node(singly_list_node_t *node_head, int position_x, int position_y);
