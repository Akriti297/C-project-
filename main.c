
#include <stdio.h>
#include <stdlib.h>

#define ROWS    25     
#define COLS    70    
#define BLANK   '_'     
#define DOT     '*'     
#define MAX     64
 

#define CIRCLE    1
#define RECTANGLE 2
#define LINE      3
#define TRIANGLE  4
 

struct Shape {
    int id;       
    int type;     
    int alive;    
    int x, y;     
    int a, b;     
};
 
char         canvas[ROWS][COLS];      
struct Shape shapes[MAX];             
int          total   = 0;            
int          next_id = 1;            

void clear_canvas(void)
{
    int r, c;
    for (r = 0; r < ROWS; r++)
        for (c = 0; c < COLS; c++)
            canvas[r][c] = BLANK;
}

void show_canvas(void)
{
    int r, c;
 
    /* top border */
    printf("+");
    for (c = 0; c < COLS; c++) printf("-");
    printf("+\n");
 
    /* each row */
    for (r = 0; r < ROWS; r++) {
        printf("|");
        for (c = 0; c < COLS; c++)
            printf("%c", canvas[r][c]);
        printf("|\n");
    }
 
    /* bottom border */
    printf("+");
    for (c = 0; c < COLS; c++) printf("-");
    printf("+\n");
}
 
//puts dots i.e, '*' on the canvas (or) replaces '_' with '*'
void put_dot(int row, int col)
{
    if (row >= 0 && row < ROWS && col >= 0 && col < COLS)
        canvas[row][col] = DOT;
}
 
// removes the dots from the canvas (or) replaces '*' with '_'
void remove_dot(int row, int col)
{
    if (row >= 0 && row < ROWS && col >= 0 && col < COLS)
        canvas[row][col] = BLANK;
}
void draw_rectangle(int x, int y, int width, int height)
{
    int i;

    // top side
    for(i = x; i < x + width; i++)
        put_dot(y, i);

    // bottom side
    for(i = x; i < x + width; i++)
        put_dot(y + height - 1, i);

    // left side
    for(i = y; i < y + height; i++)
        put_dot(i, x);

    // right side
    for(i = y; i < y + height; i++)
        put_dot(i, x + width - 1);
}
void draw_line(int x1, int y1, int x2, int y2)
{
    int i;

    if(y1 == y2) 
    {
        for(i = x1; i <= x2; i++)
            put_dot(y1, i);
    }

    else if(x1 == x2) 
    {
        for(i = y1; i <= y2; i++)
            put_dot(i, x1);
    }
}
void draw_triangle(int x, int y, int height)
{
    int i;

    
    for(i = 0; i < height; i++)
        put_dot(y + i, x - i);

    
    for(i = 0; i < height; i++)
        put_dot(y + i, x + i);

    
    for(i = x - height + 1; i <= x + height - 1; i++)
        put_dot(y + height - 1, i);
}
void draw_circle(int x, int y, int radius)
{
    int r, c;
    int r2 = radius * radius;

    for(r = y - radius; r <= y + radius; r++)
    {
        for(c = x - radius; c <= x + radius; c++)
        {
            int dx = c - x;
            int dy = r - y;

            if(dx * dx + dy * dy <= r2)
            {
                put_dot(r, c);
            }
        }
    }
}

void redraw_shapes(void)
{
    int i;

    for(i = 0; i < total; i++)
    {
        if(shapes[i].alive == 1)
        {
            if(shapes[i].type == RECTANGLE)
            {
                draw_rectangle(
                    shapes[i].x,
                    shapes[i].y,
                    shapes[i].a,
                    shapes[i].b
                );
            }

            else if(shapes[i].type == LINE)
            {
                draw_line(
                    shapes[i].x,
                    shapes[i].y,
                    shapes[i].a,
                    shapes[i].b
                );
            }

            else if(shapes[i].type == CIRCLE)
            {
                draw_circle(
                    shapes[i].x,
                    shapes[i].y,
                    shapes[i].a
                );
            }

            else if(shapes[i].type == TRIANGLE)
            {
                draw_triangle(
                    shapes[i].x,
                    shapes[i].y,
                    shapes[i].a
                );
            }
        }
    }
}
void delete_shape(int id)
{
    int i;

    for(i = 0; i < total; i++)
    {
        if(shapes[i].id == id)
        {
            shapes[i].alive = 0;
            break;
        }
    }
}
int main(void)
{
    clear_canvas();
    draw_rectangle(10,5,20,8);
    draw_line(5, 15, 25, 15);
    draw_triangle(55, 8, 6);
    draw_circle(25, 18, 5);
    
shapes[0].type = RECTANGLE;
shapes[0].alive = 0;
shapes[0].x = 10;
shapes[0].y = 5;
shapes[0].a = 20;
shapes[0].b = 8;

shapes[1].type = LINE;
shapes[1].alive = 1;
shapes[1].x = 5;
shapes[1].y = 15;
shapes[1].a = 25;
shapes[1].b = 15;

    draw_line(5, 15, 25, 15);

shapes[2].type = LINE;
shapes[2].alive = 1;
shapes[2].x = 40;
shapes[2].y = 5;
shapes[2].a = 40;
shapes[2].b = 18;

    draw_line(40,5,40,18);

shapes[3].type = TRIANGLE;
shapes[3].alive = 1;
shapes[3].x = 55;
shapes[3].y = 8;
shapes[3].a = 6;

    draw_triangle(55, 8, 6);
shapes[4].type = CIRCLE;
shapes[4].alive = 1;
shapes[4].x = 25;
shapes[4].y = 18;
shapes[4].a = 5;

    clear_canvas();

shapes[0].id=1;
shapes[0].type = RECTANGLE;
shapes[0].alive = 0;
shapes[0].x = 10;
@@ -241,6 +256,7 @@ shapes[0].a = 20;
shapes[0].b = 8;


shapes[1].id=1+2;
shapes[1].type = LINE;
shapes[1].alive = 1;
shapes[1].x = 5;
@@ -249,6 +265,7 @@ shapes[1].a = 25;
shapes[1].b = 15;


shapes[2].id=3;
shapes[2].type = LINE;
shapes[2].alive = 1;
shapes[2].x = 40;
@@ -257,13 +274,15 @@ shapes[2].a = 40;
shapes[2].b = 18;


shapes[3].id=4;
shapes[3].type = TRIANGLE;
shapes[3].alive = 1;
shapes[3].x = 55;
shapes[3].y = 8;
shapes[3].a = 6;

shapes[4].id=5;
shapes[4].type = CIRCLE;
shapes[4].alive = 1;
shapes[4].x = 25;
@@ -280,6 +299,8 @@ total = 5;

    // draw_circle(25, 18, 5);

    delete_shape(5);

    draw_circle(25, 18, 5);
total = 5;


    redraw_shapes();
    show_canvas();

    return 0;
}