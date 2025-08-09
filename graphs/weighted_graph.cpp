
#include <vector>
#include <cstdlib>
#include <iostream>

struct graph {
    std::vector<struct edge*> edges;
    std::vector<struct vertex*> vertices;
};

struct edge {
    struct vertex* node1;
    struct vertex* node2;
    int weight;
};

struct vertex {
    int val;
};

struct graph* create_graph();
struct vertex* create_vertex(int);
struct edge* create_edge(struct vertex*, struct vertex*, int);

void add_vertex(struct graph*, int);
void add_edge(struct graph*, int, int, int);

int find_vertex(struct graph*, int);
struct vertex* get_vertex(struct graph*, int);

std::vector<struct vertex*> get_neighbours(struct graph*, int);
int get_adjacent(graph*, int, int);

void print_edges(struct graph*);

void remove_vertex(struct graph*, int);
void remove_edge(struct graph*, int, int);
void remove_all_edges(struct graph*, int);

int get_weight(struct graph*, int, int);

int main (){
    struct graph* graph = create_graph();
    add_vertex(graph, 2);
    add_vertex(graph, 4);
    add_vertex(graph, 5);
    /* std::cout << find_vertex(graph, 2) << std::endl;
    std::cout << find_vertex(graph, 4) << std::endl; */
    add_edge(graph, 2, 4, 5);
    add_edge(graph, 4, 5, 3);
    /* print_edges(graph); */
    get_neighbours(graph, 2);
    get_neighbours(graph, 4);

    get_adjacent(graph, 7, 5);
    get_adjacent(graph, 2, 5);

    remove_edge(graph, 2, 4);
    get_neighbours(graph, 2);
    get_neighbours(graph, 4);

    remove_vertex(graph, 5);
    get_neighbours(graph, 4);
}

struct graph* create_graph(){
    return new graph();
}

struct vertex* create_vertex(int x){
    struct vertex* temp = (struct vertex*) malloc(sizeof(struct vertex));
    temp->val = x;
    return temp;
}

void add_vertex(struct graph* g, int x){
    g->vertices.push_back(create_vertex(x));
}

int find_vertex(struct graph* g, int x){
    for(struct vertex* v : g->vertices) {
        if(v->val == x){
            return 1;
        } 
    }
    return 0;
}

struct vertex* get_vertex(struct graph* g, int x){
    for(struct vertex* v : g->vertices) {
        if(v->val == x){
            return v;
        } 
    }
    return NULL;
}

void add_edge(struct graph* g, int x, int y, int w){
    struct vertex* v1 = get_vertex(g, x);
    struct vertex* v2 = get_vertex(g, y);
    if(v2 != NULL && v2 != NULL){
        /* std::cout << "creating edge" << std::endl; */
        g->edges.push_back(create_edge(v1, v2, w));
    }
}

struct edge* create_edge(struct vertex* x, struct vertex* y, int w){
    struct edge* temp = (struct edge*) malloc(sizeof(struct edge));
    temp->node1 = x;
    temp->node2 = y;
    temp->weight = w;
    return temp;
}

void print_edges(struct graph* g){
    for(struct edge* e : g->edges){
        std::cout << "edge from " << e->node1->val << " to " << e->node2->val << std::endl;
    }
}

std::vector<struct vertex*> get_neighbours(struct graph* g, int x){
    std::vector<struct vertex*> temp;
    for(struct edge* e : g->edges){
        if(e->node1->val == x){
            std::cout << "Has an edge with " << e->node2->val << std::endl;
            temp.push_back(e->node2);
        } else if (e->node2->val == x){
            std::cout << "Has an edge with " << e->node1->val << std::endl;
            temp.push_back(e->node1);
        }
    }
    return temp;
}

int get_adjacent(graph* g, int x, int y){
    for(struct edge* e : g->edges){
        if(e->node1->val == x && e->node2->val == y){
            std::cout<< "Found edge with " << e->node1->val << " and " << e->node2->val << std::endl;
            return 1;
        } else if (e->node2->val == x && e->node1->val == y){
            std::cout<< "Found edge with " << e->node1->val << " and " << e->node2->val << std::endl;
            return 1;
        }
    }
    std::cout<< "Can't find an edge with " << x << " and " << y << std::endl;
    return 0;
}

void remove_edge(struct graph* g, int x, int y){
    for(int i = 0; i < g->edges.size(); i++){
        if(g->edges[i]->node1->val == x && g->edges[i]->node2->val == y){
            g->edges.erase(g->edges.begin() + i);
        } else if(g->edges[i]->node2->val == x && g->edges[i]->node1->val == y){
            g->edges.erase(g->edges.begin() + i);
        }
    }
}

void remove_all_edges(struct graph* g, int x){
    for(int i = 0; i < g->edges.size(); i++){
        if(g->edges[i]->node1->val == x || g->edges[i]->node2->val == x){
            g->edges.erase(g->edges.begin() + i);
        }
    }
}

void remove_vertex(struct graph* g, int x){
    for(int i = 0; i < g->vertices.size(); i++){
        if(g->vertices[i]->val == x){
            /* std::cout << "found vertex" << std::endl; */
            remove_all_edges(g, x);
            g->vertices.erase(g->vertices.begin() + i);
        }
    }
}

int get_weight(graph* g, int x, int y){
    for(struct edge* e : g->edges){
        if(e->node1->val == x && e->node2->val == y){
            std::cout<< "Edge with " << e->node1->val << " and " << e->node2->val << " has a weight of " << e->weight << std::endl;
            return e->weight;
        } else if (e->node2->val == x && e->node1->val == y){
            std::cout<< "Edge with " << e->node1->val << " and " << e->node2->val << " has a weight of " << e->weight << std::endl;
            return e->weight;
        }
    }
    std::cout<< "Can't find an edge with " << x << " and " << y << std::endl;
    return 0;
}