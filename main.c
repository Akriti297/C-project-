
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




int main(void)
{
    clear_canvas();
    draw_rectangle(10,5,20,8);
    show_canvas();

    return 0;
}