/*g++ mainsajat.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images` -std=c++11*/

#include "Simple_window.h"
#include "Graph.h"


using namespace Graph_lib;

int main()
try {

    const Point tl {100, 100};
    Simple_window win {tl, 800, 1000, "13Drill"};

    int x_size = 800;
    int y_size = 800;
    int x_grid = 100;
    int y_grid = 100;

    Lines grid;
    for (int x = x_grid; x < x_size; x += x_grid)
        grid.add(Point{x, 0}, Point{x, y_size});    
    for (int y = y_grid; y < y_size; y += y_grid)
        grid.add(Point{0, y}, Point{x_size, y});

    grid.set_color(Color::red);

    win.attach(grid);
    
    win.wait_for_button();

    Vector_ref<Rectangle> rects;
    for (int i = 0; i < x_size; i += x_grid) {
        rects.push_back(new Rectangle{Point{i,i}, Point{i+x_grid,i+x_grid}});
        rects[rects.size() - 1].set_color(Color::invisible);
        rects[rects.size() - 1].set_fill_color(Color::red);
        win.attach(rects[rects.size() - 1]);
    }


    Image cpp1 {Point{0,300}, "index.jpg"};
    Image cpp2 {Point{300,600}, "index.jpg"};
    Image cpp3 {Point{500,100}, "index.jpg"};
    cpp1.set_mask(Point{0,0},200,200);
    cpp2.set_mask(Point{0,0},200,200);
    cpp3.set_mask(Point{0,0},200,200);
    win.attach(cpp1);
    win.attach(cpp2);
    win.attach(cpp3);

    Image picture {Point{0,0}, "index.jpg"};
    picture.set_mask(Point{0,0},100,100);
    win.attach(picture);
    win.wait_for_button();
    
    for (int i = 0; i < 8; ++i) {   
        for (int j =0; j < 8; ++j) {
            picture.move(100, 0);
            win.wait_for_button();
        }
        picture.move(-800, 100);      
        win.wait_for_button();
            }
}
catch(exception& e) {
    cerr << "exception: " << e.what() << '\n';
    return 1;
}
catch(...) {
    cerr << "error\n";
    return 2;
}
