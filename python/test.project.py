import curses

maze = [
    "#################",
    "#P      #      E#",
    "# ### # # #######",
    "#     #   #     #",
    "##### ##### ### #",
    "#   #       #   #",
    "# # ########### #",
    "# #           # #",
    "#################"
]

def draw_maze(stdscr, player_x, player_y):
    stdscr.clear()
    for y, row in enumerate(maze):
        stdscr.addstr(y, 0, row)
    stdscr.addstr(player_y, player_x, "P")  # Draw Player
    stdscr.refresh()

def game(stdscr):
    curses.curs_set(0)
    stdscr.nodelay(1)
    stdscr.timeout(100)

    player_x, player_y = 1, 1  # Player Start

    while True:
        draw_maze(stdscr, player_x, player_y)
        key = stdscr.getch()

        if key in [ord("q")]:  # Quit
            break

        # Movement logic
        new_x, new_y = player_x, player_y
        if key == curses.KEY_UP:
            new_y -= 1
        elif key == curses.KEY_DOWN:
            new_y += 1
        elif key == curses.KEY_LEFT:
            new_x -= 1
        elif key == curses.KEY_RIGHT:
            new_x += 1

        # Check walls
        if maze[new_y][new_x] != "#":
            player_x, player_y = new_x, new_y

        # Check exit
        if maze[player_y][player_x] == "E":
            stdscr.addstr(len(maze), 0, "You win! Press any key to exit.")
            stdscr.refresh()
            stdscr.getch()
            break

curses.wrapper(game)
