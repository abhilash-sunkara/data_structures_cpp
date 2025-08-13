#include <vector>
#include <iostream>

struct graph {
    std::vector<std::vector<int>> matrix;
    std::vector<int> keys;
    int width;
};

struct graph* create_graph(){
    return new graph();
}

int find_key(graph* g, int x){
    for(int i = 0; i < g->keys.size(); i++){
        if(g->keys.at(i) == x){
            return i;
        }
    }
    return -1;
}

void add_vertex(struct graph* g, int x){
    g->keys.push_back(x);
    std::vector<int> temp(g->width);
    g->matrix.push_back(temp);
    g->width++;
    for(std::vector<int>& v : g->matrix){
        v.push_back(0);
    }
}

void add_edge(struct graph* g, int x1, int x2, int w){
    int cx1 = find_key(g, x1);
    int cx2 = find_key(g, x2);

    g->matrix[cx1][cx2] = w;
    g->matrix[cx2][cx1] = w;
}

int get_edge(struct graph* g, int x1, int x2){
    int cx1 = find_key(g, x1);
    int cx2 = find_key(g, x2);
    
    return g->matrix[cx1][cx2];
}

void remove_edge(struct graph* g, int x1, int x2){
    int cx1 = find_key(g, x1);
    int cx2 = find_key(g, x2);
    
    g->matrix[cx1][cx2] = 0;
    g->matrix[cx2][cx1] = 0;
}

void remove_vertex(struct graph* g, int x){
    int cx = find_key(g, x);
    
    g->matrix.erase(g->matrix.begin() + cx);

    for(std::vector<int>& v : g->matrix){
        v.erase(v.begin() + cx);
    }

    g->width--;
}

void print_graph(struct graph* g){
    for(int i = 0; i < g->width; i++){
        for(std::vector<int> v : g->matrix){
            std::cout << v.at(i) << " ";
        }
        std::cout << std::endl;
    }
}

int main(){
    struct graph* graph = create_graph();
    add_vertex(graph, 2);
    add_vertex(graph, 4);
    add_vertex(graph, 6);
    add_edge(graph, 2, 4, 5);
    add_edge(graph, 4, 6, 3);
    print_graph(graph);

    remove_edge(graph, 2, 4);
    print_graph(graph);
    remove_vertex(graph, 2);
    print_graph(graph);
}