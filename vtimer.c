/* Vtimer v0.2
 * Author: Kurashov Artem
 * License: GNU GPLv3
 */
#include <curses.h>
#include <stdlib.h>
#include <unistd.h>

int main (int argc, char **argv)
{
  int i, j, ds;
  WINDOW *vt0;
  if (argc == 1)
    {
      printf ("usage: vtimer seconds\n");
      return 1;
    }
  ds = atoi (argv[1]);
  initscr ();
  clear ();
  curs_set (0);
  vt0 = newwin (LINES, COLS, 0, 0);
  mvwaddch (vt0, LINES / 2, 0, '[');
  mvwaddch (vt0, LINES / 2, COLS - 1, ']');
  wrefresh (vt0);
  for (i = 0; i < ds; i++)
    {
      sleep (1);
      for (j = 1; j < (i + 1) * (COLS - 1) / ds; j++)
	mvwaddch (vt0, LINES / 2, j, '#');
      wrefresh (vt0);
    }
  endwin ();
  return 0;
}
